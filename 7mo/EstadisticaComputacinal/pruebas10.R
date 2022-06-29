
## Ejemplo 1: Intervalo para comparacion de medias

antdes   <- c(rep("Antes",12),rep("Despues",12))
defectos <- c(8,7,6,9,7,10,8,6,5,8,10,8,6,5,8,6,9,8,10,7,5,6,9,5)
datos <- data.frame(momento = antdes,
                cantidad = defectos)

names(datos); str(datos)
factor(datos$momento)

boxplot(datos$cantidad~datos$momento, las=1, ylab="erores", 
        xlab="antes/despues",main="errores ates y despues",col=rainbow(2))

# calculamos la diferencia en medias

errormedio_ant<- mean(datos$cantidad[datos$momento=="Antes"])  
errormedio_des<- mean(datos$cantidad[datos$momento=="Despues"]) 

Dif.Medias<- errormedio_ant-errormedio_des; Dif.Medias


# calculamos la diferencia en medianas

errormediano_ant<- median(datos$cantidad[datos$momento=="Antes"])  
errormediano_des<- median(datos$cantidad[datos$momento=="Despues"]) 

Dif.Medianas<- errormediano_ant-errormediano_des; Dif.Medianas

# NOTA: no se que metodo uses, pero usa uno de boostrap, NO USES EL PRIMERO ya que es como lo asiamos en estadistica
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




