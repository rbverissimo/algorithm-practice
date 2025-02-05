#include<stdio.h>

#define V 5


void printSolution(int path[]);

int isSafe(int v, int graph[V][V], int path[], int pos){
	
	if(graph[path[pos-1]][v] == 0) return 0; //if the last position isn't adjacent to this vertex, return 0;
	
	for(int i = 0; i < pos; i++) if(path[i] == v) return 0; //if vertex already exists in the path array return 0;
	
	return 1;
}

int hamCycleUtil(int graph[V][V], int path[], int pos){
	
	if(pos == V) return graph[path[pos-1]][path[0]] == 1 ? 1 : 0;
	
	for(int v = 1; v < V; v++){
		
		if(isSafe(v, graph, path, pos)){
			path[pos]=v;
			if(hamCycleUtil(graph, path, pos+1) == 1) return 1;
			
			path[pos]=-1;
		}
	}
	
	return 0; //solution not found for that position
}


int hamCycle(int graph[V][V]){
	int path[V];
	for(int i = 0; i < V; i++) path[i] = -1;
	
	path[0] = 0; //we start from the 0-vertex
	
	if(hamCycleUtil(graph, path, 1) == 0)
	{
		printf("The solution does not exist");
		return 0;
	}
	
	printSolution(path);
	return 1;
	
}

void printSolution(int path[]){
	
	printf("Solution is: ");
	for(int i = 0; i < V; i++) printf(" %d ", path[i]);
	
	printf(" %d ", path[0]);
	printf("\n");
}


 int main(){
 	
	int graph1[V][V] = {
		{
			0, 1, 0, 1, 0
		},
		{
			1, 0, 1, 1, 1
		},
		{
			0, 1, 0, 0, 1
		},
		{
			1, 1, 0, 0, 1
		},
		{
			0, 1, 1, 1, 0
		}		  
	};
	
	hamCycle(graph1);
 	
	return 0;
 }