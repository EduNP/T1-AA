#include <stdio.h>

void gerarRelatorio(char* nome, char* condicao, int tamanhoVetor, long tempoMicroSec, long tempoSec, int comparacoes, int trocas){

    char novoNome[50];
    sprintf(novoNome,"..\\Relatorio\\%s",nome);

    FILE* arquivo = fopen(novoNome,"a+");

    fprintf(arquivo,"Algoritmo:                    %s\nCondição:                     %s\nTamanho do vetor:             %d\nTempo de execução (microsec): %ld\nTempo de execução (sec):      %ld\nComparações realizadas:       %d\nTrocas realizadas:            %d\n\n", nome, condicao, tamanhoVetor, tempoMicroSec, tempoSec,comparacoes, trocas);

    fclose(arquivo);

}

//   int main(void){


//       gerarRelatorio("Merge Sort","Totalmente desordenado",10,27,30,500,1000);

//       return 0;
//   }