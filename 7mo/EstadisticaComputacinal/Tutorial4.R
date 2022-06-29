setwd("C:/Users/Emman/Documents/CCH-N} FES-A/fessaa/FES/7mo semestre/Temas Selectos de Estadistica")
getwd()

# Temas Selectos de Estadistica: Estadistica Computacional
# Prof. Elizabeth Martinez
# FES-Acatlan, UNAM
# TUTORIAL 4: ESTIMACION E INTERPRETACION DE MODELOS PROBABILISTICOS


###############################################################################################
###############################################################################################
####################### PROPIEDADES DE LA ESTIMACION PUNTUAL ##################################
###############################################################################################
###############################################################################################

#Ejemplo 1: Se realiza un estudio sobre el gasto promedio en libros de un estudiante 
#universitario por semestre, de manera que se hace una encuesta a 50 estudiantes

gasto<- read.table("./DATA/gastos.dat",header=F)
attach(gasto)
head(gasto); tail(gasto)

#Podemos proponer varios estimadores para la media

m1=sum(gasto)/50; m1
m2=sum(gasto)/(50-1); m2
m3=(max(gasto)-min(gasto))/2; m3

#Cual utilizo?, ¿que criterio puedo considerar para discriminar entre buenas aproximaciones
#y malas aproximaciones?

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

# Ejemplo 2: Para un mismo individuo se realizan distintas mediciones de su
# nivel de potasio en la sangre debido tanto a la imprecision del procedimiento de medicion como al hecho de 
# que el nivel real varia, dependiendo de factores tales como la cantidad de alimentos
# consumidos o los ejercicios fisicos realizados recientemente. 
# Supongamos que, para un cierto individuo se sabe que sus niveles de potasio varian 
# alrededor de un valor medio mu con una desviacion tipica sigma=0.3. Se muestran los valores
# registrados en 4 mediciones:

potasio<- c(3.6,3.9,3.4,3.5); n<- length(potasio)
sigma<- 0.3

# Estima el nivel medio de potasio para esta persona, asi como su error estandar.

xbar<- mean(potasio)

ee<- sigma/sqrt(n);ee

# EXTRA: si se desea reducir el error estandar a 0.05, estima el valor de "n"

ee<- 0.05
n<- (sigma/ee)^2; n

##############################################################################
################ METODOS DE ESTIMACION PUNTUAL DE PARAMETROS #################
##############################################################################

# Ejemplo 1: Estimacion de parametros (datos simulados usando R)

library(MASS)
set.seed(092021)
mis_datos <- rnorm(5000, mean=2.3, sd=1.5)  # parametros desconocidos

# METODO 1: usando los estimadores por momentos

xbar<- mean(mis_datos)
n<- length(mis_datos)
muhat_MOM<- xbar
sigma2hat_MOM<- (sum(mis_datos^2)/n)-(muhat_MOM^2); sqrt(sigma2hat_MOM)

hist(mis_datos, pch=20,breaks=15,prob=T, main="")
curve(dnorm(x, muhat_MOM, sqrt(sigma2hat_MOM)), col="black", lwd=2, add=T)


# METODO 2: Usando directamente la funcion "fitdistr"

(fit <- fitdistr(mis_datos, densfun="normal"))  # sup. que mis_datos~Normal(?,?)

hist(mis_datos, pch=20,breaks=15,prob=TRUE, main="")
curve(dnorm(x, fit$estimate[1], fit$estimate[2]), col="red", lwd=2, add=T)

# METODO 3: Escribimos los estimadores MLE para la distribucion Normal

n<- length(mis_datos)
muhat_MLE<- sum(mis_datos)/n; muhat_MLE
sigma2hat_MLE<- sum((mis_datos-muhat_MLE)^{2})/n; sqrt(sigma2hat_MLE)

hist(mis_datos, pch=20,breaks=15,prob=TRUE, main="")
curve(dnorm(x, muhat_MLE, sqrt(sigma2hat_MLE)), col="green", lwd=2, add=T)


# METODO 4: Escribimos la funcion de log-verosimilitud para la distribucion Normal

log_likelihood <- function(params) { 
  loglik=-sum(dnorm(mis_datos, params[1], params[2], log=TRUE)) 
  loglik
}

(fit2 <- optim(c(muhat_MOM,sqrt(sigma2hat_MOM)), log_likelihood))   # estimaciones por momentos como puntos iniciales

hist(mis_datos, pch=20, breaks=15, prob=TRUE,main="")
curve(dnorm(x, fit2$par[1],fit2$par[2]),col="blue", lwd=3, add=T) 

# Otra forma 

log_likelihood2 <- function(theta) {
  n= length(mis_datos)
  mu= theta[1]
  sigma= theta[2]
  ll1=(n/2)*log(2*pi*sigma^2)
  ll3=(1/(2*sigma^2))*(mis_datos-mu)^2
  ll=-ll1-sum(ll3)
  return(-ll)   # para maximizar
}

