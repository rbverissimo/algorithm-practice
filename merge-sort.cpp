#include<stdio.h>

//Merge Sort
//Best Case and Worst Case: O = n. log(n); 
//divides array in the halves and keep doing so until each element of the array is sorted by default (arrays of one element); 
//highly parallelizable; 

void mergeSort(int a[], int l, int r); 
void merge(int a[], int l, int m, int r);

int main() {
	
	int array[] = {1, 7, 10, 11, 3, 6, 5}; 
	int length = sizeof(array) / sizeof(array[0]); 
	
	mergeSort(array, 0, length - 1); 
	
	for(int i = 0; i < length; i++) printf("%d ", array[i]);
	
	return 0; 
}

void mergeSort(int a[], int l, int r){ 

	if(l < r){
		int m = l + (r - l) / 2; 
		 
		mergeSort(a, l, m); 
		mergeSort(a, m + 1, r); 
		
		merge(a, l, m, r);
	}
}


void merge(int a[], int l, int m, int r){
	
	int i, j, k;  
	int n1 = m - l + 1;  
	int n2 = r - m;  
	
	int temp_left[n1]; 
	int temp_right[n2]; 
	
	
	for(i = 0; i < n1; i++) temp_left[i] = a[l + i]; 
	
	for(j = 0; j < n2; j++) temp_right[j] = a[m + 1 + j]; 
		
	i = 0;
	j = 0;
	k = l;
	
	while(i < n1 && j < n2){
		
		if(temp_left[i] <= temp_right[j]){
			a[k] = temp_left[i];
			i++;
		} else {
			a[k] = temp_right[j];
			j++;
		}
		k++;	
	}
	
	while(i < n1){
		a[k] = temp_left[i];
		i++;
		k++;
	}
	
	while(j < n2){
		a[k] = temp_right[j];
		j++;
		k++;	
	}
	
	
	
	
	
}
