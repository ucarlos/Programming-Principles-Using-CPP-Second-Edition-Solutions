#include "./std_lib_facilities.h"
/*
 * Purpose: Program illustates what happens when unhandled 
 * exception occurs.
 *
 * In this case, a out_of_range exception occurs in the print list function
 * (the i <= list.size() comparison)
 *
 * If compiled, you should see this error at runtime. 
 */



void print_list(vector<int> list){
    for (int i = 0; i <= list.size(); i++)
        cout << "list[" << i << "]:\t" << list[i] << "\n";
    

}
int main(void){
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//    int num {12.12};
    
    print_list(list);

    return 0;
}    
