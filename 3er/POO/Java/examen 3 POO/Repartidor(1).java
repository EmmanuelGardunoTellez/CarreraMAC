public class Repartidor extends EmpleadoPizeria{
    private double propina;
    
    
    
    public Repartidor(String nombre, int edad, double salario, double propina){
        super(nombre, edad, salario);
        this.propina = propina;
    }
    
    public double getPropina(){
        return propina;
    }
    
    public void setPropina (double pro){
        this.propina = pro;
    } 
}
