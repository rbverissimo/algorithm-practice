// pre, post and in order in one go

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL; 
	}
};


void prePostInOrderInOneFlowRecursive(Node* root, vector<int>& pre, vector<int>& post, vector<int>& in){
	
	if(root == NULL) return;
	
	pre.push_back(root->data);
	
	prePostInOrderInOneFlowRecursive(root->left, pre, post, in);
	
	in.push_back(root->data);
	
	prePostInOrderInOneFlowRecursive(root->right, pre, post, in);
	
	post.push_back(root->data);
	
}



int main(){
	
	
	/*
					  	  1
				 2				   3
			4	      5      6          7     
		8		  9                10      11
		  12
	*/
	
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(9);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->left->right = new Node(12);
	root->right->right->left = new Node(10);
	root->right->right->right = new Node(11);
	
	
	vector<int> pre, post, in;
	
	prePostInOrderInOneFlowRecursive(root, pre, post, in);
	
	cout << "Pre Order : ";
    for (auto i : pre) cout << i << " ";
    
 
    cout << endl;
    cout << "Post Order : ";
    for (auto i : post) cout << i << " ";
    
    cout << endl;
    cout << "In Order : ";
    for (auto i : in) cout << i << " ";
    
	
	return 0;
}