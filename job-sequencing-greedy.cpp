#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
	char id;
	int dead;
	int profit;
} Job;


int min(int a, int b ){
	return (a < b) ? a : b;
}

// used in qsort, if negative a comes first, else reverse it
int compare(const void* a, const void* b)
{
	Job* temp1 = (Job*)a;
	Job* temp2 = (Job*)b;
	return (temp2->profit - temp1->profit);
}


void printSchedule(Job arr[], int n){
	
	qsort(arr, n, sizeof(Job), compare);
	
	bool slot[n];
	
	for(int i = 0; i < n; i++) slot[i] = false;
	
	
}


int main(){
	
	Job arr[] = {
		{
			'a', 2, 100
		},
		{
			'b', 1, 19
		},
		{
			'c', 2, 27
		},
		{
			'd', 1, 25
		},
		{
			'e', 3, 15 
		}
	};
	
	
	int n = sizeof(arr) / sizeof(arr[0]);
	
	return 0;
}