#include "./std_lib_facilities.h"
#include <climits>
long fibonacci(int num){
    long num1, num2;
    num1 = num2 = 1;
    long temp;

    
    for (int i = 0; i < num; i++){
        temp = num1 + num2;
        num1 = num2;
        num2 = temp;

    }
    
    return num2;
}    


int main(void){
    int index = 2;
    long temp = 1;

    while (temp <= INT_MAX && (index <= (INT_MAX))){ // Find the index that breaks the loop
        temp = fibonacci(index++);
    }

    if (index >= INT_MAX)
        error("Error: Index is greater than INT_MAX. Aborting.");

    //Subtract by two so that you get the actual amount
    temp = fibonacci(index - 2);
    
    cout << "The largest fibonacci number that fits " << INT_MAX << " is "
         << temp << "\n";
    cout << "It took " << index << " attempts.\n";

         


}

