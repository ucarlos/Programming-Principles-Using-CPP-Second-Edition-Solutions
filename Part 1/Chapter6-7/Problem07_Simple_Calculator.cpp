#include "../std_lib_facilities.h"

/* -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 08/21/2019  
 *
 * Problem07_Simple Calculator.cpp
 * This is an implementation of the simple calculator program found in 
 * Chapter 7 of Bjarne Stroustrup's Principles and Practice Using C++ (2nd Ed.)
 * 
 * Information:
	As you might already know, Calc_03_Base.cpp is a older implementation
	of the Calcultor program in Pricniples and Practice. This version
	implements the code found in the 2nd edition so that you're able
	to answer some of the exercises found in the chapter.
 *
 *
 * -----------------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
// Constants

// Char Constants:
const char prompt = '>';
const char let = 'L';
const char quit = 'q';
const char result = '=';
const char print = ';';
const char number = '8';
const char name = 'a';
const char user_func = 'F';

// String Constants:
const string empty = "";
const string declkey = "let";
const string str_quit = empty + quit;
const string str_name = empty + name;

//------------------------------------------------------------------------------   
// Token Class
class Token{
    public:
    char kind;
    double value;
    string name;
    Token(char ch) : kind(ch), value(0) {}
    Token(char ch, double val) : kind(ch), value(val) { }
    Token(char ch, string n): kind{ch}, name{n} {}
};


//------------------------------------------------------------------------------
// Token_stream Class
class Token_stream{
    public:
    Token_stream() : full{false}, buffer(0) {}
    Token get();
    void putback(Token t);
    void ignore(char c);
    private:
    bool full;
    Token buffer;
};


Token Token_stream::get(){
    if (full){
	full = false;
	return buffer;
    }

    char ch;
    cin >> ch;
    switch (ch){
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
	    {
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	    }
    default:
	if (isalpha(ch)){
	    string s;
	    s += ch;
	    while (cin.get(ch) && (isalpha(ch) || isdigit(ch)
				   || ch == '_'))
		s+=ch;

	    cin.putback(ch);
	    if (s == str_quit) return Token{quit};
	    if (s == declkey) return Token{let};
	    if (s == str_name) return Token{name};
	    
	    return Token(name, s);
	}
	error("Bad Token Detected");

    }
}

void Token_stream::putback(Token t){
    if (full)
	error("Cannot call putback() into a full buffer.");
    buffer = t;
    full = true;
}

void Token_stream::ignore(char c){
    if (full && c == buffer.kind){
	full = false;
	return;
    }
    
    full = false;

    char ch;
    while (cin >> ch)
	if (ch == c) return;
    
}

Token_stream ts;
//------------------------------------------------------------------------------
// Variable Class
class Variable{
    public:
    string name;
    double value;
    Variable(string n, double v);
};

Variable::Variable(string n, double v){
    this->name = n;
    this->value = v;
}    

// Vector
vector<Variable> var_table;

double get_value(string s){
    for (const Variable&v : var_table)
	if (v.name == s) return v.value;

    //Otherwise
    error("get_value(): Undefined Variable ", s);
}

void set_value(string s, double d){
    for (Variable&v : var_table)
	if (v.name == s){
	    v.value = d;
	    return;
	}
    error("set_value(): Undefined Variable ", s);
}

bool is_declared(string s){
    for (const Variable&v : var_table)
	if (v.name == s)
	    return true;

    return false; // If not found;

}    
//------------------------------------------------------------------------------
// Grammar Definitions/ Prototypes:
void calculate(void);
double expression(void);
double primary(void);
double term(void);
double statement(void);
//------------------------------------------------------------------------------
// Grammar Implementation


double term(void){
    double left = primary();
    while (true){
	Token t = ts.get();
	switch (t.kind){
	case '*':
	    left *= primary();
	    break;
	case '/':{
	    double d = primary();
	    if (d == 0)
		error("Division by Zero Detected.");
	    left  /= d;
	    break;
	}
	case '%':{
	    double d = primary();
	    if (d == 0)
		error("Division by Zero Detected.");
	    left = fmod(left, d);
	    break;
	}
	default:
	    ts.putback(t);
	    return left;
	}
    }

}

double expression(void){
    double left = term();
    while (true){
	Token t = ts.get();
	switch (t.kind){
	case '+':
	    left += term();
	    break;
	case '-':
	    left -= term();
	    break;
	default:
	    ts.putback(t);
	    return left;
	}
    }

}

double declaration(void){
    Token t = ts.get();
    if (t.kind != name)
	error ("Name Expected in Declaration.");

    string name = t.name;
    bool check_declared = is_declared(name);
    if (check_declared)
	error (name, " is already declared.");

    Token t2 = ts.get();
    if (t2.kind != '=')
	error("= Missing in Declaration of ", name);
    double d = expression();
    var_table.push_back(Variable(name, d));
    return d;

}

double primary(void){
    Token t = ts.get();
    switch (t.kind){
    case '(':{
	double d = expression();
	t = ts.get();
	if (t.kind != ')')
	    error ("')' Expected");
	return d;
    }
    case number:
	return t.value;
    case name:
	return get_value(t.name); 
    case '-':
	return -primary();
    case '+':
	return primary();
    default:
	error("Primary Expected.");
    }
}    


double statement(){
    Token t = ts.get();
    switch (t.kind){
    case let:
	return declaration();
    default:
	ts.putback(t);
	return expression();
    }
}    


void clean_up_mess(){
    ts.ignore(print);
}
void calculate(){
    while (cin){
	try{
	    cout << prompt << " ";
	    Token t = ts.get();
	    while (t.kind == print)
		t = ts.get();

	    if (t.kind == quit) return;
	    ts.putback(t);
	    cout << result << " " << statement() << "\n";
	}
	catch (exception& e){
	    cerr << e.what() << "\n";
	    clean_up_mess();
	}
    }
}


int main(){
    try{
	calculate();

	keep_window_open();
	return 0;
    }
    catch (exception& e){
	cerr << e.what() << "\n";
	keep_window_open("~~");
	return 1;
    }
    catch (...){
	cerr << "Exception\n";
	keep_window_open("~~");
	return 2;
    }

}
