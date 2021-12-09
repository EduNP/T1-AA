#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <math.h>

void gerarVetor(int tamanho, int max){

    int valor=0;

    char nome[50];

    sprintf(nome,"..\\Vetores\\Vetor-aleatorio_%d.bin",tamanho);

    FILE* arquivo = fopen(nome,"w+b");

    srand(time(0));

    fwrite(&tamanho, sizeof(tamanho),1,arquivo);

    for(int c=0;c<tamanho; c++){

        valor = rand() % max;

        fwrite(&valor,sizeof(valor),1,arquivo);

    }

    fclose(arquivo);

}

void carregarVetor(char* nome, int** vetor, int* tamanho){

    char novoNome[100];

    sprintf(novoNome,"..\\Vetores\\%s",nome);

    FILE* arquivo = fopen(novoNome,"r+b");

    int contador = 0;

    fread(tamanho,sizeof(int),1,arquivo);

    *vetor = (int* ) malloc(sizeof(int)*(*tamanho));

    fread(*vetor,sizeof(int),*tamanho,arquivo);

    fclose(arquivo);

}

void alterarVetor(char *nome, int* vetor, int tamanho){

    char novoNome[100];

    sprintf(novoNome,"..\\Vetores\\%s",nome);

    FILE* arquivo = fopen(novoNome,"w+b");

    fwrite(&tamanho, sizeof(tamanho), 1, arquivo);

    fwrite(vetor,sizeof(int), tamanho, arquivo);

    fclose(arquivo);

}

int separa (int v[], int p, int r) {
   int c = v[r]; // pivô
   int t, j = p;
   for (int k = p; /*A*/ k < r; ++k)
      if (v[k] <= c) {
         t = v[j];
         v[j] = v[k];
         v[k] = t;
         ++j; 
      } 
   t = v[j];
   v[j] = v[r];
   v[r] = t;
   return j; 
}

void quicksort (int v[], int p, int r){
   int j;
   if (p < r) {                   
      j = separa (v, p, r);   
      quicksort (v, p, j-1);      
      quicksort (v, j+1, r);     
   }
}

void gerarVetores(int passo, int max){

    int valor = passo;

    while(valor <= max){

        gerarVetor(valor,INT_MAX);

        valor += passo;

    }
    

}

void ordenarVetores(int passo, int max){

    int valor = passo, *A, tamanho;

    char nome[100]; 

    while(valor <= max){

        sprintf(nome,"Vetor-aleatorio_%d.bin",valor);

        carregarVetor(nome,&A,&tamanho);

        quicksort(A,0,tamanho-1);

        sprintf(nome,"Vetor-ordenado_%d.bin",valor);

        alterarVetor(nome,A,tamanho);

        valor+=passo;

    }

}

void inversamenteOrdenarVetores(int passo, int max){

    char nome[100];

    int valor = passo, *A, tamanho, temp;

    while(valor <= max){

        sprintf(nome,"Vetor-ordenado_%d.bin",valor);

        carregarVetor(nome,&A,&tamanho);

        for(int c=0, j=tamanho-1;c<tamanho/2;c++,j--){

            temp = A[j];
            A[j] = A[c];
            A[c] = temp;

        }

        sprintf(nome,"Vetor-inversamente-ordenado_%d.bin",valor);

        alterarVetor(nome,A,tamanho);

        valor+=passo;

    }

}

int main(void){

    gerarVetores(10,10000);

    ordenarVetores(10,10000);

    inversamenteOrdenarVetores(10, 10000);

    return 0;

}