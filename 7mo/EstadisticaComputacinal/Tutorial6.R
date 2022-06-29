# Temas Selectos de Estadistica: Estadistica Computacional
# Prof. Elizabeth Martinez
# FES-Acatlan, UNAM
# TUTORIAL 6: GENERACION DE VARIABLES ALEATORIAS
setwd("C:/Users/Emman/Documents/CCH-N} FES-A/fessaa/FES/7mo semestre/Temas Selectos de Estadistica")
########################################################################################
######################## GENERADORES DE NUMEROS ALEATORIOS #############################
########################################################################################

#***************************************************************************************
#************************ METODO 1: TRANSFORMACION INVERSA CONTINUO ********************
#***************************************************************************************

## Ejemplo 1: X~Beta(alpha=3, beta=1)

f<- function(x) 3*x^2

y<-seq(0,1,0.001)
plot(y,f(y),type="l",col="red")

# O bien,
curve(f,0,1,col="purple")

# ¿funcion de densidad valida?

integrate(f,0,1)

# Generacion de numeros aleatorios

n<- 20000
set.seed(112021)
u<- runif(n)
x<- u^(1/3)
hist(x,prob=TRUE,main=expression(f(x)==3*x^2),col="gray70")   # histograma de densidad para la muestra
lines(y,f(y),col="red",lwd=2)


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Ejercicio: Calcula el valor esperado y la varianza TEORICOS para la variable X con 
# f(x)=3x^2. Compara con los correspondientes valores de la muestra aleatoria.
#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

fx<- function(x) x*(3*x^2)
fx2<- function(x) (x^2)*(3*x^2)

EX<- integrate(fx,0,1); EX$value     # promedio teorico
mean(x)     # promedio de los nuevos valores generados

EX2<- integrate(fx2,0,1); 
varX<- EX2$value-(EX$value)^2; varX  # varianza teorica
var(x)   # varianza de los nuevos valores generados


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 2: X~exp(lambda)
n<- 20000
u<- runif(n)
lambda<- 1.5
x<- -(1/lambda)*log(u)

library(RColorBrewer)
display.brewer.all()    # muestra todos los colores disponibles de la paleta RColorBrewer


hist(x,prob=TRUE,col=brewer.pal(n = 6, name = "Blues"))   # histograma de densidad para la muestra
y<-seq(0,5,0.01)
lines(y,lambda*exp(-lambda*y),col="blue",lwd=2)    # curva de densidad para f(x)

1/lambda      # promedio teorico
mean(x)                # promedio de los nuevos valores generados

1/lambda^2      # varianza teorica
var(x)

hist(rexp(2000,rate=lambda))



#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 3: X~Wei(alpha,beta)

n<- 2000
u<- runif(n)
alpha<- 2
beta<- 3.5
x<- beta*(-log(1-u))^{1/alpha}; x
library(RColorBrewer)
hist(x,prob=TRUE,col=brewer.pal(n = 6, name = "Oranges"))   # histograma de densidad para la muestra
y<-seq(0,10,0.01)
lines(y,(alpha/beta^{alpha})*y^{alpha-1}*exp(-(y/beta)^alpha),col="blue",lwd=2)


EW<- beta*gamma(1+1/alpha); EW   # promedio teorico Weibull
mean(x)    # promedio de los nuevos valores

EW2<- beta^2*(gamma(1+2/alpha))
varW<- EW2-(EW^2); varW    # varianza teorica Weibull
var(x)    # varianza de los nuevos valores

#***************************************************************************************
#************************ METODO 1: TRANSFORMACION INVERSA DISCRETO ********************
#***************************************************************************************

## Ejemplo 1:

x<- c(0,1,2)   # valor real
px<- c(0.3,0.2,0.5)  # valor real

library(dplyr)
inv_discr <- function(n){
  u <- runif(n)
  x <- case_when(         # library(dplyr)
    u <= 0.3 ~ 0, 
    u <= 0.5 ~ 1,
    u <= 1   ~ 2
  )
}

x.sim <- inv_discr(20000)
prop.table(table(x.sim))    # distribucion de probabilidad simulada
barplot(table(x.sim))

# Calculamos los valores teoricos:

EX<- function(x,fx) sum(x*fx)
VX<- function(x,fx) sum((x^2)*fx)-(EX(x,fx))^2

EX(x,px); VX(x,px)

mean(x.sim);var(x.sim)   # valores muestrales

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 2: X~Ber(p)

