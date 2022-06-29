import numpy as np
import torch as th
import random

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

def poliexa(elec, data, funimp, funpol, funest, funcos):
    ss=data[0]
    sk=data[1]
    sr=data[2]
    mt=data[3]
    mts=th.FloatTensor(mt)
    mt=mts.numpy()
    ct=data[4]
    
    '''
    print('\n ---  PRESENTACIÓN DEL PROBLEMA  ---')
    print('Estados: \n ', ss)
    print('Decisiones:\n',sk)
    print('Politicas: \n')
    funimp(sr)
    
    print('Matrices de transición: \n ')
    for i in range(len(mt)):
        funimp(mt[i])
        print('')
        
    print('Costos: \n')
    
    for i in range(len(ss)):
        for j in range(len(sk)):
            print('Costo de estar en estado',i,'y tomar desición',j+1)
            print(ct[i][j])
    '''
    mpol=funpol(mt, sr)
    print('Matrices por política: \n ')
    for i in range(len(mpol)):
        print('P(r=',i+1,'): \n')
        funimp(mpol[i])
    
     
    mve=funest(mpol)
    print('\nVectores de distribucion estacionarios:')
    for i in range(len(mve)):
        print('π_',i+1,' : \n')
        print(mve[i])
    print('Posibles valores')    
    total=funcos(ct,sr,mve)
    if(elec==1):
        print('\n El maximo es:')
        print(max(total))
        w=total.index(max(total))
        print('La politica optima es la',sk[w],': \n')
        print(sr[w])
    else:
        print('\n El minimo es:')
        print(min(total))
        w=total.index(min(total))
        print('La politica optima es la',sk[w],': \n')
        print(sr[w])

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

def polale(pol):
    return random.choice(pol)

def matpolin(tens, pin):
    mti=[]
    t=0
    for i in range(len(pin)):
        mi=[]
        lr=[]
        lrr=[]
        t=pin[i]
        lr=tens[t-1][ i]
        lrr=[round(elem, 4) for elem in lr]
        mti.append(lrr)
    return mti

def vecos(pin, cos):
    vc=[]
    for i in range(len(pin)):
        t=pin[i]
        vc.append(cos[i][t-1])
    print('\n Vector de costos:')
    print(vc)
    return vc

def detvin(polin, vc, matin):
    matizq=np.zeros((len(polin),len(polin)))
    #print(matizq)
    matizq[:,0]=np.ones(len(polin))
    for i in range(len(matizq)-1):
        matizq[i, i+1]=1.0
    ##matizq[:,1]=np.ones(len(polin))
    #print(matizq)
    matder=np.zeros_like(matizq)
    #print(matder)
    for i in range(len(matder)):
        for j in range(len(matder[i])-1):
            '''
            print('+'*30)
            print(j)
            print(matder[i,j+1])
            print(matin[i,j])
            '''
            matder[i,j+1]=matin[i,j]
    #print(matder)
    a=matizq-matder
    print('\n SISTEMA: \n')
    for i in range(len(a)):
        print('E1:  ',a[i],' = ',vc[i])
    x=np.linalg.inv(a).dot(vc)
    print('\n Vector V asociada a politica inicial \n')
    print(x)
    return a,x

def mejora(pin, vin, mt, matc, das, ele):
    pnn=[]
    minp=[]
    vn=[]
    m=0
    vn=np.zeros_like(vin)
    
    for i in range(len(vn)-1):
        vn[i]=vin[i+1]

    for i in range(len(das)):
        print('Estado',i,' :  \n')
        minp=[]
        for h in range(len(das[i])):
            k=0
            m=0
            k=das[i][h]
            if(len(das[i])==1):
                
                k=das[i][h]
                print('K=',k)
                pnn.append(k)
                key=1
                print('No se calcula, pasa k como desicion elegida \n')
            else:
                e=0
                key=2
                for j in range(len(das)):
                    e=e+mt[k-1,i,j]*vn[j]
        
                m=matc[i][k-1]+e-vn[i]
                minp.append(m)
                
        print('Costos')
        print(minp)  
        print('\n')      
        if(key!=1):
            if(ele==1):
                q=max(minp)
                nk=minp.index(q)+1
                pnn.append(nk)
                print("Se elige la desición k=",nk)
            else:
                q=min(minp)
                nk=minp.index(q)+1
                pnn.append(nk)
                print("Se elige la desición k=",nk)
    print('NUEVA POLITICA :')
    print(pnn)
    print('\n')
    if(pnn==pin):
        print('La politica optima es: \n')
        print(pnn)
    else:
        print('\n Siguiente iteracion \n')
        pin=pnn
        return mejora(pin, vin, mt, matc, das, ele)

def detvin_des(polin, vc, matin, alfa):
    
    matizq=np.zeros((len(matin),len(matin)))
    for i in range(len(matizq)):
        matizq[i,i]=1.0
    #print(matizq)
    matder=np.zeros_like(matizq)
    #print(matder)
    matder=matin
    a=matizq-alfa*matder
    print('\n -- PASO #1 \n')
    print('Sistema: \n')
    for i in range(len(a)):
        print('E1:  ',a[i],' = ',vc[i])
    x=np.linalg.inv(a).dot(vc)
    print('\n Vector V asociada a politica inicial \n')
    print(x)
    return a,x

