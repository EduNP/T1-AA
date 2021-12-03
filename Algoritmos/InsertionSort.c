#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int *v,int tam);  
// Função de Ordenação por Inserção
// Insertion sort function
int main(){
    int *v;
    int i,tam=10;
    insertion_sort(v,tam);
    for(i=0;i<tam;i++)
        printf("%d ",v[i]);
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