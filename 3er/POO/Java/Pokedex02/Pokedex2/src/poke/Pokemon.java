/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poke;

/**
 *
 * @author EMANUEL
 */
public class Pokemon {
    //Datos del poke
    protected String especie;
    protected  String tipo01;
    protected  String tipo02;
    protected  String habilidad;
    
    //constructor con parÃ¡metros
    public Pokemon(String especie, String tipo01, String tipo02,String habilidad){
        this.especie = especie;
        this.tipo01 = tipo01;
        this.tipo02 = tipo02;
        this.habilidad = habilidad;
    }
    
    public String getEspecie(){
        return especie;
    }
     public String getTipo01(){
        return tipo01;
    } 
     public String getTipo02(){
        return tipo02;
    }
     public String getHabilidad(){
        return habilidad;
    }
    
    
}
