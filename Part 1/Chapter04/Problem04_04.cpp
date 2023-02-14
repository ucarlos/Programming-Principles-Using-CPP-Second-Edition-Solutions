#include "./std_lib_facilities.h"
#define SIZE (100)
void binary_search(int input, int low, int high);

int main(void){
    int input;
    cout << "Please enter a number between 1 and " << SIZE << ": \n";

    while (cin >> input && !(1 <= input && input <= SIZE)){
        cout << "The number is outside the range of 1 and " << SIZE << ".";
        cout << " Please try again.\n";
    }

    binary_search(input, 1, (SIZE));
    
    return 0;
}

void binary_search(int input, int low, int high){
    string question;

    while (low <= high){
        int mid = (low + high) / 2;
        cout << "Is your number " << mid << "?[y/n]\n";
        cin >> question;
        
        if (question == "y"){
            cout << "Looks like " << mid << " was the number after all.\n";
            return;
        }
        else{
            cout << "Is your number larger than " << mid << "? [y/n]\n";
            cin >> question;
            if (question == "y")
                low = (mid + 1);
            else
                high = (mid - 1);
        }
        
        
    }

    // If not found.
    int num;
    cout << "I give up. Please tell me the number.";
    cin >> num;
    
    if (num == input)
        cout << "Thanks.\n";
    else if ((1 <= num && num <= SIZE))
        cout << "I don't think that's the right number, but okay.\n";
    else
        cout << "Liar. That number's outside the range.\n";
}