def mejora_des(pin, vin, mt, matc, das, alfa, ele):
    pnn=[]
    minp=[]
    m=0
    
    for i in range(len(das)):
        print('Estado',i,' :  \n')
        minp=[]
        for h in range(len(das[i])):
            k=0
            m=0
            k=das[i][h]
            if(len(das[i])==1):
                
                k=das[i][h]
                print('K=',k)
                pnn.append(k)
                key=1
                print('No se calcula, pasa k como desicion elegida \n')
            else:
                e=0
                key=2
                for j in range(len(das)):
                    e=e+mt[k-1,i,j]*vin[j]
        
                m=matc[i][k-1]+alfa*e
                minp.append(m)
                
        print('Costos')
        print(minp)  
        print('\n')
        if(key!=1):
            if(ele==1):
                q=max(minp)
                nk=minp.index(q)+1
                pnn.append(nk)
                print('\n El maximo es: ', q)
                print(" \n Se elige la desición k=",nk)
            else:
                q=min(minp)
                nk=minp.index(q)+1
                pnn.append(nk)
                print('\n El minimo es: ', q)
                print("\n Se elige la desición k=",nk)
    print('NUEVA POLITICA :')
    print(pnn)
    print('\n')
    if(pnn==pin):
        print('\n LA POLITICA ÓPTIMA ES: \n')
        print(pnn)
        
    else:
        print('\n Siguiente iteracion \n')
        pin=pnn
        return mejora_des(pin, vin, mt, matc, das,alfa, ele)
    
    
def main():
    
    dat=lectura()
    ss=dat[0]
    sk=dat[1]
    sr=dat[2]
    mt=dat[3]
    mts=th.FloatTensor(mt)
    mt=mts.numpy()
    ct=dat[4]
    das=dat[5]
    print('\n ---  PRESENTACIÓN DEL PROBLEMA  ---')
    print('Estados: \n ', ss)
    print('Decisiones:\n',sk)
    print('Politicas: \n')
    mator(sr)
    
    print('Matrices de transición: \n ')
    for i in mt:
        print(i)
    

    print('Costos: \n')
    
    for i in range(len(ss)):
        for j in range(len(sk)):
            print('Costo de estar en estado',i,'y tomar desición',j+1)
            print(ct[i][j])
    
    mpol=matpol(mt, sr)
    print('Matrices por política: \n ')
    for i in range(len(mpol)):
        print('P(r=',i+1,'): \n')
        mator(mpol[i])
    
    print('Desiciones aplicables \n')
    
    for i in range(len(das)):
        print('La decision #', i+1,'aplica a los estados:')
        print(das[i])
    
    print('\n 1. Politicas Exhaustivas. \n 2. Programacion Lineal. \n 3.Mejoramiento. \n 4.Mejoramineto con descuento \n')
    print('Elija el método: ')
    mtd=int(input())
        
    if(mtd==1):
        print('Maximizar(1)  o  minimizar(0) :')
        desi=int(input())
        poliexa(desi, dat, mator, matpol, vecest, cosfi)
        
    if(mtd==3):
        print("\n ----  MEJORAMIENTO DE POLITICAS ---- \n")
    
        print("\n Max 1 o min 0:   ")
        ele=int(input())
        
        ##Se obtiene una politica aleatoria
        print('\n Politica inicial: \n')
        polin=polale(sr)
        print(polin)
        
        ##Se obtiene su matriz de transicion
        print('\n Matriz asociada a la política ', polin, '\n')
        matin=matpolin(mt.tolist(), polin)
        mator(matin)
        
        ##vector de costos
        vc=vecos(polin, ct)
        
        ##Paso 1. det del valor Vin
        matin=np.array(matin)
        v=detvin(polin, vc, matin)
        polnew=[]
        print("\n -- MEJORAMIENTO --")
        ##Mejoramiento de politica
        polnew=mejora(polin, v[1], mt, ct, das, ele)
    
    if(mtd==4):
        print('\n -- METORAMIENTO CON DESCUENTO -- \n')

    
        print("\n Max 1 o min 0: ")
        ele=int(input())
        
        ##Se obtiene una politica aleatoria
        print('\n Politica inicial: \n')
        polin=polale(sr)
        print(polin)
        
        ##Se obtiene su matriz de transicion
        print('\n Matriz asociada a la política ', polin)
        matin=matpolin(mt.tolist(), polin)
        print('\n')
        mator(matin)
        
        ##vector de costos
        vc=vecos(polin, ct)
        
        ##Paso 1. det del valor Vin
        print('\n Descuento:  ')
        alfa=float(input())
        matin=np.array(matin)
        v=detvin_des(polin, vc, matin, alfa)
        polnew=[]
        print("---- MEJORAMIENTO ---- \n")
        ##Mejoramiento de politica
        polnew=mejora_des(polin, v[1], mt, ct, das,alfa, ele)
    

main()




















