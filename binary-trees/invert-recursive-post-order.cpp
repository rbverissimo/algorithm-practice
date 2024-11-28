#include<stdio.h>
#include<stdlib.h>

// Basic inversion of a tree using the post order (left, root, right)


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

struct Node* mirror(struct Node* root){
	if(root == NULL ) return NULL;
	
	struct Node* left = mirror(root->left);
	struct Node* right = mirror(root->right);
	
	root->left = right;
	root->right = left;
	return root;
}

void postOrder(struct Node* root){
	if(root == NULL) return;
	
	postOrder(root->left);
	printf("%d ", root->data);
	postOrder(root->right);
}

int main(){
	
	struct Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	
	root = mirror(root);
	
	postOrder(root);
	
	return 0;
	
}