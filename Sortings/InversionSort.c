#include<stdio.h>
#include<stdlib.h>

int countMerge(int *arr,int l, int mid,int h){
	int *aux=(int *)malloc(sizeof(int)*(h-l+1));
	int k=0,i=l,j=mid+1;
	int count=0;
	while(i<=mid&&j<=h){
		if(arr[i]<arr[j]){
			aux[k]=arr[i];
			i++;
			k++;
		}
		else{
			aux[k]=arr[j];
			count+=(mid-i+1);
			j++;
			k++;
		}
	}
	while(j<=h){
		aux[k]=arr[j];
		j++;
		k++;
	}
	while(i<=mid){
		aux[k]=arr[i];
		i++;
		k++;
	}
	for(int i=0;i<h-l+1;i++){
		arr[l+i]=aux[i];
	}
	free(aux);
	return count;
}

int inversionSort(int *arr,int l,int h){
	if(h-l+1<=1){
		return 0;
	}
	int mid=(l+h)/2;
	return inversionSort(arr,l,mid)+inversionSort(arr,mid+1,h)+countMerge(arr,l,mid,h);
}

int main(int argc,char *argv[]){
	if(argc<2){
		printf("Invalid Arguements: ./a.out a1 a2 a3..... aN\n");
		return 0;
	}
	int *arr=(int *)malloc(sizeof(int)*(argc-1));
	for(int i=1;i<argc;i++){
		arr[i-1]=atoi(argv[i]);
	}
	printf("Number of Inversions: %d\n",inversionSort(arr,0,argc-2));
	printf("Sorted array: ");
	for(int i=0;i<argc-1;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	free(arr);
	return 0;
}
