#include "../std_lib_facilities.h"
#include <cstdlib>
#include <ctime>
#include <cctype>
/*------------------------------------------------------------------------------
  Created by Ulysses Carlos on 08/15/19
  
  Program06_08.cpp
      Redo the “Bulls and Cows” game from exercise 12 in Chapter 5 to use
      four letters rather than four digits.

 *------------------------------------------------------------------------------
*/
//------------------------------------------------------------------------------
// Macros:
#define LIST_SIZE (4)
#define ASCII_ALPHA_LOW  ((int) 'a')
#define ASCII_ALPHA_HIGH ((int) 'z')

//------------------------------------------------------------------------------
// Class Information:

enum token_type { bull, cow, neither, inital };

class Bull_Token{
public:
	char letter;
	void set_type(token_type type);
	token_type get_type();
	Bull_Token(char letter);
private:
	token_type type {inital};
};

Bull_Token::Bull_Token(char letter){
	this->letter = letter;
}	

void Bull_Token::set_type(token_type type){
	this->type = type;
}	

token_type Bull_Token::get_type(){
	return this->type;
}

//------------------------------------------------------------------------------

void generate_input(vector<Bull_Token> *list){
	// Now populate input:
	char input;
    string check;
	for (int i = 0; i < LIST_SIZE; i++){
		cin >> input;
		if (!isalpha(input)) {
		    check += input;
            error("Error: \" "  + check + " \" is a Non-alphabetical character.");
        }
		input = tolower(input);
		list->push_back(Bull_Token(input));
	}

}	

int check_bull(vector<char> list, vector<Bull_Token> user, vector<char> *test){
	int bull = 0;
	
	for (int i = 0; i < LIST_SIZE; i++){
		if (user[i].letter  == list[i]){
			bull++;
			user[i].set_type(token_type(bull));
		}
		else
			test->push_back(list[i]);
	}
	
	return bull;
}

int search_list(vector<char> list, char check){
	
	for (int i = 0; i < list.size(); i++)
		if (list[i] == check)
			return i;

	return -1; //Not found
}

int check_cows(vector<char> test, vector<Bull_Token> user){
	int cows = 0;
	int check;
	
	for (int i = 0; i < LIST_SIZE; i++){
		if (user[i].get_type() != bull){
			check = search_list(test, user[i].letter);
			if (check != -1){
				cows++;
				test.erase(test.begin() + check);
				user[i].set_type(token_type(cow));
			}
		}
	}

	return cows;
}


int main(void){
	// Generate Random numbers:
	srand(time(NULL));

	vector<char> list;
	vector<Bull_Token> user;
	vector<char> test;
	
	int number;

	int bull_count = 0;
	int cow_count = 0;

	int attempts = 0;
	// Populate List:
	for (int i = 0; i < LIST_SIZE; i++){
		number = (rand() % (ASCII_ALPHA_HIGH - ASCII_ALPHA_LOW)) + ASCII_ALPHA_LOW;
		list.push_back((char)number);
	}

	puts("Please enter four letters (a - z):");
	do{
		user.clear();
		test.clear();
		generate_input(&user);

        bull_count = check_bull(list, user, &test);
        cow_count = check_cows(test, user);

		printf("%d Bull(s) found.\n", bull_count);
		printf("%d Cow(s) found.\n", cow_count);

		attempts++;

	}while(bull_count != LIST_SIZE);
		
	printf("Gameover! It took you %d attempts to win.", attempts);

	return 0;
}

