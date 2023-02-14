#include "../std_lib_facilities.h"

/*
 * -----------------------------------------------------------------------------
 * Created by ulysses on 08/16/2019
 * 
 * Program 06_10
 * 
 * Problem Specifications:
 * Design a program that asks users for two numbers, asks them whether
 * they want to calculate permutations or combinations, and prints out the
 * result. This will have several parts. Do an analysis of the above require-
 * ments. Write exactly what the program will have to do. Then, go into
 * the design phase. Write pseudo code for the program, and break it into
 * sub-components. This program should have error checking. Make sure
 * that all erroneous inputs will generate good error messages.

 * -----------------------------------------------------------------------------
 */

long factorial(int val){ // Recursive for the hell of it
	if (val < 0){
		string temp = "" + val;
		error("Error: Negative Factorial (" + temp + ")");
	}
	else if (val == 0)
		return 1;
	else return val * factorial(val - 1);
}

double permutation(int a, int b){
	double val = (factorial(a) / factorial(a - b));
	return val;
}

double combination(int a, int b){
	double val = (permutation(a, b) / factorial(b));
	return val;
}	

void Instructions(void){
	cout << "To use a permutation, enter 'p', while to"
	     << " use a combination, enter 'c'.\n"
	     << "To exit, enter 'q'.\n";
	
}		

int main(void){
	int a, b;
	cout << "Please input two non-negative numbers:";
	cin >> a >> b;
	
	if (a < 0 || b < 0)
		error("Non-negative number detected.");
	
	Instructions();
	char input;
	cin >> input;

	switch(input){
	case 'p':
		cout << "Permutation value: " << permutation(a, b)
		     << "\n";
		break;
	case 'c':
		cout << "Combination value: " << combination(a, b)
		     << "\n";
		break;
	case 'q':
		break;
	default:
		cout << "Invalid input. This program will"
		     << " now close.\n";
		break;
	}
		
	return 0;
}	