n<- 2000
u<- runif(n)
p<- 0.4  # prob. exito
q<- 1-p  # prob. fracaso
x.sim<- as.integer(u > 1-p)   
prop.table(table(x.sim))    # distribucion de probabilidad simulada
barplot(table(x.sim))

# Otra forma

ber <- function(n,p){
  u <- runif(n)
  x <- case_when(         # library(dplyr)
    u <= 1-p ~ 0, 
    u <= 1 ~ 1
  )
}

x.sim<- ber(2000,0.4)
prop.table(table(x.sim))    # distribucion de probabilidad simulada
barplot(table(x.sim))


# Manera opcional: 
rbinom(n,size=1,prob=p)

# Comparamos valores teoricos vs muestrales

EX<- p; EX    # promedio teorico
mean(x.sim)       # promedio de los nuevos valores

varX<- p*(1-p); varX   # varianza teorica
var(x.sim)                 # varianza de los nuevos valores

# Usando la funcion en R:

barplot(table(rbinom(n,size=1,prob=p)))


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 3: X~Geom(p)

n<- 2000
u<- runif(n)
p<- 0.4
q<- 1-p
x<- ceiling(log(1-u)/log(q))-1   # alternativa: floor(log(u)/log(q))

barplot(table(x))   # grafica de barras valores muestrales
# O bien,
plot(table(x)) #poner asi en caos de var discreta

EX<- (1-p)/p; EX   # promedio teorico
mean(x)            # promedio muestral

varX<- (1-p)/p^2; varX   # varianza teorica
var(x)                   # varianza muestral

# Otra alternativa

x<- trunc(log(u)/log(1-p))


# Usando la funcion en R:

barplot(table(rgeom(n,prob=p)))


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 4: X~log(theta)
# Esta distribucion fue presentada por Fisher en un articulo (1943) 
# donde describia la abundancia relativa de especies en un
# determinado habitat.
# funcion sacada dde un articulo, para drarlo como ejemplo
rlogaritmo<-function(n,theta){
  u= runif(n)
  N= ceiling(-16/log10(theta))
  k= 1:N
  a= -1/log(1-theta)
  fk= exp(log(a)+k*log(theta)-log(k))
  Fk= cumsum(fk)
  x= integer(n)
  for(i in 1:n){
    x[i]= as.integer(sum(u[i]>Fk)) # inversa
    while(x[i]==N){
      logf= log(a)+(N+1)*log(theta)-log(N+1)
      fk= c(fk,exp(logf))
      Fk= c(Fk,Fk[N]+fk[N+1])
      N= +1
      x[i]= as.integer(sum(u[i]>Fk))
    }
  }
  x+1
}


n<-2000
theta<-0.5  # (0,1)
x<-rlogaritmo(n,theta)  # num. aleatorios

barplot(table(x),col=terrain.colors(7))   # grafica valores muestrales

a<- -1/log(1-theta)
EX<- a*(theta/(1-theta)); EX   # promedio teorico
mean(x)                        # promedio muestral

num<- theta^2+(theta*log(1-theta))
denom<- (1-theta)^2*(log(1-theta))^2 
varX<- -num/denom; varX     # varianza teorica
var(x)                      # varianza muestral


# Calculamos la funcion de probabilidad teorica usando los x's aleatorios

k<- sort(unique(x))

pk<- a*theta^{k}/k; pk

# Comparamos con la f.m.p muestral
prob.muestral<- table(x)/n
round(rbind(prob.muestral,pk),digits=4)


#***************************************************************************************
#******************************** METODO 2: TRANSFORMACIONES ***************************
#***************************************************************************************

## Ejemplo 1: X~Beta(alpha,beta) como el cociente de v.a 

n<- 2000
alpha<- 4
beta<- 3
u<- rgamma(n,shape=alpha,rate=1)
v<- rgamma(n,shape=beta,rate=1)
x<- u/(u+v)   # transformacion 
hist(x)

mean(x); alpha/(alpha+beta)    # promedio muestral vs teorico

var(x); (alpha*beta)/(((alpha+beta)^2)*(alpha+beta+1))    # varianza muestral vs teorica


# Otra manera de comparar:

q<- qbeta(ppoints(n),alpha,beta)
qqplot(q,x,cex=0.2,xlab="Beta(4,3)",ylab="muestra")
abline(0,1,col="red")   # recta a 45 grados


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 2: X~chi^2 (nu=1)

n<- 2000
nu<- 1
u<- rnorm(n,mean=0,sd=1)  #usamos el generador de R
x<- u^2    # transformacion cuadratica

