#include<stdio.h>

//Merge Sort
//Best Case and Worst Case: O = n. log(n); 
//divides array in the halves and keep doing so until each element of the array is sorted by default (arrays of one element); 
//highly parallelizable; 

void mergeSort(int a[], int length);
void mergeSortRecursion(int a[], int l, int r); //the purpose of this function is the break the arrays in halves, l stands for left and r for right; 
// void mergeSortedArrays 

int main() {
	
	int array[] = {2, 4, 0, 1, 7, 8, 3, 9, 5, 6}; 
	int length = 10; //for the sake of simplicity; 
	
	mergeSort(array, length); 
	
	return 0; 
}

void mergeSort(int a[], int length) {
	
	mergeSortRecursion(a, 0, length - 1); //this line is passing the full og array for the beginning of the sorting processs; 
	
}

void mergeSortRecursion(int a[], int l, int r){ //again takes the left-most and right most index and haves; 
	
	int m = l + (r - l) / 2; //finding the middle = the left most index + the righ-most - the left-most defines the total length of the array / 2 = the middle; 
	 
}
