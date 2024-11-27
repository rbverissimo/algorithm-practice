#include<stdio.h>
#include<stdlib.h>


struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};


struct Node* createNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	
	return n;
}

int main(){
	
	struct Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	
	return 0;
	
}