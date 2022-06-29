da<-data.frame(      x=c(13,  16,   5,  22,  24,   4,  18,  17,   1,  39,  44,  22),
                  tra=c("t1","t2","t3","t1","t2","t3","t1","t2","t3","t1","t2","t3"),
               bloque=c("b1","b1","b1","b2","b2","b2","b3","b3","b3","b4","b4","b4"))
mod<-lm(x~tra+bloque,da)
anova<-aov(mod)
summary(anova)

F_0<- 351.8/8.6
F_0
qf(0.95,2,6)
F_0>qf(0.95,2,6)
# Ejemplo-------------------------------------------------------------------------------
da<-data.frame(x=c(9.3,9.4,9.2,9.7,9.4,9.3,9.4,9.6,9.6,9.8,9.5,10,10,9.9,9.7,10.2),
               trat=as.factor(rep(c("t1","t2","t3","t4"),4)),
               bloque=as.factor(rep(c("b1","b2","b3","b4"),each=4)))
mod<-lm(x~trat+bloque,da)
anova<-aov(mod)
summary(anova)


da<-data.frame(x=c(   1.7, 1.5,  1.2,  1.5, 1.8, 1.6,  1.8,  1.9, 1.9, 1.7,  2.1,  2.0, 2.3, 1.9,  1.7,  1.5,  2.1, 2.2, 2.5,  2.3),
                 trat=c("t1","t2", "t3", "t4","t1","t2", "t3", "t4","t1","t2", "t3", "t4","t1","t2", "t3", "t4","t1","t2", "t3", "t4"),
               bloque=c("b1","b1", "b1", "b1","b2","b2", "b2", "b2","b3","b3", "b3", "b3","b4","b4", "b4", "b4","b5","b5", "b5", "b5"))
mod<-lm(x~trat+bloque,da)
anova<-aov(mod)
summary(anova)

0.028/0.0513
qf(0.95,3,12)
0.028/0.0513>qf(0.95,3,12)

