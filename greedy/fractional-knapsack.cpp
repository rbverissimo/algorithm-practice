#include<bits/stdc++.h>


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
	
	
	return 0.0;
	
}

int main(){
	
	int capacity = 50;
	Item arr[] = { {30, 5}, {20, 10}, {100, 20}, {90, 30}, {160, 40} };
	
	return 0;
}