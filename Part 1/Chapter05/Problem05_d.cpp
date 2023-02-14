#include "./std_lib_facilities.h"

int main(void){
	try{
		int res = 7;
		vector<int> v(10);
		v[5] = res;
		cout << "Success!\n";
		keep_window_open();
		return 0;
		
	}
	catch (exception& e){
		cerr << "Error:" << e.what() << "\n";
		keep_window_open();
		return 1;
	}
	catch(...){
		cerr << "Unknown Exception has occurred.\n";
		keep_window_open();
		return 2;
	}
	
       

}	
