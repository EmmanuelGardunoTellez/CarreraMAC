# Temas Selectos de Estadistica: Estadistica Computacional
# Prof. Elizabeth Martinez
# FES-Acatlan, UNAM
# TUTORIAL 3: ANALISIS DE DATOS

options(digits=4,papersize = "letter")  
# https://stat.ethz.ch/R-manual/R-devel/library/base/html/options.html


# Opciones globales en graficas
par(mar=c(5.1,5,4.1,2.1),font=3,# 1=plain,2=bold,3=italic,4=bold italic,5=symbol
    family="sans",bg="yellow")   # sans, serif, mono, symbol

setwd("C:/Users/Emman/Documents/CCH-N} FES-A/fessaa/FES/7mo semestre/Temas Selectos de Estadistica")
getwd()
# **********************************************************************
# **********************************************************************
# **********************************************************************

# Ejemplo (Empleados). Considera una base de datos que contiene informacion de
# 200 empleados de una empresa.

# OJO: para no escribir de nuevo toda la ruta se usa ./
datos1 <- read.table("./DATA/Empleados.txt",header=TRUE,row.names=1)
# row.names=1: la columna 1 es el ID y por lo tanto no se debe tomar como una variable.

# Para leer arhivos con tabulador ("\t") como separador se usa:
# install.packages("readr")

# Si los datos estuvieran en el MISMO directorio de trabajo basta con:
#datos1<- read.table("Empleados.txt",header=TRUE,row.names=1)

head(datos1)    # ver los primeros 6 renglones del conjunto de datos
tail(datos1)    # ver los ultimos 6 renglones del conjunto de datos
dim(datos1)
names(datos1)
str(datos1)
mode(datos1)

# Exploremos algunas variables

datos1$antiguedad
datos1[,3] # da la columna 3

datos1[3,] # da el renglon 3

datos1$sexo  # da la columna 3

datos1[1:10,3:6]  # para seleccionar una parte de los datos

# pero....
antiguedad  # habiamos llamado datos1$antiguedad

antiguedad*12


# Solucion.....

attach(datos1) # con el attach ya puedo accesar a los nombres de las variables

antiguedad

antiguedad*12

# OJO: el problema con attach es que si manejo 2 o mas bases de datos distintas,
# y estas comparten el mismo nombre de las columnas, R se hace bolas y no
# sabra exactamente a que base de datos se refiere.

detach(datos1) # para decirle a R que ya NO usare esa base de datos

ls()   # nos "enlista" todo lo que tengo en la hoja de trabajo

#*****************************************************************************************

# 0. Descripcion de las variables de tu conjunto de datos

# Las variables que se midieron son
# Antiguedad: antiguedad en años
# Hora extra: horas extra trabajadas en el año
# Sexo: 1-mujer, 2-hombre
# Cursos: numero de cursos de capacitacion en un año
# Incapacidad: dias de incapacidad
# Aptitudes: indice de aptitudes y capacidades
# Escolaridad: 0-bachillerato, 1-licenciatura sin titulo, 2-licenciatura con titulo, 3-posgrado
# Salarios: salario anual en dolares
# Edad: edad en años del trabajador

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Ejercicio: Describe la naturaleza de cada variable. Indica tanto el tipo como la escala de medicion.
#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#****** Solucion******
# Antiguedad: cuantitativa/discreta; razon
# Hora extra: cuantitativa/discreta; razon
# Sexo: cualitativa/nominal
# Cursos: cuantitativa/discreta; razon
# Incapacidad: cuantitativa/discreta; razon
# Aptitudes: cuantitativa/continua; intervalo
# Escolaridad: cualitativa/ordinal
# Salarios: cuantitativa/continua; razon
# Edad: cuantitativa/discreta; razon

###############################################################################################
############################ I.ANALISIS DE VARIABLES CUALITATIVAS #############################
###############################################################################################

# A. Datos cualitativos nominales 

# Tabla de frecuencias
tabla_sexo <- table(sexo)  # hace una tabla de frecuencias absolutas para esta variable
print(tabla_sexo)
sum(tabla_sexo)
prop.sexo <- round(prop.table(tabla_sexo),digits=3)
print(prop.sexo)
sum(prop.sexo)
cumsum(prop.sexo)

names(tabla_sexo)

names(tabla_sexo)[1]   # solo me da el nombre asociado con 1

names(tabla_sexo)[2]   # solo me da el nombre asociado con 2

sum(tabla_sexo)  # suma los valores

tablar_sexo <- prop.table(tabla_sexo)  # convierte una tabla en una tabla de frecuencias relativas 
print(tablar_sexo)
sum(tablar_sexo)  # suma las entradas de un objeto
