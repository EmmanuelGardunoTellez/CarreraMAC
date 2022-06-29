import torch as th
import numpy as np

##IMPRIME MATRIZ DE MANERA ORDENADA
def mator(a):
  for i in range(len(a)):
    print(a[i])


##LECTURA DE DATOS
def lectura():
    ##ESTADOS
    s=[]
    print('Ingrese el numero de estados')
    ns=int(input())
    for i in range(ns):
        s.append(i)
    print(s)
    
    ##DESICIONES
    k=[]
    print('Ingrese el numero de desiciones')
    nk=int(input())
    for i in range(nk):
        k.append(i+1)
    print(k)
    
    ##POLITICAS
    r=[]
    ri=[]
    print('Definición de políticas')
    print('Total de políticas')
    nr=int(input())
    for i in range(nr):
        ri=[]
        print('Politica #', i+1,':')
        for j in range(ns):
            
            print('Decision elegida en estado #', j,':')
            ri.append(int(input()))
        r.append(ri)
    
    ##MATRICES DE TRANSICION
    print('Matrices de transicion:')
    pks=[]
    pki=[]
    pk=[]
    ##pks=np.array(pks)
    for i in range(nk):
        print('Matriz de desicion K=',i+1,':')
        pki=[]
        for j in range(ns):
            pk=[]
            for h in range(ns):
                
                print('Probabilidad de ',j,'a',h,':')
                pk.append(float(input()))
            pki.append(pk)
        pks.append(pki)
        print(pks)
                
    return s,k,r,pks  
    
def main():
    
    data=lectura()
    ss=data[0]
    sk=data[1]
    sr=data[2]
    mt=data[3]
    mts=th.FloatTensor(mt)
    mt=mts.numpy()
    print('Estados: \n ', ss)
    print('Decisiones:\n',sk)
    print('Politicas: \n')
    mator(sr)
    print('Matrices de transición: \n ', mt)

    '''
    for i in range(len(sk)):
      for j in range(len(ss)):
        for t in range(len(ss)):
          print(mt[i,j,t])
    '''
  
    
main()
