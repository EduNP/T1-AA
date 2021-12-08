#include <stdio.h>
#include <sys/time.h>
#include "..\Gerador\Gerador.c"
#include "..\Relatorio\Relatorio.c"

int totalComp = 0;
int totalTroca = 0;

//versão para medir trocas e comparações
void selection_sort_comp(int vetor[],int max) {
  int i, j, min, aux;
  
  for (i = 0; i < (max - 1); i++) {
    min = i;
    for (j = i+1; j < max; j++) {
      if (vetor[j] < vetor[min]) {
            min = j;
      }
      totalComp++;
    }
    if (i != min) {
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
        totalTroca++;
    }
  }
}

void selection_sort (int vetor[],int max) {
  int i, j, min, aux;
  
  for (i = 0; i < (max - 1); i++) {
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
    for (j = i+1; j < max; j++) {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vetor[j] < vetor[min]) {
            min = j;
      }
    }
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
    if (i != min) {
        aux = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = aux;
    }
  }
}

int main (int argv, char* argc[]) {
  int *v, n;

  carregarVetor(argc[1],&v,&n);
  struct timeval begin,end;

  gettimeofday(&begin,0);
  selection_sort(v, n);
  gettimeofday(&end,0);
  free(v);
  
  carregarVetor(argc[1],&v,&n);
  selection_sort_comp(v,n);
  free(v);

  long resultMicro = end.tv_usec-begin.tv_usec;
      if(resultMicro < 0)
        resultMicro += 1000000;
  gerarRelatorio("Selection Sort","Aleatorio",n,resultMicro, (long)end.tv_sec - begin.tv_sec,totalComp,totalTroca);
}