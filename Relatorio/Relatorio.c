#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

void gerarRelatorioTxt(char* nome, char* condicao, int tamanhoVetor, long tempoMicroSec, long tempoSec, int comparacoes, int trocas){

    char novoNome[100];

    sprintf(novoNome,"..\\Relatorio\\Resultados\\%s\\%s.txt",nome, nome);

    FILE* arquivo = fopen(novoNome,"a+");

    fprintf(arquivo,"Algoritmo:                    %s\nCondição:                     %s\nTamanho do vetor:             %d\nTempo de execução (microsec): %ld\nTempo de execução (sec):      %ld\nComparações realizadas:       %d\nTrocas realizadas:            %d\n\n", nome, condicao, tamanhoVetor, tempoMicroSec, tempoSec,comparacoes, trocas);

    fclose(arquivo);

}

void gerarRelatorioCsv(char* nome, char* condicao, int tamanhoVetor, long tempoMicroSec, long tempoSec, int comparacoes, int trocas){

    char novoNome[100];

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

void gerarRelatorioGeralTxt(char* nome, char* condicao, int tamanhoVetor, long tempoMicroSec, long tempoSec, int comparacoes, int trocas){

    char novoNome[100];

    sprintf(novoNome,"..\\Relatorio\\Resultados\\Geral\\Geral.txt");

    FILE* arquivo = fopen(novoNome,"a+");

    fprintf(arquivo,"Algoritmo:                    %s\nCondição:                     %s\nTamanho do vetor:             %d\nTempo de execução (microsec): %ld\nTempo de execução (sec):      %ld\nComparações realizadas:       %d\nTrocas realizadas:            %d\n\n", nome, condicao, tamanhoVetor, tempoMicroSec, tempoSec,comparacoes, trocas);

    fclose(arquivo);

}

void gerarRelatorioGeralCsv(char* nome, char* condicao, int tamanhoVetor, long tempoMicroSec, long tempoSec, int comparacoes, int trocas){

    char novoNome[100];

    sprintf(novoNome,"..\\Relatorio\\Resultados\\Geral\\Geral.csv");

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
    
    gerarRelatorioGeralTxt(nome,condicao,tamanhoVetor,tempoMicroSec,tempoSec,comparacoes,trocas);

    gerarRelatorioCsv(nome,condicao,tamanhoVetor,tempoMicroSec,tempoSec,comparacoes,trocas);

    gerarRelatorioGeralCsv(nome,condicao,tamanhoVetor,tempoMicroSec,tempoSec,comparacoes,trocas);

}

void explodirBombaAtomica(int max){

    char comando[100];

    int valor = 10;

    DIR* diretorio;

    struct dirent* dir;

    diretorio = opendir("..\\Algoritmos");

    if(diretorio){

        while(dir = readdir(diretorio)){

            if(dir->d_name[0] != '.' && dir->d_name[dir->d_namlen-1] == 'e'){

                while(valor <= max){

                    sprintf(comando,"..\\Algoritmos\\%s Vetor_%d.bin",dir->d_name,valor);

                    printf("%s\n",comando);

                    system(comando);

                    valor+=10;

                }

                valor=10;


            }

        }

        closedir(diretorio);

    }

}

int main(void){

    explodirBombaAtomica(10000);

    return 0;
}