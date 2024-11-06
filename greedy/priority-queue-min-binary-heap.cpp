#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
	int items[MAX];
	int size;	
} PriorityQueue;

void enqueue(PriorityQueue* q, int value){
	
	if(q->size == MAX){
		printf("Queue can't take more values because it is full.");
		return;
	}
	
	q->items[q->size++] = value;
}

void print_queue(PriorityQueue* q){
	
	for(int i = 0; i < q->size; i++) printf("%d ", q->items[i]);
}

int main(){
	
	PriorityQueue q = { {0}, 0};
	
	enqueue(&q, 4);
	enqueue(&q, 10);
	enqueue(&q, 3);
	
	print_queue(&q);
	
	return 0;
}