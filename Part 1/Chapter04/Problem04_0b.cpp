#include "./std_lib_facilities.h"
#define ALPHABET (26)
#define CHAR_LIMIT (80)
constexpr char lineseq = '-';
void print_line(void){
	for (int i = 0; i < CHAR_LIMIT; i++)
		cout << lineseq;
	cout << "\n";

}

int main(void){
	char begin_lower = 'a';
	char begin_upper = 'A';

	print_line();
	cout << "\tLowercase\t\tUppercase\n";
	print_line();
	
	for (int i = 0; i < ALPHABET; i++){
		cout << "\t";
		cout << (char)begin_lower << "\t" << (int)begin_lower++ << "\t\t";
		cout << (char)begin_upper << "\t" << (int)begin_upper++ << "\n";
	}
	print_line();
	return 0;
	
		

}