(fit3<- nlm(log_likelihood2,c(1,1),hessian=T))   # ajuste de dos parametros
hist(mis_datos, pch=20, breaks=15, prob=TRUE,main="")
curve(dnorm(x, fit3$estimate[1],fit3$estimate[2]),col="magenta", lwd=4, add=T) 

# comparacion de los metodos:

muhat<- cbind(muhat_MOM, fit2$par[1])
colnames(muhat)<- c("MOM","MLE"); muhat

sigmahat<- cbind(sqrt(sigma2hat_MOM),fit2$par[2])
colnames(sigmahat)<- c("MOM","MLE"); sigmahat

hist(mis_datos, pch=20, breaks=15, prob=TRUE,main="")
curve(dnorm(x, muhat_MOM, sqrt(sigma2hat_MOM)),col="black",lwd=2,add=T) # " momentos
curve(dnorm(x, fit$estimate[1], fit$estimate[2]),col="red",lwd=2,add=T) # "fitdistr" fit
curve(dnorm(x, fit2$par[1],fit2$par[2]),col="blue", lwd=4, add=T) # "optim"
curve(dnorm(x, fit3$estimate[1], fit3$estimate[2]),col="yellow",lwd=1,add=T) # "fitdistr" fit


# *****************************************************************************

# Ejemplo 2: Datos simulados (Weibull)

alfa<- 2.5  # shape Positivos y en los reales
beta<- 3  # scale
set.seed(2021)
u<- runif(30000)
y<- beta*(-log(1-u,base=exp(1)))^(1/alfa)

hist(y,col="gray")

mean(y); beta*gamma(1+1/alfa)   # promedio teorico vs muestral
var(y); beta^2*(gamma(1+2/alfa)-(gamma(1+1/alfa))^2)   # varianza teorica vs muestral

library(MASS)
fit_wei<- fitdistr(y,densfun = "weibull",list(shape=2,scale=1)); fit_wei
ee_wei_MLE<- sqrt(fit_wei$vcov); ee_wei_MLE   # error estandar=sqrt(Vcov)


hist(y, pch=20,prob=TRUE, main="",col="pink")
curve(dweibull(x, fit_wei$estimate[1],fit_wei$estimate[2]), col="red", lwd=2, add=T)


# Comparemos con el generador "Weibull" de R:

set.seed(2021)

hist(rweibull(10000, shape = alfa, scale = beta))


# *****************************************************************************

# Ejemplo 3: Lluvias en Mexico

lluvias= read.table("./DATA/Datos lluviasFile.txt",sep="\t",row.names = 1,header=T)
attach(lluvias)
y= Precipitacion   # renombro la variable por comodidad

# Graficamos los datos para "ver" el perfil que describen.
hist(y,breaks=seq(0,2400,300),main= "Precipitacion anual en Mexico (2017)",
     xlab="Precipitacion (mm)")

# O bien, con intervalos desiguales:

hist(y,breaks=c(0,200,400,600,800,1000,1700,2500),main= "Precipitacion anual en Mexico (2017)",
     xlab="Precipitacion (mm)")

hist(y,breaks = quantile(y, 0:10 / 10))


# De acuerdo al perfil del histograma parece que el modelo de probabilidad
# adecuado puede ser:

# 1. Exponencial de parametro "lambda"
# 2. Gamma de parametros alfa y beta. Recordemos que modela el mismo tipo de fenomenos
# que la exponencial.

# La funcion de densidad EXPONENCIAL se ve como:
# rate=lambda
plot(seq(0,30,0.1),dexp(seq(0,30,0.1),rate=0.4),ty="l",xlab="x",ylab="f(x)")

# Recordemos que la funcion de densidad GAMMA se ve como:
# shape=alfa, scale=beta
plot(seq(0,30,0.1),dgamma(seq(0,30,0.1),shape=2,scale=2),ty="l",xlab="x",ylab="f(x)")

# IDEA: debemos estimar los valores de los parametros para cada modelo propuesto
# a partir de las observaciones muestrales. 

#******** 1. MODELO EXPONENCIAL PARA LLUVIAS

### METODO DE MOMENTOS

# Se sabe de la teoria que: lambda.hat=1/xbar

lambdahat.MOM<- round(1/mean(y),digits=4); lambdahat.MOM

### METODO MLE: funcion "fitdistr"

library(MASS)
fit_mle1<- fitdistr(y, densfun="exponential",rate=0.01) # lo hace con MLE
str(fit_mle1)


### METODO MLE: funcion de verosimilitud

lik_exp<- function(theta){
  l=prod(theta*exp(-theta*y))
  return(-l)
}

# Para graficar la funcion de verosimilitud

th.lik<-seq(0,0.003,1e-7)  # valores propuestos para el parametro
l<- rep(0,length(th.lik))   # repite el valor de la primera entrada tantas veces como
# la longitud del vector th.lik lo indique

pdf("Funcion de verosimilitud para lluvias.pdf")
for (i in 1:length(th.lik)) l[i] <- lik_exp(th.lik[i])
plot(th.lik,l,type="l",lwd=2,col="red",xlab="theta",ylab="L",main="")
dev.off()

# Maximizamos la funcion de verosimilitud

