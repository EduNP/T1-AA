#include <stdio.h>

void MaxHeapify(int* A, int n, int i){
    int e = (2*i)+1; //vetor começa em 0
    int d = (2*i) + 2;
    int maior;
    if(e < n && A[e] > A[i])
        maior = e;
    else maior = i;

    if(d < n && A[d] > A[maior])
        maior = d;
    if(maior != i){
        int temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;
        MaxHeapify(A, n, maior);
    }
}

void BuildMaxHeap(int* A, int n){
    for(int i = (n/2)-1; i >= 0; i--){
        MaxHeapify(A, (n-1), i);
    }
}

void HeapSort(int *A, int n){
    BuildMaxHeap(A,n);
    for(int i = (n-1); i > 0; i--){
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        MaxHeapify(A,i,0);
    }
}

int main(){
    int n = 5;
    int A[5] = {10,9,8,7,6};
    HeapSort(A,n);
    
    for(int i = 0; i < 5; i++)
        printf("item (%d) = %d\n", i, A[i]);
}