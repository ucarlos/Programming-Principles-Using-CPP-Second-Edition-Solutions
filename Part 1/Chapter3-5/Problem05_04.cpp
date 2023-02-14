#include "std_lib_facilities.h"


// Do exercise 3 again, but this time handle the error inside ctok()
constexpr double kelvin = 273.15;
double ctok(double c){
	if (c < -kelvin){
		error("Error: Temperature cannot be below absolute zero.");
	}

	double k = c + kelvin;
	return k;
}


double ktoc(double kel){
	if (kel < 0)
		error("Error: Kelvin cannot be negative.");
	double centigrade = kel - kelvin;
	return centigrade;

}

int main(void){
	double input;
	cin >> input;

	double result;
	

}
