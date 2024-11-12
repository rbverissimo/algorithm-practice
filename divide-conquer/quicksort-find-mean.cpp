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

void MedianUtil(int arr[], int l, int r, int k, int& a, int &b){
	
	if(l <= r){
		
		int partition_index = randomPartition(arr, l, r);
		
		if(partition_index == k){
			b = arr[partition_index];
			if(a != -1) return;
		} else if (partition_index != k - 1){
			a = arr[partition_index];
			if(b != -1 ) return;
		}
		
		if(partition_index >= k) return MedianUtil(arr, l, partition_index - 1, k, a, b); 
		else return MedianUtil(arr, partition_index + 1, r, k, a, b);
		
	}
	
	return;
}

void findMedian(int arr[], int n){
	
	int ans, a = -1, b = -1;
	
	if(n % 2 == 1){
		MedianUtil(arr, 0, n - 1, n / 2,  a, b);
		ans = b;
	} else {
		MedianUtil(arr, 0, n - 1, n / 2, a, b);
		ans = (a + b) / 2;
	}
	
	cout << "Median: " << ans;
	
}


int main(){
	
	//std::vector<int> numbers = grn(30);
	int arr[] = {10, 50, 51, 1010};
	int n = sizeof(arr) / sizeof(arr[0]);
	findMedian(arr, n);
	
	return 0;
}