#include "../std_lib_facilities.h"
/* ------------------------------------------------------------------------------
 * Created by Ulysses on 08/15/2019
 *
 * Problem 06_04:
                Define a class Name_value that holds a string and a value.
		Rework Exercise 19 in Chapter 4 to use a vector<Name_value>
		instead of two vector s.

 */

//------------------------------------------------------------------------------
// Class: Name_value
class Name_value{
public:
	string name {"NoName"};
	int value {0};

};

int search_list(vector<Name_value> list, Name_value search){
	for (int i = 0; i < list.size(); i++)
		if (list[i].name == search.name && list[i].value == search.value)
			return i;
	return -1;
}


Name_value create(){
	Name_value temp;
	string name;
	int value;
	cin >> name >> value;
	temp = {name, value};

	return temp;
}


//------------------------------------------------------------------------------

int main(void){
	vector<Name_value> list;
	Name_value temp;

	puts("Please enter a name alongside a value (Such as Joe 17)");
	puts("To quit, enter \"NoName\" 0 ");

    temp = create();
    bool is_valid = !(temp.name == "NoName" && temp.value == 0);

    while (is_valid){
        if (list.empty()){
            list.push_back(temp);
            cout << "\t" << temp.name << " " << temp.value << "\n";
            continue;
        }
        temp = create();

        is_valid = !(temp.name == "NoName" && temp.value == 0);
        if (!is_valid)
            continue;

        int test = search_list(list, temp);

        if (test != -1 && (list.size()))
        cout << "\t" << temp.name << " " << temp.value
             << " is already in the list.\n";
        else{
            list.push_back(temp);
            cout << "\t" << temp.name << " " << temp.value << "\n";

        }

    }
}

    