fit_mle2<- optimize(lik_exp,c(0,0.01));fit_mle2

# optim(lambdahat.MOM,lik_exp,method="BFGS")  # Optimizador para proposito general
#?optim para ver los metodos de optimizacion
# Comparamos resultados

res_exp<- round(cbind(lambdahat.MOM,fit_mle1$estimate,fit_mle2$minimum),digits=5)
colnames(res_exp)<- c("momentos","fitdistr","lik_MLE")
res_exp

# Graficamos el modelo exponencial

hist(y, pch=20,prob=TRUE,main="")
curve(dexp(x,lambdahat.MOM),col="blue",lwd=2,add=T)   # momentos
curve(dexp(x,fit_mle1$estimate),col="red",lwd=2,add=T) # "fitdistr" fit
curve(dexp(x, fit_mle2$minimum),col="green", lwd=2, add=T) # "MLE optim"


#******** 2. MODELO GAMMA PARA LLUVIAS

### METODO 1: estimacion por el "metodo de momentos" (notas de clase)

# Se sabe de la teoria que: 
# alfa.hat= nxbar^2/(sum(x^2)-nxbar^2)
# beta.hat= xbar/alfa.hat

n= length(y)
num<- n*(mean(y)^2)
denom<- sum(y^2)-(n*mean(y)^2)
alfahat.MOM<- num/denom ; alfahat.MOM
betahat.MOM<- mean(y)/alfahat.MOM; 1/betahat.MOM

### METODO 2a: estimacion por el "metodo de MLE" (funcion "fitdistr")

library(MASS)
lluvias_mle1<- fitdistr(y, densfun="gamma") # lo hace con MLE

### METODO 2b: estimacion por el "metodo de MLE" (funcion de verosimilitud)

lik_gamma<- function(theta){
  alfa= theta[1]
  beta= theta[2]
  num= y^(alfa-1)*exp(-y/beta)
  denom= gamma(alfa)*beta^(alfa)
  l=prod(num/denom)
  return(-l)
}

# Maximizamos la funcion de verosimilitud

lluvias_mle2<- optim(c(alfahat.MOM,betahat.MOM),lik_gamma);lluvias_mle2

# comparacion de los metodos:

alfahat<- cbind(alfahat.MOM, lluvias_mle1$estimate[1],lluvias_mle2$par[1]);alfahat
betahat<- cbind(1/betahat.MOM, lluvias_mle1$estimate[2],1/lluvias_mle2$par[2]);betahat
hist(Precipitacion, pch=20, breaks=15, prob=TRUE,main="")
curve(dgamma(x, lluvias_mle1$estimate[1], lluvias_mle1$estimate[2]),col="red",lwd=2,add=T) # "fitdistr" fit
curve(dgamma(x, lluvias_mle2$par[1],1/lluvias_mle2$par[2]),col="blue", lwd=2, add=T) # "optim"

fit_mle1= fitdistr(y,densfun = "exponential");str(fit_mle1)

# Graficamente se ve mucho mejor el modelo gamma de dos parametros. Verifiquemos esto:

k=1   # numero de parametros a estimar
n= length(y)
AIC_exp= 2*k-(2*fit_mle1$loglik); AIC_exp
BIC_exp= log(n)*k-(2*fit_mle1$loglik); BIC_exp

k=2   # numero de parametros a estimar
AIC_gamma= 2*k-(2*lluvias_mle1$loglik); AIC_gamma
BIC_gamma= log(n)*k-(2*lluvias_mle1$loglik); BIC_gamma

# El modelo preferido es el de menor AIC por lo que en efecto, el modelo gamma es el que mejor
# explica la distribucion de lluvias en Mexico.


# Otra forma: 

library(AdequacyModel)

pdf_gamma <- function(par,x){
  alpha = par[1]
  lambda = par[2]   # shape=alfa, rate=lambda=1/beta
  (lambda^(alpha)/gamma(alpha))*x^(alpha-1)*exp(-lambda*x)
}


cdf_gamma <- function(par,x){
  alpha = par[1]
  lambda = par[2]
  pgamma(x,shape= alpha, rate= lambda)  # usamos la de R
}


result<- goodness.fit(pdf=pdf_gamma, cdf=cdf_gamma,
                      starts=c(alfahat.MOM,1/betahat.MOM), 
                      method= "PSO", data=y, mle=c(lluvias_mle2$par[1],
                                                   1/lluvias_mle2$par[2]) ,
                      lim_inf = c(1,100),
                      lim_sup = c(200,400))

result2<- goodness.fit(pdf=pdf_gamma, cdf=cdf_gamma,
                       starts=c(alfahat.MOM,1/betahat.MOM), 
                       method= "Nelder-Mead", 
                       data=y, mle=NULL,
                       lim_inf = c(alfahat.MOM-10,(1/betahat.MOM)-10),
                       lim_sup = c(200,400))

x = seq(0,ceiling(max(y)), length.out = 500)
hist(y, probability = TRUE)
lines(x, pdf_gamma(par = result2$mle, x), col = "blue",lwd=2)



























