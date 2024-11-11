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
	
	return i;
	
}


int main(){
	return 0;
}