#include<stdio.h>
#include <sys/time.h>
#include "..\Gerador\Gerador.c"
#include "..\Relatorio\Relatorio.c"

int totalComp = 0;
int totalTroca = 0;

void insertion_sort_comp(int *v,int tam){
    int i, j, chave; 
    for(j = 1; j < tam; j++){
        chave = v[j];
        i=j-1;
        while(i>=0 && v[i]>chave){
            v[i+1]=v[i];
            i-=1;
            totalComp++;
            totalTroca++;
        }
        v[i+1]=chave;
        totalTroca++;
    }
}

void insertion_sort(int *v,int tam){
    int i, j, chave; 
    for(j = 1; j < tam; j++){
        chave = v[j];
        i=j-1;
        while(i>=0 && v[i]>chave){
            v[i+1]=v[i];
            i-=1;
        }
        v[i+1]=chave;
    }
}

int main(){
    int *v, n;

    carregarVetor("Vetor_64.bin",&v,&n);
    struct timeval begin,end;

    gettimeofday(&begin,0);
    insertion_sort(v,n);
    gettimeofday(&end,0);
    free(v);

    carregarVetor("Vetor_64.bin",&v,&n);
    insertion_sort_comp(v,n);
    free(v);

    gerarRelatorio("InsertionSort-Teste-1","Aleatorio",n,(long)(end.tv_usec-begin.tv_usec), (long)end.tv_sec - begin.tv_sec,totalComp,totalTroca);

    return 0;
}
