#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
	int items[MAX];
	int size;	
} PriorityQueue;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int peek(PriorityQueue* q){
	if(!q->size) {
		printf("The queue is empty! ");
		return -1;
	}
	return q->items[0]; 
}

void heapifyUp(PriorityQueue* q, int index){
	
	if(index && q->items[(index - 1) / 2] > q->items[index]){
		swap(&q->items[(index - 1) / 2], &q->items[index]);
		heapifyUp(q, (index - 1) / 2);
	}
	
}

void heapifyDown(PriorityQueue *q, int index){
	int smallest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	
	if(left < q->size && q->items[left] < q->items[smallest]) smallest = left;
	
	if(right < q->size && q->items[right] < q->items[smallest]) smallest = right;
	
	if(smallest != index){
		swap(&q->items[index], &q->items[smallest]);
		heapifyDown(q, smallest);
	}
}

void enqueue(PriorityQueue* q, int value){
	
	if(q->size == MAX){
		printf("Queue can't take more values because it is full.");
		return;
	}
	
	q->items[q->size++] = value;
	heapifyUp(q, q->size-1);
}

int dequeue(PriorityQueue* q){

	int item = peek(q);
	if(item == -1) return item;
	q->items[0] = q->items[--q->size];	
	heapifyDown(q, 0);
	return item;
}


void print_queue(PriorityQueue* q){
	
	for(int i = 0; i < q->size; i++) printf("%d ", q->items[i]);
}

int main(){
	
	PriorityQueue q = { {0}, 0};
	
	enqueue(&q, 4);
	enqueue(&q, 10);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 5);
	
	print_queue(&q);
	
	dequeue(&q);
	
	printf("\nDequeued: ");
	print_queue(&q);
	
	return 0;
}