#include<iostream>
#include<queue>
#include<limits.h>

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

int calculateCost(int costMatrix[N][N], int x, int y, bool assigned[]){
	int cost = 0;
	bool available[N] = {true};
	
	for(int i = x + 1; i < N; i++){
		int min = INT_MAX, minIndex = -1;
		
		for(int j = 0; j < N; j++){
			
			if(!assigned[j] && available[j] && costMatrix[i][j] < min)
			{
				minIndex = j;
				min = costMatrix[i][j];
			} 
		}
		
		cost += min;
		available[minIndex] = false;
	}
	
	return cost;
}

void printAssignments(Node* min){
	
	if(min->parent==NULL) return;
	
	printAssignments(min->parent);
	std::cout << "Assign worker " << char(min->workerID + 'A')
		<< " to job " << min->jobID << std::endl;
}

int findMinCost(int costMatrix[N][N]){
	
	
	std::priority_queue<Node*, std::vector<Node*>, comp> pq;
	bool assigned[N] = {false};
	Node* root = newNode(-1, -1, assigned, NULL);
	root->pathCost = root->cost = 0;
	root->workerID = -1;
	
	pq.push(root);
	
	while(!pq.empty()){
		
		Node* min = pq.top(); //retrieve, but does not pops out of the queue;
		
		pq.pop();
		
		int i = min->workerID + 1;
		
		if(i == N){
			printAssignments(min);
			return min->cost;
		}
		
		for(int j = 0; j < N; j++){
			
			if(!min->assigned[j]){
				Node* child = newNode(i, j, min->assigned, min);
				child->pathCost = min->pathCost + costMatrix[i][j];
				child->cost = child->pathCost + calculateCost(costMatrix, i, j, child->assigned);
				pq.push(child);
			}
			
		}	
	}
	
}


int main(){
	
	int costMatrix[N][N] = {
		{
			9, 2, 7, 8
		},
		{
			6, 4, 3, 7
		},
		{
			5, 8, 1, 8
		},
		{
			7, 6, 9 , 4
		}
	};
	
	int minCost = findMinCost(costMatrix);
	
	std::cout << "\nOptimal cost is " << minCost;
	return 0;
}