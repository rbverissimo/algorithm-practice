#include<stdio.h>
#include<stdlib.h>


struct Node {
	int key;
	struct Node* left;
	struct Node* right;	
};

struct Node* newNode(int key){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Node* insert(struct Node* node, int key){
	
	if(node == NULL) return newNode(key);
	
	if(node->key == key) return node;
	
	if(node->key < key) node->right = insert(node->right, key);
	else node->left = insert(node->left, key);
	
	return node;
	
}

void inorder(struct Node* root){
	if(root == NULL ) return;
	inorder(root->left);
	printf("%d ", root->key);
	inorder(root->right);
}

int main(){
	
	struct Node* root = newNode(50);
	root = insert(root, 100);
	
	inorder(root);
	
	return 0;
}