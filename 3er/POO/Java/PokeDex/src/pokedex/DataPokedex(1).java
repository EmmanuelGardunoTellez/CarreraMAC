/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pokedex;

/**
 *
 * @author EMANUEL
 */
public class DataPokedex extends Pokemon{
    protected  String categoria;
    protected  String descripcion1;
    protected  String descripcion2;
    protected  String descripcion3;
    protected  String descripcion4;
    protected  double peso;
    protected  double altura;
    protected  int numero;
    protected  String imagen;
    
    
        public DataPokedex(String especie, String categoria, String tipo01, String tipo02,String descripcion1,String descripcion2,String descripcion3,String descripcion4, String habilidad,double peso,double altura,int numero,String imagen){
        super(especie,tipo01,tipo02, habilidad );
        this.categoria = categoria; 
        this.descripcion1 = descripcion1;
        this.descripcion2 = descripcion2;
        this.descripcion3 = descripcion3;
        this.descripcion4 = descripcion4;
        this.peso = peso;
        this.altura = altura;
        this.numero = numero;
        this.imagen = imagen;
    }
    
     public String getCategoria(){
        return categoria;
    }
      public String getDescipcion(){
        return descripcion1;
    }
       public double getPeso(){
        return peso;
    }
    
     public double getAltura(){
        return altura;
    }
     public int getNumero(){
        return numero;
    }
}
