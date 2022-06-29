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

def poliexa(elec, data, funimp, funpol, funest, funcos):
    ss=data[0]
    sk=data[1]
    sr=data[2]
    mt=data[3]
    mts=th.FloatTensor(mt)
    mt=mts.numpy()
    ct=data[4]
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
    mpol=funpol(mt, sr)
    print('Matrices por política: \n ')
    for i in range(len(mpol)):
        print('P(r=',i+1,'): \n')
        funimp(mpol[i])
     
    mve=funest(mpol)
    print('\nVectores de distribucion estacionarios:')
    for i in range(len(mve)):
        print('Pi_r=',i+1,': \n')
        print(mve[i])
    print('Posibles valores')    
    total=funcos(ct,sr,mve)
    print(min(total))

    
def exaustivas(elec, data, funimp, funpol, funest, funcos):
    ss=data[0]# estados
    sk=data[1]# decisiones
    sr=data[2]# POLITICAS
    pks=data[3]# matrices de transcicion
    ctt=data[4]# COSTOS
    ds=data[5]# DESICIONES APLICABLES A CADA ESTADO
    mts=th.FloatTensor(pks)
    pks=mts.numpy()
    print('\n ---  PRESENTACIÓN DEL PROBLEMA  ---')
    print('Estados: \n ', ss)
    print('Decisiones:\n',sk)
    
    print('Matrices de transición: \n ')
    for i in range(len(pks)):
        funimp(pks[i])
        print('')
        
    print('Costos: \n')
    
    for i in range(len(ss)):
        for j in range(len(sk)):
            print('Costo de estar en estado',i,'y tomar desición',j+1)
            print(ctt[i][j])
    print('desisiones asociadas a estado')
    for i in range(len(ds)):
      funimp(ds[i])
      print('')

    
    print('Seleccione el numero de iteracciones')
    itera=int(input())
    print('De un descuento')
    descu=float(input())
    poliOp=np.zeros((itera,len(ss))) #Polita optima por iteracion
    V =np.zeros((itera,len(ss))) #Valor que toma el costo
    n=0
    if elec==0:
        while n < itera :
          if (n==0):
            for i in range(len(ss)):
              print('V_',i,'^',n+1)
              print(ctt[i])
              print('El max es:',max(ctt[i]))
              V[n][i] = max(ctt[i])
              for k in range(len(sk)):
                if (ctt[i][k]==max(ctt[i])):
                  poliOp[n][i]=k+1
          else:
            for i in range(len(ss)):
              print('V_',i,'^',n+1)
              q=0
              auxV=np.zeros((len(ss),len(ds[i])))
              for k in ds[i]:
                aux=0
                print('k=',k)
                for j in range(len(ss)):
                  #print(descu,'*',pks[k-1][i][j],'*',V[n-1][j])
                  aux=aux + descu*(pks[k-1][i][j]*V[n-1][j])
                aux = aux+ ctt[i][k-1]
                auxV[0][q]=aux
                auxV[1][q]=k
                q=q+1
                print(auxV[0])
                print(auxV[1])
                r=0
                while r < q:
                    if (auxV[0][r]==max(auxV[0])):
                        V[n][i]=max(auxV[0])
                        poliOp[n][i]=auxV[1][r]
                    r=r+1
          #for i in range(len(ss)):
          #  if (abs(V[n-1][i]-V[n][i])<= error):
          #    errorn=1
          n=n+1
    else:
        while n < itera:
          if (n==0):
            for i in range(len(ss)):
              print('V_',i,'^',n+1)
              print(ctt[i])
              print('El min es:',min(ctt[i]))
              V[n][i] = min(ctt[i])
              for k in range(len(sk)):
                if (ctt[i][k]==min(ctt[i])):
                  poliOp[n][i]=k+1
          else:
            #print(poliOp)
            #print('')
            #print(V)
            for i in range(len(ss)):
              print('V_',i,'^',n+1)
              q=0
              auxV=np.zeros((len(ss),len(ds[i])))
              for k in ds[i]:
                aux=0
                print('k=',k)
                for j in range(len(ss)):
                  #print(descu,'*',pks[k-1][i][j],'*',V[n-1][j])
                  aux=aux + descu*(pks[k-1][i][j]*V[n-1][j])
                aux = aux+ ctt[i][k-1]
                auxV[0][q]=aux
                auxV[1][q]=k
                q=q+1
                print(auxV[0])
                print(auxV[1])
                r=0
                while r < q:
                    if (auxV[0][r]==min(auxV[0])):
                        V[n][i]=min(auxV[0])
                        poliOp[n][i]=auxV[1][r]
                    r=r+1
          #for i in range(len(ss)):
          #  if (abs(V[n-1][i]-V[n][i])<= error):
          #    errorn=1
          n=n+1
    print(poliOp)
    print('')
    print(V)
        
    '''
    while n < itera:
      if (n==0):
        for i in range(len(ss)):
          print('V_',i,'^',n+1)
          print(ctt[i])
          print('El min es:',min(ctt[i]))
          V[n][i] = min(ctt[i])
          for k in range(len(sk)):
            if (ctt[i][k]==min(ctt[i])):
              poliOp[n][i]=k+1
      else:
        for i in range(len(ss)):
          print('V_',i,'^',n+1)
          q=0
          auxV=np.zeros((len(ss),len(ds[i])))
          for k in ds[i]:
            aux=0
            print('k=',k)
            for j in range(len(ss)):
              print(descu,'*',pks[k-1][i][j],'*',V[n-1][j])
              aux=aux + descu*(pks[k-1][i][j]*V[n-1][j])
            aux = aux+ ctt[i][k-1]
            auxV[0][q]=aux
            q=q+1
            print(auxV[0])
          r=0
          while r < q:
              if (auxV[0][r]==min(auxV[0])):
                  V[n][i]=min(auxV[0])
                  poliOp[n][i]=k
              r=r+1
      n=n+1
    print(poliOp)
    print('')
    print(V)
    '''


      
    
              
def main():
    
    dat=lectura()
    print('Maximizar(0)  o  minimizar(1) :')
    desi=int(input())
    print('Elija el método 1')
    print('Aproximaciones sucesivas 2')
    print('salir 9')
    mtd=int(input())
    
    if(mtd==1):
      poliexa(desi, dat, mator, matpol, vecest, cosfi)
    if(mtd==2):
      exaustivas(desi, dat, mator, matpol, vecest, cosfi)
      
        
main()


