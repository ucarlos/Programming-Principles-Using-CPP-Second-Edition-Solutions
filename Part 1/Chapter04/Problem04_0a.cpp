#include "./std_lib_facilities.h"
#include <cctype>
int main(void){
	constexpr double yen_ex_rate = 108.05;
	constexpr double euro_ex_rate = 0.89;
	constexpr double pounds_ex_rate = 0.80;
	
	cout << "Please enter the number of U.S Dollars followed by a unit.\n";
	cout << "The units are as follows:\ny(Yen)\te(Euros)\tp(Pounds Sterling)\n";
	
	double dollars;
	char input;
	cin >> dollars >> input;
	//Convert input to lowercase:
	input = tolower(input);
	double convert;
	// Clear Screen:
	system("clear");
	switch(input){
	case 'y':
		convert = yen_ex_rate * dollars;
		printf("$%.2f dollars is the same as \u00A5%.2f yen.\n",
		       dollars, convert);
		break;
	case 'e':
		convert = euro_ex_rate * dollars;
		printf("$%.2f dollars is the same as \u20AC%.2f euros.\n",
		       dollars, convert);
		break;
	case 'p':
		convert = pounds_ex_rate * dollars;
		printf("$%.2f dollars is the same as \u00A3%.2f pounds.\n",
		       dollars, convert);
		break;
	default:
		cout << "Error: " << input << " is not recognized. Abort.\n";
	}

	return 0;
		
	

}	
