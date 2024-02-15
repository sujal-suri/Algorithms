/*-----------------------------------------------------------------------------------------------------
Following is the implementation of the Knapsack problem. Given on page 271 Algorithm Design(Eva Tardos)
-----------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return a>=b?a:b;
}

typedef struct {
    int value;
    int weight;
}request;

void Opt(int **Knap,int n, int W, request *t){
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(t[i-1].weight>j){
                Knap[i][j]=Knap[i-1][j];
            }
            else{
                Knap[i][j]=max(Knap[i-1][j],t[i-1].value+Knap[i-1][j-t[i-1].weight]);
            }
        }
    }
    return;
}

int main(){
    int W;//Maximum weight of the sack.
    scanf("%d",&W);
    int n; //Number of request.
    scanf("%d",&n);
    request * task = (request *)malloc(sizeof(request)*n);
    int ** Knapsack=(int **)malloc(sizeof(int *)*(n+1));
    for(int i=0;i<=n;i++){
        int * temp= (int *)calloc(W+1,sizeof(int));
        Knapsack[i]=temp;
    }
    /*N rows to space separated integers value(i), weight(i).*/
    for(int i=0;i<n;i++){
        scanf("%d %d",&task[i].value,&task[i].weight);
    } 
    Opt(Knapsack,n,W,task);
    /*
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            printf("%d ",Knapsack[i][j]);
        }
        printf("\n");
    }
    printf("\n"); 
    */
    // Uncomment to print the value Knapsack array.

    //Printing the Optimal array of request to and maximum achieved value.
    printf("Maximum value can be achieved is: %d\n",Knapsack[n][W]);
    int i=n;
    int j=W;
    while(i>0&&j>0){
        int OptIn=task[i-1].value+Knapsack[i-1][j-task[i-1].weight];
        int OptOut=Knapsack[i-1][j];
        if(OptIn>=OptOut){
            printf("<value: %d, weight: %d> ",task[i-1].value,task[i-1].weight);
            j=j-task[i-1].weight;
            i=i-1;
        }
        else{
            i=i-1;
        }
    }
    printf("\n");


    //Freeing up used space.
    for(int i=0;i<=n;i++){
        free(Knapsack[i]);
    }
    free(Knapsack);
    free(task);
    return 0;
}