library("tidyverse")
library("ggplot2")
library("moments")
library(readr)
library(car)
latex2exp
install.packages(latex2exp)
Transporte <- read_delim("~/CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Transporte.csv", 
                         ";", escape_double = FALSE, trim_ws = TRUE)
GastoMujeres <- subset(Transporte, SEXO=="M", select = c(GASTO, SEXO))
GastoHombres <- subset(Transporte, SEXO=="H", select = c(GASTO, SEXO))
GASTOS<-rbind(GastoHombres,GastoMujeres)
rangos1<- rank(GASTOS$GASTO)
GASTOS<-cbind(GASTOS, rangos1)
r1=0
r2=0
for(i in 1:length(GASTOS$GASTO)){
  if(GASTOS$SEXO[i]=="H") r1<-r1+(GASTOS$rangos1[i])
}
for(i in 1:length(GASTOS$GASTO)){
  if(GASTOS$SEXO[i]=="M") r2<-r2+(GASTOS$rangos1[i])
}
n1<-length(GastoHombres$GASTO)
n2<-length(GastoMujeres$GASTO)
U1 <- (n1*n2)+(n1*(n1+1)/2)-r1
U2 <- (n1*n2)+(n2*(n2+1)/2)-r2
U<- min(U1,U2)
U
Z<-(U-(n1*n2)/2)/(sqrt((n1*n2*(n1+n2+1)/12)))
abs(Z)
alfa=0.05
qnorm(1-(alfa)/2,0,1)
abs(Z)>qnorm(1-(alfa)/2,0,1)
#############################################################

Desplazamientos<-read.delim("CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Desplazamientos.csv", 
                             header = T, sep=";", dec=",")
DesplazamientosPublico<-subset(Desplazamientos, Transporte=="Publico",select = c(Tiempo, Transporte))
DesplazamientosPrivado<-subset(Desplazamientos, Transporte=="Privado", select = c(Tiempo, Transporte))
TIEMPOS<-rbind(DesplazamientosPublico,DesplazamientosPrivado)
TIEMPOS<-arrange(TIEMPOS, Tiempo)
rango2<-rank(TIEMPOS$Tiempo)
TIEMPOS<-cbind(TIEMPOS, rango2)
t1=0
t2=0
for(i in 1:length(TIEMPOS$Tiempo)){
  if(TIEMPOS$Transporte[i]=="Publico") t1<-t1+(TIEMPOS$rango2[i])
}
for(i in 1:length(TIEMPOS$Tiempo)){
  if(TIEMPOS$Transporte[i]=="Privado") t2<-t2+(TIEMPOS$rango2[i])
}
m1<-length(DesplazamientosPublico$Tiempo)
m2<-length(DesplazamientosPrivado$Tiempo)
W1 <- (m1*m2)+(m1*(m1+1)/2)-t1
W2 <- (m1*m2)+(m2*(m2+1)/2)-t2
W<- min(W1,W2)
W
Z1<-(W-(m1*m2)/2)/(sqrt((m1*m2*(m1+m2+1)/12)))
abs(Z1)
alfa=0.05
qnorm(1-(alfa)/2,0,1)
abs(Z1)>qnorm(1-(alfa)/2,0,1)


#Problema 3 a
#leer datos problema 3, nota separados por ",", conseguir y arreglar las fechas
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
rango3 <-rank(Edad_ingreso_sem2$EdadFraccion)
Edad_ingreso_sem2<- cbind(Edad_ingreso_sem2,rango3)
hombres2 <- subset(Edad_ingreso_sem2, GENERO == "H")$EdadFraccion
mujeres2 <- subset(Edad_ingreso_sem2, GENERO == "M")$EdadFraccion
par(mfrow = c(1, 1))
plot(density(hombres2), col = "red", lwd = 3, main = "Distribibion de densidad Hombres y Mujeres",
     xlab = "Edad", ylab = "densidad")
lines(density(mujeres2), col = "blue", lwd = 3)
legend("topleft", lwd = 2, col = c("blue","red"),
       legend = c("Mujeres", "Hombres" ))
# b
e1=0
e2=0
for(i in 1:length(Edad_ingreso_sem2$EdadFraccion)){
  if(Edad_ingreso_sem2$GENERO[i]=="H") e1<-e1+(Edad_ingreso_sem2$rango3[i])
}
for(i in 1:length(Edad_ingreso_sem2$EdadFraccion)){
  if(Edad_ingreso_sem2$GENERO[i]=="M") e2<-e2+(Edad_ingreso_sem2$rango3[i])
}
p1<-length(hombres2)
p2<-length(mujeres2)
X1 <- (p1*p2)+(p1*(p1+1)/2)-e1
X2 <- (p1*p2)+(p2*(p2+1)/2)-e2
X<- min(X1,X2)
X
Z3<-(X-(p1*p2)/2)/(sqrt((p1*p2*(p1+p2+1)/12)))
abs(Z3)
alfa=0.05
qnorm(1-(alfa)/2,0,1)
abs(Z3)>qnorm(1-(alfa)/2,0,1)



#Problema 4
Gastotabaco <- read_delim("CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Gastotabaco.csv", 
                          ";", escape_double = FALSE, trim_ws = TRUE)

plot(x = Gastotabaco$EDAD,y= Gastotabaco$GASTO)

ggplot(Gastotabaco, aes(x=EDAD, y=GASTO)) + geom_point() + ggtitle("Diagrama de Dispersión") + xlab("EDAD") + ylab("GASTO")

r<- length(Gastotabaco$GASTO)
Fn <- ecdf(Gastotabaco$GASTO)
library(dplyr)
library(latex2exp)
datosTabaco <- Gastotabaco %>% mutate(F_n = Fn(Gastotabaco$GASTO),
                                      F_X = punif(Gastotabaco$GASTO, 0, 50),
                                      D_n = abs(F_n - F_X))
