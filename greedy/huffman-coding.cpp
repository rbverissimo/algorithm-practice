#include<stdio.h>
#include<stdlib.h>

#define MAX_TREE_HT 100


struct MinHeapNode {
	char data;
	unsigned freq;
	
	struct MinHeapNode *left, *right;
};


struct MinHeap {
	unsigned size;
	unsigned capacity;
	struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq){
	
	struct MinHeapNode* temp = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
	
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	
	return temp;
	
}

int main(){
	return 0;
}