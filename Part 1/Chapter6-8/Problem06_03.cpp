#include "../std_lib_facilities.h"

/* ------------------------------------------------------------------------------
   Created by ulysses on 08/15/2019
   
   Problem06_03:

   Add a factorial operator: use a suffix ! operator to represent “factorial.”
   For example, the expression 7! means 7 * 6 * 5 * 4 * 3 * 2 * 1 . Make ! bind
   tighter than * and / ; that is, 7*8! means 7*(8!) rather than (7*8)! . Begin by
   modifying the grammar to account for a higher-level operator. To agree
   with the standard mathematical definition of factorial, let 0! evaluate to 1 .
   Hint: The calculator functions deal with double s, but factorial is defined
   only for int s, so just for x! , assign the x to an int and calculate the
   factorial of that int .

 *  
 */

/* ------------------------------------------------------------------------------
 * Grammar Rules:
 * Modifications: Added Factorial to <expression>

       <expression> = <term> + <expression>
	            = <term> - <expression>
	            = <term>
		    = <factorial>
		    
       <factorial> = <expression>!	    

       <term> = <primary>
              = <term> * <primary>
	      = <term> / <primary>

       <primary> = <number>
	         = (<expression>)

       <number> = <float_literal> 

*/

/* ------------------------------------------------------------------------------
 * Added Code:
	    case '!': { 
            int left_int = (int) left;
            left = calculate_fact(left_int);
            t = ts.get();
            break;
*/

void version(){
    puts("Problem6_03: Added Factorials (!) .");
}

//------------------------------------------------------------------------------
// Added Factorial Function:

long calculate_fact(int value){
	if (value < 0)
		error("Negative value for factorial detected. Exiting.");
	if (value == 0)
		return 1;

	long result = 1;
	for (int i = 1; i <= value; i++)
		result *= i;

	return result;
}

// Fixed missing 'c'
class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get() // added Token_stream 
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    } 

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':    // for "print"
    case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
    case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9': // Added case '8' 
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected"); // Missing "
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
	    break;
        case '/':
            {    
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
  double left = term();      // read and evaluate a Term -- Also fixed function call:
    Token t = ts.get();        // get the next token from token stream

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract, also changed += to -=
            t = ts.get();
            break;
	case '!': { // For factorials, get int of number, and compute factorial.
            int left_int = (int) left;
            left = calculate_fact(left_int);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------
void greeting(){
  puts("Welcome to our simple calculator.");
  puts("Please enter expressions using floating-point numbers.");
  puts("To finish an expression, add an ';' to the end. To quit, input 'q'.");
  puts("Any bizarre input will cause an error.");

}  
int main()

try
{
  greeting();
  version();
  double val = 0; // Added double val here:
  while (cin) {

        Token t = ts.get();

	
        if (t.kind == 'q')
	  break; // 'q' for quit
        if (t.kind == ';')        // ';' for "print now"
            cout << "= " << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
	keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
	keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
	keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------


