#include "../std_lib_facilities.h"

/* -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 08/20/2019
 * 
 * Problem07_03.cpp
 * 	Provide named constants that you really can’t change the value of. 
 *      
 *      Hint:
	You have to add a member to Variable that distinguishes between con-
	stants and variables and check for it in set_value() . If you want to let
	the user define constants (rather than just having pi and e defined as
	constants), you’ll have to add a notation to let the user express that, for
	example, const pi = 3.14; .
 
 *
 * Solution:
 *         The solution is shown below:
 *
 * -----------------------------------------------------------------------------
 */


struct Token { // Why is Token a structure?
        char kind;
        double value;
        string name;
        Token(char ch) :kind(ch), value(0) { }
        Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string n): kind{ch}, name{n} {} // Added back this constructor?
    
};

//------------------------------------------------------------------------------
// User_function class

class User_function{
public:
  string name;
  User_function() :name("null") {}
  User_function(string name, int arg);
  int getarg_count();
  void setarg_count(int arg);
private:
  int arg_count{0};
  
};

User_function::User_function(string name, int arg){
  this->name = name;
  setarg_count(arg);
}  

void User_function::setarg_count(int arg) {
    arg_count = arg;
}

int User_function::getarg_count(){
	return arg_count;
}


vector<User_function>function_list;

//Allow usage
void initalize_function_list(){
  function_list.push_back(User_function("sqrt", 1));

}  
//------------------------------------------------------------------------------
// Token_Steam Class
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char user_func = 'F';
const char constant = 'C';

// String constants:
const string empty = "";
const string declkey = "let";
const string str_quit = empty + quit;
const string str_name = empty + name;
const string constkey = "const";

// Function constants:
//const string declfunction = "function";
const string function_sqrt = "sqrt";

Token Token_stream::get()
{
	if (full) { full=false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(number,val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch; // Fixed added '+' back to assignment
			cin.unget();
			if (s == str_quit) return Token(quit);
			if (s == declkey) return Token(let);
			if (s == function_sqrt) return Token(user_func);
			if (s == constkey) return Token(constant);
			if (s == str_name) return Token(name); // Replaced 'quit' with 'a' for name
			return Token(name,s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}


//------------------------------------------------------------------------------
// Variable class

struct Variable {
	string name;
	double value;
	bool isConstant{false};
	Variable(string n, double v) :name(n), value(v) { }
	Variable(string n, double v, bool isconst) :
		name(n), value(v), isConstant(isconst) { }
};

vector<Variable> names;	

double get_value(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
}

void set_value(string s, double d)
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			if (names[i].isConstant)
				error(s, " is a constant variable.");
			else
				names[i].value = d;
			
			return;
		}
	error("set: undefined name ",s);
}

bool is_declared(string s)
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

int find_variable(string s){
	int check = -1;
	for (int i = 0; i < names.size(); i++)
		if (names[i].name == s){
			check = i;
			break;
		}

	return check;
}
bool check_constant(string s){
	int search = find_variable(s);

	if (search == -1) // If not found
		error("Variable has not been defined.");
	else
		return (names[search].isConstant);
}

// Adding define_name
double define_name(string var, double val){
    if (is_declared(var))
	error(var, "Declared twice");
    
    names.push_back(Variable(var, val));
    return val;
}

//------------------------------------------------------------------------------
// Grammar Section of Problem

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		//t = ts.get(); // This should not be called twice, added deliberately.
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d; // Added this back to program
	}
	case '-':
		return - primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':{
		    double d = primary();
		    if (d == 0)
		        error ("Divide by zero");

		    left = fmod(left, d);
		   // t = ts.get(); // Causes issues
		    break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	bool isConstant = false;
	Token t = ts.get();
	if (t.kind == constant){
		isConstant = true;
		//Now do ts.get()
		t = ts.get();
	}		
	if (t.kind != name) error ("name expected in declaration");
	string tname = t.name;
	bool Declared = is_declared(tname);

	if (Declared){
		bool status = check_constant(tname);
		if (status)
			error(tname, " is a constant variable and cannot be reassigned.");
	}
	
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,tname);
	double d = expression();

	if (Declared)
        set_value(tname, d);
	else
	    names.push_back(Variable(tname,d, isConstant));

	return d;
}

double ufunction(){
  Token t = ts.get();
  // All I can guarantee is that ( is the first
  if (t.kind != '(')
    error("Improper function call for sqrt.");

  ts.unget(t);
  double d = expression();
  if (d < 0)
    error("Error: Contents of sqrt cannot be negative.");

  return sqrt(d);
}  

double statement()
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	case user_func:
	    return ufunction();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

void predefined_variables();

void predefined_variables(){
    define_name("kilo", 1000);

}

int main()
{
    predefined_variables();
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >>c&& c!=';') ;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
}
