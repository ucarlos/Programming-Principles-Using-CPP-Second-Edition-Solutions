#include "std_lib_facilities.h"
/*
  Write a program that converts from Celsius to Fahrenheit and from 
  Fahrenheit to Celsius (formula in §4.3.3). 
  Use estimation (§5.8) to see if your results are plausible.
*/

constexpr double multiply_const= (9.0/5);
constexpr double temp_const = 32;
const string degree = "\u00b0";

double ftoc(double fah){
	double result;
	result = (1.0 / multiply_const) * (fah - temp_const);
	return result;
}

double ctof(double celsius){
	double result;
	result = multiply_const * celsius + temp_const;
	return result;
	
}

int main(void){
	puts("If you want to covert Fahrenheit to Celsius, enter the number '1'.");
	puts("If you want to convert Celsius to Fahrenheit, enter the number '2'.");
	puts("Any other number will close the program.");

	int input;
	double temp, result;
	cin >> input;
	
	if (!(input == 1 || input == 2))
		error("Invalid number. This program will close.");
	
	cout << "Now please enter the temperature.";
	cin >> temp;
	result = (input == 1)? ftoc(temp) : ctof(temp);		

	if (input == 1)
		cout << temp << degree << "F is equal to " << result << degree
		     << "C" << "\n";
	else
		cout << temp << degree << "C is equal to " << result << degree
		     << "F\n";

	return 0;

}