mean(x); nu    # promedio muestral vs teorico

var(x); 2*nu    # varianza muestral vs teorica

hist(x)



#################################33 3 grados de libertad 
n<- 20000
nu<- 3
u1<- rnorm(n,mean=0,sd=1)  #usamos el generador de R
u2<- rnorm(n,mean=0,sd=1)  #usamos el generador de R
u3<- rnorm(n,mean=0,sd=1)  #usamos el generador de R
x<- (u1^2)+(u2^2)+(u3^2)    # transformacion cuadratica

mean(x); nu    # promedio muestral vs teorico

var(x); 2*nu    # varianza muestral vs teorica

hist(x)

q<- qchisq(ppoints(n),nu)
qqplot(q,x,cex=0.2,xlab="Chi^2 (3 gl)",ylab="muestra")
abline(0,1,col="red")   # recta a 45 grados


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 3: X~N(0,1) (transformacion de Box-Muller)

n = 5000
U1 = runif(n, min = 0, max = 1)
U2 = runif(n, min = 0, max = 1)
Z1 = sqrt(-2*log(U1))*cos(2*pi*U2)
Z2 = sqrt(-2*log(U1))*sin(2*pi*U2)
hist(Z2);hist(Z1)


#***************************************************************************************
#***************************** METODO 3: ACEPTACION-RECHAZO ****************************
#***************************************************************************************

## Ejemplo 1: discreto

#x<- c(1,2,3,4)
#px<- c(0.20,0.15,0.25,0.40)


AR_discr <- function() {
  pj = c(0.20,0.15,0.25,0.40)
  qj = 1/4 
  c = length(pj)*max(pj)  
  x = numeric()   # para guardar los valores generados
  i = 1         # contador
  while(i <= 1){
    u = runif(1) # Paso 1
    y = sample(1:4,1) # Paso 2
    if(u <= pj[y]/c*qj){
      x[i] <- y
      i <- i+1
    }
  }
  x  # valores generados
}

AR_discr(1000)  # NO!

library(purrr)
x <- rerun(1000, AR_discr())%>% flatten_dbl()   # library(purrr)
# flatten_dbl: una lista es convertida a un vector, en este caso, doble. Es parecido a "unlist".

# %>% es un operador "pipe", que pasa datos de la salida de una funcion a la izquierda y los
# pone (por default) en el primer parametro de la funcion de la derecha.

prop.table(table(x))
barplot(prop.table(table(x)))


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 3: X~Beta(2,2)

alpha<- 2
beta<- 2

x<-seq(0,1,0.01)
fx<-(6*x)*(1-x)

# Graficamos la funcion objetivo, f(x)

plot(x,fx,type="l",col="blue",lwd=2,xlim=c(0,1))

# Observamos que esta limitada a tomar valores dentro de la region rectangular:

abline(h=1.5,lty=2)
abline(v=1,lty=2)

# Asi que un candidato natural para ser g(x) es la constante 1, esto es,
gx<- 1     # distribucion uniforme U[0,1]

fx/gx
plot(x,fx/gx,type="l",col="red")

# Se observa que fx/gx<3/2, de aqui que c=3/2

n<- 2000
k<- 0   # contador para aceptar valores
j<- 0  # contador de iteraciones necesarias para generar las "n" variables
y<- numeric(n)

while(k< n){
  u= runif(1)
  j= j+1  
  x= runif(1)     # v.a de g(x)~U(0,1)
  if(4*x*(1-x) > u){   # comparo con f(x)/cg(x)
    k= k+1  # acepto x
    y[k]= x   
  }    
}		

j

# Se necesitan "j" iteraciones para producir "n" variables aleatorias.

# a) Verificacion: grafica
hist(y,probability = T,col="gray50")  # histograma de las variables simuladas
curve(dbeta(x,alpha,beta),col="darkblue", lwd=2, add=TRUE, yaxt="n")   # curva teorica

# b) Verificacion: media y varianza teoricos vs muestrales
mean(y); alpha/(alpha+beta)   # promedio muestral y teorico
var(y); (alpha*beta)/((alpha+beta)^2*(alpha+beta+1))   # varianza muestral y teorica

# c) Verificacion: cuantiles teoricos vs muestrales
p<- seq(0.1,0.9,0.1)
Qhat<- quantile(y,p)   # cuantiles muestrales
Q<- qbeta(p,alpha,beta)  # teoricos

rbind(Qhat,Q)

## Otra forma:

