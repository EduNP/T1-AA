#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "..\Gerador\Gerador.c"
#include "..\Relatorio\Relatorio.c"

int totalComp = 0;
int totalTroca = 0;

void Intercala_comp(int *v, int p, int q, int r) {
   int tempVect[r-p];
   for(int i = p; i < q; i++)
      tempVect[i-p] = v[i];
   
   for(int j  = q; j < r;j++)
      tempVect[r-p+q-j-1] = v[j];

   int iniPos = 0;
   int endPos = r-p-1;
   for(int k = p; k < r; k++){
      if(tempVect[iniPos] <= tempVect[endPos])
         v[k] = tempVect[iniPos++];
      else
         v[k] = tempVect[endPos--];
      totalTroca++;
      totalComp++;
   }
}

void Mergesort_comp(int *v,int p,int r){
   if(p < r-1){
      int q = (p+r)/2;
      Mergesort_comp(v,p,q);
      Mergesort_comp(v,q,r);
      Intercala_comp(v,p,q,r);
   }
}


void Intercala(int *v, int p, int q, int r) {

   int tempVect[r-p];
   for(int i = p; i < q; i++)
      tempVect[i-p] = v[i];
   
   for(int j  = q; j < r;j++)
      tempVect[r-p+q-j-1] = v[j];

   int iniPos = 0;
   int endPos = r-p-1;
   for(int k = p; k < r; k++){
      if(tempVect[iniPos] <= tempVect[endPos])
         v[k] = tempVect[iniPos++];
      else
         v[k] = tempVect[endPos--];
      
   }
}

void Mergesort(int *v,int p,int r){
   if(p < r-1){
      int q = (p+r)/2;
      Mergesort(v,p,q);
      Mergesort(v,q,r);
      Intercala(v,p,q,r);
   }
}

int main(){
   int *v, n;

   carregarVetor("Vetor_64.bin",&v,&n);
   struct timeval begin,end;

   gettimeofday(&begin,0);
   Mergesort(v,0,n);
   gettimeofday(&end,0);
   free(v);

   carregarVetor("Vetor_64.bin",&v,&n);
   Mergesort_comp(v,0,n);
   free(v);

   gerarRelatorio("MergeSort-Teste-1","Aleatorio",n,(long)(end.tv_usec-begin.tv_usec), (long)end.tv_sec - begin.tv_sec,totalComp,totalTroca);

   return 0;
}