##Librerias a utilizar
import numpy as np
import math 
import scipy 

def main():
    print("Presiona 1 para MAXIMIZAR")
    print("Presiona 2 para minimizar")
    user_choice = int(input())
    if user_choice == 1:
        maxim()
def mator(a):
  for i in range(len(a)):
    print(a[i])

def igmat(a,b):
  for i in range(len(a)):
    a[i]=b[i]
  return a

def paso0(func,va,z,zo,ma):
  for i in range(len(va)):
    zo=zo+ma[va[i]]
  print("Zo= ", zo)
  print("Z= ", z)
  func(ma)
  return zo
    
def maxim():
    print("Numero de varibles en la funcion objetivo: ")
    number_of_variables = int(input())
    listz = []
    lisnam=[]
    # Función a maximizar
    for i in range(number_of_variables):
        print('Valor de la variable X', i + 1, 'en la funcion a maximizar: ')
        val = float(input())
        listz.append(val)

    # Numero de restricciones
    print('Numero de restricciones: ')
    number_of_inequalities = int(input())
    listz.extend(np.zeros((number_of_inequalities*2)+1).tolist())
    listzo=np.zeros(len(listz))
    print("Funcion objetivo: ", listz)
    # Matriz de restricciones
    matrix_list = []
    # Variables de olgura y artificiales
    e_values = np.zeros(number_of_inequalities).tolist()
    a_values = np.zeros(number_of_inequalities).tolist()
    lds=[]
    types_res=[]
    for i in range(number_of_inequalities):
        k=i
        values_list = []
        for j in range(number_of_variables):
            print('Valor de  X', j + 1, 'en la restricción ', i + 1,":")
            value = float(input())
            values_list.append(value)
        print("Si la desiguadad es -Mayor que- intruduzca >, si  es -Menor que- intraduzca < : ")
        typeres=input()
        types_res.append(typeres)
        if typeres=='<':
          ##print("Menor")
          arti=False
          e_values[i]=1.0
          
        else: 
          ##print("Mayor")
          arti=True
          e_values[i]=-1.0
          listzo[number_of_variables+number_of_inequalities+i]=-1.0
          a_values[i]=1.0
        # Llenar con 0, 1 o -1 las variables de olgura, exceso y artificiales.
        if i != 0 :
            e_values[i - 1] = 0.0
            a_values[i-1]=0.0
            
        for e_value in e_values:
            values_list.append(e_value)
        for a_value in a_values:
            values_list.append(a_value)
        ####################################
        print('Lado derecho de la restriccion :', i + 1)
        res = float(input())
        lds.append(res)
        # Fin de cada llenado de restriccion
        values_list.append(res)
        values_list=np.array(values_list)
        # Añade la restriccion a la matriz
        matrix_list.append(values_list)
        ##print(matrix_list)
        ##print(type(matrix_list))
    
    listzo=np.array(listzo)
    print("Zo= ",listzo)
    listz=np.array(listz)
    print("Z= ",listz)
    matrix_list=np.array(matrix_list)

    mator(matrix_list)
      ##print(types_res[i])
      ##print(lds[i])
    ##print(types_res)
    ##print(lds)
    van=[]
    for i in range(number_of_inequalities):
      if matrix_list[i][number_of_variables+ number_of_inequalities+i]== 1.0:
        van.append(i)
        print("Con variable artificial en restriccion", i+1)
      else:
        print("Sin variable artificial en restriccion", i+1)
    if len(van)!=0:
      print("Fase 1 inicia")
      f1=True
    else:
      print("Fase 2 inicia")
      f2=True
      ##FAse 2 funcion
    if f1==True:
      listzo=paso0(mator,van,listz,listzo,matrix_list)
      zo1=np.zeros(len(listzo)-1)
      #funcion que encuentra el mayor
      while(listzo[len(listzo)-1] > 0):
        for i in range(len(listzo)-1):
          zo1[i]=listzo[i]
        zmax=np.amax(zo1)
        print("Max UT: ")
        print(zmax)
        ind=int(np.where(zo1==np.nanmax(zo1))[0])
        print("POS: ")
        print(ind +1)
        coci=np.zeros(len(lds))

        for i in range(len(lds)):
          if matrix_list[i][ind]<=0.0:
            print(lds[i],"/",matrix_list[i][ind])
            print("division entre 0 o negativo, valor nulo")
            coci[i]=np.nan
          else:
            print(lds[i],"/",matrix_list[i][ind])
            coci[i]=float( lds[i]/matrix_list[i][ind])
        print(coci)
        print("Min Coc: ")
        cmin=np.nanmin(coci)
        print(cmin)
        ind2=int(np.where(coci==np.nanmin(coci))[0])
        print("pos: ")
        print(ind2 +1)
        pivote=matrix_list[ind2][ind]
        print("Pivote en posi [",ind2 +1 ,"][",ind +1 ,"] = ",pivote)  
        mataux=np.zeros_like(matrix_list)
        ##mator(mataux)
        mataux[ind2]=matrix_list[ind2]/pivote
        lds[ind2]=lds[ind2]/pivote
        ##mator(mataux)
        listzo=listzo-listzo[ind]*mataux[ind2]
        listz=listz-listz[ind]*mataux[ind2]
        for i in range(len(lds)):
          if i!=ind2:
            mataux[i]=matrix_list[i]-matrix_list[i][ind]*mataux[ind2]
            lds[i]=lds[i]-matrix_list[i][ind]*lds[ind2]
        
        print(listzo)
        print(listz)
        mator(mataux)
        igmat(matrix_list,mataux)
        

main()