beta22 <- function(){
  u1 = runif(1)
  u2 = runif(1)
  while(u2 > 4*u1*(1-u1)){   # comparo con f(x)/cg(x)
    u1 = runif(1)
    u2 = runif(1)
  }
  u1
}


library(plyr)
x <- rdply(2000, beta22)    # library(plyr)

system.time(rdply(2000, beta22))


mean(x$V1); var(x$V1)

library(purrr)
hist(rerun(2000, beta22())%>% flatten_dbl(),main="Beta(2,2)",xlab="",probability = T)  # library(purrr)


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 3: X~Beta(alpha=3,beta=1)


curve (dbeta(x,3 ,1),0 ,1) # jeje ya la habiamos analizado: f(x)=3x^2

n =2000
mbeta <- numeric()   # guarda los valores generados
for (i in 1:n)
{
  y <- runif(1)
  pseud2 <- runif(1)
  if (pseud2 <= y^2) mbeta[i] <-y
  else mbeta[i]=0
}
mbetadef <- mbeta[mbeta!=0]

tasacepbeta <- length (mbetadef )/length(mbeta)
cat('tasa de aceptacion:',tasacepbeta)

print('numero promedio de iteraciones')
print(1/tasacepbeta)

## O bien,

k<- 0   # contador para aceptar valores
j<- 0  # contador de iteraciones necesarias para generar las "n" variables
y<- numeric(n)

while(k< n){
  u= runif(1)
  j= j+1  
  x= runif(1)     # v.a de g(x)~U(0,1)
  if(x^2 > u){   # comparo con f(x)/cg(x)
    k= k+1  # acepto x
    y[k]= x   
  }    
}		

j

# Se necesitan aprox. 6000 iteraciones para producir 2000 valores.

# a) Verificacion: teoricos vs muestrales

alpha=3; beta=1
alpha/(alpha+beta); mean(mbetadef)   # media
(alpha*beta)/(((alpha+beta)^2)*(alpha+beta+1)); var(mbetadef)  # varianza

# b) Verificacion: grafica
hist(mbetadef,freq =F,main="Simulación de Beta(3,1)")
curve(dbeta(x,3,1),add =T,col ='red')

qqplot(qbeta(ppoints(n),alpha,beta),mbetadef,cex=0.2,xlab="Beta(3,1)",ylab="muestra")
abline(0,1,col="red")   # recta a 45 grados

# c) Verificacion: prueba de hipotesis no parametrica de bondad de ajuste

ks.test (mbetadef, alternative = "two.sided", 'pbeta',shape1=3,shape2=1)   # prueba de Kolmogorov-Smirnov


# Un codigo general para el metodo AR

A.R <- function(f, c, g, rg, n) { 
  n.aceptados= 0
  muestra=rep(NA, n)
  while (n.aceptados < n) {
    u=runif(1,0,1)
    y=rg(1)         
    if (u < f(y)/(c*g(y))) { # paso 3 (aceptar)
      n.aceptados=n.aceptados+1
      muestra[n.aceptados]= y
    }
  }
  muestra
}
#declarar a f g y rg como cunciones

f  <- function(x) 3*x^2     # funcion original
g  <- function(x) 1           # g(x) = 1 
rg <- function(n) runif(n,0,1)  # muestreo a partir de g
c  <- 3                         

x.simul <- A.R(f, c, g, rg, 5000) 

# Valores simulados
hist(x.simul, breaks=30, freq=FALSE, main="Simulación Beta(3,1)")
lines(seq(0, 1, len=100), 3*seq(0, 1, len=100)^2, col="red", lwd=2)



#***************************************************************************************
#********************************** METODO 4: CONVOLUCIONES ****************************
#***************************************************************************************

## Ejemplo 1: distribucion chi-cuadrada

n<- 2000   # renglones
nu<- 4     # columnas (# de normales)
x<- matrix(rnorm(n*nu),n,nu)^2   # matriz de normales al cuadrado
#suponemos que el metodo de normales es funcional de maxel-nueler
y<- rowSums(x)     # sumas de los renglones 
# O bien, y<-apply(X,MARGIN=1,FUN=sum)   # suma de los renglones aplicando la funcion "apply"

hist(y,col="gray70",probability = T,ylim=c(0,0.2))
curve(dchisq(x,nu),col="darkblue", lwd=2, add=TRUE, yaxt="n")   # curva teorica

mean(y); nu    # promedio muestral vs teorico
var(y); 2*nu   # varianza muestral vs teorica
#mean(y^2) ni se sabe que es

# Otra forma:

