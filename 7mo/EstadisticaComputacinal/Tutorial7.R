
# Temas Selectos de Estadistica: Estadistica Computacional
# Prof. Elizabeth Martinez
# FES-Acatlan, UNAM
# TUTORIAL 7: INTRODUCCION A METODOS DE MONTE CARLO


# CALCULO DE INTEGRALES 

## Caso 1: intervalo (0,1)

## a) funcion exponencial

f1<- function(x) exp(-x)

int_num<- integrate(f1,0,1)$value; int_num

# Simulacion MC
n<- 2000
x<- runif(n,min=0,max=1)
thetahat.f1<- mean(exp(-x))

print(c(int_num,thetahat.f1))  # exacto vs estimado


## b) funcion 

f2<- function(x) 1/(1+x^2)

int_num2<- integrate(f2,0,1)

# Simulacion MC
n<- 2000
x<- runif(n,min=0,max=1)
thetahat.f2<- mean(1/(1+x^2))

print(c(int_num2$value,thetahat.f2))  # exacto vs estimado

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Caso 2: Integracion intervalo (a,b)

# a) funcion exponencial

m<- 2000
a<- 2
b<- 4  
x<- runif(m,min=a,max=b)
thetahat.exp<- mean(exp(-x))*(b-a) 

int_teo<- -exp(-b)+exp(-a)       # valor exacto
print(c(int_teo,thetahat.exp))   # exacto vs estimado


# Una funcion mas general para integrar por MC en el intervalo (a,b)

integral_mc <- function(fun, a, b, n) {
  # La integracion definida por MC de una funcion que utiliza
  # una muestra de tamaño n
  x= runif(n, a, b)
  gx= sapply(x,fun) 
  return(mean(gx)*(b-a))
}

# Con la funcion general

integral_mc(f1,a,b,m)

# Calculemos la varianza del estimador

(var.thetahat<- (((b-a)^2)/m)*var(exp(-x)))   # varianza del estimador


# b) 

f3<- function(x){
  ((2*x)+1)/((x^2)+x)
}

integrate(f3,1,2)$value    # resultado integracion numerica de f3

# Resolviendo la integral por MC

m<- 2000
a<- 1
b<- 2  
x<- runif(m,min=a,max=b)
thetahat.f3<- mean(f3(x))*(b-a); thetahat.f3

# Usando la funcion general de MC
integral_mc(f3,a,b,m)

# EXTRA: apliquemos la funcion general a los ejemplos con intervalo
# de integracion (0,1)

integral_mc(f1,0,1,2000); thetahat.f1
integral_mc(f2,0,1,2000); thetahat.f2



#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Caso 3: Integracion en intervalo no acotado

# Para x>=0
x<- seq(0,6,length=100)
n<- 15000
u<- runif(n)
fda<- numeric(length(x))
for(i in 1:length(x)){
  g= x[i]*exp(-(u*x[i])^2/2)
  fda[i]= 0.5+(mean(g)/sqrt(2*pi))
}

fda

Phi<- pnorm(x)   # valor numerico de R
print(rbind(x,fda,Phi)) 

plot(x,fda,type="l")
lines(x,Phi,col="blue")


# Para x<0
x<- seq(-6,0,length=100)
n<- 15000
u<- runif(n)
fda_neg<- numeric(length(x))
for(i in 1:length(x)){
  g= x[i]*exp(-(u*x[i])^2/2)   
  fda_neg[i]= 1-(0.5+(-mean(g)/sqrt(2*pi)))
}

fda_neg
Phi_neg<- pnorm(x)   # valor numerico de R
print(rbind(x,fda_neg,Phi_neg)) 

plot(x,fda_neg,type="l")
lines(x,Phi_neg,col="purple")



#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Caso 4: Si X~N(mu=-5.68,sigma=3.25), calcula P(X< -5.68) usando MC

# Graficamos la distribucion normal

mu<- -5.68
sigma<- 3.25
xx<- seq(-20,10,length.out= 100)
plot(xx,dnorm(xx,mean=mu, sd= sigma),type="l")

t<- -8.35  # cuantil de interes
abline(v=t)
n <- 2000
x <- rnorm(n, mean = mu, sd = sigma)
g.ind<- x<= t    # funcion indicadora
theta.hat<- mean(g.ind)  # estimacion MC de la fda

