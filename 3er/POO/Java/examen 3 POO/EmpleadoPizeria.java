public class EmpleadoPizeria {
    protected  String nombre;
    protected  int edad;
    protected  double salario;
    
    public EmpleadoPizeria(String nombre, int edad, double salario){
        this.edad = edad;
        this.nombre = nombre;
        this.salario = salario;
    }
    
    public int getEdad(){
        return edad;
    }
    
    public String getNombre(){
        return nombre;
    }
     
    public double getSalario(){
        return salario;
    }
    
    public void setEdad (int ed){
        this.edad = ed;
    } 
    
    public void setNombre(String name){
        this.nombre = name;
    }
    
    public void setSalario(double sal){
        this.salario = sal;
    }
}