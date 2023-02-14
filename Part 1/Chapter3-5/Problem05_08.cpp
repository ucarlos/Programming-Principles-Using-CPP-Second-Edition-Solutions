#include "./std_lib_facilities.h"

void print_list(vector<int> list, int endpoint){
	for (int i = 0; i < endpoint; i++){
		if ((i + 1) != endpoint)
			cout << list[i] << " ";
		else
			cout << list[i];
	}

}

int main(void){
	vector<int> list;
	int val, input;
	int sum = 0;

	puts("Enter the number of values you want to sum:");
	cin >> val;

	puts("Please enter some integers (press '|' to stop):");
	for (int i = 0; (cin >> input && (i < val)); i++){
		list.push_back(input);
		sum += input;
	}

	cout << "The sum of the first " << val << " numbers ";
	cout <<"(";
	print_list(list, val);
	cout << ") is " << sum << ".\n";
}	
