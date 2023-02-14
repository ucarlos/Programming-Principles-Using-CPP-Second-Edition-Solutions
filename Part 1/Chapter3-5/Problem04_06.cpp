#include "./std_lib_facilities.h"
#include <cctype>


// Function Declarations:
string to_lower_string(string input){
    string temp = "";
    for (unsigned i = 0; i < input.size(); i++)
        temp += tolower(input[i]);

}

int check_list(vector<string> list, string input){
    int index = -1;

    for (int i = 0; i < list.size(); i++){
        if (list[i] == input){
            index = i;
            break;
        }
    }

    return index;
    
}    
int main(void){
    vector<string> name_list = {"zero","one", "two", "three", "four",
                                "five", "six", "seven", "eight", "nine"};
    
    int user_input;
    cout << "Enter a number (0 - 9). To exit, enter a number outside"
         << " that range.\n";
    
    
    for (; cin >> user_input && !(0 <= user_input && user_input <= 9);){
        cout << "Invalid number. Please enter a number "
             << "in the range (0 - 9)\n";
        
    }
    
    cout << user_input << " is represented as "
         << name_list[user_input] << "\n";

    string string_input;
    cout << "Next, please spell out a number (such as zero for 0)\n";
    cin >> string_input;

    //Make sure string is lowercase:
    string_input = to_lower_string(string_input);

    // Now check:
    int result = check_list(name_list, string_input);
    cout << string_input << " ";

    if (result != 1)
        cout << "is represented as " << result << "\n";
    else cout << "is not a number in the range (0 - 9)\n";

    
    


    

}   
