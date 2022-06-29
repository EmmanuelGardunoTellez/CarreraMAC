public class Cuenta{
   protected String noCuenta;
   protected String NombreCliente;
   protected int saldoActual = 0;
   
   public Cuenta (String numeroC, String nombreCl){
      noCuenta = numeroC;
      NombreCliente = nombreCl;
   }
   public void dopesitar (int agregar){
      saldoActual= saldoActual + agregar;
   }
   
   public void retirar (int sacar){
      saldoActual= saldoActual -  sacar;
   }
   
   public int consultarSaldo(){
   return saldoActual;
   }

}