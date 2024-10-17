#include <stdio.h>



int binarySearch(int arr[], int left, int right, int key){
	
	if(right >= left){
		
		int mid = left + (right - left) / 2;
		
		if(arr[mid] == key) return mid;
		
		if(arr[mid] > key){
			return binarySearch(arr, left, mid - 1, key);
		}
		
		return binarySearch(arr, mid + 1, right, key);
		
	}
	
	return -1; 
}


int main(void){
	
	int arr[] = {4, 11, 17, 23, 31, 41, 42, 43, 47};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	int key = 47;
	
	int index = binarySearch(arr, 0, size - 1, key);
	if(index == -1){
		printf("The key isn't present in the array. \n");
	} else {
		printf("Key found at index: %d\n", index);
	}
	
	return 0;
}