#include "./std_lib_facilities.h"

int main (void){
    string censored = "Nope";

    vector<string> list;
    cout << "Please enter a string (Enter exit to stop):";
    for (string temp; cin >> temp && temp != "exit";){
       
        if (temp != censored){
            list.push_back(temp);
            cout << "Entered Word: " << temp << "\n";
        }
        else cout << "[Redacted]\n";
        
    }

    return 0;
}
