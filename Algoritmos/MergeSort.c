void mergesort_i (int *v,int tam){
    int b = 1;
    while (b < tam) {
        int p = 0;
        while (p + b < tam) {
            int r = p + 2*b;
            if (r > tam) 
                r = tam;
            intercala (p, p+b, r, v);
            p = p + 2*b; 
        }
    b = 2*b;
   }
}