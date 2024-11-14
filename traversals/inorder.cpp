#include<stdio.h>
#include<stdlib.h>
// Inorder Traversal: DFS, visits Left -> Root -> Right

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

void inorderTraversal(struct Node* root){
	
	if(root == NULL) return;
	
	inorderTraversal(root->left);
	printf("%d ", root->data);
	inorderTraversal(root->right);
	
}

int main(){
	
	
	struct Node* root = newNode(1);
	root->left = newNode(4);
	root->right = newNode(25);
	root->left->left = newNode(26);
	
	printf("Inorder traversal: ");
	inorderTraversal(root);
	printf("\n");
	return 0;
	
}