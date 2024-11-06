#include<bits/stdc++.h>
using namespace std;

int H[50];
int size = -1;



int parent(int i){
	return (i - 1) / 2;
}

int left_child(int i){
	return ((2 * i) + 1);
}

int right_child(int i){
	return ((2 * i) + 2);
}

void shiftUp(int i){
	
	while(i > 0 && H[parent(i)] < H[i]){
		swap(H[parent(i)], H[i]);
		i = parent(i);
	}
	
}

void shiftDown(int i){
	
	int max_index = i;
	
	int l = left_child(i);
	
	if(l <= size && H[l] > H[max_index]) max_index = l;
	
	int r = right_child(i);
	
	if(r <= size && H[r] > H[max_index]) max_index = r;
	
	if(i != max_index){
		swap(H[i], H[max_index]);
		shiftDown(max_index);
	}
}

void insert(int p){
	size = size + 1;
	H[size] = p;
	shiftUp(size);
}

int extractMax(){
	int result = H[0];
	H[0] = H[size];
	size = size - 1;
	shiftDown(0);
	return result;
}

int getMax(){
	return H[0];
}

void remove(int i){
	
	H[i] = getMax() + 1;
	shiftUp(i);
	extractMax();
	
}


int main(){
	
	
	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert (31);
	
	int i = 0;
	
	
	cout << "Priority Queue: ";
	while(i <= size){
		cout << H[i] << " ";
		i++;
	}	
	
	return 0;
}