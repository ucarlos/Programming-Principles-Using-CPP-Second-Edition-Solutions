#include "./std_lib_facilities.h"

#define SIZE (20)
int main(void){
    vector<int> list;

    for (int i = 0; i < SIZE; i++)
        list.push_back(i);

    for (int i : list)
        cout << i << "\n";
    
    return 0;

}    
