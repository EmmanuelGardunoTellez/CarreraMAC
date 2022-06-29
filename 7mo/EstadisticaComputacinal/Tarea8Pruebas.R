setwd("C:/Users/Emman/Documents/CCH-N} FES-A/fessaa/FES/7mo semestre/Temas Selectos de Estadistica")
rnd<- read.table("./DATA/aleatorios2.txt",header=F)
attach(rnd)


sort(rnd$V1)
dim(rnd)

frnd <- seq(0,1, length=71)
frnd[-1]


absoluto <- abs(sort(rnd$V1)-frnd[-1])


KS <- data.frame(
  "RND_i" = sort(rnd$V1),
  "FRBD_I" = frnd[-1],
  "RND_i-FRBD_I"=  absoluto
  
)
KS

max(KS$RND_i.FRBD_I) #valor maximo de |rnd- frnd|

1.52/sqrt(70) #valor obtenido de la tabla 70 valores con alpha = 0.02

# como 0.3278571 > 0.1816747, entonces SE puede rechazar la uniformidad de los num aleatorios
ks.test(rnd,"punif",0,1)

#2 Por arriba y por abajo

k<- 0 #contador
n<- 70 #num de var aleatorias
y<- numeric(n)  #asignamos el 0 y 1 parra las corridas
while(k<n){
  k=k+1
  if(rnd$V1[k]<=0.5){
    y[k]<- 0
  } else {
    y[k]<- 1
  }
}

corridas <- data.frame(
  "RND_i" = rnd$V1,
  "0-1" = y
  
)
corridas


# 1.	1 1                    | 2
# 2.	0 0                    | 2
# 3.	1 1                    | 2
# 4.  0                      |1
# 5.	1 1 1                  |  3
# 6.	0                      |   4
# 7.	1 1 1 1                |  3
# 8.	0 0 0                  |   4
# 9.	1 1 1 1                |   4
# 10.	0                      |1
# 11.	1 1                    | 2
# 12.	0 0                    | 2
# 13.	1 1 1 1 1 1            |    6    
# 14.	0 0                    | 2
# 15.	1 1                    | 2
# 16.	0                      |1
# 17.	1                      |1 
# 18.	0                      |1
# 19.	1 1 1 1 1 1 1 1 1 1    |    10
# 20.	0                      |1
# 21.	1 1                    | 2
# 22.	0                      |1
# 23.	1 1 1 1 1 1 1 1        |    8
# 24.	0                      |1
# 25.	1 1 1 1 1 1 1          |    7

i <- 1:10
FEi <- (n-i+3)/(2^(i+1))
FO<- c(8,8,2,3,0,1,1,1,0,1)
FT<- ((FEi-FO)^2)/FEi

E <- (n+1)/2; E #Corridas
sum(FO)
corridasTabla <- data.frame(
  "Long" = i,
  "FE" = FEi,
  "FO" = FO,
  "FT" = FT
)
corridasTabla
# de lla tabla anterior suma de FT
sum(corridasTabla$FT)
# jiCuadrada = 47.49933
# valor - p = P|jiCuadrada >= 47.49933 | = |jiCuadrada_{n-1}>=47.49933|
# P|juCuadrada_{9}>=47.49933|

pchisq(q=47.49933, df=9, lower.tail = F) # 3.16751e-07 valor calculado


qchisq(p=0.02,df=9,lower.tail = F) #Valor critico 19.67
# por lo tanto no rechazo hipotess nula por lo tanto val independientes

















