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
	
	mergeSortRecursion(a, l, m); //passing the array the left-most until the middle of the array; 
	mergeSortRecursion(a, m + 1, r); //passing from the middle + 1 index unil the right-most;  
}


void mergeSortedArrays(int a[], int l, int m, int r){
	
	int left_length = m - l + 1; //because of 0 index it should add +1 to count the correct length; 
	int right_length = r - m; //the right length is all the array - 1 index (which will be sorted by default) - the middle index legth; 
	
	//storing the subarrays into temporary arrays based on the length acquired by the last step: 
	
	int temp_left[left_length]; 
	int temp_right[right_length];
	
	//from here on: we will trasverse the og array using for loops in order to fill the temporary arrays with our halves of og array; 
	
	int i, j, k; //to control the for loops 
	
	for(int i = 0; i < left_length; i++)
		temp_left[i] = a[l + i]; //each index of a starting in the left side + the index of the loop will be passed to the temp_left array;
		//this means we are basically copying the og array to the temp_left until it fills accordingly to the length calculated in the beginning of the method; 
	
	for(int i = 0; i < right_length; i ++)
		temp_right[i] = a[m + 1 + i]; //in this line we doing basically the same in the right portion but starting from the middle + 1; 
	
	
}
