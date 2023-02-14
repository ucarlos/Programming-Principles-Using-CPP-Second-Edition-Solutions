#include "./std_lib_facilities.h"

int main(void){
    int pennies, sum;
    int nickels, dimes;
    int quarters, half_dollars;
    int dollars;

    string prompt = "How many ";
    
    cout << prompt << "pennies do you have? ";
    cin >> pennies;
    cout << prompt << "nickels do you have? ";
    cin >> nickels;
    cout << prompt << "dimes do you have? ";
    cin >> dimes;
    cout << prompt << "quarters do you have? ";
    cin >> quarters;
    cout << prompt << "half-dollar coins do you have? ";
    cin >> half_dollars;
    cout << prompt << "dollar coins do you have? ";
    cin >> dollars;
    
    sum = pennies + 5 * nickels + 10 * dimes + 25 * quarters;
    sum += (50 *half_dollars)  + (100 * dollars);

    cout << "\n\n\n\n";
    
    printf("You have %d pennies.\nYou have %d nickels.\n", pennies, nickels);
    printf("You have %d dimes.\nYou have %d quarters.\n", dimes, quarters);
    printf("You have %d half dollars.\nYou have %d dollars.\n",
           half_dollars, dollars);



    printf((pennies == 1)? "You have 1 penny.\n" : "You have %d pennies.\n",
           pennies);

    printf((nickels == 1)? "You have 1 nickel.\n" : "You have %d nickels.\n",
           nickels);

    printf((dimes == 1)? "You have 1 " "dime " ".\n" : "You have %d " "dimes"
           ".\n", dimes);

    printf((quarters == 1)? "You have 1 " "quarter " ".\n" : "You have %d "
           "quarter" ".\n", quarters);

    printf((half_dollars == 1)? "You have 1 " "half-dollar " ".\n" :
           "You have %d " "half-dollars" ".\n", half_dollars);

    printf((dollars == 1)? "You have 1 " "dollar coin" ".\n" :
           "You have %d " "dollar coins" ".\n", dollars);
    
////////////////////////////////////////////////////////////////////////////////
    
    cout << "The value of all your coins is " << sum << " cents.\n";
    printf("In normal usage, that would be $%.2f\n", (double)sum / 100);

    return 0;
    
}    
