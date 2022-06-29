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


#leer datos problema 1
library(readr)
Transporte <- read_delim("~/CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Transporte.csv", 
                         ";", escape_double = FALSE, locale = locale(decimal_mark = ",", 
                                                                     grouping_mark = "."), trim_ws = TRUE)
#Obtener Mann-Whitney
rango <-rank(Transporte$GASTO)
cbind(Transporte,rango)
hombres <- subset(Transporte, SEXO == "H")$GASTO
mujeres <- subset(Transporte, SEXO == "M")$GASTO
wilcox.test(hombres, mujeres)
wilcox.test(mujeres,hombres)

#problema 2

library(readr)
Desplazamientos <- read_delim("CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Desplazamientos.csv", 
                              ";", escape_double = FALSE, trim_ws = TRUE)

View(Desplazamientos)
rangoDesplazamiento <- rank(Desplazamientos$Tiempo)
cbind(Desplazamientos,rangoDesplazamiento)
publico <- subset(Desplazamientos, Transporte == "Publico")$Tiempo
privado <- subset(Desplazamientos, Transporte == "Privado")$Tiempo
wilcox.test(publico,privado)

# problma 3

#leer datos problema 2, nota separados por ",", conseguir y arreglar las fechas
Edad_ingreso_sem = read.table("~/CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Edad_ingreso_sem.csv", sep=",", header=1)
Edad_ingreso_sem$FECHA_INGRESO <- ifelse(Edad_ingreso_sem$FECHA_INGRESO == '01/15/2010', c('15/01/2010'),Edad_ingreso_sem$FECHA_INGRESO)
Edad_ingreso_sem$RFC <- substr(Edad_ingreso_sem$RFC, start = 5, stop = 11) 
mode(Edad_ingreso_sem$RFC)<-"numeric"
Edad_ingreso_sem$RFC <-as.Date(str_replace(Edad_ingreso_sem$RFC,"(\\d{1,2})(\\d{1,2})(\\d{1,2})","19\\1/\\2/\\3"), format =  "%Y/%m/%d")
Edad_ingreso_sem$FECHA_INGRESO <- as.Date(Edad_ingreso_sem$FECHA_INGRESO, format="%d/%m/%Y")
edad_decimal <- (Edad_ingreso_sem$FECHA_INGRESO-Edad_ingreso_sem$RFC)
edad_decimal2 <- (edad_decimal/365)
Edad_ingreso_sem2 <- Edad_ingreso_sem %>% mutate (EdadFraccion = edad_decimal2)
#NOTA: EdadFraccion debe ser tipo caracter
Edad_ingreso_sem2$EdadFraccion <- as.numeric(Edad_ingreso_sem2$EdadFraccion)
rango2 <-rank(Edad_ingreso_sem2$EdadFraccion)
Edad_ingreso_sem2<- cbind(Edad_ingreso_sem2,rango2)
hombres2 <- subset(Edad_ingreso_sem2, GENERO == "H")$EdadFraccion
mujeres2 <- subset(Edad_ingreso_sem2, GENERO == "M")$EdadFraccion
par(mfrow = c(1, 1))
plot(density(hombres2), col = "red", lwd = 3, main = "Distribibion de densidad Hobres y Mujeres",
     xlab = "Edad", ylab = "densidad")
lines(density(mujeres2), col = "blue", lwd = 3)
legend("topleft", lwd = 2, col = c("blue","red"),
       legend = c("Mujeres", "Hombres" ))






wilcox.test(mujeres2,hombres2)
#otro metod para sacar Mann
mode(Edad_ingreso_sem2$EdadFraccion)<-"numeric"
tapply(Edad_ingreso_sem2$EdadFraccion,Edad_ingreso_sem2$GENERO,summary)
res=wilcox.test(EdadFraccion~GENERO,data = Edad_ingreso_sem2, exact=FALSE)
res$p.value

#problema 3

Gastotabaco <- read_delim("CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Gastotabaco.csv", 
                          ";", escape_double = FALSE, trim_ws = TRUE)
View(Gastotabaco)

plot(x = Gastotabaco$EDAD,y= Gastotabaco$GASTO)
