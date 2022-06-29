#Instalar librerias y habilitarlas
install.packages("tidyverse")
install.packages("ggplot2")
install.packages("moments")
library("tidyverse")
library("ggplot2")
library("moments")
library(readr)
library(stringr)

#Asignar la carpeta del trabajo
getwd()
setwd("C:\\Users\\Emman\\Documents\\CCH-N} FES-A\\fessaa\\FES\\5to Semestre\\Estadistica")
list.files()

#Recopilar todos los datos
Dato01 <- read_csv("practica1/AHG_Practica1.csv", col_names = FALSE)
Dato02 <- read_csv("practica1/alan.csv", col_names = FALSE)
Dato03 <- read_csv("practica1/archivo para practica 1 Mitzi.csv", col_names = FALSE)
Dato04 <- read_csv("practica1/Archivo_Practica1.csv", col_names = FALSE)
Dato05 <- read_csv("practica1/archivoparapractica1.csv", col_names = FALSE)
Dato06 <- read_csv("practica1/BasilioPPractica.csv", col_names = FALSE)
Dato07 <- read_csv("practica1/Datos Práctica 1.csv", col_names = FALSE)
Dato08 <- read_csv("practica1/Datos_1.csv", col_names = FALSE)
Dato09 <- read_csv("practica1/Estadistica.csv", col_names = FALSE)
Dato10 <- read_csv("practica1/fer2.csv", col_names = FALSE)
Dato11 <- read_csv("practica1/Jerson.csv", col_names = FALSE)
Dato12 <- read_csv("practica1/jorge.csv", col_names = FALSE)
Dato13 <- read_csv("practica1/karina lizeth ortiz munoz - Hoja 1.csv", col_names = FALSE)
Dato14 <- read_csv("practica1/LAHF.csv", col_names = FALSE)
Dato15 <- read_csv("practica1/Libro3.csv", col_names = FALSE)
Dato16 <- read_csv("practica1/Nombre.csv", col_names = FALSE)
Dato17 <- read_csv("practica1/OCJM-2016.csv", col_names = FALSE)
Dato18 <- read_csv("practica1/Pract.csv", col_names = FALSE)
Dato19 <- read_csv("practica1/Practica 1 (1).csv", col_names = FALSE)
Dato20 <- read_csv("practica1/practica 1 (2).csv", col_names = FALSE)
Dato21 <- read_csv("practica1/Practica 1.csv", col_names = FALSE)
Dato22 <- read_csv("practica1/Practica 1__.csv", col_names = FALSE)
Dato23 <- read_csv("practica1/practica-1502.csv", col_names = FALSE)
Dato24 <- read_csv("practica1/Practica.1.csv", col_names = FALSE)
Dato25 <- read_csv("practica1/practica01.csv", col_names = FALSE)
Dato26 <- read_csv("practica1/Practica1 (1).csv", col_names = FALSE)
Dato27 <- read_csv("practica1/Practica1 (2).csv", col_names = FALSE)
Dato28 <- read_csv("practica1/Practica1 (3).csv", col_names = FALSE)
Dato29 <- read_csv("practica1/Practica1 (4).csv", col_names = FALSE)
Dato30 <- read_csv("practica1/practica1 augusto.csv", col_names = FALSE)
Dato31 <- read_csv("practica1/Practica1.csv", col_names = FALSE)
Dato32 <- read_csv("practica1/Practica1.Juan Carlos.csv", col_names = FALSE)
Dato33 <- read_csv("practica1/Practica1_.csv", col_names = FALSE)
Dato34 <- read_csv("practica1/practica1C.csv", col_names = FALSE)
Dato35 <- read_csv("practica1/Practica_1 (1).csv", col_names = FALSE)
Dato36 <- read_csv("practica1/Practica_1.csv", col_names = FALSE)
Dato37 <- read_csv("practica1/Práctica 1..csv", col_names = FALSE)
Dato38 <- read_csv("practica1/Práctica 1.csv", col_names = FALSE)
Dato39 <- read_csv("practica1/Práctica.1..csv", col_names = FALSE)
Dato40 <- read_csv("practica1/Práctica_1.csv", col_names = FALSE)
Dato41 <- read_csv("practica1/Práctica_1_.csv", col_names = FALSE)
Dato42 <- read_csv("practica1/sergio2.csv", col_names = FALSE)
Dato43 <- read_csv("practica1/t2.csv", col_names = FALSE)
Dato44 <- read_csv("practica1/ulises.csv", col_names = FALSE)

#Juntas los datos similares en vectores
genero <- c(Dato01[1,1],Dato02[1,1],Dato03[1,1],Dato04[1,1],Dato05[1,1],Dato06[1,1],Dato07[1,1],Dato08[1,1],Dato09[1,1],Dato10[1,1],
            Dato11[1,1],Dato12[1,1],Dato13[1,1],Dato14[1,1],Dato15[1,1],Dato16[1,1],Dato17[1,1],Dato18[1,1],Dato19[1,1],Dato20[1,1],
            Dato21[1,1],Dato22[1,1],Dato23[1,1],Dato24[1,1],Dato25[1,1],Dato26[1,1],Dato27[1,1],Dato28[1,1],Dato29[1,1],Dato30[1,1],
            Dato31[1,1],Dato32[1,1],Dato33[1,1],Dato34[1,1],Dato35[1,1],Dato36[1,1],Dato37[1,1],Dato38[1,1],Dato39[1,1],Dato40[1,1],
            Dato41[1,1],Dato42[1,1],Dato43[1,1],Dato44[1,1])

