#include "./std_lib_facilities.h"
/*----------------------------------------------------------------------
 * Just an minor revision to Problem 5.08
 *
 */
void print_list(vector<double> list, int endpoint);

void print_list(vector<double> list, int endpoint){
	for (int i = 0; i < endpoint; i++){
		if ((i + 1) != endpoint)
			cout << list[i] << " ";
		else
			cout << list[i];
	}

}

int main(void){
	vector<double> list;
    vector<double> differences;
    
	int val;
    double input;
	double sum = 0;

	puts("Enter the number of values you want to sum:");
	cin >> val;

	puts("Please enter some numbers (press '|' to stop):");
	for (int i = 0; ((i < val)); i++){
        if (cin >> input){
            list.push_back(input);
            sum += input;
        }
        else
            error("Error: Invalid Input.\n");
	}
    
    // Now work with the differences vector:
    for (int i = 1; i < list.size(); i++){
        input = list[i] - list[i - 1];
        differences.push_back(input);
    } 

    system("clear");
	cout << "The sum of the first " << val << " numbers ";
	cout <<"(";
	print_list(list, val);
	cout << ") is " << sum << ".\n";

    cout << "Now, the differences table is as follows:\n";
    cout << "[";
    print_list(differences, differences.size());
    cout << "]\n";
}	
