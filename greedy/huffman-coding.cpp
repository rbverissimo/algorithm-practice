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
	mh->array[0] = mh->array[mh->size - 1];
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

void buildMinHeap(struct MinHeap* minHeap){
	int n = minHeap->size - 1;
	for(int i = (n - 1) / 2; i >=0; --i) minHeapify(minHeap, i);
}


void printArr(int arr[], int n){
	for(int i = 0; i < n; ++i) printf("%d", arr[i]);
	
	printf("\n");
	
}

int isLeafNode(struct MinHeapNode* root){
	return !(root->left) && !(root->right);
}
void printCodes(struct MinHeapNode* root, int arr[], int top){
	
	if(root->left){
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	
	if(root->right){
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	
	if(isLeafNode(root)){
		printf("%c: ", root->data);
		printArr(arr, top);
	}
	
}

struct MinHeap* assembleMinHeap(char data[], int freq[], int size){
	
	struct MinHeap* mh = createMinHeap(size);
	
	for(int i = 0; i < size; i++) mh->array[i] = newNode(data[i], freq[i]);
	
	mh->size = size;
	buildMinHeap(mh);
	return mh;
	
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
	
	struct MinHeapNode *left, *right, *top;
	
	struct MinHeap* minHeap = assembleMinHeap(data, freq, size);
	
	
	while(!isSizeOne(minHeap)){
		
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		
		insertMinHeap(minHeap, top);
		
	}
	
	
	return extractMin(minHeap);
	
}

void HuffmanCodes(char data[], int freq[], int size){
	
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top);
	
}

int main(){
	
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	HuffmanCodes(arr, freq, size);
	
	return 0;
}

