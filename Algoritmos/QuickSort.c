// A função rearranja o vetor v[p..r], com p <= r+1,
// de modo que ele fique em ordem crescente.
void quicksort (int v[], int esq, int dir);
int particione(int v[],int esq,int dir);
void trocar(int v[],int i,int j);
int main(){
   int n=10;
   int v[10]={50,10,40,20,60,70,80,8,9,10};
   quicksort(v,0,n-1);
   for(int i=0;i<n;i++)
      printf("%d ",v[i]);
}
void quicksort (int v[], int esq, int dir){
   if(esq<dir){
      int j= particione(v,esq,dir);
      quicksort(v,esq,j-1);
      quicksort(v,j+1,dir);
   }
}
int particione(int v[],int esq,int dir){
   int i=esq+1;
   int j=dir;
   int pivo=v[esq];
   while (i<=j){
      if (v[i]<=pivo)i++;
      else if(v[j]>pivo)j++;
      else if(i<=j){
         trocar(v,i,j);
         i++;
         j--;
      }
   }
}
void trocar(int v[],int i,int j){
   int aux=v[i];
   v[i]=v[j];
   v[j]=aux;
}