cat("Tiempo de proceso", proc.time()[1], "segundos.\n")

cbind(x,g.ind)   # comparamos los valores simulados con la indicadora

# Comparamos con la funcion de R
pnorm(t,mean = mu,sd = sigma,lower.tail = T)


## ERROR ESTANDAR EN EL ESTIMADOR DE LA INTEGRAL POR MC P(X< -5.68)

m<- 2000
x <- rnorm(m, mean = mu, sd = sigma)
g.ind<- x<= t    # funcion indicadora
theta.hat<- mean(g.ind)  # estimacion MC de la fda

se.hat<- (1/m)*sqrt(sum((g.ind-theta.hat)^2)); se.hat   

# Intervalo de confianza para el estimador de la probabilidad acumulada

alpha<- 1-0.92   # ic 92%
c(theta.hat+qnorm(alpha/2,lower.tail = T)*se.hat,
  theta.hat+qnorm(alpha/2,lower.tail = F)*se.hat)   

########################################################################################
################################## ESTIMACION PUNTUAL ##################################
########################################################################################

## Ejemplo 1: Estimacion de E[|X1-X2|] con X1~N(0,1), X2~N(0,1)

m<- 10000   # replicas
g<- numeric(m)
for(i in 1:m){
  x<- rnorm(2)   # 2 normales estandar
  g[i]<- abs(x[1]-x[2])   # replicas
}

theta.hat<- mean(g); theta.hat  # valor esperado estimado
theta<- 2/sqrt(pi)  # valor esperado teorico

cbind(theta,theta.hat)  # comparo teorico vs estimado

# Error estandar en la estimacion del promedio usando 
# el estimador SESGADO

se.xbar<- (1/sqrt(m))*mean((g-mean(g))^2); se.xbar   # estimado

# Error estandar en la estimacion del promedio usando 
# el estimador INSESGADO

se.xbar2<- (1/sqrt(m-1))*mean((g-mean(g))^2); se.xbar2   # estimado

sqrt((2-(4/pi))/m)   # teorico


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 2: Estimacion del ECM de un estimador

n <- 30   # tamaño muestra
m <- 5000  # replicas
p<- 0.275  # probabilidad de exito

y<- rbinom(m,size = n, prob = p)
plot(table(y))
phat<- (y+1)/(n+2)
theta.hat <- (phat-p)^2

ECM.hat<- mean(theta.hat); ECM.hat # estimacion MC de ECM
se_ECM.hat<- sqrt(sum((theta.hat-mean(theta.hat))^2))/m; se_ECM.hat    # error estandar del ECM

ECM_teo<- ((4-n)*(p^2-p)+1)/(n+2)^2; ECM_teo

c(ECM.hat,ECM_teo)


#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

# Ejemplo 3: TCL para medianas

# Hay una version del TCL para las medianas muestrales, 
# de tal manera que la mediana puede usarse para estimar
# a la mediana poblacional. 

# Para distribuciones simetricas, esto significa que la 
# mediana muestral puede usarse tambien para estimar a la
# media poblacional.


m <- 5000  # # replicas
n <- 1000  # tamaño muestra
mu<- 2.4
sigma<- 5

xtilde.hat <- rep(NA, m)  
for (i in seq_len(m)) {   # notar "seq_len" en el contador
  x= rnorm(n, mean = mu, sd = sigma)  # valores simulados de una distribucion simetrica
  xtilde.hat[i] = median(x)   # mediana muestral
}


hist(xtilde.hat,probability = T)
curve(dnorm(x,mean = mean(xtilde.hat),sd=sd(xtilde.hat)),add=T,lwd=2,col="red")

# Checamos normalidad

qqnorm(xtilde.hat);qqline(xtilde.hat, col = 2)
library(nortest)
lillie.test(xtilde.hat)
mean(xtilde.hat); mu  # comparamos con la media poblacional mu
sd(xtilde.hat)   # error estandar mediana muestral
sigma/sqrt(n)   # error estandar media muestral

# Eficiencia relativa entre los estimadores de la media poblacional: media muestral vs mediana muestral
(ECM_media<- sigma^2/n)
(ECM_mediana<- var(xtilde.hat))

eff<- ECM_media/ECM_mediana; eff


