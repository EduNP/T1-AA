// A função rearranja o vetor v[p..r], com p <= r+1,
// de modo que ele fique em ordem crescente.
#include<stdio.h>
#include<stdlib.h>
int main(){
   int op,n=10;
   int v[10]={50,10,40,20,60,70,80,8,9,10};
   printf("1-Quicksort aleatorio\n2-QuickSort normal\nOpcao:");
   scanf("%d",&op);
   quicksort(v,0,n-1,op);
   for(int i=0;i<n;i++)
      printf("%d ",v[i]);
}
int separa (int v[], int p, int r) {
   int c = v[r]; // pivô
   int t, j = p;
   for (int k = p; /*A*/ k < r; ++k)
      if (v[k] <= c) {
         t = v[j], v[j] = v[k], v[k] = t;
         ++j; 
      } 
   t = v[j], v[j] = v[r], v[r] = t;
   return j; 
}
int separa_aleatorio (int v[], int p, int r) {
   int i=rand()%(r+1);
   int c = v[i]; // pivô
   int t, j = p;
   for (int k = p; /*A*/ k < r; ++k)
      if (v[k] <= c) {
         t = v[j], v[j] = v[k], v[k] = t;
         ++j; 
      } 
   t = v[j], v[j] = v[r], v[r] = t;
   return j; 
}
void quicksort (int v[], int p, int r,int op){
   int j;
   if (p < r) {                   
      if(op==1)  j=separa_aleatorio(v,p,r);
      else j = separa (v, p, r);   
      quicksort (v, p, j-1,op);      
      quicksort (v, j+1, r,op);     
   }
}