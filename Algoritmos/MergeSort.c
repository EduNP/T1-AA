#include <stdio.h>
#include <stdlib.h>

void Intercala(int *v, int p, int q, int r) {
   int temp[r-p+1];

	int i = p, j = q+1, k = 0;

	while(i <= q && j <= r) {
		if(v[i] <= v[j]) {
			temp[k] = v[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = v[j];
			k += 1; j += 1;
		}
	}

	while(i <= q) {
		temp[k] = v[i];
		k += 1; i += 1;
	}

	while(j <= r) {
		temp[k] = v[j];
		k += 1; j += 1;
	}

	for(i = p; i <= r; i += 1) {
		v[i] = temp[i - p];
	}
}

void Mergesort(int *v,int p,int r,int tam){
   int q;

   if (p < r) {  
   q = (p+r)/2;
   Mergesort(v, p, q,tam);
   Mergesort(v, q+1, r,tam);
   Intercala(v, p, q, r);
   }else{
      for(int i=0;i<tam;i++){
         printf("%d ",v[i]);
      }
      return;
   }
}

int main(){
   int i,inicio, fim,tam,*vet;
   scanf("%d",&tam);
   vet = (int *) malloc(tam * sizeof(int));
   
   for (i = 0; i <tam; i++) {
    scanf ("%d",&vet[i]);
  }
  inicio = vet[0];
  fim = vet[tam-1];
  Mergesort(vet,inicio,fim,tam);
  free(vet);
}