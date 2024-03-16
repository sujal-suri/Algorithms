#include<stdlib.h>
#include<stdio.h>

typedef struct{
    int val;
    Node *pNext;
}Node;

Node * initialize_linkList(int arr[],int len){
    if(len<=0){
        return NULL;
    }
    Node *Head=(Node*)malloc(sizeof(Node));
    Head->val=arr[0];
    Head->pNext=NULL;
    for(int i=1;i<len;i++){
        insert(Head,arr[i]);
    }
    return Head;
}

void insert(Node *Head,int val){
    Node *temp=Head;
    while(temp->pNext!=NULL){
        temp=temp->pNext;
    }
    Node *next=(Node *)malloc(sizeof(Node));
    next->val=val;
    next->pNext=NULL;
    temp->pNext=next;
    return;
}

int length(Node *Head){
    int len=0;
    Node *ite=Head;
    while(ite!=NULL){
        len++;
        ite=ite->pNext;
    }
    return len;
}

void finish(Node *Head){
    Node *temp1=Head;
    Node *temp2=NULL;
    while(temp1!=NULL){
        temp2=temp1->pNext;
        free(temp1);
        temp1=temp2;
    }
}

int delete(Node *Node,int index){

}

int main(){

}