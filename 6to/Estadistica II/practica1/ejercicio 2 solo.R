library("stringr")
library(lubridate)
library(tidyverse)

install.packages("tidyverse")
install.packages("ggplot2")
install.packages("moments")
install.packages("car")
library("tidyverse")
library("ggplot2")
library("moments")
library(readr)
library(car)

a =  "~/CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Edad_ingreso_sem.csv"
#lee la tabla y pone como header los nombres que tiene y separa de ";"
data = read.table(a, sep=",", header=1)
#View(data)



data$FECHA_INGRESO <- ifelse(data$FECHA_INGRESO == '01/15/2010', c('15/01/2010'),data$FECHA_INGRESO)
data$RFC <- substr(data$RFC, start = 5, stop = 11) 
mode(data$RFC)<-"numeric"
data$RFC <-as.Date(str_replace(data$RFC,"(\\d{1,2})(\\d{1,2})(\\d{1,2})","19\\1/\\2/\\3"), format =  "%Y/%m/%d")

#data$FECHA_INGRESO <- as.Date(str_replace(data$FECHA_INGRESO,"(\\d{1,2})(\\d{1,2})(\\d{1,4})","\\1/\\2/\\3"), format =  "%d/%m/%Y")
data$FECHA_INGRESO <- as.Date(data$FECHA_INGRESO, format="%d/%m/%Y")


View(data)


edad_decimal <- c(data$FECHA_INGRESO-data$RFC)

edad_decimal2 <- (edad_decimal/365)

edad_decimal2

data <- (data)

Data2 <- data %>% mutate (EdadFraccion = edad_decimal2)

rango <-rank(Data2$EdadFraccion)
cbind(Data2,rango)
hombres <- subset(Data2, GENERO == "H")$EdadFraccion
mujeres <- subset(Data2, GENERO == "M")$EdadFraccion
wilcox.test(hombres, mujeres)
wilcox.test(mujeres,hombres)



tapply(Data2$EdadFraccion,Data2$GENERO,summary)
res=wilcox.test(GASTO~SEXO,data = Transporte, exact=FALSE)
res$p.value