datosTabaco <-  datosTabaco %>% arrange(D_n)


#tau de kendal
(Kendall.muestral <- cor(cbind(datosTabaco$EDAD, datosTabaco$GASTO), method = "kendall")[1, 2])
#relacion de la tau de kendall completa
edad <- c(lapply(datosTabaco[2:2], as.numeric))
gastos <- c(lapply(datosTabaco[5:5], as.numeric))

correkend <- cor.test(as.vector(unlist(edad)),as.vector(unlist(gastos)), 
                      method = "kendall")
correkend


# Número de observaciones
r <- length(datosTabaco$GASTO)
#Función empirica
Fn <- ecdf(datosTabaco$GASTO)
library(latex2exp)
# Funciones de distribución acumulativas
plot(Fn, main = "", xlab = "Gasto", ylab = "Probabilidad")
curve(pexp(x, rate=1/15), add = TRUE, col = 4, lwd = 2)
datos2 <- datosTabaco %>% arrange(GASTO)
lines(rep(datos2$GASTO[1], 2),
      c(Fn(datos2$GASTO[1]), pexp(datos2$GASTO[1], rate=1/15)),
      col = 3, lwd = 2, pch = 16, type = "o", cex = 0.75)
lines(rep(datos2$GASTO[r], 2),
      c(Fn(datos2$GASTO[r]), pexp(datos2$GASTO[r], rate=1/15)),
      col = 2, lwd = 2, pch = 16, type = "o", cex = 0.75)
legend("bottomright", lwd = 2, col = c(1, 4, 3, 2),
       legend = latex2exp::TeX(c("$F_n$", "$F_0$", "$D_n^+$", "$D_n^-$")))
rug(datosTabaco$GASTO)


ex   <- 0
ex <- rexp(gastotabaco, rate = 1/15)
ex4 <- rexp(datosTabaco, rate = 1/15)
#Prueba Kolmogorov- Smirnov en R
ks.test(ex3, "pexp", rate=1/15)

ex <- pexp(datosTabaco$GASTO, rate = 1/15)
ex
#Prueba Kolmogorov- Smirnov en R
ks.test(ex, "pexp", rate=1/15)

##__________________________________________________


+ Dibuja esquemáticamente un diagrama de dispersión que relacione la edad y el gasto en tabaco e indica si existe aparentemente algún tipo de relación entre ambas variables.
library(dplyr)
setwd("CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Gastotabaco.csv")
gastotabaco <- read.csv("CCH-N} FES-A/fessaa/FES/6to semestre/Estadistica II/practica1/Gastotabaco.csv",sep=";",dec=",",
                        stringsAsFactors = FALSE)
head(gastotabaco)#priemros datos de la tabla
#diagrama de dispersion
plot(x = gastotabaco$EDAD, y = gastotabaco$GASTO, lwd = 2, col = "blue",
     main = "Diagrama de dispersion", xlab = "EDAD", ylab = "GASTO TABACO")
Parece que la gente de menor edad (menor de 22 años) es la que menos gasta en tabaco, mientras que entre se mayor se nota un mayor gasto, concideraria una Correlación positiva entre ambas

+ Indica si existe evidencia estadística  de que cuando aumenta la edad, aumenta el gasto en tabaco.

Usando tau de kendall
#tau de kendal
(Kendall.muestral <- cor(cbind(gastotabaco$EDAD, gastotabaco$GASTO), method = "kendall")[1, 2])
#relacion de la tau de kendall completa
edad <- c(lapply(gastotabaco[2:2], as.numeric))
gastos <- c(lapply(gastotabaco[5:5], as.numeric))

correkend <- cor.test(as.vector(unlist(edad)),as.vector(unlist(gastos)), 
                      method = "kendall")
correkend
se nota que la tau de kendall es positiva por lo cual cuando aumenta la edad tambien aumenta el gasto

+ Dibuja esquemáticamente la función de distribución empírica del gasto en tabaco y, en la misma gráfica, dibuja la función de distribución teórica de una exponencial de media 15 euros.
# Número de observaciones
r <- length(gastotabaco$GASTO)
#Función empirica
Fn <- ecdf(gastotabaco$GASTO)
library(latex2exp)
# Funciones de distribución acumulativas
plot(Fn, main = "", xlab = "Gasto", ylab = "Probabilidad")
curve(pexp(x, rate=1/15), add = TRUE, col = 4, lwd = 2)
datos2 <- gastotabaco %>% arrange(GASTO)
lines(rep(datos2$GASTO[1], 2),
      c(Fn(datos2$GASTO[1]), pexp(datos2$GASTO[1], rate=1/15)),
      col = 3, lwd = 2, pch = 16, type = "o", cex = 0.75)
lines(rep(datos2$GASTO[r], 2),
      c(Fn(datos2$GASTO[r]), pexp(datos2$GASTO[r], rate=1/15)),
      col = 2, lwd = 2, pch = 16, type = "o", cex = 0.75)
legend("bottomright", lwd = 2, col = c(1, 4, 3, 2),
       legend = latex2exp::TeX(c("$F_n$", "$F_0$", "$D_n^+$", "$D_n^-$")))
rug(gastotabaco$GASTO)

+ Contrasta la hipótesis de que el gasto en tabaco siga una distribución exponencial de media 15 euros.
#aqui utilizamos una media de 15 entonces seria (1 = r * 15)
ex   <- 0
ex <- rexp(gastotabaco, rate = 1/15)
ex3 <- rexp(gastotabaco, rate = 1/15)
#Prueba Kolmogorov- Smirnov en R
ks.test(ex3, "pexp", rate=1/15)


