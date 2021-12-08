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

#alterar opcao de acordo com o algoritmo
op <-3     
menu(op)

switch(op,
       "1" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Selection Sort/Selection Sort.csv")
              nome<- "Selection_Sort"},
       
       "2" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Insertion Sort/Insertion Sort.csv")
              nome<- "Insertion_Sort"},
       
       "3" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Merge Sort/Merge Sort.csv")
              nome<- "Merge_Sort"},
       
       "4" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Heap Sort/Heap Sort.csv")
              nome<- "Heap_Sort"},
       
       "5" = {dados<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Quick Sort/Quick Sort.csv")
              nome<- "Quick_Sort"},
       
       stop("opção inválida")
)
 

plot(dados$`Tamanho do vetor`, dados$`Tempo de execução (microsec)`, 
     xlab = "Tamanho do vetor", ylab = "Tempo de execução", 
     main = nome)

#tempo de execução:
x <- dados$`Tempo de execução (microsec)`
#Média:
mean(x)
#Desvio padrão:
sd(x)
#Variância:
var(x)

#Comparações realizadas:
x<- dados$`Comparações realizadas`
#Média:
mean(x)
#Desvio padrão:
sd(x)
#Variância:
var(x)

#Trocas realizadas:
x <- dados$`Trocas realizadas`
#Média:
mean(x)
#Desvio padrão:
sd(x)
#Variância:
var(x)



#Média:   
library(dplyr)

graph<- aggregate(dados$`Tempo de execução (microsec)`, list(dados$`Tamanho do vetor`), FUN = mean)
plot(graph, 
     xlab = "Tamanho do vetor", ylab = "Tempo de execução", 
     main = nome)
plot(graph$Group.1, graph$x, pch=19,xlab = "Tamanho do vetor", ylab = "Tempo de execução", xlim=c(0,1000), ylim=c(0,250), main='')

dados %>%
  group_by(dados$`Tamanho do vetor`) %>%
  summarise_at(vars(dados$`Tempo de execução (microsec)`), list(name = mean))

#print(dados)

