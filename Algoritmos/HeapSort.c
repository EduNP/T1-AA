#include <stdio.h>
#include "..\Gerador\Gerador.c"

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
    char teste[][50] = {"Vetor_8_2147483647.bin", "Vetor_27_2147483647.bin","Vetor_512_2147483647.bin", 
    "Vetor_19683_2147483647.bin","Vetor_32768_2147483647.bin","Vetor_14348907_2147483647.bin"};

    int n;
    int* A;

    carregarVetor("Vetor_14348907_2147483647.bin", &A, &n);
    HeapSort(A,n);
    for(int k = 0; k < n; k++)
        printf("item (%d) = %d\n", k, A[k]);

    for(int p = 0; p < n-1; p++){
        if(A[p] > A[p+1])
            printf("Deu ruim");
    }
    
    free(A);
   
    return 0;
}