#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <math.h>

void gerarVetor(int tamanho, int max){

    int valor=0;

    char nome[50];

    sprintf(nome,"..\\Vetores\\Vetor_%d.bin",tamanho);

    FILE* arquivo = fopen(nome,"wb");

    valor = rand() % max;

    srand(time(0));

    fwrite(&tamanho, sizeof(tamanho),1,arquivo);

    for(int c=0;c<tamanho+1; c++){

        fwrite(&valor,sizeof(valor),1,arquivo);
        
        valor = rand() & max;

    }

    fclose(arquivo);

}

void carregarVetor(char* nome, int** vetor, int* tamanho){

    char novoNome[50];

    sprintf(novoNome,"..\\Vetores\\%s",nome);

    FILE* arquivo = fopen(novoNome,"rb");

    int contador = 0;

    fread(tamanho,sizeof(tamanho),1,arquivo);

    *vetor = (int* ) malloc(sizeof(int)*(*tamanho));

    fread(*vetor,sizeof(int),*tamanho,arquivo);

    fclose(arquivo);

}

void alterarVetor(char *nome, int* vetor, int tamanho){

    sprintf(nome,"..\\Vetores\\%s",nome);

    FILE* arquivo = fopen(nome,"r+b");

    fseek(arquivo,0,0);

    fwrite(&tamanho, sizeof(tamanho), 1, arquivo);

    fwrite(vetor,sizeof(int), tamanho, arquivo);

    fclose(arquivo);

}

//ADICIONAR CASOS PIORES E MELHORES
// int main(void){

//     // gerarVetor(pow(2,3),INT_MAX);
//     // gerarVetor(pow(3,3),INT_MAX);
//     // gerarVetor(pow(5,3),INT_MAX);
//     // gerarVetor(pow(7,3),INT_MAX);
//     // gerarVetor(pow(2,6),INT_MAX);
//     // gerarVetor(pow(3,6),INT_MAX);
//     // gerarVetor(pow(5,6),INT_MAX);
//     // gerarVetor(pow(7,6),INT_MAX);

//     int valor = 10;

//     while(valor <= 10000){

//         gerarVetor(valor,INT_MAX);

//         valor += 10;

//     }
    
//     return 0;
// }