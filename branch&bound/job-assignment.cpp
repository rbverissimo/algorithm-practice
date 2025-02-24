#include<iostream>
#include<queue>

#define N 4

struct Node 
{
	Node* parent;
	int pathCost, cost, workerID, jobID;
	bool assigned[N];
};

Node* newNode(int x, int y, bool assigned[], Node* parent)
{
	Node* node = new Node();
	for(int j = 0; j < N; j++) node->assigned[j] = assigned[j];
	node->assigned[y] = true;
	node->parent = parent;
	node->workerID = x;
	node->jobID = y;
	return node;	
}

struct comp {
	bool operator()(const Node* lhs, const Node* rhs) const 
	{
		return lhs->cost > rhs->cost;	
	}	
};


int main(){
	return 0;
}