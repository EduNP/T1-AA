#include <stdio.h>

void gerarRelatorioTxt(char* nome, char* condicao, int tamanhoVetor, long tempoMicroSec, long tempoSec, int comparacoes, int trocas){

    char novoNome[50];
    
    sprintf(novoNome,"..\\Relatorio\\Resultados\\%s\\%s.txt",nome, nome);

    FILE* arquivo = fopen(novoNome,"a+");

    fprintf(arquivo,"Algoritmo:                    %s\nCondição:                     %s\nTamanho do vetor:             %d\nTempo de execução (microsec): %ld\nTempo de execução (sec):      %ld\nComparações realizadas:       %d\nTrocas realizadas:            %d\n\n", nome, condicao, tamanhoVetor, tempoMicroSec, tempoSec,comparacoes, trocas);

    fclose(arquivo);

}

void gerarRelatorioCsv(char* nome, char* condicao, int tamanhoVetor, long tempoMicroSec, long tempoSec, int comparacoes, int trocas){

    char novoNome[50];

    sprintf(novoNome,"..\\Relatorio\\Resultados\\%s\\%s.csv",nome, nome);

    FILE* arquivo = fopen(novoNome,"r");

    if(arquivo == NULL){

        fclose(arquivo);

        arquivo = fopen(novoNome,"w");

        fprintf(arquivo,"Algoritmo,Condição,Tamanho do vetor,Tempo de execução (microsec),Tempo de execução (sec),Comparações realizadas,Trocas realizadas");

    }
        
    fclose(arquivo);

    arquivo = fopen(novoNome,"a+");

    fprintf(arquivo,"\n%s,%s,%d,%ld,%ld,%d,%d", nome, condicao, tamanhoVetor, tempoMicroSec, tempoSec,comparacoes, trocas);

    fclose(arquivo);

}

void gerarRelatorio(char* nome, char* condicao, int tamanhoVetor, long tempoMicroSec, long tempoSec, int comparacoes, int trocas){

    gerarRelatorioTxt(nome,condicao,tamanhoVetor,tempoMicroSec,tempoSec,comparacoes,trocas);

    gerarRelatorioCsv(nome,condicao,tamanhoVetor,tempoMicroSec,tempoSec,comparacoes,trocas);

}


int main(void){

       gerarRelatorio("Merge Sort","Totalmente desordenado",10,2217,30,500,1000);
       gerarRelatorio("Quick Sort","Totalmente desordenado",10,2217,30,500,1000);

       return 0;
}