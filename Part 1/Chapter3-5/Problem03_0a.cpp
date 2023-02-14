#include "./std_lib_facilities.h"

int main(void){
    int num;
    cout << "Please enter a floating-point number:";
    cin >> num;

    cout << "n       : " << num << "\n";
    cout << "n + 1   : " << num + 1 << "\n";
    cout << "3 * n   : " << 3 * num << "\n";
    cout << "n ^ 2   : " << num * num << "\n";
    cout << "n / 2   : " << num / 2 << "\n";
    cout << "n % 2   : " << num % 2 << "\n";
    cout << "sqrt(n) : " << sqrt((double)num) << "\n";

    return 0;
    
}    
