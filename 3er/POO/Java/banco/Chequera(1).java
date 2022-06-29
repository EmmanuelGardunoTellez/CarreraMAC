public class Chequera extends Cuenta{
   public Chequera(String numeroC, String nombreCl){
      super(numeroC,nombreCl);
   }
   
   public void retirar (int sacar){
      if(0>=(saldoActual -  sacar)){
         saldoActual= saldoActual;
      }else{ 
         saldoActual= saldoActual -  sacar;
      }
   }
   }