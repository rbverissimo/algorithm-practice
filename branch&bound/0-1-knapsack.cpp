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
	
	int profit_bound = u.profit;
	int j = u.level + 1;
	int totweight = u.weight;
	
	while((j < n) && (totweight + arr[j].weight <= W)){
		totweight += arr[j].weight;
		profit_bound = arr[j].value;
		j++;
	}
	
	//let's say some weight is left like 0.08 weight
	// we're going to multiple it by the ratio of the last iteration over the arr of itens
	// and sum it into the profit_bound
	// by doing so we have the max ammount of profit in this branch
	if(j < n) profit_bound += (W - totweight) * (arr[j].value / arr[j].weight);
	
	
	return profit_bound;
}

int knapsack(int W, Item arr[], int n){
	
	//the basic setup is:
	// 1. sort the arr of elements using the cmp function
	// 2. start up two Nodes (which each will be the root of its own branch)
	// 3. set a dummy node as starting point for the while loop
	
	std::sort(arr, arr+n, cmp);
	
	std::queue<Node> Q;
	Node u, v;
	
	// starting a dummy node and pushing it into queue
	u.level = -1;
	u.profit = u.weight = 0;
	Q.push(u);
	
	int max_profit = 0;
	
	while(!Q.empty()){
		
		u = Q.front();
		Q.pop();
		
		if(u.level == -1) v.level = 0;
		
		if(u.level == n-1) continue;
		
		v.level = u.level + 1; //it isn't the last level and also isn't the first, so v should be the next available level
		
		//account in this node the weight and value of the last node (which is the sum of weights and values thus far)
		v.weight = u.weight + arr[v.level].weight;
		v.profit = u.profit + arr[v.level].value;
		
		if(v.weight <= W && v.profit > max_profit) max_profit = v.profit;
		
		v.bound = bound(v, n, W, arr);
		
		if(v.bound > max_profit) Q.push(v);
		
		// this node might not be a part of the solution, therefore let's compute bound without it
		v.weight = u.weight;
		v.profit = u.profit;
		v.bound = bound(v, n, W, arr);
		if(v.bound > max_profit) Q.push(v);	
	}
	
	return max_profit;
}


int main(){
	
	int W = 10;
	
	Item arr[] = {{2, 40},{3.14, 50},{1.98, 100},{5, 95},{3, 30}};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	std::cout << "Maximum profit is: " << knapsack(W, arr, n); 
	
	return 0;
}