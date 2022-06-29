/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package examen03;

/**
 *
 * @author 316211091
 */
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
