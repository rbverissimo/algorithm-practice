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


void heapifyUp(PriorityQueue* q, int index){
	
	if(index && q->items[(index - 1) / 2] > q->items[index]){
		swap(&q->items[(index - 1) / 2], &q->items[index]);
		heapifyUp(q, (index - 1) / 2);
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

void print_queue(PriorityQueue* q){
	
	for(int i = 0; i < q->size; i++) printf("%d ", q->items[i]);
}

int main(){
	
	PriorityQueue q = { {0}, 0};
	
	enqueue(&q, 4);
	enqueue(&q, 10);
	enqueue(&q, 1);
	
	print_queue(&q);
	
	return 0;
}