edad   <- c(Dato01[1,2],Dato02[1,2],Dato03[1,2],Dato04[1,2],Dato05[1,2],Dato06[1,2],Dato07[1,2],Dato08[1,2],Dato09[1,2],Dato10[1,2],
            Dato11[1,2],Dato12[1,2],Dato13[1,2],Dato14[1,2],Dato15[1,2],Dato16[1,2],Dato17[1,2],Dato18[1,2],Dato19[1,2],Dato20[1,2],
            Dato21[1,2],Dato22[1,2],Dato23[1,2],Dato24[1,2],Dato25[1,2],Dato26[1,2],Dato27[1,2],Dato28[1,2],Dato29[1,2],Dato30[1,2],
            Dato31[1,2],Dato32[1,2],Dato33[1,2],Dato34[1,2],Dato35[1,2],Dato36[1,2],Dato37[1,2],Dato38[1,2],Dato39[1,2],Dato40[1,2],
            Dato41[1,2],Dato42[1,2],Dato43[1,2],Dato44[1,2])

correo <- c(Dato01[1,3],Dato02[1,3],Dato03[1,3],Dato04[1,3],Dato05[1,3],Dato06[1,3],Dato07[1,3],Dato08[1,3],Dato09[1,3],Dato10[1,3],
            Dato11[1,3],Dato12[1,3],Dato13[1,3],Dato14[1,3],Dato15[1,3],Dato16[1,3],Dato17[1,3],Dato18[1,3],Dato19[1,3],Dato20[1,3],
            Dato21[1,3],Dato22[1,3],Dato23[1,3],Dato24[1,3],Dato25[1,3],Dato26[1,3],Dato27[1,3],Dato28[1,3],Dato29[1,3],Dato30[1,3],
            Dato31[1,3],Dato32[1,3],Dato33[1,3],Dato34[1,3],Dato35[1,3],Dato36[1,3],Dato37[1,3],Dato38[1,3],Dato39[1,3],Dato40[1,3],
            Dato41[1,3],Dato42[1,3],Dato43[1,3],Dato44[1,3])
splited <- str_split_fixed(correo, pattern = '@', n=2)

#Crear una matrix con todos los datos
datosgnl <- matrix(c(genero, edad, correo, splited),
                   nrow = 44, ncol = 5)
#Nombrar las columnas
colnames(datosgnl) <- c("Genero","Edad","Correo","correo2","dominio" )
#Depurar los datos
datosgnl[[2,2]] <- 21
#Ver datos listos
view(datosgnl)
#Por comodidad crear un archivo csv, donde esten todos los datos juntos
write.csv(datosgnl, "datosjuntoos.csv")
#Leer los datos juntos
datos <- read_csv("C:\\Users\\Emman\\Documents\\CCH-N} FES-A\\fessaa\\FES\\5to Semestre\\Estadistica\\datosjuntoos.csv")
#Cambiar los nombre (se agrego una col de mas con la num de 1 al 44)
colnames(datos) <- c("NUM","Genero","Edad","Correo","correo2","dominio")
View(datos)

#1.-Construir un diagrama de caja y brazos de la valariable edad y calcular las siguientes medidas
#q(0.5), q(0.25) ??? 1.5RIC, q(0.75) + 1.5RIC, q(0.25), q(0.75)
attach(datos)

#Diagrama de caja
boxplot(datos$Edad)
IQR(datos$Edad)
#cuantiles
quantile(datos$Edad)
MIN <- (20-1.5*ric)      #q(0.25) ??? 1.5RIC
MAX <- (21+1.5*ric)      #q(0.75) + 1.5RIC
print("q(0.25) ??? 1.5RIC=") 
print(MIN)
print("q(0.75) ??? 1.5RIC=") 
print(MAX)

#2.-Calcular la desviacion estándar, la asimetría y el coeficiente de curtosis de la variable edad.
#desviacion estándar
sd(datos$Edad)
#asimetria
skewness(datos$Edad)
#el coeficiente de curtosis
kurtosis(datos$Edad)
#3.-Elaborar una grafica de pastel de la variable sexo.
generod<- factor(datos$Genero)
levels(generod) <- c("hombre","Mujer")
datosGenero <- table(generod)

pie(datosGenero, ylab = "cantidad", col = c("blue", "red"),main = "Cantidad de Hombre y Mujeres")

#4.- A partir del registro de los correos electronicos, crear una gráfica de barras horizontal de los dominios. 
dominiod<-  factor(datos$dominio)
levels(dominiod) <- c("comunidad", "gmail", "hotmail", "outlook.com", "outlook.es")
datosDominio <- table(dominiod)
barplot(datosDominio, horiz = T,main = "Dominios", col= c("gold", "blue", "red", "green", "green"))
#5.- Crear una grafica de barras vertical de los dominios por sexo.
p <- ggplot(data = datos,
            mapping = aes(x= factor(Genero),
                          fill= factor(dominiod)))
p + geom_bar(position = 'stack', stat = 'count')
#____________________________________________________________________________________________________________

