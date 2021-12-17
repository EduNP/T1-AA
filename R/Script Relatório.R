#alterar opcao de acordo com o algoritmo
op <-1     

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
       
       stop("opï¿½ï¿½o invï¿½lida")
)
#somar total de segundo*1000000 + Microsegundos
dados$'Tempo total' = dados$`Tempo de execução (microsec)` + (1000000*dados$`Tempo de execução (sec)`)

dados1 = subset(dados, Condição == 'aleatorio')

#nome = bquote(.(nomeFile)~"- Vetores Aleatórios")

dados2 = subset(dados, Condição == 'ordem-decrescente')
#nome = bquote(.(nomeFile)~"- Vetores Ordem Decrescente")

dados3 = subset(dados, Condição == 'ordem-crescente')
#nome = bquote(.(nomeFile)~"- Vetores Ordem Crescente")


media <- mean(dados1$`Tempo total`)
desvio <- sd(dados1$`Tempo total`)
correlacaoPerson <- cor(dados1$`Tempo total`,dados1$`Tamanho do vetor`,method="pearson",use="complete.obs")
correlacaoSpearman <- cor(dados1$`Tempo total`,dados1$`Tamanho do vetor`,method="spearman",use="complete.obs")

print("Dados Aleatórios")
media
desvio
correlacaoPerson
correlacaoSpearman


media <- mean(dados2$`Tempo total`)
desvio <- sd(dados2$`Tempo total`)
correlacaoPerson <- cor(dados2$`Tempo total`,dados2$`Tamanho do vetor`,method="pearson",use="complete.obs")
correlacaoSpearman <- cor(dados2$`Tempo total`,dados2$`Tamanho do vetor`,method="spearman",use="complete.obs")

print("Dados ordem-decrescente")
media
desvio
correlacaoPerson
correlacaoSpearman



media <- mean(dados3$`Tempo total`)
desvio <- sd(dados3$`Tempo total`)
correlacaoPerson <- cor(dados3$`Tempo total`,dados3$`Tamanho do vetor`,method="pearson",use="complete.obs")
correlacaoSpearman <- cor(dados3$`Tempo total`,dados3$`Tamanho do vetor`,method="spearman",use="complete.obs")

print("Dados ordem-crescente")
media
desvio
correlacaoPerson
correlacaoSpearman

#coeficiente de variação
#cv <- function(x){coef<-sd(x)/mean(x)*100 
#      return(coef)}

#plot(dados$`Tamanho do vetor`, dados$`Tempo de execução (microsec)`, xlab = "Tamanho do vetor", ylab = "Tempo de execuï¿½ï¿½o (microsegundos)", main = nome)
#plot(dados$`Tamanho do vetor`, dados$`Trocas realizadas`, xlab = "Tamanho do vetor", ylab = "Nï¿½mero de trocas", main = nome)
#plot(dados$`Tamanho do vetor`, dados$`Comparaï¿½ï¿½es realizadas`, xlab = "Tamanho do vetor", ylab = "Nï¿½mero de comparaï¿½ï¿½es", main = nome)
##TEMPOS DE EXECUï¿½ï¿½O
#library(dplyr)
#graph<- aggregate(dados$'Tempo total', list(dados$`Tamanho do vetor`), FUN = mean)
#plot das médias
#plot(graph, xlab = "Tamanho do vetor", ylab = "Tempo de execução (microsegundos)", main = bquote(.(nome) ~"- Médias"))
#plot(graph, xlab = "Tamanho do vetor", ylab = "Tempo de execução (microsegundos)", main = bquote(.(nome) ~""), pch = 18, col = "gray",xlim=c(0,10000),ylim=c(0,60000))
##MUDAR Funções pior caso
#par(new = TRUE)
#curve(x^2, from = 0, to = 10000, axes = FALSE, col = "red", ylab = "", xlab = "",lwd=2,xlim=c(0,10000),ylim=c(0,60000))
##MUDAR Função melhor CASO
#par(new = TRUE)
#curve(x^1, from = 0, to = 10000, axes = FALSE,lwd=2, ylab = "", xlab = "" ,col = "green",xlim=c(0,10000),ylim=c(0,60000))
