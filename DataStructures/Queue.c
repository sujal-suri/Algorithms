#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *que;
	int front;
	int rear;
	int len;
}Queue;


//returns a que pointer with given size.
Queue* initialize_que(int size){
	Queue*temp=(Queue*)malloc(sizeof(Queue));
	if(temp==NULL){
		return NULL;
	}
	temp->front=0;
	temp->rear=0;
	temp->len=size;
	temp->que=(int *)malloc(sizeof(int)*size);
	if(temp->que==NULL){
		return NULL;
	}
	return temp;
}


//adds to the given que the specified value
void enqueue(Queue*Que,int x){
	if((Que->rear+1)%Que->len==Que->front){
		printf("Queue is full\n");
		return;
	}
	Que->rear=(Que->rear+1)%Que->len;
	Que->que[Que->rear]=x;
	return;
}



//returns the value removed from the given que
int dequeue(Queue*Que){
	if(Que->front==Que->rear){
		printf("Queue is empty\n");
		return -1;
	}
	Que->front=(Que->front+1)%Que->len;
	return Que->que[Que->front];
}

// prints the whole que
void showQueue(Queue*q){
	int t=q->front+1;
	while(t!=(q->rear+1)%q->len&&!(q->front==q->rear)){
		printf("%d ",q->que[t]);
		t=(t+1)%q->len;
	}
	printf("\n");
}

void finish_que(Queue*q){
	free(q->que);
	free(q);
}

int main(){
	int size;
	printf("Enter the size of the queue: ");
	scanf("%d",&size);
	Queue *q=initialize(size);
	int command;
	int done=0;
	while(!done){
		printf("--------\n1. enqueue\n2. dequeue\n3. show\n4. quit\n--------\n");
		scanf("%d",&command);
		if(command==1){
			int val;
			printf("Value to enqueue: ");
			scanf("%d",&val);
			enqueue(q,val);
		}
		else if(command==2){
			printf("value dequeue: %d\n",dequeue(q));
		}
		else if(command==3){
			showQueue(q);
		}
		else{
			done=1;
		}
	}
	printf("Freeing queue\n");
	free(q);
	return 0;
}
