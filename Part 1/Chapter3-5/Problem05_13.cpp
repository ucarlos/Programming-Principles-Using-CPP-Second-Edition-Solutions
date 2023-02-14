#include "./std_lib_facilities.h"
#include <cstdlib>
#include <ctime>

#define LIST_MAX (4)

int check_bulls(vector<int> list, vector<int> cows, vector<int> input){
    int bulls = 0;
    for (int i = 0; i < list.size(); i++){
        if (list[i] == input[i])
            bulls++;
        else
            cows.push_back(list[i]);
    }

    return bulls;
}

int check_cows(vector<int> list,  vector<int> cows){ // n^2 :(
    int cow_count = 0;
    for (int i = 0; i < cows.size(); i++){
        for (int j = 0; j < list.size(); j++)
            if (cows[i] == list[j])
                cow_count++;
    }
    
    return cow_count;
}

void populate_input(vector<int> input){
    int temp;
    puts("Please enter four numbers (0-9):");
    for (int i = 0; i < LIST_MAX; i++){
        cin >> temp;
        if (!(0 <= temp && temp <= 9))
            error("Number outside the range [0, 9]. Aborting.");
        else
            input.push_back(temp);
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
    
    // FUCKING HELL, I CAN'T THINK OF A GOOD ALGORITHM

    vector<int> input;
    vector<int> cows;

    int bull_count = 0;
    int cow_count = 0;
    int attempts = 0;
    
    do{
        // Clear vectors before processing
        input.clear();
        cows.clear();

        populate_input(input);
        check_bulls(list, cows, input);
        check_cows(list, cows);
        attempts++;
        
        printf((bull_count  == 1)? "One bull has been found.\n" :
               "%d bulls have been found.\n ", bull_count);
        printf((cow_count == 1)? "One cow has been found.\n" :
               "%d cows have been found.\n", cow_count);

        if (bull_count == LIST_MAX)
            printf("It took you %d attempts to win.\n", attempts);
        
    }while(bull_count != LIST_MAX);
    
    
}