########################################################################################
############################### ESTIMACION POR INTERVALOS ##############################
########################################################################################

## Ejemplo 1: Intervalo de confianza para la media 
## Supuesto: X~N(mu,sigma) 

media.pob <- 4   # media normal
desvest.pob <- 2   # desv estandar normal
a<- 0.90

ic_media <- function(n, nivel_conf=a, mu=media.pob, sigma=desvest.pob) {
  x = rnorm(n, mu, sigma)   # supuesto normalidad
  xbar = mean(x)
  alpha = 1 - nivel_conf
  q = abs(qnorm(alpha/2,lower.tail=TRUE))
  se = sigma / sqrt(n)   # error estandar de la media
  ci = data.frame(lim.inf = xbar - q * se,
                  lim.sup = xbar + q * se)
  ci
}

ic_media(1000)  # ic para una sola muestra de tamaño n

# Afortunadamente en R....
library(PASWR2)
cisim(samples = 100, n = 30, parameter = 100, sigma = 10, conf.level = 0.90)
# Simula 100 muestras de n=30 a partir de N(mu=100, sigma=10)
# A partir de estas 100 muestras, el 90% de los ic para la media se muestran en la 
# grafica.  

cisim(100, 30, 100, 10, type = "Var")  # ic varianza

cisim(100, 50, 0.5, type = "Pi", conf.level = 0.92)   # ic proporcion

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 2: Intervalo de confianza para la proporcion
## Supuesto: X~Ber(p)

ic_p = function(datos,confianza){
  n = length(datos)
  alpha= 1-confianza
  p_hat = mean(datos)
  se = sqrt(p_hat * (1 - p_hat) / n)
  z_star = abs(qnorm(p = alpha / 2, lower.tail = FALSE))
  c(lower = p_hat - z_star * se, upper = p_hat + z_star * se)
}

y<- rbinom(20, size=1, prob=0.56)   # generamos bernoulli
ic_p(y,0.87)


#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 3: Estimacion MC del nivel de confianza del intervalo 
## para varianza
## Supuesto: X~N(mu,sigma)

n<- 100  # tamaño muestra
alpha<- 0.05
m<- 2000   # replicas, es decir, numero de muestras
mu<- -1.4
sigma<- sqrt(25)

# La idea es que la proporcion muestral de intervalos que contengan al valor verdadero
# sigma^2=25 es una estimacion MC de 1-alpha

# Por simplicidad consideramos el intervalo superior.

icvar_sup<- function(n,alpha){
  y= rnorm(n,mean=mu,sd=sigma)
  return((n-1)*var(y)/qchisq(alpha,df=n-1))  # lim. sup ic varianza
}

lim.sup<- replicate(m,expr=icvar_sup(n=100,alpha=0.05))
sum(sigma^2< lim.sup)   # no. intervalos que contiene a sigma^2
conf.hat_MC<- mean(sigma^2< lim.sup); conf.hat_MC  # media para nivel de confianza
se.hat<- sqrt((conf.hat_MC*(1-conf.hat_MC)/m)); se.hat  # error estandar   


########################################################################################
############################## PRUEBAS DE HIPOTESIS ####################################
########################################################################################


## Ejemplo 1: Error empirico (tipo I)

# H0: mu=750
# Ha: mu>750

n<- 20; alpha<- 0.05  # valor "teorico"
mu0<- 750
s<- 50 # valor estimado para sigma poblacional 
m<- 10000   # replicas
p<- numeric(m)  # guarda los valores-p
for(j in 1:m){
  x= rnorm(n,mean=mu0,sd=s)  # supuesto forzoso para estadistico T rnorm(n,mean=4,sd=0)
  prueba.t= t.test(x,alternative="greater",mu=mu0)
  p[j]<-prueba.t$p.value  # valor "simulado"
}

p[1:100]  # primeros 100 valores del valor-p de la prueba

p.hat<- mean(p< alpha); p.hat   # error tipo I
se.hat<- sqrt(p.hat*(1-p.hat)/m)
rbind(p.hat,se.hat)


# Las estimaciones de p.hat deben ser cercanas a alpha=0.05 porque todas las muestras
# fueron generadas bajo el supuesto de distrib. normal.

# Que pasa si suponemos que X~exp(lambda)?

