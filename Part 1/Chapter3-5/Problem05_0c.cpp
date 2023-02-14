#include "./std_lib_facilities.h"

int main(void){
    const string unit = "\u00B0F";
    vector<double> temp_list;

    puts("Please enter a number. To stop, enter something nonnumerical.");
    
    for (double temp; cin >> temp;)
        temp_list.push_back(temp);

    // Set default high and low temperatures:
    double sum = 0;
    double low_temp, high_temp;
    
    low_temp = high_temp = temp_list[0];

    for (double e : temp_list){
        low_temp = (e < low_temp) ? e : low_temp;
        high_temp = (e > high_temp) ? e : high_temp;
        sum += e;
    }

    // Print output:
    cout << "Low Temperature: " << low_temp << unit <<  "\n";
    cout << "High Temperature: " << high_temp << unit << "\n";
    cout << "Average Temperature: " <<
        (sum / temp_list.size()) << unit << "\n";

    return 0;
}    
