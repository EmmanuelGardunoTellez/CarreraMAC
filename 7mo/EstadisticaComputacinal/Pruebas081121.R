setwd("C:/Users/Emman/Documents/CCH-N} FES-A/fessaa/FES/7mo semestre/Temas Selectos de Estadistica")


rnd<- read.table("./DATA/AleatoriosClase.txt",header=F)
attach(rnd)

sort(rnd$V1)

sum(rnd>=0 & rnd<0.20)
sum(rnd>=0.2 & rnd<0.40)
sum(rnd>=0.4 & rnd<0.60)
sum(rnd>=0.6 & rnd<0.80)
sum(rnd>=0.8 & rnd<=1)

chi2_crit <- qchisq(p=0.05,df=5-1,lower.tail = F)

# chisq.test necesita de una tabla de frecuencias

chisq.test(table(rnd))  # tabla de frecuencias sin agrupar
h<- hist(rnd$V1,breaks=seq(0,1,0.2))  # dist$V1 y de alli dist$V1$breaks[3] es la anchura de la clase
chisq.test(h$counts) # tabla de frecuencias con datos 


####################################################################################
################################# PRUEBAS ESTADISTICAS #############################
####################################################################################

## ALEATORIEDAD (UNIFORMIDAD)
# H0: uniformidad de los aleatorios
# Ha: NO uniformidad

rnd<- read.table("./DATA/AleatoriosClase.txt",header=F)
attach(rnd)

# 1a. Prueba chi-cuadrada (a mano)

prueba.chi2<- function(datos, alfa){  #NOTA: debemos escribir $V1 porque asi reconoce
  #  R a la primera columna del archivo
  N= nrow(datos)
  n= round(sqrt(N),digits=0)
  
  # Construimos la tabla de frecuencias con "fdt"
  library(fdth)
  tabla= fdt(datos,start=0, end=1, k=n,right=T)
  fo= tabla$V1$table$f     # frecuencia observada
  fe<- rep(N/n,n)   # frecuencia esperada
  chi2_calc= sum((fe-fo)^2/fe)
  pval= pchisq(chi2_calc, df=n-1, lower.tail = F)
  
  # Construimos la tabla de frecuencias con la funcion "hist"
  his<- hist(datos$V1,breaks=seq(0,1,1/n))
  fo2<- his$counts
  chi2_calc2= sum((fe-fo2)^2/fe)
  pval2= pchisq(chi2_calc2, df=n-1, lower.tail = F)
  
  chi2_crit= qchisq(p= alfa, df= n-1, lower.tail = F)
  cat("chi^2 calculado:",chi2_calc,";","Valor-p:",pval,"(fdt)","\n")
  cat("chi^2 calculado:",chi2_calc2,";","Valor-p:",pval2,"(hist)", "\n")
  cat("chi^2 crítica:",chi2_crit)
}

prueba.chi2(rnd,0.05)


# 1b. Prueba chi-cuadrada (en R)

# Se necesita de una tabla de frecuencias: datos sin agrupar vs datos agrupados

chisq.test(table(rnd))  # tabla de frecuencias sin agrupar

# No es correcto hacerlo asi porque "rnd" es una variable continua

tabla.frec<- fdt(rnd$V1,start=0, end=1,right= F)

chisq.test(tabla.frec$table$f)

## INDEPENDENCIA (CORRIDAS)

# 1. Corridas por arriba y abajo de la media

library(snpar)
runs.test(rnd$V1,exact=F, alternative="two.sided")
qchisq(p=0.05, df=4, lower.tail = F)


















