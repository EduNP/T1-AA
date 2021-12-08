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
op <-3
menu(op)

switch(op,
       "1" = {arq<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Selection Sort/Selection Sort.csv")
              nome<- "Selection_Sort"},
       
       "2" = {arq<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Insertion Sort/Insertion Sort.csv")
              nome<- "Insertion_Sort"},
       
       "3" = {arq<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Merge Sort/Merge Sort.csv")
              nome<- "Merge_Sort"},
       
       "4" = {arq<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Heap Sort/Heap Sort.csv")
              nome<- "Heap_Sort"},
       
       "5" = {arq<- read_csv("~/GitHub/T1-AA/Relatorio/Resultados/Quick Sort/Quick Sort.csv")
              nome<- "Quick_Sort"},
       
       stop("opção inválida")
)
 

plot(arq$`Tamanho do vetor`, arq$`Tempo de execução (microsec)`, 
     xlab = "Tamanho do vetor", ylab = "Tempo de execução", 
     main = nome)
