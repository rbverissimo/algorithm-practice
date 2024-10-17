#include<stdio.h>


int recursiveIteration(int arr[], int idx){
	printf("%d\n", arr[idx]);
	if(idx == 0) return 0;
	return recursiveIteration(arr, idx - 1);
}


int main(void){
	
	
	int arr[] = {1, 2, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	printf("Iterative mode using a for loop: ");
	for(int i = 0; i < size; i++ ){
		printf("%d\n", arr[i]);
	}
	
	printf("Recursive mode using a function: ");
	recursiveIteration(arr, size - 1);
	
	return 0;
}