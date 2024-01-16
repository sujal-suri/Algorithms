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
/*--------------------------------------------------------------------------
Code taken from Stack.c
----------------------------------------------------------------------------
*/
typedef struct{
    int **mat;
    int n;
}AdjMat;

AdjMat * initialize_gp(int size){
    AdjMat *graph=(AdjMat*)malloc(sizeof(AdjMat));
    graph->n=size;
    graph->mat=(int **)malloc(sizeof(int*)*(size+1));
    for(int i=1;i<=size;i++){
        graph->mat[i]=(int *)malloc(sizeof(int)*(size+1));
    }
    //printf("Enter the matrix below:\n");
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            scanf("%d",&graph->mat[i][j]);
        }
    }
    //printf("Input to matrix taken\n");
    return graph;
}

void finish_gp(AdjMat *gp){
    for(int i=1;i<=gp->n;i++){
        free(gp->mat[i]);
    }
    free(gp->mat);
    free(gp);
}


void showMat(AdjMat *gp){
    printf("the number of vertices are: %d\n",gp->n);
    for(int i=1;i<=gp->n;i++){
        for(int j=1;j<=gp->n;j++){
            printf("%d ",gp->mat[i][j]);
        }
        printf("\n");
    }
}

void dfs(AdjMat *mat,Stack *st,int *visited){
    while(!isEmpty(st)){
        int curr=pop(st);
        printf("%d ",curr);
        for(int i=1;i<=mat->n;i++){
            if(mat->mat[curr][i]==1&&visited[i]==0){
                visited[i]=1;
               //printf("going in %d\n",i+1);
                push(st,i);
                dfs(mat,st,visited);
            }
        }
        return;
    }
}

void doDFS(){
    int numNodes;
    //printf("Enter the number of nodes: ");
    scanf("%d",&numNodes);
    AdjMat *mat=initialize_gp(numNodes);
    Stack *st=initialize_st(numNodes+1);
    int start;
    //printf("Enter DFS starting point: ");
    scanf("%d",&start);
    int *visited = (int *)calloc(numNodes+1,sizeof(int));
    visited[start]=1;
    push(st,start);
    dfs(mat,st,visited);
    printf("\n");
    finish_st(st);
    finish_gp(mat);
    free(visited);
}

int main(){
    doDFS();
    return 0;
}