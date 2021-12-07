#include <stdio.h>
#include <stdlib.h>
#include "..\Gerador\Gerador.c"
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
   int n;
   int* A;
     
   carregarVetor("Vetor_64.bin", &A, &n);
   Mergesort(A,0,n);
   
   free(A);
    
   return 0;
}