#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*Comparator)(const void *a, const void *b);

void Merge(void *Arr, int mid, int length, int size, Comparator compare) {
    void* Aux=malloc(size*length);
    int i=0;
    int j=mid;
    int k=0;
    while (i<mid && j<length) {
        int res=compare((char*)Arr+i*size, (char*)Arr+j*size);
        if (res<0) {
            memcpy((char*)Aux+k*size, (char*)Arr+i*size, size);
            i++;
        } else {
            memcpy((char*)Aux+k*size, (char*)Arr+j*size, size);
            j++;
        }
        k++;
    }

    while (i<mid) {
        memcpy((char*)Aux+k*size,(char*)Arr+i*size, size);
        i++;
        k++;
    }

    while (j<length) {
        memcpy((char*)Aux+k*size, (char*)Arr+j*size, size);
        j++;
        k++;
    }

    memcpy((char*)Arr, (char*)Aux, size * length);
    free(Aux);
}

void Merge_sort(void *Arr, int length, int size_elements, Comparator compare) {
    int mid = length / 2;
    if (length > 1) {
        Merge_sort(Arr, mid, size_elements, compare);
        Merge_sort((char*)Arr + size_elements * mid, length - mid, size_elements, compare);
        Merge(Arr, mid, length, size_elements, compare);
    }
}
