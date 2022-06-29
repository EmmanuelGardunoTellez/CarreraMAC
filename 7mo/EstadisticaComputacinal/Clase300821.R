#ebola

setwd("C:/Users/Emman/Documents/CCH-N} FES-A/fessaa/FES/7mo semestre/Temas Selectos de Estadistica")
getwd()

# **********************************************************************
# ************************** MANEJO DE DATOS ***************************
# **********************************************************************

## Problema: Se tienen los siguientes registros de una hipotetica 
## epidemia de ebola. Los datos estan desordenados (sucios).
install.packages("rio")
library(rio)
datos_sucios<- import("./DATA/ebola.xlsx") 

# Revisamos los datos

install.packages("skimr")
skimr::skim(datos_sucios)

names(datos_sucios)

### 1. LIMPIEZA DE DATOS 

# Algunos nombres de columnas tienen espacios y eso puede dar 
# problemas, ademas la ultima columna esta "rara".
# Solucion: hay que homologar estos nombres

# METODO 1: Usando la funcion "clean_names"

install.packages("janitor")
library(janitor)

datos<- clean_names(datos_sucios)
names(datos)

# O bien: 

datos<- datos_sucios %>%
  janitor::clean_names()


# METODO 2: Manual

install.packages("dplyr")
library(dplyr)

#        NUEVO                 # ANTERIOR
datos2<- rename(datos, date_infection       = infection_date,
                date_hospitalisation = hosp_date,
                date_outcome         = date_of_outcome,
                weight_kg = wt_kg)

names(datos2)


### 2. SELECCION DE COLUMNAS

# 2.1 Si queremos conservar algunas columnas solamente

datos2 %>% 
  select(case_id, date_onset, date_hospitalisation, fever) %>% 
  names()


# O bien,

datos3<- select(datos2, case_id, date_onset, 
                date_hospitalisation, fever)


# 2.2 Si queremos seleccionar algunas columnas basadas en su clase:

datos2 %>% 
  select(where(is.numeric)) %>%    # se deben ejecutar las 3 lineas
  names()

# O bien,

datos4<- select(datos2,where(is.numeric))

# 2.3 Si queremos seleccionar algunas columnas que contengan algunas
# palabras:

datos2 %>% 
  select(contains("date")) %>%   # se deben ejecutar las 3 lineas
  names()


# 2.4 Si queremos mover una columna a otra:

datos2 %>% 
  select(date_onset, date_hospitalisation, everything()) %>% 
  names()

# O bien,

datos2.a<- select(datos2,date_onset, date_hospitalisation, everything())
names(datos2.a)


### 3. ELIMINACION DE COLUMNAS 

datos2%>% 
  select(-c(date_onset, fever:vomit)) %>% # elimina date_onset y todas las columnas desde
  names()                                 # "fever" hasta "vomit"

# OJO: si queremos guardarlos:

datos5<- datos2%>%select(-c(date_onset, fever:vomit)) 

# En realidad no interesan las variables: case_id, row_num
# age_unit,merged_header,x28

datos2.b<- datos2%>%select(-c(case_id, row_num, age_unit,
                              merged_header,x28))  


### 4. DATOS FALTANTES 

# 4.1 Reemplazar los "NA" por alguna otra palabra o valor

library(tidyr)
View(datos2.b)
datos2.c <- datos2.b %>% 
  mutate(hospital = replace_na(hospital, "Missing"))

# 4.2 Asegurar datos faltantes

install.packages("naniar")
library(naniar)


pct_miss(datos2.b)

# % de renglones con cualquier dato faltante
pct_miss_case(datos2.b)   
n_complete(datos2.b)  # numero de casos

# % de renglones completos (no hay valores faltantes)  
pct_complete_case(datos2.b) 

# mejor graficamos!
gg_miss_var(datos2.b, show_pct = TRUE)  # muestra % de faltantes


vis_miss(datos2.b)  # library(naniar)
# las lineas negras indican la posicion del dato faltante en cada columna


# NOTA: otra manera sencilla de contar el # de faltantes en todas
# las columnas:

sapply(datos2.b, function(x) sum(is.na(x)))

# 4.3 Manejar faltantes en R

library(tidyr)

# a) Eliminar renglones con CUALQUIER valor faltante

datos2.b %>% 
  drop_na() %>%      
  nrow()

# O bien, 

drop_na(datos2.b)

# b) Elimina renglones faltantes usando una cierta columna

datos2.b %>% 
  drop_na(date_onset) %>%  
  nrow()

# c) Elimina  valores faltantes para cualquiera de las columnas
datos2.b %>% 
  drop_na(case_id, date_onset, age) 

# d) Usando la libreria "base"

