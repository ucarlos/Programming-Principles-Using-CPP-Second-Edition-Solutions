
//-----------------------------------------------------------------------------
// Created by ulysses on 8/9/19.
//
//-----------------------------------------------------------------------------


#include "../std_lib_facilities.h"

int main(void){
	// Oh god, what have I wrought?
	cout << "Please enter an expression (We can handle + and -):";
	int lval = 0;
	int rval;
	char op;
	int res;
	cin >> lval >> op >> rval;

	if (op == '+')
		res = lval + rval;
	else if (op == '-')
		res = lval - rval;

	cout << "Result: " << res << "\n";
	keep_window_open();
	return 0;

}
