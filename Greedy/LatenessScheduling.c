/*
Given N number of jobs with t(i) time to complete with a deadline d(i) and finish_time f(i)
Minimize the Maximum lateness f(i)-d(i).
*/

#include<stdio.h>
#include<stdlib.h>
#include"../Sortings/GenericMergeSort.h"

typedef struct{
    int time;
    int deadline;
    int index;
}task;

int compare(const void *a,const void *b){
    return (*(task**)a)->deadline-(*(task**)b)->deadline;
}

int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    task **arr=(task**)malloc(sizeof(task*)*n);
    for(int i=0;i<n;i++){
       task *job=(task*)malloc(sizeof(task)*n);
        printf("Enter the length of Job and Deadline: ");
        scanf("%d %d",&job->time,&job->deadline);
        job->index=i+1;
        arr[i]=job; 
    }
    Merge_sort(arr,n,sizeof(task*),compare);
    int lateness=0;
    int cur_time=0;
    for(int i=0;i<n;i++){
        cur_time+=arr[i]->time;
        lateness=lateness<cur_time-arr[i]->deadline?cur_time-arr[i]->deadline:lateness;
        printf("schedule-task: %d",arr[i]->index);
        printf("\n");
    }
    printf("maximum delay: %d\n",lateness);
    for(int i=0;i<n;i++){
        free(arr[i]);
    }
    free(arr);
}