is.na(datos2.b); !is.na(datos2$date_onset)

# **********************************************************************
# ***************************** IMPUTACION *****************************
# **********************************************************************

# Para comprender mejor como se puede identificar el patron de faltantes
# analicemos este ejemplo hipotetico.
# Se muestra la informacion de 250 personas en un hospital.

install.packages("VIM")
install.packages("mice")
install.packages("tibble")
library(VIM)
library(dplyr)
library(tibble)

install.packages("Rcmdr")

library("Rcmdr")

dat <- read.csv(url("https://goo.gl/4DYzru"), header=TRUE, sep=",")
head(dat)
tail(dat)
view(dat)
set.seed(092021)

# Simulamos datos faltantes "MNAR" en dat
missing <- rbinom(n= nrow(dat),size= 1, prob= 0.24) # simulamos un indicador para NA's

dat$Cholesterol <- with(dat, ifelse(BMI >= 30&missing==1, NA, Cholesterol))
#ifelse(condicion, si, no)

# Los datos faltantes son de personas obesas. 

dat$Cholesterol

sum(is.na(dat$Cholesterol))

# Son 15 pacientes obesos sin registro de colesterol.

# Ahora imputamos valores con el metodo PMM (predictive mean matching)
install.packages("mice")
library(mice)

set.seed(2510)
imputed= mice(dat, m=1, defaultMethod = "pmm")
imp = complete(imputed)

# Creamos un conjuntos de datos que incluya a los valores imputados
# y una variable indicadora que muestre cuales valores fueron imputados.
# Es un requisito para usar "marginplot".

dt1 = dat %>% 
  rename(Cholesterol_imp = Cholesterol) %>% 
  mutate(Cholesterol_imp = as.logical(ifelse(is.na(Cholesterol_imp),
                                             "TRUE", "FALSE"))
  ) %>% 
  rownames_to_column()

dt <- left_join(imp,dt1)

dt<- select(dt,c(Age,Gender,Cholesterol,Cholesterol_imp,SystolicBP,
                 BMI,Smoking,Education))


library(VIM)
marginplot(dt[,c("BMI","Cholesterol","Cholesterol_imp")],
           delimiter = "_imp", col=c(3,6), pch=16)

# El verde indica los valores no-faltantes para colesterol
# El magenta muestra los valores faltantes que ya fueron imputados

# INTERPRETACION: Las personas con datos faltantes en colesterol
# tienen un BMI mas alto que las personas que tienen el registro
# de colesterol. ESTO SIGNIFICA QUE EL PATRON DE FALTANTES NO ES
# ALEATORIO.
# El boxplot muestra que la mediana del BMI para personas con datos
# faltantes es aprox. 33, mientras que el de aquellos que si tienen
# registro de colesterol es aprox. 26.

## Otra manera de visualizar el patron:

# OJO: 

plot(dat$BMI,dat$Cholesterol,pch=19) # no protesta por NA's

# Peeero....

library(ggplot2)
ggplot(dat,
       aes(x = BMI,
           y = Cholesterol)) +
  geom_point(color='darkblue')


# Veamos la siguiente grafica:

library(naniar)
ggplot(dat,
       aes(x = BMI,
           y = Cholesterol)) +
  geom_miss_point()

# Agregamos una segunda variable con datos faltantes

missing2 <- rbinom(n= nrow(dat),size= 1, prob= 0.9) # simulamos un indicador para NA's

dat$Age <- with(dat, ifelse(missing2==1, NA, Age))

dat$Age

# Veamos el conjunto "dat"
dat

set.seed(092021)
imputed2= mice(dat, m=1, defaultMethod = "pmm")  # imputacion simple
imp2 = complete(imputed2)   # imputa en todas las variables donde se requiera

cbind(imp$Age,imp2$Age)
cbind(imp$Cholesterol,imp2$Cholesterol)


#---------------------------------------------------------------
# Otra manera de generar patron de aleatorios:

install.packages("missMethods")
library(missMethods)
library(ggplot2)

set.seed(123)

grafica_MD <- function(ds_comp, ds_mis) {
  ds_comp$missX <- is.na(ds_mis$X)
  ggplot(ds_comp, aes(x = X, y = Y, col = missX)) +
    geom_point()
}

# Generamos un conjunto de datos 
datos_hip <- data.frame(X = rnorm(1000,mean=2, sd=0.45), 
                        Y = rnorm(1000,mean=-3.1, sd=2),
                        Z= rnorm(1000))

# 1. MCAR

ds_mcar <- delete_MCAR(datos_hip, 0.25, "X")  # elimina el 25%
grafica_MD(datos_hip, ds_mcar)

gg_miss_var(ds_mcar, show_pct = T)  # muestra % de faltantes

