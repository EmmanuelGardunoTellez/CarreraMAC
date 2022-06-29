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
public class EmpleadoPizeria {
    protected  String nombre;
    protected  int edad;
    protected  double salario;
    
    //constructor con parÃ¡metros
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
