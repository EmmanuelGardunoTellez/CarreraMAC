public class Ahorros extends Cuenta{
   public Ahorros(String numeroC, String nombreCl){
      super(numeroC,nombreCl);
   }
   
   public void interes(){
      saldoActual =saldoActual + saldoActual/5;
   }
}