n<- 20; alpha<- 0.05  # valor "teorico"
mu0<- 750
m<- 10000   # replicas
p<- numeric(m)  # guarda los valores-p
for(j in 1:m){
  lambda<- 1/mu0  
  x= rexp(n,rate=lambda)   # rate=lambda en nuestra parametrizacion
  prueba.t= t.test(x,alternative="greater",mu=mu0)
  p[j]<-prueba.t$p.value  # valor "simulado"
}

p.hat<- mean(p< alpha); p.hat   # error tipo I
se.hat<- sqrt(p.hat*(1-p.hat)/m)
rbind(p.hat,se.hat)

# El supuesto de normalidad es un requisito muy importante 
# para usar el estadistico de prueba T.

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 2: Normalidad univariada (prueba para la asimetria)

# H0: asimetria=0 (simetrica)
# Ha: asimetria=!0

asimetria<- function(x){   # calcula el coef. de asimetria muestral
  xbar= mean(x)
  m3= mean((x-xbar)^3)  # tercer momento central
  m2= mean((x-xbar)^2)  # segundo momento central
  return(m3/m2^1.5)
}

n<- c(10,20,30,50,100,500)   # tamaños de muestra
p.rechazo<- numeric(length(n))

alpha<- 0.05
m<- 20000    # numero de replicas
val.crit_derecha<- qnorm(alpha/2,0,sqrt(6/n),lower.tail = F)  # valores criticos para cada n
val.crit_izquierda<- qnorm(alpha/2,0,sqrt(6/n),lower.tail = T)  # valores criticos para cada n


for(i in 1:length(n)){  # ciclo tamaño muestra
  prueba.asimetria= numeric(m)  # decisiones de la prueba
  for(j in 1:m){  # ciclo simulacion para ese valor de n
    x= rnorm(n[i])  # distribucion de la poblacion
    prueba.asimetria[j]= as.integer(asimetria(x)>=val.crit_derecha[i]|
                                      asimetria(x)<=val.crit_izquierda[i])  # 1(rech),0(acep)
  }
  p.rechazo[i]<- mean(prueba.asimetria)  # proporcion rechazada
}

p.rechazo
result<- rbind(n,p.rechazo)
colnames(result)<- c("","","","","","")
rownames(result)<- c("n","alfa_hat"); result


# OJO: la aproximacion asintotica para el coef. de asimetria NO es adecuada para
# n<=50, ya que las estimaciones estan muy alejadas del valor verdadero de alfa=0.05

# Usamos val.crit2 (valor exacto para muestras finitas)

n<-c(10,20,30,50,100,500,1000)   # tamaños de muestra
p.rechazo<-numeric(length(n))
m<-20000
val.crit_derecha2<- qnorm(alpha/2,0,sqrt(6*(n-2)/((n+1)*(n+3))),lower.tail = F)  # valores criticos para cada n
val.crit_izquierda2<- qnorm(alpha/2,0,sqrt(6*(n-2)/((n+1)*(n+3))),lower.tail = T)  # valores criticos para cada n

for(i in 1:length(n)){  # ciclo tamaño muestra
  prueba.asimetria= numeric(m)  # decisiones de la prueba
  for(j in 1:m){  # ciclo simulacion para ese valor de n
    x= rnorm(n[i])  # distribucion del coef. asimetria
    prueba.asimetria[j]= as.integer(asimetria(x)>=val.crit_derecha2[i]|
                                      asimetria(x)<=val.crit_izquierda2[i])  # 1(rech),0(acep)
  }
  p.rechazo[i]<- mean(prueba.asimetria)  # proporcion rechazada
}
result<- rbind(n,p.rechazo)
colnames(result)<- c("","","","","","")
rownames(result)<- c("n","alfa_hat"); result

# Ahora si las estimaciones de "alpha" son mas cercanas al valor verdadero.

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 3: Potencia (empirica) de una prueba

# H0 vs Ha, un error Tipo II ocurre cuando Ha es cierta 
# pero H0 NO es rechazada

# H0: mu=750
# Ha: mu>750

# Potencia de una prueba esta dada por la funcion potencia.

n<- 50    # tamaño muestra
m<- 2000    # num. replicas
mu0<- 750   # hipotesis nula
s<- 50    # desv. estandar muestral
alpha<- 0.05
mu<- c(seq(500,1000,by= 5))   # alternativas
M<- length(mu)
potencia<- numeric(M)

