#include "./std_lib_facilities.h"
#include <cstdlib>
#include <ctime>

#define LIST_MAX (4)

int check_bulls(vector<int> list, vector<int> *cows, vector<int> *check, vector<int> input){
    int bulls = 0;
    for (int i = 0; i < list.size(); i++){
        if (list[i] == input[i])
            bulls++;
        else {
            cows->push_back(input[i]);
            check->push_back(list[i]);
        }
    }

    return bulls;
}

int check_cows(vector<int> list,  vector<int> cows){ // n^2 :(
    int cow_count = 0;
    for (int i = 0; i < cows.size(); i++){
        for (int j = 0; j < list.size(); j++)
            if (cows[i] == list[j]){
                    cow_count++;
                    list.erase(list.begin() + j);
                    break;
            }
    }
    
    return cow_count;
}

void populate_input(vector<int> *input){
    vector<int>new_list;
    int temp;
    puts("Please enter four numbers (0-9):");
    for (int i = 0; i < LIST_MAX; i++){
        cin >> temp;
        if (!(0 <= temp && temp <= 9))
            error("Number outside the range [0, 9]. Aborting.");
        else
            input->push_back(temp);
    }
        
 
}
    
int main(void){

    //Generate Random Numbers
    srand(time(NULL));
    
    vector<int> list;
    int temp;
    for (int i = 0; i < LIST_MAX; i++){
        temp = rand() % 9;
        list.push_back(temp);
    }
    cout << "Numbers have been generated...\n";
    // FUCKING HELL, I CAN'T THINK OF A GOOD ALGORITHM

    vector<int> input;
    vector<int> cows;
    vector<int> check;

    int bull_count = 0;
    int cow_count = 0;
    int attempts = 0;


    do{

        // Clear vectors before processing
        input.clear();
        cows.clear();
        check.clear();

        populate_input(&input);
        bull_count = check_bulls(list, &cows, &check, input);
        cow_count = check_cows(check, cows);
        attempts++;
        
        printf((bull_count == 1)? "One bull has been found.\n" :
               "%d bulls have been found.\n", bull_count);
        printf((cow_count == 1)? "One cow has been found.\n" :
               "%d cows have been found.\n", cow_count);

        printf("\n");
        if (bull_count == LIST_MAX)
            printf("It took you %d attempts to win.\n", attempts);
        
    }while(bull_count != LIST_MAX);
    
    
}




