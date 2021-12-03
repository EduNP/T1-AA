#include <stdio.h>

void gerarRelatorioTeste(char* nome, char* condicao, int tamanhoVetor, int tempo, int comparacoes, int trocas){

    FILE* arquivo = fopen("RelatorioTeste.txt","a+");

    fprintf(arquivo,"Algoritmo: %s\nCondição: %s\nTamanho do vetor: %d\nTempo de execução: %ds\nComparações realizadas: %d\nTrocas realizadas: %d\n\n", nome, condicao, tamanhoVetor, tempo, comparacoes, trocas);

    fclose(arquivo);

}

int main(void){


    gerarRelatorio("Merge Sort","Totalmente desordenado",27,500,1000);

    return 0;
}