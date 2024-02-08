#include<stdio.h>
#include<stdlib.h>

//Structure holding context relating to each task.
typedef struct{
    int start;
    int end;
    int weight;
}task;

//Simple Max function return maximum of two integer.
int max(int a,int b){
    return a>=b?a:b;
}

int p(int index,task *sched){
    //Could be Optimized to perform a Binary Search over the array [0,i-1].
    for(int i=index-1;i>=0;i--){
        if(sched[i].end<=sched[index].start){
            return i;
            // Returns the index of the latest task earlier than ith task with f(i)<=s(index);
        }
    }
    return 0;
}

//Computes the Maximum Weight tasks for T weighted tasks. For Detail check pg-258 Algorithm Design(Eva Tardos).
int Compute_Opt(task *sched, int t,int *Optimal){
    for(int i=1;i<=t;i++){
        Optimal[i]=max(sched[i].weight+Optimal[p(i,sched)],Optimal[i-1]);
    }
    return Optimal[t];
}

/*Compare function to sort Sched*/
int compare(const void *a,const void *b){
    return ((task *)a)->end-((task *)b)->end;
}

int main(){
    int n;  //Taking the number of Tasks.
    scanf("%d",&n);
    task *sched=(task*)malloc(sizeof(task)*(n+1)); //Allocating array for the tasks. sched[i], i=1,2,...n
    sched[0].end=0;
    sched[0].start=0;
    sched[0].weight=0;
    for(int i=1;i<=n;i++){
        /*taking input of the form s(i) f(i) w(i) iterating over i.*/
        scanf("%d %d %d",&sched[i].start,&sched[i].end,&sched[i].weight);
    }
    // sorting the sched array.
    qsort(sched+1,n,sizeof(task),compare);
    int *Optimal = (int *)calloc(n+1,sizeof(int));
    printf("Maximum Weighted Sequence: %d\n",Compute_Opt(sched, n, Optimal));
    printf("Maximum weight for each task: ");
    for(int i=1;i<=n;i++){
        printf("%d ",Optimal[i]);
    }
    printf("\n");
    //Freeing the Allocated Memory.
    free(sched); 
    free(Optimal);
}