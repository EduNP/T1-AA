void mergesort_i (int n, int v[]){
   int b = 1;
   while (b < n) {
      int p = 0;
      while (p + b < n) {
         int r = p + 2*b;
         if (r > n) r = n;
         intercala (p, p+b, r, v);
         p = p + 2*b; 
      }
      b = 2*b;
   }
}