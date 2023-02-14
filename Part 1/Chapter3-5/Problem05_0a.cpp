#include "./std_lib_facilities.h"
#define ABS(x) ((x < 0) ? -(x) : (x))

int area(int x, int y){
	return ((x < 0) || (y < 0)? -1 : (x * y));
}

int framed_area(int x, int y){
	constexpr int frame_size = 2;
	if (x <= frame_size || y <= frame_size)
		error("Non-positive area() argument called by framed_area()");
	return area(x - frame_size, y - frame_size);
}	

int f(int x, int y, int z){
	int area1, area2, area3;
	area1 = area2 = area3 = 0;
	area1 = area(x, y);
	
	if (area1 <= 0)
		error("Non-positive area.");
	area2 = framed_area(1, z);
	area3 = framed_area(y, z);
	
	double ratio = (double)(area1 / area3);
	
}

int main(void){

}
