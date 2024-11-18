#include<bits/stdc++.h>
using namespace std;


struct Item {
	int profit, weight;
	
	Item(int profit, int weight){
		this->profit = profit;
		this->weight = weight;
	}
};

static bool comp(struct Item a, struct Item b){
	double r1 = (double)a.profit / a.weight;
	double r2 = (double)b.profit / b.weight;
	
	return r1 > r2;
}

double fractKpsk(int capacity, struct Item arr[], int N){
	
	sort(arr, arr + N, comp);
	double rst = 0.0;
	
	
	for(int i = 0; i < N; i++){
		
		if(arr[i].weight <= capacity){
			capacity -= arr[i].weight;
			rst += arr[i].profit;	
		} else {
			rst += arr[i].profit * ((double) capacity / (double) arr[i].weight); 
			break;
		}	
	}
	
	return rst;
	
}

int main(){
	
	int capacity = 60;
	Item arr[] = { {30, 5}, {20, 10}, {100, 20}, {90, 30}, {160, 40} };
	
	int N = sizeof(arr) / sizeof(arr[0]);
	
	cout << fractKpsk(capacity, arr, N);
	
	return 0;
}