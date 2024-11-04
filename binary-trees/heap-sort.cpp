#include <stdio.h>


// max heap
void heapify(int arr[], int n, int i){
	
	int max = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if(l < n && arr[l] > arr[max]) max = l;
	
	if(r < n && arr[n] > arr[max]) max = r;
	
	if(max != i){
		int temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
		heapify(arr, n, max);
	}
}

void heap_sort(int arr[], int n){
	
	for(int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
	
	for(int i = n - 1; i > 0; i--){
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
	
		heapify(arr, i, 0);
	}
	
	
}

void print_array(int arr[], int n){
	
	for(int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
	
}

int main(){
	
	int arr[] = {9, 4, 3, 8, 10, 2, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	heap_sort(arr, n);
	
	printf("Sorted array: ");
	print_array(arr, n);
	
	return 0;
}