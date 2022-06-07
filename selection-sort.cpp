#include <stdio.h>

//Selection Sort;
//Best Case: O = (n²); Worst Case = 0 = (n²); because it will always run the whole array in order to sort it out; 
//Array gets divided into two portions = one the left side things are always sorted, on the right side: always unsorted;  

int main () {
	
	int a[] = {9, 3, 2, 1, 0, 4, 6, 7, 5};
	int lenght = 10; //hard coded lenght of the array for the sake of simplicity 
	
	//the first step of the selection sort is to assume that the index we are looking at at any given time is the lowest possible in the sequence
	
	for(int i = 0; i < lenght - 1; i++){ //lenght - 1 because the last element of the array will sort itself through the process; 
		
		int min = i; //meaning that the index we are iterating over will be handing on the minimum possible value; 
		for(int j = i + 1; j < lenght; j++){
			if(a[j] < a[min]) { //condition to check if the minimum index is actually the minimum in the unsorted portion
				min = j;
			}
			
			if(min != i) { //condition to check if a swap is necessary; 
				int temp = a[i];
				a[i] = a[min];
				a[min] = temp;  
				
			}
			
			
		}
		printf("\na[%d] = %d", i, a[i]); 
	}
	
	return 0; 
}
