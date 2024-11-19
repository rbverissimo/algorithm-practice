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

struct MinHeap* createMinHeap(unsigned capacity){
	
	struct MinHeap* temp = (struct MinHeap*) malloc(sizeof(struct MinHeap));
	
	temp->size = 0;
	temp->capacity = capacity;
	temp->array = (struct MinHeapNode**)malloc(temp->capacity * sizeof(struct MinHeapNode*));
	return temp;
}

void swapMinHeapNode(struct MinHeapNode** a,  struct MinHeapNode** b){
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct MinHeap* mh, int idx){
	
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;
	
	if(left < mh->size && mh->array[left]->freq < mh->array[smallest]->freq) smallest = left;
	
	if(right < mh->size && mh->array[right]->freq < mh->array[smallest]->freq) smallest = right;
	
	if(smallest != idx){
		swapMinHeapNode(&mh->array[smallest], &mh->array[idx]);
		minHeapify(mh, smallest);
	}
	
}

int isSizeOne(struct MinHeap* mh){
	return (mh->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* mh){
	
	struct MinHeapNode* temp = mh->array[0];
	--mh->size;
	minHeapify(mh, 0);
	return temp; 
	
}

void insertMinHeap(struct MinHeap* mh, struct MinHeapNode* node){
	
	mh->size++;
	int i = mh->size - 1;
	
	while(i && node->freq < mh->array[(i - 1) / 2]->freq){
		mh->array[i] = mh->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	
	mh->array[i] = node;
}


int main(){
	return 0;
}