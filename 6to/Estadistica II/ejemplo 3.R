#Prueba K-S
install.packages("dplyr")
library(dplyr)

getwd() #Ver y seleccionar carpetas donde estan los archivos
setwd("CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II")
datos <- read.csv("hora_nacimientos.csv") #leemos el archivo
head(datos) #vista de datos

#funcios de val. absoluto
abs<-function(n){
  ifelse(n>0,n,n<-n*-1)
}

#Agregamos la columna Fn y Fx  a nuesrta tabla pero crearemos otra auxiliar
datos2=datos%>% mutate(Fn=row(datos)/37,Fx=Minutos/1440,"|Fn-Fx|"=abs(Fn-Fx)) 
datos2

#calculamos el maximo de "|Fn-Fx|"
a<-c(select(datos2,"|Fn-Fx|"))
b<-max(as.numeric(unlist(a)))

ndn<-sqrt(37)*b
print(ndn)