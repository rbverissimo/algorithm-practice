#include "bits/stdc++.h"
using namespace std;


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int arr[], int l, int r){
	
	int last = arr[r], i = l, j = l;
	while(j < r){
		if(arr[j] < last){
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[r]);
	return i;
	
}

int randomPartition(int arr[], int l, int r){
	
	int n = r - l + 1; 
	int pivot = rand() % n;
	swap(&arr[l + pivot], &arr[r]);
	return Partition(arr, l, r);
}


int main(){
	
	
	int arr[] = {12, 13, 14};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	
	return 0;
}