#include <stdio.h>
#include <sys/time.h>
#include "..\Gerador\Gerador.c"
#include "..\Relatorio\Relatorio.c"

int totalComp = 0; //total de condicionais
int totalTroca = 0; //total que o vetor foi alterado

//Algoritmo para medir o número de comparações e trocas
void MaxHeapify_Comp(int* A, int n, int i){
    int e = (2*i)+1; //vetor começa em 0
    int d = (2*i) + 2;
    int maior;

    if(e < n && A[e] > A[i]) //comparação +1
        maior = e;
    else maior = i;

    if(d < n && A[d] > A[maior])//comparação +1
        maior = d;


    if(maior != i){
        int temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;
        totalTroca ++;
        MaxHeapify_Comp(A, n, maior);
    }
    totalComp += 2;
}

void BuildMaxHeap_Comp(int* A, int n){
    for(int i = (n/2)-1; i >= 0; i--){
        MaxHeapify_Comp(A, (n-1), i);
    }
}

void HeapSort_Comp(int *A, int n){
    BuildMaxHeap_Comp(A,n);
    for(int i = (n-1); i > 0; i--){
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        totalTroca ++;
        MaxHeapify_Comp(A,i,0);
    }
}

//Algoritmo em condições normais
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
    int n;
    int* A;
    
    struct timeval begin,end;
    carregarVetor("Vetor_15625.bin", &A, &n);

    gettimeofday(&begin,0);
    HeapSort(A,n);
    gettimeofday(&end,0);
    free(A);

    carregarVetor("Vetor_15625.bin", &A, &n);
    HeapSort_Comp(A,n);
    free(A);

    gerarRelatorio("HeapSort-Teste-1","Aleatorio",n,(long)(end.tv_usec-begin.tv_usec), (long)end.tv_sec - begin.tv_sec,totalComp,totalTroca);
    
    return 0;
}