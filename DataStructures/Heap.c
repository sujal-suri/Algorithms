#include<stdio.h>
#include<stdlib.h>

struct heap{
	int *arr;
	int sz;
	int head;
};

void swap(int *arr, int index1,int index2){
	int temp = arr[index1];
	arr[index1]=arr[index2];
	arr[index2]=temp;
}

struct heap * initialize_heap(int n_ele){
	struct heap *hp=(struct heap *)malloc(sizeof(struct heap));
	hp->arr = (int *)malloc(sizeof(int)*(n_ele+1));
	hp->sz = n_ele;
	hp->head = 1;
	return hp;
}

void finish_heap(struct heap * hp){
	free(hp->arr);
	free(hp);
}

int insert_heap(struct heap * hp, int ele){
	if(hp->head==hp->sz+1){
		return -1;//Heap full.
	}
	hp->arr[hp->head]=ele;
	int index = hp->head;
	hp->head++;
	while(index>1&&hp->arr[index]<hp->arr[index/2]){
		swap(hp->arr,index,index/2);
		index=index/2;
	}
	return 0;
}

int	get_min(struct heap * hp){
	if(hp->head==1){
		return -1;
	}
	swap(hp->arr,1,hp->head-1);
	int index = 1;
	hp->head--;
	while(index*2+1<=hp->head-1&&( hp->arr[index]>hp->arr[index*2] || hp->arr[index]>hp->arr[index*2 +1])){
		if(hp->arr[index]>hp->arr[index*2] && hp->arr[index]>hp->arr[index*2 +1]){
			if(hp->arr[index*2]<=hp->arr[2*index+1]){
				swap(hp->arr,index , index*2);
				index = index*2;
			}
			else{
				swap(hp->arr,index , index*2+1);
				index = index*2+1;
			}
		}
		else if(hp->arr[index]>hp->arr[index*2] && hp->arr[index]<= hp->arr[index*2+1]){
			swap(hp->arr, index , index*2);
			index = index * 2;
		}
		else if(hp->arr[index]<=hp->arr[index*2] && hp->arr[index]> hp->arr[index*2+1]){
			swap(hp->arr, index , index*2+1);
			index = index*2+1;
		}
		else{
			break;
		}
	}
	if(index == hp->head -1){
		return hp->arr[hp->head];
	}
	else if(index == (hp->head-1)/2){
		if(hp->arr[index]>hp->arr[index*2]){
			swap(hp->arr,index,index*2);
		}
		return hp->arr[hp->head];
	}

	return hp->arr[hp->head];
}

int main(){
	struct heap * myHeap=initialize_heap(10);
	int size;
	printf("enter the size of heap: ");
	scanf("%d",&size);
	int num;
	for(int i=0;i<size;i++){
		scanf("%d",&num);
		insert_heap(myHeap,num);
	}
	for(int i=0;i<size;i++){
		printf("%d ",get_min(myHeap));
	}
	printf("\n");
	finish_heap(myHeap);
	return 0;
}