vis_miss(ds_mcar)  # library(naniar)

mcar_test(ds_mcar)
# DECISION: valor alto de ji-cuadrada y p-value bajo: los datos
# no son MCAR

# 2. MAR

ds_mar <- delete_MAR_censoring(datos_hip, 0.25, "X", cols_ctrl = "Y")
grafica_MD(datos_hip, ds_mar)

gg_miss_var(ds_mar, show_pct = T)  # muestra % de faltantes

vis_miss(ds_mar)  # library(naniar)

mcar_test(ds_mar)   

# O bien,

ds_mar2 <- delete_MAR_1_to_x(datos_hip, 0.25, "X", cols_ctrl = "Y", 
                             x = 2)
grafica_MD(datos_hip, ds_mar2)

gg_miss_var(ds_mar2, show_pct = T)  # muestra % de faltantes

vis_miss(ds_mar)  # library(naniar)

# 3. MNAR

ds_mnar <- delete_MNAR_censoring(datos_hip, 0.25, "X")
ds_mnar2 <- delete_MNAR_rank(datos_hip, 0.25, "X")
ds_mnar3<- delete_MNAR_1_to_x(datos_hip,0.25,"X",x=4)

grafica_MD(datos_hip, ds_mnar3)

mcar_test(ds_mnar3)

#-------------------------------------------------------------
#-------------------------------------------------------------
# Ahora lo aplicamos a nuestros datos de ebola

# Graficamos el patron (2 variables al menos)

install.packages("UpSetR")
library(UpSetR)
gg_miss_upset(datos2.b, nsets = n_var_miss(datos2.b),
              nintersects= NA) # muestra todas las interacciones

# nsets= # variables
# nintersects= # combinaciones


# Otra manera:

aggr(datos2.b,col=c("blue", "red"),  # primer color datos reales
     combined= T, bars=F, numbers=F, sortVars= F)  

# Para facilitar un poco las interpretaciones
aggr(datos4,col=c("blue", "red"),  # primer color datos reales
     combined= F, bars=F, numbers=T,sortVars= T, 
     prop = c(TRUE, FALSE))

# INTERPRETACION: 
# 1. Hay 6453 renglones con datos completos
# 2. Hay 151 renglones donde la variable "temp" tiene faltantes
# 3. Hay 7 renglones donde "temp", "generation", "lon", "lat",
# "weight_kg", "ht_cm", "ct_blood" tienen faltantes



# Imputaciones

# Una paqueteria MUY utilizada: mice

install.packages("mice")
library(mice)

# Recordemos que:

aggr(datos4,numbers=T,sortVar=T)   # variables numericas

columns <- c("temp","generation","lon","lat","weight_kg",
             "ht_cm","ct_blood","row_num")
imputed_data <- mice(datos4[,names(datos4) %in% columns],m = 1,
                     maxit = 1, method = "mean",seed = 092021)
complete.data <- mice::complete(imputed_data)
summary(complete.data)

imputed_data2<- mice(datos4[,c("temp","generation","weight_kg")],m=1, blocks=c("temp","generation","weight_kg"),
                     method= c("pmm","mean","sample") )
complete.data2 <- mice::complete(imputed_data2)

# Otra libreria util: missForest

install.packages("missForest")
library(missForest)

data("iris")
iris.mis <- prodNA(iris, noNA = 0.1)  # missForest y metemos 10% faltantes
summary(iris.mis)
view(iris.mis)
# imputamos
iris.imp <- missForest(iris.mis)

# vemos los valores imputados
iris.imp$ximp
str(iris.imp)
# error de imputacion
iris.imp$OOBerror

# NRMSE es el error cuadratico normalizado y se usa
# para representar el error derivado al imputar valores continuos

# PFC (proporcion de clasificados falsos) y se usa 
# para representar el error derivado al imputar valores categoricos.

# comparamos los datos actuales (ya imputados) con los originales

iris.err <- mixError(iris.imp$ximp, iris.mis, iris)

# Las categoricas son imputadas con el 6% de error 
# Las continuas con el 15% de error

# Otra libreria util: Hmisc

install.packages("Hmisc")
library(Hmisc)

# imputacion con el promedio (min, max, median)

iris.mis$imputed <- with(iris.mis, impute(Sepal.Length, mean))

# imputacion con valor aleatorio

iris.mis$imputed2 <- with(iris.mis, impute(Sepal.Length, 'random'))

# argImpute
impute_arg <- aregImpute(~ Sepal.Length + Sepal.Width + Petal.Length + Petal.Width +
                           Species, data = iris.mis, n.impute = 3)
str(impute_arg)
# valores de una de las columnas imputadas
impute_arg$imputed$Sepal.Length



