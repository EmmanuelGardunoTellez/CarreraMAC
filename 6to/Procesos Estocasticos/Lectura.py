import numpy as np
import torch as th

##IMPRIME MATRIZ DE MANERA ORDENADA
def mator(a):
  for i in range(len(a)):
    print(a[i])

##LECTURA DE DATOS
def lectura():
    ##ESTADOS
    s=[]
    print('Ingrese el numero de estados: \n')
    ns=int(input())
    for i in range(ns):
        s.append(i)
    print(s)
    
    ##DESICIONES
    k=[]
    print('Ingrese el numero de desiciones: \n')
    nk=int(input())
    for i in range(nk):
        k.append(i+1)
    print(k)
    
    
    '''
    ##ESTADOS ELEGIBLES A CADA DESICION
    ct=[]
    ans=0
    print('--- Digite 99 para saltar desicion--- \n')
    for i in range(nk):
        key=0
        cti=[]
        while(key!=1):
            print('ESTADO EN QUE APLICA LA DESICIÓN #',i+1,': \n')
            ans=int(input())
            if(ans==99):
                key=1
            else:
                cti.append(ans)
        ct.append(cti)
    mator(ct)
    ##ct=np.array(ct)
    '''
    
    ##DESICIONES APLICABLES A CADA ESTADO
    ds=[]
    ans=0
    for i in range(len(s)):
        key=0
        dsi=[]
        while(key!=1):
            print('Desición aplicables al estado',i,':')
            ans=int(input())
            if(ans==99):
                key=1
            else:
                dsi.append(ans)
        ds.append(dsi)
    mator(ds)
        
    
    ##POLITICAS
    r=[]
    ri=[]
    print('-- DEFINICION DE POLITICAS -- \n')
    print('Total de políticas: ')
    nr=int(input())
    for i in range(nr):
        ri=[]
        print('Politica #', i+1,':')
        for j in range(ns):
            
            print('Decision elegida en estado #', j,':')
            ri.append(int(input()))
        r.append(ri)
    
    
    ##COSTOS
    print('\n --- COSTOS ---')
    ctt=[]
    qi=[]
    for i in range(ns):
        qi=[]
        for j in range(nk):
            ci=0
            print('Costo de estar en estado', i,'y tomar desición', j+1,':')
            ci=float(input())
            qi.append(ci)
        ctt.append(qi)
    print('--Matriz de costos--\n')
    mator(ctt)
    
    
    ##MATRICES DE TRANSICION
    print('--Matrices de transicion:-- \n\n')
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
        ##print(pks)
                
    return s,k,r,pks,ctt,ds


def matpol(tens, pol):
    mp=[]
    mpi=[]
    mi=[]
    for i in range(len(pol)):
        mpi=[]
        for j in range(len(pol[i])):
            mi=[]
            ##print(pol[i][j])
            q=pol[i][j]
            ##print(tens[q-1,j])
            mi=tens[q-1,j]
            mpi.append(mi)
        mp.append(mpi)
    
    return mp

def vecest(tens):
    matid=[]
    matc=[]
    n=len(tens[0])
    matid=np.zeros((n,n))
    for i in range(n):
        matid[i,i]=1.0
    matid[n-1]=np.ones(n)
    b=np.zeros(n)
    b[n-1]=1.0
    ##print(matid)
    for i in range(len(tens)):
        ##n=len(tens[i])
        mans=[]
        m1=tens[i]
        m1=np.array(m1)
        m2=np.transpose(m1)
        m2[n-1]=np.zeros(n)
        mans=matid-m2
        ##print(mans)
        ##print(b)
        x=np.linalg.inv(mans).dot(b)
        matc.append(x)
    ##print(matc)
    
    return matc

def cosfi(cost, pol, vest):
    
    ei=0
    em=[]
    for j in range(len(pol)):
        ei=0
        for i in range(len(pol[j])):
            ei=ei+vest[j][i]*cost[i][(pol[j][i])-1]
        em.append(ei)
    print(em)
    return em
              
def main():
    
    data=lectura()
    ss=data[0]
    sk=data[1]
    sr=data[2]
    mt=data[3]
    mts=th.FloatTensor(mt)
    mt=mts.numpy()
    ct=data[4]
    das=data[5]
    print('\n ---  PRESENTACIÓN DEL PROBLEMA  ---')
    print('Estados: \n ', ss)
    print('Decisiones:\n',sk)
    print('Politicas: \n')
    mator(sr)
    
    print('Matrices de transición: \n ')
    for i in range(len(mt)):
        mator(mt[i])
        print('')
       
    print('Costos: \n')
    
    for i in range(len(ss)):
        for j in range(len(sk)):
            print('Costo de estar en estado',i,'y tomar desición',j+1)
            print(ct[i][j])
    
    '''
    p=-1
    for i in range(len(ss)):
        p=p+1
        for j in range(len(sk)):
            print('Costo de estar en estado', i,'y tomar desición', j+1,':', ct[i+j+p])
    print(ct)
    '''
    
    mpol=matpol(mt, sr)
    print('Matrices por política: \n ')
    for i in range(len(mpol)):
        print('P(r=',i+1,'): \n')
        mator(mpol[i])
        
    mve=vecest(mpol)
    print('\nVectores de distribucion estacionarios:')
    for i in range(len(mve)):
        print('Pi_r=',i+1,': \n')
        print(mve[i])
    print('Posibles valores')    
    total=cosfi(ct,sr,mve)
    print(min(total))
    
    #######################
    print('Desiciones aplicables \n')
    
    for i in range(len(das)):
        print('La decision #', i+1,'aplica a los estados:')
        print(das[i])
        
main()












