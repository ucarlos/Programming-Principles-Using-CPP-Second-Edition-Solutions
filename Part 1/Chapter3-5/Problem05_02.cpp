#include "std_lib_facilities.h"
// Incorrect funtion:
/*
double ctok(double c){
    int k = c + 273.15;
    return int
 */

// Correct:

double ctok(double c){
	constexpr double kelvin = 273.15;
	double k = c + kelvin;
	return k;
}



// Incorrect function:
/*
  int main(void){
      double c = 0;
      cin >> d;
      double k = ctok("c");
      Cout << k << "\n";

 */

int main(void){
	double c = 0;
	cin >> c;
	double k = ctok(c);

	cout << k << "\n";
	return 0;
	

}
