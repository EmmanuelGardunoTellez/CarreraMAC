y <- c(16.68, 11.50, 12.03, 14.88, 13.75, 18.11, 8.00 ,17.83, 79.24, 
       21.50, 40.33, 21.00, 13.50, 19.75, 24.00, 29.00, 15.35, 19.00, 
       9.50, 35.10, 17.90, 52.32, 18.75, 19.83, 10.75)
x1 <- c(7, 3, 3, 4, 6, 7, 2, 7, 30, 5, 16, 10, 4, 6, 9, 10, 6, 7, 3, 
        17, 10, 26, 9, 8, 4)
x2 <- c(560, 220, 340, 80,150, 330, 110, 210, 1460, 605, 688, 215,
        255, 462, 448, 776, 200, 132, 36,  770, 140, 810, 450, 635, 150)
bebidas <- data.frame(y, x1, x2)
unos <- c(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1)

names(bebidas) <- c("Tiempo de Entrega(Y)", "Cantidad de Cajas(X1)", "Distancia(X2)")
#Esta es la matriz X
x <- matrix(c(unos, x1, x2), nrow = 25, ncol = 3) 
#Matriz Y o vector columna Y
matriz_y <- matrix(c(y), nrow = 25, ncol = 1)
#La transpuesta de X o X'
x_trans <- t(x)
#Matriz  X X'
multx_x_trans <- x_trans %*% x
#Matriz X'y
x_trans_y <- x_trans %*% matriz_y
#Matriz inversa de X'X o (X'X)^{-1}
inversa <- solve(multx_x_trans)
#Obtener B0 B1 y B2
betas <- inversa %*% x_trans_y
betas 


#Para la tabla ANOVA
#SSErrores 
ss_e <- (t(matriz_y-(x%*%betas)))%*%(matriz_y-x%*%betas)
#SStotal
y_i <- (sum(y))^2/25
ss_t <- (t(matriz_y)%*%matriz_y)- y_i
#SSregresion
ss_r <- ss_t - ss_e
# el valor de p son la cantidad de x_i
p <- length(bebidas)-1
#n son la cantidad de observaciones
n <- nrow(bebidas)
#n-p-1
gl <- n-p-1
#MSregresion
ms_r <- ss_r/p
#MSerrores recordemos que MSe es la varianza 
ms_e <- ss_e/(n-p-1)
fcero <- ms_r/ms_e
#Tabla Anova
SS    <-c(ss_r,ss_e,ss_t)
tgl   <-c(p, gl, n-1)
MS    <-c(ms_r,ms_e,"--")
val_F <-c(fcero,"--","--")
TAnova <- matrix(c(SS,tgl,MS,val_F),nrow=3,ncol=4)
colnames(TAnova)<-c("SS","gl","MS","F_0")
rownames(TAnova)<-c("Regresión", "Errores", "Total")
TAnova
#Estimaciones
Testimacion <-matrix(c(betas,ms_e), nrow = 4, ncol=1)
colnames(Testimacion)<-c("Estimación")
rownames(Testimacion)<-c("beta_0", "beta_1", "beta_2","sigma^2")
Testimacion


#X_0
x_0 <- matrix(x[c(1,26,51)], nrow = 1, ncol = 3)
#X_0'
x_0_trans <- t(x_0)
#y_0
y_calculada <- matrix(c(betas[1]*x[c(1:25)]+betas[2]*x[c(26:50)]+betas[3]*x[c(51:75)]),nrow = 25, ncol = 1)

minimo<-c(ss_e/qchisq(1-(.05/2),gl),Testimacion[1]-qt(1-(.05/2),gl)*(sqrt(ms_e* inversa[1])),Testimacion[2]-qt(1-(.05/2),gl)*(sqrt(ms_e* inversa[5])),Testimacion[3]-qt(1-(.05/2),gl)*(sqrt(ms_e* inversa[9])))
medio<-c(ms_e,Testimacion[1],Testimacion[2],Testimacion[3])
maximo<-c(ss_e/qchisq(.05/2,gl),Testimacion[1]+qt(1-(.05/2),gl)*(sqrt(ms_e* inversa[1])),Testimacion[2]+qt(1-(.05/2),gl)*(sqrt(ms_e* inversa[5])),Testimacion[3]+qt(1-(.05/2),gl)*(sqrt(ms_e* inversa[9])))

intCon<-matrix(c(minimo,medio,maximo),nrow = 4,ncol = 3)
colnames(intCon)<-c("Lim Min","Estimación","Lim Max")
rownames(intCon)<-c("sigma^2","beta_0", "beta_1", "beta_2")
intCon




minimo2 <-c(y_calculada[1]- qt(1-(.05/2),gl)*(sqrt(ms_e* x_0%*%inversa%*%x_0_trans)),y_calculada[1]-qt(1-(.05/2),gl)*(sqrt(ms_e* (1+x_0%*%inversa%*%x_0_trans))))
medio2  <-c(y_calculada[1],y_calculada[1])
maximo2 <-c(y_calculada[1]+ qt(1-(.05/2),gl)*(sqrt(ms_e* x_0%*%inversa%*%x_0_trans)),y_calculada[1]+qt(1-(.05/2),gl)*(sqrt(ms_e* (1+x_0%*%inversa%*%x_0_trans))))
IntMF<-matrix(c(minimo2,medio2,maximo2),nrow = 2,ncol = 3)
colnames(IntMF)<-c("Lim Min","Estimación","Lim Max")
rownames(IntMF)<-c("res. media","val. futuros")
IntMF
#Estimcion or intervalos res media
y_calculada[1]- qt(1-(.05/2),gl)*(sqrt(ms_e* x_0%*%inversa%*%x_0_trans))
y_calculada[1]
y_calculada[1]+ qt(1-(.05/2),gl)*(sqrt(ms_e* x_0%*%inversa%*%x_0_trans))

#Estimcion or intervalos obs futuras
y_calculada[1]-qt(1-(.05/2),gl)*(sqrt(ms_e* (1+x_0%*%inversa%*%x_0_trans)))
y_calculada[1]
y_calculada[1]+qt(1-(.05/2),gl)*(sqrt(ms_e* (1+x_0%*%inversa%*%x_0_trans)))

qchisq(1-(.05/2),20-2)
qchisq((.05/2),20-2)