for(i in 1:M){
  mua= mu[i]  # valores alternativos
  p.val= replicate(m,expr={
    x= rnorm(n,mean=mua,sd=s)
    prueba.t= t.test(x,alternative="greater",mu=mu0)
    prueba.t$p.value
  })
  
  potencia[i]= mean(p.val<= alpha)
}

# Dibujamos la curva de la potencia empirica con barras de error

install.packages("Hmisc")
library(Hmisc)

plot(mu,potencia,type="l")
abline(v=mu0,lty=1,col="red")
abline(h=alpha,lty=1,col="blue")

se<- sqrt(potencia*(1-potencia)/m)

errbar(mu,potencia,yplus=potencia+se,yminus=potencia-se,xlab=bquote(theta))
lines(mu,potencia,lty=3)


########################################################################################
##################### METODOS DE MONTE CARLO NO PARAMETRICOS ########################### 
#####################             (BOOTSTRAP)                ###########################
########################################################################################

## a) Estimacion del error estandar 

### Ejemplo 1: Coeficiente de correlacion (datos law82)

install.packages("bootstrap")
library(bootstrap)

# Datos originales: Calificaciones de 82 escuelas
# LSAT (average score on a national law test) 
# GPA (average undergraduate grade-point average)

data(law82)  # 82 escuelas en total
names(law82)
plot(law82$LSAT,law82$GPA,pch=16)

N<- nrow(law82)

cor.original<- cor(law82$LSAT,law82$GPA)      # correlacion datos originales
error.teo.original<- sqrt((1-(cor.original^2))/(N-2))   # error estandar teorico para la correlacion original

(original<- cbind(cor.original,error.teo.original))

# Tomamos la muestra de Efron & Tibshirani (data law)

N_efr<- nrow(law)
cor.efron<- cor(law$LSAT,law$GPA)    # correlacion datos Efron
error.teo.efron<- sqrt((1-(cor.efron^2))/(N_efr-2))  # error estandar teorico para la correlacion efron

(efron<-cbind(cor.efron,error.teo.efron))


# Comparando la poblacion con la muestra de Efron

(cor.compara<- cbind(cor.original,cor.efron))
(se.compara<- cbind(error.teo.original,error.teo.efron))

# Estimacion bootstrap del coeficiente de correlacion

B<- 500          # numero de replicas (muestras) bootstrap
R<- numeric(B)     # para guardar las replicas
n<- nrow(law)     # tamaño muestra Efron

for(b in 1:B){
  i= sample(1:n,size=n,replace=TRUE)  # con reemplazo
  print(i)   # para ver el # de renglon que es seleccionado
  LSAT= law$LSAT[i]
  GPA= law$GPA[i]
  R[b]= cor(LSAT,GPA)  
}
R
# Obtenemos por bootstrap:

(cor.boot<- R) # correlaciones de todas las muestras bootstrap
mean(cor.boot)
error.boot<- sd(R); error.boot   # error estandar por bootstrap
hist(R,prob=TRUE,
     main=paste("Distribución del coeficiente de correlación \n basado en",B, "réplicas bootstrap"),xlim=c(0,1))   # histograma de las replicas
abline(v=mean(cor.boot),lwd=2,col="blue",lty=2)
lines(density(cor.boot),lwd=2)  # densidad empirica
curve(dnorm(x, mean=mean(cor.boot), sd=sd(cor.boot)), 
      col="darkred", lwd=2,add=T)

# Comparamos la muestra original Efron con las replicas bootstrap:

error<- cbind(error.teo.efron,error.boot); error

# Otra manera (paquete "boot")
install.packages("boot")
library(boot)

r<- function(x,i){
  cor(x[i,1],x[i,2])
}

out_1<- boot(data=law,statistic=r,R=500); str(out_1)

# Analizamos la salida de "boot" 

cor.hat_efron.b<- out_1$t0; cor.hat_efron.b    # estimacion bootstrap del coef. correlacion (Efron)           
se.efron.b<- apply(out_1$t,2,sd); se.efron.b   # error estandar bootstrap

########################################################################################
############################# Estimacion de intervalos de confianza ####################
########################################################################################

