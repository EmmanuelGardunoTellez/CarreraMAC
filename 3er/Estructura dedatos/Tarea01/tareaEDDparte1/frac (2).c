#include <stdio.h>
#include <stdlib.h>

typedef struct FRAC {
    short numerador;
    short denominador;
    }
FRAC;FRAC setvalue(int a, int b){
FRAC ar;
if(b!=0){
    ar.denominador=b;
    ar.numerador=a;
    return(ar);
}
printf("Entonces el valor no existe");
ar.numerador=-1;
ar.denominador=1;
return(ar);
}
void toprint (FRAC ar){
printf("%d/%d", ar.numerador, ar.denominador);
return;
}
FRAC mult(FRAC a, FRAC b){
 FRAC ar;
 ar.numerador=a.numerador*b.numerador;
 ar.denominador=a.denominador*b.denominador;
 return(ar);
}
FRAC div(FRAC a, FRAC b) {
FRAC ar;
ar.numerador=a.numerador*b.denominador;
ar.denominador=a.denominador*b.numerador;
return(ar);
}
FRAC suma(FRAC a, FRAC b){
FRAC ar;
ar.numerador=a.numerador*b.denominador+b.numerador*a.denominador;
ar.denominador=a.denominador*b.denominador;
return(ar);
} 
FRAC rest(FRAC a, FRAC b){
FRAC ar;
ar.numerador=a.numerador*b.denominador-b.numerador*a.denominador;
ar.denominador=a.denominador*b.denominador;
return(ar);
} 
int main(void){
       FRAC nomvar1, nomvar2, nomvar3;
       nomvar1=setvalue(1,3);
       nomvar2=setvalue(1,2);
       nomvar3=mult(nomvar1, nomvar2);
       printf("\n\t");
       toprint(nomvar1);
       printf(" * ");
       toprint(nomvar2);
       printf(" = ");
       toprint(nomvar3);
    
       /*todo lo que sigue es lo mismo*/
       FRAC n1, n2, n3;
       n1=setvalue(1,3);
       n2=setvalue(1,2);
       n3=div(n1, n2);
       printf("\n\t");
       toprint(n1);
       printf(" / ");
       toprint(n2);
       printf(" = ");
       toprint(n3);
 
    
       FRAC m1, m2, m3;
       m1=setvalue(1,3);
       m2=setvalue(1,2);
       m3=suma(m1, m2);
       printf("\n\t");
       toprint(m1);
       printf(" + ");
       toprint(m2);
       printf(" = ");
       toprint(m3);
    
       FRAC p1, p2, p3;
       p1=setvalue(1,3);
       p2=setvalue(1,2);
       p3=rest(p1, p2);
       printf("\n\t");
       toprint(p1);
       printf(" - ");
       toprint(p2);
       printf(" = ");
       toprint(p3);
    
    printf("\n\n\n");
    system("pause");
   }