x1<- rnorm(1000)^2
x2<- rnorm(1000)^2
x3<- rnorm(1000)^2
x4<- rnorm(1000)^2

y.<- x1+x2+x3+x4; hist(y.)
mean(y.); var(y.)


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 2: distribucion normal estandar (metodo "crudo")

n<- 2000
mu<- 0.5   # valor recomendado
sigma<- sqrt(1/12)  # valor recomendado

# En la literatura se ha hecho la siguiente propuesta para generar una variable N(0,1).
# Se deben generar 12 uniformes

r1<- runif(n)
r2<- runif(n)
r3<- runif(n)
r4<- runif(n)
r5<- runif(n)
r6<- runif(n)
r7<- runif(n)
r8<- runif(n)
r9<- runif(n)
r10<- runif(n)
r11<- runif(n)
r12<- runif(n)

z<- (r1+r2+r3+r4+r5+r6+r7+r8+r9+r10+r11+r12)-6
hist(z,probability = T)
curve(dnorm(x),col="red", lwd=2, add=TRUE, yaxt="n")   # curva teorica
mean(z);sd(z)


#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 3: distribucion triangular

n<- 2000

r1<- runif(n)
r2<- runif(n)
r3<- runif(n)
r4<- runif(n)
r5<- runif(n)
r6<- runif(n)
r7<- runif(n)
r8<- runif(n)
r9<- runif(n)
r10<- runif(n)
r11<- runif(n)
r12<- runif(n)

y<- r1+r2+r3+r4+r5+r6+r7+r8+r9+r10+r11+r12
hist(y,probability = T)
library(EnvStats)
curve(dtri(x,min = 3, max = 9, mode = 6),col="red", lwd=2, add=TRUE, yaxt="n")   # curva teorica
mean(y);mean(rtri(n,min = 3, max = 9, mode = 6))



#***************************************************************************************
#********************************** METODO 5: COMPOSICION ******************************
#***************************************************************************************

## Ejemplo 1: mezclas de varias funciones gamma(alpha,lambda)

nd<- 6   # numero de distribuciones
n<- 2000

alpha<- 2  # parametro gamma
lambda<- c(1,1.6,2.5,3,5.1,9)  # parametros gammas

theta<- (1:nd)/nd   # pesos de las componentes
k<- sample(1:nd,size=n,replace=TRUE,prob=theta)  
rate2<- lambda[k]
x<- rgamma(n,shape=2,rate=rate2)   # valores de la muestra

hist(x,col="gray",main="Mezcla de gammas con igual peso")
# Grafica de la densidad de la mezcla total
plot(density(x),ylim=c(0,2.5),lwd=3,xlab="x",col="red",main="Mezcla de Gammas")
# Grafica de las densidades de probabilidad de las componentes
for(i in 1:nd)
  lines(density(rgamma(n,alpha,lambda[i])))

# Otra forma 

f<- function(x,a,b,c){
  sum(c*dgamma(x,a,b))
}

x<- seq(0,10,length=1000)
dim(x)<- length(x)  # necesario para "apply"
y<- apply(x,1,f,alpha,lambda,theta)

plot(x,y,type="l",xlim=c(0,6))
for(j in 1:nd){
  y<- apply(x,1,dgamma,shape=alpha,rate=lambda[j])
  lines(x,y)
}

## Ejemplo 3: Binomial negativa como mezcla de gamma-poisson

n<- 2000
beta<- 9
r<- 4

# En este ejemplo, consideramos el generador aleatorio gamma y Poisson de R

# Generamos valores aleatorios del parametro "lambda" de Poisson
Lambda<- rgamma(n,shape= r,rate= beta)  # scale=1/beta 

x<- rpois(n,Lambda)  # poisson

plot(prop.table(table(x)))  # distribucion empirica (valores simulados)

# Se demuestra que: BinNeg(r, beta/1+beta) 
bin.neg<- dnbinom(0:max(x),size=r,prob= beta/(1+beta))   # distribucion teorica de la mezcla
lines(0:max(x),bin.neg, type="h",col="red")

# O bien,

p<- 0.45  # probabilidad de exito
Lambda_2<- rgamma(n,shape= r,scale= p/(1-p))

xx<- rpois(n,Lambda_2)  # poisson

plot(prop.table(table(xx)))  # distribucion empirica (valores simulados)

# Se demuestra que: BinNeg(r,1-p)
bin.neg2<- dnbinom(0:max(xx),size=r,prob= 1-p) 

lines(0:max(xx),bin.neg2, type="h",col="blue")


