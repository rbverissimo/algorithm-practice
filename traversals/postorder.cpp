#include<stdio.h>
#include<stdlib.h>

//POSTORDER: LEFT, RIGHT, NODE 
// This is used for tree deletion because we need to delete subtrees before deleting the current node.
// It is also useful to get the postfix expression from an expression tree.

struct Node {
	
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data){
	
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return node; 	
}

void postorder(struct Node* root){
	
	if(root == NULL ) return;
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
	
}

int main(){
	
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	root->right->right = newNode(6);
	
	postorder(root);
	
	return 0;
}