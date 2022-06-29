setwd("C:/Users/Emman/Documents/CCH-N} FES-A/fessaa/FES/7mo semestre/Temas Selectos de Estadistica")


library(MASS)
library(ggplot2)
library(plotly)


fx<-function(x,a){
  (1/(2*a))*exp(-sqrt(x*x)/a)
  
}
a <- 1
x<- seq(-5,5,0.01)
plot(x,fx(x,a),type="l",col="red", xlim = c(-5,5), ylim = c(0,1), lwd=2)
n<- 5000
k<- 0   # contador para aceptar valores
j<- 0  # contador de iteraciones necesarias para generar las "n" variables
y<- numeric(n)

while(k< n){
  u= runif(1)
  j= j+1  
  x= runif(1)
  if(u < .5){ 
    k= k+1
    y[k]= -a*log(x)
  }else{
    k=k+1
    y[k]= a*log(x)
  }  
}		
j #Numero de intentos para obtener los ",n, " números aleatorios

hist(y,probability = T,col="gray50",ylim = c(0,0.5))  # histograma de las variables simuladas
curve(fx(x,a),col="darkblue", lwd=2, add=TRUE, yaxt="n")   # curva teorica