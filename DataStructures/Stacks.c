#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int *arr;
	int size;
	int top;
}Stack;

//The stack is for positive integers.
//Creates a stack of a particular Size dynamically.
Stack * initialize_st(int sz){
	Stack *st=(Stack *)malloc(sizeof(Stack));
	st->size=sz;
	st->top=0;
	st->arr=(int *)malloc(sizeof(int)*sz);
	return st;
}

//free the allocated memory.
void finish_st(Stack *st){
	free(st->arr);
	free(st);
}

//push value into the stack.
void push(Stack *st,int val){
	if(st->top==st->size){
		printf("Stack Overflow\n");
		return;
	}
	st->arr[st->top]=val;
	st->top++;
}

//pop values from the stack.
int pop(Stack *st){
	if(st->top==0){
		printf("Stack Underflow\n");
		return -1;
	}
	st->top--;
	return st->arr[st->top];
}

//show the top value of the stack.
int peek(Stack*st){
	if(st->top==0){
		printf("Stack Underflow\n");
		return -1;
	}
	return st->arr[st->top - 1];	
}

int isEmpty(Stack*st){
	if(st->top==0){
		return 1;
	}
	return 0;
}

int isFull(Stack*st){
	if(st->top==st->size-1){
		return 1;
	}
	return 0;
}

int main(int argc,char *argv[]){
	int size;
	printf("Enter the size: ");
	scanf("%d",&size);
	printf("------\n1. push\n2. pop\n3. peek\n4. exit\n------\n");
	Stack *stack=initialize(size);
	int command;
	int done=0;
	while(!done){
		scanf("%d",&command);
		if(command==1){
			int n;
			printf("Enter the value to push: ");
			scanf("%d",&n);
			push(stack,n);
		}
		else if(command==2){
			printf("Value popped: %d\n",pop(stack));
		}
		else if(command==3){
			printf("top value: %d\n",peek(stack));
		}
		else{
			finish(stack);
			done=1;
		}
	}
	printf("Ending program\n");
	return 0;
}
