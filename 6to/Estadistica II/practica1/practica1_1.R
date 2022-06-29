#Instalar librerias y habilitarlas
install.packages("tidyverse")
install.packages("ggplot2")
install.packages("moments")
install.packages("car")
library("tidyverse")
library("ggplot2")
library("moments")
library(readr)
library(car)

#Asignar la carpeta del trabajo
getwd()
setwd("C:\\Users\\Emman\\Documents\\CCH-N} FES-A\\fessaa\\FES\\6to Semestre\\Estadistica II\\practica1")
list.files()


library(readr)
Transporte <- read_delim("~/CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Transporte.csv", 
                         ";", escape_double = FALSE, locale = locale(decimal_mark = ",", 
                                                                     grouping_mark = "."), trim_ws = TRUE)
View(Transporte)


print(Transporte)

#Forma1
tapply(Transporte$GASTO,Transporte$SEXO,summary)
res=wilcox.test(GASTO~SEXO,data = Transporte, exact=FALSE)
res$p.value


#forma2
rango <-rank(Transporte$GASTO)
cbind(Transporte,rango)
hombres <- subset(Transporte, SEXO == "H")$GASTO
mujeres <- subset(Transporte, SEXO == "M")$GASTO
wilcox.test(hombres, mujeres)
wilcox.test(mujeres,hombres)


#----------------------------------------------------------------------------------------------------------
Edad_ingreso_sem <- read_csv("~/CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Edad_ingreso_sem.csv")
View(Edad_ingreso_sem)


AnioNacimiento <- substr(Edad_ingreso_sem$RFC, start = 5, stop = 6)
AnioNacimiento
mode(AnioNacimiento)<-"numeric"
AnioNacimiento2 <- (1900+AnioNacimiento)
AnioNacimiento2

AnioIngreso <- substr(Edad_ingreso_sem$FECHA_INGRESO, start = 7, stop = 10)
mode(AnioIngreso) <- "numeric"
AnioIngreso

EdadIngreso <- c(AnioIngreso- AnioNacimiento2)
EdadIngreso

Edad_ingreso_sem2 <- Edad_ingreso_sem %>% mutate (EdadDeIngreso = EdadIngreso)
Edad_ingreso_sem2
View(Edad_ingreso_sem2)
