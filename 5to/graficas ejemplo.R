install.packages("ggplot2")
install.packages("tidyverse")
install.packages("tibble")
library("ggplot2")
library("tidyverse")
library("tibble")

library(readr)



list.files()
setwd("C:\\Users\\Emman\\Documents\\CCH-N} FES-A\\fessaa\\FES\\5to Semestre\\Estadistica")
list.files()
housing <- read_csv("sataSets/EconomistData.csv")
head(housing, 5)
ggplot(housing,aes(x =CPI, y=HDI)) +
  geom_point()
ggplot(housing,aes(x =CPI, y=HDI)) +
  geom_point(color="blue")
ggplot(housing,aes(x =CPI, y=HDI)) +
  geom_point(aes(color=Region))
ggplot(housing,aes(x =CPI, y=HDI)) +
  geom_point(aes(color=Region, size=2))
ggplot(housing,aes(x =CPI, y=HDI)) +
  geom_point(aes(color=Region, size=HDI))