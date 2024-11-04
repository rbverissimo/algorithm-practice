//naive, recursive and in-place

#include<stdio.h>


void naive_sort(int arr[], int n, int i){
	
	if(i > n) return;
	
	if(arr[i+1] < n && arr[i] < arr[i+1]){
		int temp = arr[i+1];
		arr[i+1] = arr[i];
		arr[i] = temp;
	}
	
	naive_sort(arr, n, i + 1);	
	
}

void print_array(int arr[], int n){
	
	for(int i = 0; i < n; i++) printf("%d ", arr[i]);
}

int main(){
	
	int arr[] = { 5, 2, 7, 1, 4, 11, 12 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	naive_sort(arr, n, 0);
	print_array(arr, n);
	
	
	return 0;
}