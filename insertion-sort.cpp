#include <stdio.h>

//Insertion Sort
// Best Case: O = n  Worst Case: O = (n²);
// Really useful for small amount of data; 

void insertionSort (int a[], int length); 

int main(){
	
	int a[] = {8, 5, 4, 2, 1, 3, 6, 7, 0, 9};
	insertionSort(a, 10); 
	
	for(int i = 0; i < 10; i++){
		printf("a[%d] = %d\n", i, a[i]); 
	};
	
	
	return 0; 
} 

void insertionSort(int a[], int length){
	
	for(int i = 1; i < length; i++){ //outer loop gonna go thru every element of the array starting by the index 1, because the first index will be sorted anyway;
		int key = a[i];  //key will receive the value of the current element; 5 in our example at the very start; 
		int j = i - 1;
		while(j >= 0 && a[j] > key) { //it means that the value before the current index must be bigger than the value of the current index in order to start the loop;
			a[j + 1] = a[j]; //this line does the swap of the elements of the array;
			j = j - 1; 
		}
		a[j + 1] = key;
	}
	
	
}
