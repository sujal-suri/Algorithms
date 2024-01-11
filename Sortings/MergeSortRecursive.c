#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void Merge( int Arr[],int l,int m,int h){
	int Aux[h-l+1];
	int i=l;
	int k=0;
	int j=m+1;
	while(i<=m&&j<=h){
		if(Arr[i]<Arr[j]){
			Aux[k++]=Arr[i++];
		}
		else{
			Aux[k++]=Arr[j++];
		}
	}
	for(;i<=m;i++){
		Aux[k++]=Arr[i];
	}
	for(;j<=h;j++){
		Aux[k++]=Arr[j];
	}
	for(int m=0;m<h-l+1;m++){
		Arr[m+l]=Aux[m];
	}
}
//for array of length n
//l=starting index= 0
//h=ending index= n-1
void Merge_sort(int Arr[],int l,int h){
	int mid;
	mid=(l+h)/2;
	if(l<h){
		Merge_sort(Arr,l,mid);
		Merge_sort(Arr,mid+1,h);
		Merge(Arr,l,mid,h);
	}
}

int main(int argc,char *argv[]){
    assert(argc>1);
    int array[argc-1];
    for(int i=1;i<argc;i++){
        array[i-1]=atoi(argv[i]);
    }
    Merge_sort(array,0,argc-2);
    for(int i=0;i<argc-1;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
