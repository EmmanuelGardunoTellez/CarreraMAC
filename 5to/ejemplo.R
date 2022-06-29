# Instalar paquete
install.packages("ggplot2")

# Cargar paquete
library("ggplot2")

# Operaciones aritméticas
-2 + 3; 5 * 7; 3 - 7; 3 ^ 2; 4 %% 3

# Operaciones lógicas
4 > 3

4 < 3
4 >= 3
4 <= 3
4 != 3
4 > 3 & 5 > 3
5 < 4 | 3 < 4

# Funciones
log(1, 10)
sqrt(100)
factorial(100)
round(pi, 2)
abs(-pi)


# Declarar variables
(a <- 4 + 5)
print(a)

ls()
exists("a")
rm("a")
rm(list=ls())

# Tipos de datos
# integer, numeric, character, factor, logical, NA, NULL 

class(2)

is.integer(2)

is.integer(2L)

# Concatenar
d <- c(0,1)
(b<-c(1,d, 2, 4, 6, -3))
c(1, 2L, "d")
list(1, 2L, "d")

# Estructuras de datos ####

# Crear un vector

c<-vector(mode = "numeric", length = 10)
c

# Elementos de un vector
b[2]
b[3]

# Vector de cadena de texto
d <- c("manzana", "uva", "durazno")
d

# Funciones para vectores
sum(b)
max(b)
min(b)
length(b)
mean(b)
summary(b)
b <- sort(b, decreasing = TRUE)
subset(b, b > 4)
?sort

# Unir vectores
a <- c(2, 4, 6, 8, 0, 1, 2)
length(a)
length(b)
cbind(a, b)

rbind(a, b)

# Matrices 

obs <- c(1, 2, 3, 4, 5, 0.5,2, 6, 0, 1, 1, 0)
m <- matrix(obs, ncol = 3)
print(m)
m <- matrix(obs, ncol = 3, byrow = T)
print(m)
t(m)
dim(m)
m
m[, 1]
m[4,]
m[, c(2,3)]
ncol(m)
nrow(m)

# Data frames

datos <- data.frame(
  "entero" = 1:4, 
  "factor" = c("a", "b", "c", "d"), 
  "numero" = c(1.2, 3.4, 4.5, 5.6)
)
datos


# Listas
(lista <- list(1, "a", "b", "d"))

# Estructura de un objeto
str(datos)

# Transformaciones de estructuras
as.vector()
as.matrix()
as.data.frame()
as.list()

# Familia apply ####
apply(m, 1, sum) # Fila
apply(m, 2, sum) # Columna
lapply 
sapply
mapply

# Crear funciones ####

suma <- function(a,b) {
  c <- a+b
  c
}

suma(2,3)

# Modelos probabilísticos ####
dnorm(0, mean = 0, sd = 1)
pnorm(0, mean = 0, sd = 1)
qnorm(0.5, mean = 0, sd = 1)
num <- rnorm(100, mean = 0, sd = 1)
hist(num)
# unif, exp, pois, binom, chisq, t, f, gamma, beta

# Estadística descriptiva ####

# Ver archivo "Unidad 1.Rmd"

# Condicionales y ciclos ####

# if (proposición lógica){
#       instrucciones
#       }
# else{instrucciones
#       }

# for (x in 1:10){
#       instrucciones
#       }

# while (proposición lógica){
#       instrucciones
#       }

# Importar y exportar archivos ####
# getwd()
# setwd()
# list.files()
# read.table()
# read.csv()
# write.table()
# write.csv()