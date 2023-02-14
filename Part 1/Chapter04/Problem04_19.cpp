#include "std_lib_facilities.h"

int search_list(vector<string> list, string find){
    for (int i = 0; i < list.size(); i++)
	if (list[i] == find)
	    return i;

    return -1; // Not found:
    
    
}



void input_list(vector<string> list, vector<int> num_list, string str, int num){
    list.push_back(str);
    num_list.push_back(num);
}

int main(void){
	string name;
	int value;
	vector<string> str_list;
	vector<int> num_list;
	int check_str, check_num;
	
	cout << "Please enter a name alongside a value (Such as Joe 17)\n";
	cout << "To stop, enter 'NoName' 0\n";
	
	do{
	    cin >> name >> value;
	    if (str_list.size() == 0 && num_list.size() == 0){
		input_list(str_list, num_list, name, value);
		continue;
	    }

	    check_str = search_list(str_list, name);

	    if (check_str == -1){
		input_list(str_list, num_list, name, value);
		cout << "\t" << name << "\t" << value << "\n";
	    }
	    else
		cout << "\t" << name << " is already in the list.\n";
	    // Check for duplicates:
	    
	}while(name != "NoName" && value != 0);

	return 0;
}	
