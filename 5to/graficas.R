# Cargar datos ####
install.packages("tidyverse")
library(tidyverse)

file.choose()
getwd()
setwd("C:\\Users\\Emman\\Documents\\CCH-N} FES-A\\fessaa\\FES\\5to Semestre\\Estadistica")
list.files()
housing <- read_csv("sataSets\\landdata-states.csv")
head(housing, 5)
summary(housing)
unique(housing$State)
class(housing)
# Base form

hist(housing$Home.Value)

plot(Home.Value ~ Date,
     col = factor(State),
     data = filter(housing, State %in% c("NY", "TX")))
legend("topleft",
       legend = c("NY", "TX"),
       col = c("black", "red"),
       pch = 1)

# Ggplot
ggplot(housing, aes(x = Home.Value)) +
  geom_histogram()

ggplot(filter(housing, State %in% c("NY", "TX")),
       aes(x = Date,
           y = Home.Value,
           color = State))+
  geom_point()


# Geometic Objects (geom)
# Points (Scatterplot)
hp2001Q1 <- filter(housing, Date == 2001.25) 
ggplot(hp2001Q1,
       aes(y = Structure.Cost, x = Land.Value)) +
  geom_point()
# Escalas
ggplot(hp2001Q1,
       aes(y = Structure.Cost, x = log(Land.Value))) +
  geom_point()

# Text (Label Points)
p1 <- ggplot(hp2001Q1, aes(x = log(Land.Value), y = Structure.Cost))

p1 + 
  geom_text(aes(label=State), size = 3)


p1 + 
  geom_point() + 
  geom_text_repel(aes(label=State), size = 3)


p1 +
  geom_point(aes(size = 2),
             color="red")

p1 +
  geom_point(aes(color=Home.Value, shape = region))