## Ejemplo 1: Intervalo para comparacion de medias
setwd("C:/Users/Emman/Documents/CCH-N} FES-A/fessaa/FES/7mo semestre/Temas Selectos de Estadistica")
pollos <- read.table("./DATA/ChickData2.csv",header=T, sep=",")
attach(pollos)

names(pollos); str(pollos)
factor(pollos$alimento)

# numero de observaciones por cada tipo de dieta
table(pollos$alimento)

# comparacion del peso ganado por tipo de alimento

boxplot(pollos$peso~pollos$alimento, las=1, ylab="peso (g)", 
        xlab="alimento",main="Peso por tipo de alimento",col=rainbow(6))

# calculamos la diferencia en medias

pesomedio_cas<- mean(pollos$peso[pollos$alimento=="caseina"])  
pesomedio_harina<- mean(pollos$peso[pollos$alimento=="harina de carne"]) 

Dif.Medias<- pesomedio_cas-pesomedio_harina; Dif.Medias

# otra manera:

with(pollos, tapply(peso, alimento, mean))   # peso medio segun el tipo de alimento

# calculamos la diferencia en medianas

pesomediana_cas<- median(pollos$peso[pollos$alimento=="caseina"])  
pesomediana_harina<- median(pollos$peso[pollos$alimento=="harina de carne"]) 

Dif.Medianas<- pesomediana_cas-pesomediana_harina; Dif.Medianas

# otra manera:

with(pollos, tapply(peso, alimento, median))   # mediana del peso segun el tipo de alimento

#****************************************************************************************

# a) Intervalos de confianza basados en normalidad de las poblaciones
library(nortest)

peso.cas<- pollos$peso[pollos$alimento=="caseina"] 
peso.har<- pollos$peso[pollos$alimento=="harina de carne"]

lillie.test(peso.cas)
lillie.test(peso.har)

qqnorm(peso.cas);qqline(peso.cas,col = "steelblue", lwd = 2)
qqnorm(peso.har);qqline(peso.har,col = "darkgreen", lwd = 2)

nivel.conf<- 0.97
alpha<- 1-nivel.conf

ic<- t.test(peso.cas,peso.har,paired = F,mu0=0,var.equal=T,alternative = "two.sided",conf.level = nivel.conf)
ic$conf.int

Lmedias_t<- ic$conf.int[2]-ic$conf.int[1]  # longitud del intervalo de confianza

var.test(peso.cas,peso.har,ratio=1,alternative = "two.sided")

# Para las medianas (no se usa el supuesto de normalidad)

dif.median<- wilcox.test(peso.cas,peso.har,paired=F,mu=0, 
                         alternative = "two.sided",conf.int = T,conf.level = nivel.conf)
str(dif.median)
Lmedian_umann<- dif.median$conf.int[2]-dif.median$conf.int[1]


#****************************************************************************************

# b) Intervalos de confianza bootstrap para la diferencia de medias y medianas

set.seed(112021)   
(n.c <- length(peso.cas))  # no. de observaciones a extraer de caseina
(n.h <- length(peso.har))  # no. de observaciones a extraer de harina de carne
B <- 1000  # no. muestras bootstrap

Boot.caseina <- matrix(sample(peso.cas, size= B*n.c,replace=TRUE), 
                       ncol=B, nrow=n.c)

Boot.harina <- matrix(sample(peso.har, size= B*n.h,replace=TRUE), 
                      ncol=B, nrow=n.h)

dim(Boot.caseina); dim(Boot.harina)

# Revisemos las muestras
Boot.caseina[1:12,1:10]
Boot.harina[1:11,1:6]

# calculamos la diferencia en MEDIAS para cada muestra bootstrap
Boot.Dif.Medias <- colMeans(Boot.caseina) - colMeans(Boot.harina); Boot.Dif.Medias

# calculamos la diferencia en MEDIANAS para cada muestra bootstrap
Boot.Dif.Medianas <- apply(Boot.caseina, MARGIN=2, FUN=median) -
  apply(Boot.harina, MARGIN=2, FUN=median); Boot.Dif.Medianas

# 1. Metodo Normal

(ic_difmedias_norm<- c(mean(Boot.Dif.Medias)-abs(qnorm(alpha/2))*sd(Boot.Dif.Medias),
                       mean(Boot.Dif.Medias)+abs(qnorm(alpha/2))*sd(Boot.Dif.Medias)))

