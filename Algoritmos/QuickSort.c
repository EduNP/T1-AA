#include<stdio.h>
#include <sys/time.h>
#include "..\Gerador\Gerador.c"
#include "..\Relatorio\Relatorio.c"

int totalComp = 0;
int totalTroca = 0;

//caso com pivo aleatório -- comparar
int separa_aleatorio_comp(int v[], int p, int r) {
   int i=rand()%(r+1);
   int c = v[i]; // pivô
   int t, j = p;

   for (int k = p; /*A*/ k < r; ++k){
      if (v[k] <= c) {
         t = v[j];
         v[j] = v[k];
         v[k] = t;
         ++j; 
         totalTroca++;
      } 
      totalComp++;
   }

   t = v[j];
   v[j] = v[r];
   v[r] = t;
   totalTroca++;
   return j; 
}

void quicksort_aleatorio_comp(int v[], int p, int r){
   int j;
   if (p < r) {                   
      j = separa_aleatorio_comp(v, p, r);   
      quicksort_aleatorio_comp(v, p, j-1);      
      quicksort_aleatorio_comp(v, j+1, r);     
   }
}

//caso com pivo aleatório
int separa_aleatorio (int v[], int p, int r) {
   int i=rand()%(r+1);
   int c = v[i]; // pivô
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

void quicksort_aleatorio (int v[], int p, int r){
   int j;
   if (p < r) {                   
      j = separa_aleatorio(v, p, r);   
      quicksort_aleatorio(v, p, j-1);      
      quicksort_aleatorio(v, j+1, r);     
   }
}

//pior caso -- pivo fixo
int separa_comp(int v[], int p, int r) {
   int c = v[r]; // pivô
   int t, j = p;
   for (int k = p; /*A*/ k < r; ++k){
      if (v[k] <= c) {
         t = v[j];
         v[j] = v[k];
         v[k] = t;
         ++j; 
          totalTroca++;
      } 
      totalComp++;
   }
   t = v[j];
   v[j] = v[r];
   v[r] = t;
   totalTroca++;
   return j; 
}

void quicksort_comp(int v[], int p, int r){
   int j;
   if (p < r) {                   
      j = separa_comp(v, p, r);   
      quicksort_comp(v, p, j-1);      
      quicksort_comp(v, j+1, r);     
   }
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

int main(int argv, char* argc[]){
    int *v, n;
// pivo aleatorio
     carregarVetor(argc[1],&v,&n);
    struct timeval begin,end;

     gettimeofday(&begin,0);
     quicksort_aleatorio(v,0,n-1);
     gettimeofday(&end,0);
     free(v);

     carregarVetor(argc[1],&v,&n);
     quicksort_aleatorio_comp(v,0,n-1);
     free(v);

    
     long resultMicro = end.tv_usec-begin.tv_usec;
     if(resultMicro < 0)
        resultMicro += 1000000;

     gerarRelatorio("Quick Sort Pivo Aleatorio",argc[2],n,resultMicro, (long)end.tv_sec - begin.tv_sec,totalComp,totalTroca);


/// Analise pior caso
   totalComp = 0;
   totalTroca = 0;

   carregarVetor(argc[1],&v,&n);
   gettimeofday(&begin,0);
   quicksort(v,0,n-1);
   gettimeofday(&end,0);
   free(v);
   
   carregarVetor(argc[1],&v,&n);
   quicksort_comp(v,0,n-1);
   free(v);

   resultMicro = end.tv_usec-begin.tv_usec;
   if(resultMicro < 0)
      resultMicro += 1000000;
   gerarRelatorio("Quick Sort Pivo Fixo",argc[2],n,resultMicro, (long)end.tv_sec - begin.tv_sec,totalComp,totalTroca);

    return 0;
}