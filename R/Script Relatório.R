#alterar opcao de acordo com o algoritmo
op <-2     

library(readr)
switch(op,
       "1" = {dados <- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Selection Sort/Selection Sort.csv")
              nomeFile<- "Selection Sort"},
       
       "2" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Insertion Sort/Insertion Sort.csv")
              nomeFile<- "Insertion Sort"},
       
       "3" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Merge Sort/Merge Sort.csv")
              nomeFile<- "Merge Sort"},
       
       "4" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Heap Sort/Heap Sort.csv")
              nomeFile<- "Heap Sort"},
       
       "5" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Quick Sort Pivo Aleatorio/Quick Sort Pivo Aleatorio.csv")
              nomeFile<- "Quick Sort Pivo Aleatorio"},
       
       "6" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Quick Sort Pivo Fixo/Quick Sort Pivo Fixo.csv")
              nomeFile<- "Quick Sort Pivo Fixo"},
       
       stop("op��o inv�lida")
)
#somar total de segundo*1000000 + Microsegundos
dados$'Tempo total' = dados$`Tempo de execu��o (microsec)` + (1000000*dados$`Tempo de execu��o (sec)`)

#dados = subset(dados, Condi��o == 'aleatorio')
#nome = bquote(.(nomeFile)~"- Vetores Aleat�rios")

dados = subset(dados, Condi��o == 'ordem-decrescente')
nome = bquote(.(nomeFile)~"- Vetores Ordem Decrescente")

#dados = subset(dados, Condi��o == 'ordem-crescente')
#nome = bquote(.(nomeFile)~"- Vetores Ordem Crescente")

plot(dados$`Tamanho do vetor`, dados$`Tempo de execu��o (microsec)`, xlab = "Tamanho do vetor", ylab = "Tempo de execu��o (microsegundos)", main = nome)
plot(dados$`Tamanho do vetor`, dados$`Trocas realizadas`, xlab = "Tamanho do vetor", ylab = "N�mero de trocas", main = nome)
plot(dados$`Tamanho do vetor`, dados$`Compara��es realizadas`, xlab = "Tamanho do vetor", ylab = "N�mero de compara��es", main = nome)

##TEMPOS DE EXECU��O
library(dplyr)
graph<- aggregate(dados$'Tempo total', list(dados$`Tamanho do vetor`), FUN = mean)
#plot das m�dias
plot(graph, xlab = "Tamanho do vetor", ylab = "Tempo de execu��o (microsegundos)", main = bquote(.(nome) ~"- M�dias"))


plot(graph, xlab = "Tamanho do vetor", ylab = "Tempo de execu��o (microsegundos)", main = bquote(.(nome) ~""), pch = 18, col = "gray",xlim=c(0,10000),ylim=c(0,60000))

##MUDAR FUN��O pior caso
par(new = TRUE)
curve(x^2, from = 0, to = 10000, axes = FALSE, col = "red", ylab = "", xlab = "",lwd=2,xlim=c(0,10000),ylim=c(0,60000))

##MUDAR FUN��O melhor CASO
par(new = TRUE)
curve(x^1, from = 0, to = 10000, axes = FALSE,lwd=2, ylab = "", xlab = "" ,col = "green",xlim=c(0,10000),ylim=c(0,60000))
