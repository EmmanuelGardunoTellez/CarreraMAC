public class Cocinero extends EmpleadoPizeria{
    private double comision;
    
    
    
    public Cocinero(String nombre, int edad, double salario, double comision){
        super(nombre, edad, salario);
        this.comision = comision;
    }
    
    public double getComicion(){
        return comision;
    }
    
    public void setComicion (double com){
        this.comision = com;
    } 
}
