# ejercicio 1
(s <- c(4,2,0,9,4,2,-1,1,-4,2))
s
print(s)
mean(s)
sort(table(s))

var(s)
varianza <- function(a){
  n <- length(a)
  (n-1)/n * var(a)
}
varianza(s)

rango <- function(a){
  max(a)-min(a)
}

rango(s)

# ejercicio 2

xbar <- 1550
n <- 50
sigma <- 30
alpha <- 0.05

intervalo95 <- c(xbar - qnorm(0.975,0,1)* sigma/ sqrt(n), 
                 xbar + qnorm(0.975,0,1)* sigma/ sqrt(n))
print(intervalo95)

#4
alpha <- 1-pnorm(1.5,0,1)
beta <- pnorm(1.5,2,1)
potencia <- (1-beta)

print(alpha)
print(beta)
print(potencia)