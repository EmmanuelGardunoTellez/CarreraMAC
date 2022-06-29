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
public class Cocinero extends EmpleadoPizeria{
    private double comision;
    
    
    
    public Cocinero(String nombre, int edad, double salario, double comision){
        super(nombre, edad, salario);
        this.comision = comision;
    }
    
    public double getPropina(){
        return comision;
    }
    
    public void setPropina (double com){
        this.comision = com;
    } 
}
