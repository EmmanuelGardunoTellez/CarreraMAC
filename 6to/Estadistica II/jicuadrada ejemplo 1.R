#prube ji_cuadrada
#pro. bajo Ho
x <- 0:5
dpois(x,2)
n<- 25
freq.esp <- c(n * dpois(x,2), n * (1- sum(dpois(x,2))))

print(freq.esp)

freq.obs <- c(3,5,6,4,3,2,2)
est.ji2<- sum((freq.obs - freq.esp)^2/ freq.esp)
est.ji2