(Lmedias_norm<- ic_difmedias_norm[2]-ic_difmedias_norm[1])


(ic_difmedianas_norm<- c(mean(Boot.Dif.Medianas)-abs(qnorm(alpha/2))*sd(Boot.Dif.Medianas),
                         mean(Boot.Dif.Medianas)+abs(qnorm(alpha/2))*sd(Boot.Dif.Medianas)))

(Lmedianas_norm<- ic_difmedianas_norm[2]-ic_difmedianas_norm[1])

# Comparacion:

rbind(ic_difmedias_norm,ic_difmedianas_norm)
cbind(Lmedias_norm,Lmedianas_norm)

# 2. Metodo del porcentil

ic_difmedias_porc<- c(quantile(Boot.Dif.Medias, prob=alpha/2), quantile(Boot.Dif.Medias, prob=1-alpha/2)); ic_difmedias_porc
Lmedias_porc<- ic_difmedias_porc[2]-ic_difmedias_porc[1]


ic_difmedianas_porc<- c(quantile(Boot.Dif.Medianas, prob=alpha/2), quantile(Boot.Dif.Medianas, prob=1-alpha/2)); ic_difmedianas_porc
Lmedianas_porc<- ic_difmedianas_porc[2]-ic_difmedianas_porc[1]

# Comparacion:

rbind(ic_difmedias_porc,ic_difmedianas_porc)
cbind(Lmedias_porc,Lmedianas_porc)

# 3. Metodo basico

ic_difmedias_bas<- c(2*Dif.Medias - quantile(Boot.Dif.Medias, prob=1-alpha/2),
                     2*Dif.Medias - quantile(Boot.Dif.Medias, prob=alpha/2)); ic_difmedias_bas

(Lmedias_bas<- ic_difmedias_bas[2]-ic_difmedias_bas[1])

ic_difmedianas_bas<- c(2*Dif.Medianas - quantile(Boot.Dif.Medianas, prob=1-alpha/2),
                       2*Dif.Medianas - quantile(Boot.Dif.Medianas, prob=alpha/2)); ic_difmedianas_bas

(Lmedianas_bas<- ic_difmedianas_bas[2]-ic_difmedianas_bas[1])

rbind(ic_difmedias_bas,ic_difmedianas_bas)
cbind(Lmedias_bas,Lmedianas_bas)

# Comparacion de los intervalos de confianza para la diferencia de medias

icboot_medias<- matrix(round(c(ic_difmedias_norm[1],ic_difmedias_norm[2],Lmedias_norm,
                               ic_difmedias_porc[1],ic_difmedias_porc[2],Lmedias_porc,
                               ic_difmedias_bas[1],ic_difmedias_bas[2],Lmedias_bas,
                               ic$conf.int[1],ic$conf.int[2],Lmedias_t),digits=3),
                       byrow=T,ncol=3)
row.names(icboot_medias)<- c("Normal","Porcentil","Básico","t")
colnames(icboot_medias)<- c("lim.inf","lim.sup","L")
icboot_medias

# Comparacion de los intervalos de confianza para la diferencia de medianas

icboot_medianas<- matrix(round(c(ic_difmedianas_norm[1],ic_difmedianas_norm[2],Lmedianas_norm,
                                 ic_difmedianas_porc[1],ic_difmedianas_porc[2],Lmedianas_porc,
                                 ic_difmedianas_bas[1],ic_difmedianas_bas[2],Lmedianas_bas,
                                 dif.median$conf.int[1],dif.median$conf.int[2],Lmedian_umann),
                               digits=3),byrow=T,ncol=3)
row.names(icboot_medianas)<- c("Normal","Porcentil","Básico","U-Mann")
colnames(icboot_medianas)<- c("lim.inf","lim.sup","L")
icboot_medianas


########################################################################################
################################### Regresion lineal ###################################
########################################################################################

set.seed(112021)
n <- 500
x <- rgamma(n,2,5)
y <- x + rgamma(n,2,5)
datos.pob <- as.data.frame(cbind(x, y))

lillie.test(datos.pob$x)

datos.muestra <- datos.pob[sample(nrow(datos.pob), 20, replace = TRUE),]

