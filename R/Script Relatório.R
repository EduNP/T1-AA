#Script para analise estatistica relatório dos algoritmos de ordenação

#getwd()

menu=function(op){
  cat("Algoritmos:")
  cat("\n1 - Selection_Sort")
  cat("\n2 - Insertion_Sort")
  cat("\n3 - Merge_Sort:")
  cat("\n4 - Heap_Sort")
  cat("\n5 - Quick_Sort:")
  
}
menu(op)

#alterar opcao de acordo com o algoritmo
op <-2     

library(readr)
switch(op,
       "1" = {dados <- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Selection Sort/Selection Sort.csv")
              nome<- "Selection Sort"},
       
       "2" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Insertion Sort/Insertion Sort.csv")
              nome<- "Insertion Sort"},
       
       "3" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Merge Sort/Merge Sort.csv")
              nome<- "Merge Sort"},
       
       "4" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Heap Sort/Heap Sort.csv")
              nome<- "Heap Sort"},
       
       "5" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Quick Sort Pivo Aleatorio/Quick Sort Pivo Aleatorio.csv")
              nome<- "Quick Sort Pivo Aleatorio"},
       
       "6" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Quick Sort Pivo Fixo/Quick Sort Pivo Fixo.csv")
       nome<- "Quick Sort Pivo Fixo"},
       
       stop("opção inválida")
)
dados = subset(dados, Condição == 'aleatorio')
#dados = subset(dados, Condição == 'ordem-decrescente')
#dados = subset(dados, Condição == 'ordem-crescente')

plot(dados$`Tamanho do vetor`, dados$`Tempo de execução (microsec)`, 
     xlab = "Tamanho do vetor", ylab = "Tempo de execução", 
     main = nome)


library(dplyr)
graph<- aggregate(dados$`Tempo de execução (microsec)`, list(dados$`Tamanho do vetor`), FUN = mean)
#plot das médias
plot(graph, xlab = "Tamanho do vetor", ylab = "Tempo de execução", main = bquote(.(nome) ~"- Médias"))

#plot com comparação de O(N)
plot(graph, xlab = "Tamanho do vetor", ylab = "Tempo de execução", main = bquote(.(nome) ~"- Comparação"), pch = 18, col = "gray",xlim=c(0,10000),ylim=c(0,60000))

par(new = TRUE)
curve(x^2, from = 0, to = 10000, axes = FALSE, col = "red", ylab = "", xlab = "",lwd=2,xlim=c(0,10000),ylim=c(0,60000))

par(new = TRUE)
curve(x^1, from = 0, to = 10000, axes = FALSE,lwd=2, ylab = "", xlab = "" ,col = "green",xlim=c(0,10000),ylim=c(0,60000))


#plot do gráfico com escala detalhada
#plot(graph$Group.1, graph$x, pch=19,xlab = "Tamanho do vetor", ylab = "Tempo de execução", xlim=c(0,250), ylim=c(0,100), main=bquote(.(nome) ~"- Médias"))



#dados %>%
#  group_by(dados$`Tamanho do vetor`) %>%
#  summarise_at(vars(dados$`Tempo de execução (microsec)`), list(name = mean))

#print(dados)

##tempo de execução:
#x <- dados$`Tempo de execução (microsec)`
#Média:
#mean(x)
#Desvio padrão:
#sd(x)
#Variância:
#var(x)

#Comparações realizadas:
#x<- dados$`Comparações realizadas`
#Média:
#mean(x)
#Desvio padrão:
#sd(x)
#Variância:
#var(x)

#Trocas realizadas:
#x <- dados$`Trocas realizadas`
#Média:
#mean(x)
#Desvio padrão:
#sd(x)
#Variância:
#var(x)
