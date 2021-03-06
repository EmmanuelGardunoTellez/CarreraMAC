#Instalar librerias y habilitarlas
install.packages("tidyverse")
install.packages("ggplot2")
install.packages("moments")

library("tidyverse")
library("ggplot2")
library("moments")
library(readr)
library(stringr)

#(a) Cargar los datos
url <- 'https://raw.githubusercontent.com/fhernanb/datos/master/medidas_cuerpo'
datos <- read.table(file=url, header=T)
head(datos,10)  # Para ver tabla

#(b) Obtener la media de la variable b�ceps
mean(datos$biceps)

#(c) Obtener la media de la variable b�ceps por sexo
sapply(split(datos$biceps, datos$sexo), mean)

#(d) Obtener la mediana de la variable peso
median(datos$peso)

#(e) Obtener la mediana de la variable peso por sexo
sapply(split(datos$peso, datos$sexo), median)

#(f) Obtener la moda de la variable peso
tabla <- table(datos$peso)
m <- length(tabla)
sort(tabla)
names(sort(tabla)[m])




#(g) Obtener la desviacion est�ndar de la variable peso para hombres con altura mayor a 1.70 m �
sd(subset(datos$peso, datos$sexo=="Hombre",datos$altura>170))

#(h) Obtener la curtosis y el coeficiente de asimetr�a de la variable muneca ~
#asimetria
skewness(datos$muneca)
#curtosis
kurtosis(datos$muneca)

#(i) Realizar un histograma de la variable mu�eca
hist(datos$muneca, col = "green", main = "histograma de tama�o de mu�eca")


#(j) Realizar una grafica de barras de las personas con peso mayor a 70 kg por sexo �
x <- factor(subset(datos$sexo, datos$peso > 70))
levels(x) <- c("Hombre","Mujer")
datosGenero <- table(x)
barplot(datosGenero, ylab = "cantidad", col = c("blue", "red"),main = "Cantidad de Hombre y Mujeres con peso mator a 70")

#(k) Realizar una grafica de pastel de las personas con peso mayor a 70 kg por sexo

pie(datosGenero, ylab = "cantidad", col = c("blue", "red"),main = "Cantidad de Hombre y Mujeres con peso mator a 70")

s <- c(4,2,0,9,4,2,-1,1,-4,2)

mean(s)
median(s)
modes(s)
tabla2 <- table(s)
m <- length(tabla2)
names(sort(tabla2)[m])