rbind(prop.table(table(x)),bin.neg)
rbind(prop.table(table(xx)),bin.neg2)	



#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Convoluciones vs mezclas

n<- 2000
x1<- rnorm(n,3,2)
x2<- rnorm(n,1,4)
s<- x1+x2      # convolucion
u<- runif(n)
k<- 0.5
x<- k*x1+(1-k)*x2    # mezcla
par(mfrow=c(1,2))
hist(s,prob=TRUE)  # convolucion
hist(x,prob=TRUE) # mezcla     

## Ejemplo 3: Binomial negativa como mezcla de gamma-poisson

n<- 2000
beta<- 9
r<- 4

# En este ejemplo, consideramos el generador aleatorio gamma y Poisson de R

# Generamos valores aleatorios del parametro "lambda" de Poisson
Lambda<- rgamma(n,shape= r,rate= beta)  # scale=1/beta 

x<- rpois(n,Lambda)  # poisson

plot(prop.table(table(x)))  # distribucion empirica (valores simulados)

# Se demuestra que: BinNeg(r, beta/1+beta) 
bin.neg<- dnbinom(0:max(x),size=r,prob= beta/(1+beta))   # distribucion teorica de la mezcla
lines(0:max(x),bin.neg, type="h",col="red")

# O bien,

p<- 0.45  # probabilidad de exito
Lambda_2<- rgamma(n,shape= r,scale= p/(1-p))

xx<- rpois(n,Lambda_2)  # poisson

plot(prop.table(table(xx)))  # distribucion empirica (valores simulados)

# Se demuestra que: BinNeg(r,1-p)
bin.neg2<- dnbinom(0:max(xx),size=r,prob= 1-p) 

lines(0:max(xx),bin.neg2, type="h",col="blue")


rbind(prop.table(table(x)),bin.neg)
rbind(prop.table(table(xx)),bin.neg2)	



#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Convoluciones vs mezclas

n<- 2000
x1<- rnorm(n,3,2)
x2<- rnorm(n,1,4)
s<- x1+x2      # convolucion
u<- runif(n)
k<- 0.5
x<- k*x1+(1-k)*x2    # mezcla
par(mfrow=c(1,2))
hist(s,prob=TRUE)  # convolucion
hist(x,prob=TRUE) # mezcla     


#############################################################################
##################### DISTRIBUCIONES MULTIVARIADAS ##########################
#############################################################################

## Ejemplo 1: f(x1,x2)=6*x1 

fmult<- function(x1,x2) 6*x1
x<- seq(0,1,0.01)
y<- seq(0,1,0.01)  
z<- outer(x,y,fmult)     # La función outer evalua la función f en cada punto(xi,yj)
persp(x,y,z,theta=15,phi=60,col="orange")     # Un gráfico en perspectiva

# Generamos los aleatorios (ver notas de clase)
u1<- runif(1000)
u2<- runif(1000)

x1<- (1-u2)^{1/3}*sqrt(u1)
x2<- 1-(1-u2)^{1/3}

# Calculamos la correlacion entre (X1,X2) y comparamos con el valor teorico.        
cor(x1,x2)



#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 2a: normal multivariada (usando la factorizacion por eigenvalores)

mu<- c(0,1,2)  # vector medias
Sigma<- matrix(c(1,-0.5,0.5,-0.5,1,-0.5,0.5,-0.5,1),ncol=3,nrow=3)  # matriz var-cov
multi.eigen<- function(n,mu,Sigma){
  d= length(mu)
  ev= eigen(Sigma,symmetric=TRUE)
  lambda= ev$values   # valores propios
  vect= ev$vectors    # vectores propios
  R<- vect %*% diag(sqrt(lambda)) %*% t(vect)
  Z<- matrix(rnorm(n*d),nrow=n,ncol=d)  # matriz de N(0,1)
  X<- Z %*% R + matrix(mu,n,d,byrow=TRUE)   # transformacion
  X
}

X<- multi.eigen(2000,mu,Sigma)
plot(X,xlab="x",ylab="y",pch=19,main="eigenvalores")
print(colMeans(X))   # comparamos con la matriz de medias propuesta
print(round(cov(X),digits=3))    # comparamos con la matriz var-cov propuesta

print(round(cor(X),digits=3))

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## Ejemplo 2b: normal multivariada (usando la funcion en R)

library(mvtnorm)
plot(rmvnorm(n=2000, mean=mu, sigma=Sigma),xlab="X",ylab="Y",main="Normal multivariada")




















