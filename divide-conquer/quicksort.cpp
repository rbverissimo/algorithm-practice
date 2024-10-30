#include <stdio.h>

// in place
// big O (n log n) but a poor choice of pivot can get it down to big O(n²)
// not stable
// tends to be faster than others O(n log n) algorithms

void swap(int* a, int *b){  //* dereferences the value of the variable stored by the pointer value
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	
	int p = arr[low]; // pivot
	int i = low;
	int j = high;
	
	
	while(i < j){
		
		while(arr[i] <= p && i <= high - 1) i++;
		while(arr[j] > p && j >= low + 1) j--;	
		if(i < j) swap(&arr[i], &arr[j]);
	}
	swap(&arr[low], &arr[j]); //& passes the value of the address
	return j;
}


void quicksort(int arr[], int low, int high){
	
	if(low < high){
		
		int pi = partition(arr, low, high); 	
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);	
	}
}

int main(){
	
	int arr[] = { 24, 30, 10, 4, 11, 11, 91, 88, 98, 99, 100, 101, 23, 21, 91};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	quicksort(arr, 0, n - 1);
	
	for(int i = 0; i < n; i++) printf("%d ", arr[i]);
	
	return 0;
}