modelo.pob<- lm(y~x, data=datos.pob); summary(modelo.pob)
modelo.muestra<- lm(y~x, data=datos.muestra); summary(modelo.muestra)

# Graficamos los datos simulados con sus regresiones
plot(x,y)
abline(modelo.pob,col="red")   # todos los datos
abline(modelo.muestra,col="blue")  # la muestra

# Y si hacemos bootstrap?

muestra_coef_intercept <- NULL
muestra_coef_x1 <- NULL

for (i in 1:100) {
  
  muestra_b = datos.muestra[sample(1:nrow(datos.muestra), 
                                   nrow(datos.muestra), replace = TRUE), ]
  
  # Estimamos la regresion simple
  model_bootstrap <- lm(y ~ x, data = muestra_b)
  
  # Guardamos los coeficientes
  muestra_coef_intercept <-
    c(muestra_coef_intercept, model_bootstrap$coefficients[1])
  
  muestra_coef_x1 <-
    c(muestra_coef_x1, model_bootstrap$coefficients[2])
}

coefs <- rbind(muestra_coef_intercept, muestra_coef_x1)


# Escribimos los resultados en una tabla
means.boot = c(mean(muestra_coef_intercept), mean(muestra_coef_x1))
knitr::kable(round(
  cbind(
    pob= coef(summary(modelo.pob))[,1],
    muestra = coef(summary(modelo.muestra))[,1],
    bootstrap = means.boot),4), 
  format="simple", caption = "Coeficientes de regresión en diferentes modelos")

confint(modelo.pob)
confint(modelo.muestra)

a <-
  cbind(
    quantile(muestra_coef_intercept, prob = 0.025),
    quantile(muestra_coef_intercept, prob = 0.975))
b <-
  cbind(quantile(muestra_coef_x1, prob = 0.025),
        quantile(muestra_coef_x1, prob = 0.975))

c <-
  round(cbind(
    pob = confint(modelo.pob),
    muestra = confint(modelo.muestra),
    bootstrap = rbind(a, b)), 4)
colnames(c) <- c("2.5 %", "97.5 %",
                 "2.5 %", "97.5 %",
                 "2.5 %", "97.5 %")
knitr::kable(rbind(
  c('pob',
    'pob',
    'muestra',
    'muestra',
    'bootstrap',
    'bootstrap'),c))


#Prediccion
datos.nuevos = seq(min(x), max(x), by = 0.05)
conf_interval <-
  predict(
    modelo.muestra,
    newdata = data.frame(x = datos.nuevos),
    interval = "confidence",
    level = 0.90)

# Graficamos todas las regresiones
plot(
  y ~ x,
  col = "gray",pch=16,
  xlab = "x",
  ylab = "y",
  main = "Comparación entre regresiones")
apply(coefs, 2, abline, col = rgb(1, 0, 0, 0.1))
abline(coef(modelo.pob)[1], coef(modelo.pob)[2], col = "blue")
abline(coef(modelo.muestra)[1],coef(modelo.muestra)[2],col = "black",
       lty = 2, lwd=3)
lines(datos.nuevos, conf_interval[, 2], col = "black", lty = 3, lwd=3)
lines(datos.nuevos, conf_interval[, 3], col = "black", lty = 3, lwd=3)
legend("topleft",
       legend = c("Bootstrap", "Población", 'Muestra'),
       col = c("red", "blue", 'green'),
       lty = 1:3,
       cex = 0.8)

##############################################

## Recordemos nuestro ejemplo del tamaño del cerebro

inteligencia<- read.table("./DATA/Datos cerebroFile.txt",header=T,row.names=1);inteligencia
attach(inteligencia)

(model<- lm(IQ~., data= inteligencia))  # considera a todas las variables

(i.c<- confint(model,"(Intercept)",level=0.90))

# Lo estimamos por bootstrap

library(boot)
func.reg<- function(data, id){
  coef(lm(IQ~Cerebro+Altura+Peso, data= data[id,]))
}

model.B<- boot(inteligencia,func.reg,R=1000)
str(model.B)

model.B$t0   # estimacion bootstrap de los coeficientes

head(model.B$t)   # col1=intercepto, col2=Cerebro, col3=Altura, col4=Peso


boot.ci(model.B,conf= 0.90,index=1,type=c("norm","perc","basic"))  # intercepto

