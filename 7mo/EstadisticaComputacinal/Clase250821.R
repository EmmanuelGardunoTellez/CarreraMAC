# Temas Selectos de Estadistica: Estadistica Computacional
# Prof. Elizabeth Martinez
# FES-Acatlan, UNAM
# TUTORIAL 2: ANALISIS DE DATOS

options(digits=4,papersize = "letter")  
# https://stat.ethz.ch/R-manual/R-devel/library/base/html/options.html


# Opciones globales en graficas
par(mar=c(5.1,5,4.1,2.1),font=3,# 1=plain,2=bold,3=italic,4=bold italic,5=symbol
    family="sans",bg="yellow")   # sans, serif, mono, symbol

#***************************************************************************
#************************* EXTRA LECTURA DE DATOS **************************
#***************************************************************************

## 1. Datos provenientes de una hoja de calculo en Google Drive
install.packages("googlesheets4")
library(googlesheets4)
datos_url<- "https://docs.google.com/spreadsheets/d/1zHYnLwsO3RFhN0Wpx3J34JtavH4lajEkvxaEqNVhBEQ/edit#gid=0"
install.packages("readxl")
library(readxl)
EmpleadosTSE <- read_excel("CCH-N} FES-A/fessaa/FES/Septimo/EmpleadosTSE.xlsx", 
                           col_types = c("numeric", "numeric", "numeric", 
                                         "numeric", "numeric", "numeric", 
                                         "numeric", "numeric", "numeric", 
                                         "numeric"))
View(EmpleadosTSE)
datosweb <- EmpleadosTSE
str(datosweb)
names(datosweb)
datosweb$horasextra
datosweb<- datosweb[,2:10]   # eliminamos la primera columna del ID

# O bien,

datosweb2<- read_sheet("1_DViiUbv1HDaAOxP1t9ZXL6nlkeX7zqjCMeUn6WLdJc")
str(datosweb2)  
names(datosweb2)
datosweb2$edad

install.packages("httpuv")
library(httpuv)


## 2. Datos de internet (.dat, .csv)

otrosdatosweb <- read.table("http://users.stat.ufl.edu/~winner/data/snowchol.dat")

#para archicos .csv se usa read.csv

# Mmmm mejorando
# http://users.stat.ufl.edu/~winner/data/snowchol.txt
otrosdatosweb <- read.fwf("http://users.stat.ufl.edu/~winner/data/snowchol.dat",
                          c(32,8,5,10),header=F,
                          col.names=c("Distrito","Compania","Indicador_muerte","Casos"))
names(otrosdatosweb)
str(otrosdatosweb)
View(otrosdatosweb)

otrosdatosweb$Distrito

## 3. Datos de internet (.zip)

setwd("C:/Users/Emman/Documents/CCH-N} FES-A/fessaa/FES/Septimo")
getwd()

url<- "https://perso.telecom-paristech.fr/eagan/class/igr204/data/BabyData.zip"
download.file(url,destfile = "./DATA/dataset.zip",mode="wb") #ruta de cada computadora
unzip("./DATA/dataset.zip",exdir = "./DATA")  # checamos los archivos en el directorio


data <- read.csv("./DATA/Diaper_data_11_29_2012.csv",sep="\t",header=T)#ruta del archivo
str(data)
View(data)

# Otra manera es creando un archivo temporal
temp <- tempfile()
download.file("https://perso.telecom-paristech.fr/eagan/class/igr204/data/BabyData.zip",temp)
carsData <- read.csv(unz(temp, "Diaper_data_11_29_2012.csv"),sep="\t")
unlink(temp)  # para remover el archivo temporal
View(carsData)


## 4. Datos de internet (.html)

install.packages("rio")
rio::import("https://www.ncdc.noaa.gov/snow-and-ice/rsi/",format="html")

# Otra opcion ("chafona")
install.packages("htmltab")
htmltab::htmltab("https://www.ncdc.noaa.gov/snow-and-ice/rsi/")


## 5. Datos en paquetes de R
install.packages("datasets.load")
data(package = .packages(all.available = TRUE))
library(datasets.load)
datasets()