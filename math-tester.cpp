#include<stdio.h>


int main(){
	
	int n = 10;
	int r = 20;
	
	int a = n + (r - n) / 2;
	
	// 10 + 5
	
	int b = (n  + (r - n)) / 2;
	
	// (10 + (20 - 10)) / 2   :: 20 / 2 = 10
	
	printf("Value of a: %d\n", a);
	printf("Value of b: %d\n", b);
	
	return 0;
}