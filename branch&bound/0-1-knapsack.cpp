#include <iostream>
#include <algorithm>
#include <queue>

//Implementing the 0/1 knapsack using B&B

struct Item {
	float weight;
	int value;
};

struct Node {
	int level, profit, bound;
	float weight;
};

bool cmp(Item a, Item b){
	double a_ratio = (double)a.value/a.weight;
	double b_ratio = (double)b.value/b.weight;
	return a_ratio > b_ratio;
}

int bound(Node u, int n, int W, Item arr[]){
	
	if(u.weight >= W) return 0;
	
	int profit_bound = u.bound;
	int j = u.level + 1;
	int totweight = u.weight;
	
	while((j < n) && (totweight + arr[j].weight < W)){
		totweight += arr[j].weight;
		profit_bound = arr[j].value;
		j++;
	}
	
	if(j < n) profit_bound += (W - totweight) * arr[j].value / arr[j].weight;
	
	
	return profit_bound;
}

int knapsack(int W, Item arr[], int n){
	return 1;
}


int main(){
	
	int W = 10;
	
	Item arr[] = {
		{2, 40},{3.14, 50},{1.98, 100},{5, 95},{3, 30}
	};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	return 0;
}