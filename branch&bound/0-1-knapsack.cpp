#include <iostream>


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
	
	
	return 1;
}


int main(){
	
	return 0;
}