from nodo import Nodo

class ListaCircularDoble:

    def __init__ (self):
          self.primero = None
          self.ultimo = None
    def vacia(self):
        if  self.primero ==None :#None
                return True
        else:
               return False

     def agregar_inicio (self, dato):
           if self.vacia():
                self.primero = self.ultimo= Nodo(dato)
           else:
             aux = Nodo(dato)
             aux.siguiente=self.primero
             self.primero.anterior = aux
           self.primero= aux
           self.__unir_nodos()

    def agregar_final(self, dato):
           if self.vacia():
              self.primero =self.ultimo= Nodo(dato)
           else:
                 aux= self.ultimo
                 self.ultimo =aux.siguiente= Nodo(dato)
                 self.ultimo.anterior=aux
                 self.__unir_nodos()


    def eliminar_inicio(self):
        if self.vacia():
            print("Estructura vacía")
        elif self.primero == self.ultimo:
            self.primero = self.ultimo = None
        else:
            self.primero = self.primero.siguiente
        self.__unir_nodos()

    def eliminar_ultimo(self):
        if self.vacia():
            print("Estructura vacía")
        elif self.primero == self.ultimo:
            self.primero = self.ultimo = None
        else:
            self.ultimo = self.ultimo.anterior
        self.__unir_nodos( )

  def buscar (self , dato):
         aux= self.primero
         while aux:
                  if  aux.dato== dato:
                      return True
                  else:
                      aux=aux.siguiente
                       if aux == self.primero:
                           return False

     def __unir_nodos(self):
          if self.primero!= None:
           self.primero.anterior = self.ultimo
           self.ultimo.siguiente  = self.primero

    def recorrer_inicio_a_fin(self):
        aux=self.primero
        while aux:
              print(aux.dato)
        aux= aux.siguiente
        if aux == self.primero:
                  break

    def recorrer_fin_a_inicio(self):
          aux = self.ultimo
          while aux:
                 print(aux.dato)
                 aux = aux.anterior
                 if aux == self.ultimo:
                     break