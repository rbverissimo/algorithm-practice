#include<stdio.h>
#include<stdlib.h>

//PREORDER TRAVERSAL: ROOT -> LEFT -> RIGHT

//Use cases: create copy of the tree, get prefix expressions on an expression tree

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

void preorder(struct Node* root){
	
	if(root == NULL) return;
	
	printf("%d ", root->data);
	
	preorder(root->left);
	preorder(root->right);
}

int main(){
	
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	preorder(root);
	
	return 0;
}