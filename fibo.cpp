#include<stdio.h>



void print_message(const char *message) {
    printf("%s\n", message);
}

int fibonacci(int n){
	
	
	int f[n + 1];
	f[0] = 0;
	f[1] = 1;
	
	for(int i = 1; i < n + 1; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	
	return f[n];
	
}


int main(){
	
	int fibo = fibonacci(5);
	printf("%d\n", *fibo);
	print_message("Success!");
	
	
	return 0;
}