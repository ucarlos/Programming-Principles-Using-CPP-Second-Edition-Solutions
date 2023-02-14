#include "./std_lib_facilities.h"
// Program Usage:
// Quadratic Formula (AGAIN)


#define DISCRIMINANT(a, b, c) ((b) * (b) - 4 * (a) * (c))

int main(void){
	cout << "Please enter the a, b, and c value for the quadratic"
	     << " formula.";

	double a, b, c;
	cin >> a >> b >> c;
	double check = DISCRIMINANT(a, b, c);

	if (check < 0)
		error("Error: The solutions to this quadratic are non-real. Aborting.");

	double pos_solution = (-b + sqrt(DISCRIMINANT(a, b, c))) / (2 * a);
	double neg_solution = (-b - sqrt(DISCRIMINANT(a, b, c))) / (2 * a);

	cout << "Solution 1: " << pos_solution << "\n";
	cout << "Solution 2: " << neg_solution << "\n";

	return 0;
	
}	
