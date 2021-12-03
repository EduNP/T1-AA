// A função rearranja o vetor v[p..r], com p <= r+1,
// de modo que ele fique em ordem crescente.

void quicksort_it (int *v,int tam, int p, int r)
{
   int j, *pilhap, *pilhar, t;

   pilhap = malloc ((r-p+1) * sizeof (int));
   pilhar = malloc ((r-p+1) * sizeof (int));
   pilhap[0] = p; pilhar[0] = r; t = 0; 
   
   while (t >= 0) {      
      p = pilhap[t]; r = pilhar[t]; --t;
      if (p < r) {
         j = separa (v, p, r);    
         ++t; pilhap[t] = p; pilhar[t] = j-1; 
         ++t; pilhap[t] = j+1; pilhar[t] = r; 
      }
   }
}