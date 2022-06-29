public class Pokemon {
    //Datos del poke
    private String especie;
    private String categoria;
    private String tipo01;
    private String tipo02;
    private String descripcion;
    private String habilidad;
    private float peso;
    private float altura;
    private int numero;
    //constructor con parámetros
    public Pokemon(String especie, String categoria, String tipo01, String tipo02,String descripcion,String habilidad,float peso,float altura,int numero){
        this.especie = especie;
        this.categoria = categoria;
        this.tipo01 = tipo01;
        this.tipo02 = tipo02;
        this.descripcion = descripcion;
        this.habilidad = habilidad;
        this.peso = peso;
        this.altura = altura;
        this.numero = numero;
    }
    
    public void setEspecie(String especie) {
        this.especie = especie;
    }
    public String getEspecie(){
        return especie;
    }
    
    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }
    public String getCategoria(){
        return categoria;
    }
    
    public void setTipo01(String tipo01) {
        this.tipo01 = tipo01;
    }
     public String getTipo01(){
        return tipo01;
    }
     
     public void setTipo02(String tipo02) {
        this.tipo02 = tipo02;
    }
     public String getTipo02(){
        return tipo02;
    }
     
     public void setDescricion(String descripcion) {
        this.descripcion = descripcion;
    }
     public String getDescipcion(){
        return descripcion;
    }
     
     public void setHabilidad(String habilidad) {
        this.habilidad = habilidad;
    }
     public String getHabilidad(){
        return habilidad;
    }
     
     public void setPeso(float peso) {
        this.peso = peso;
    }
     public float getPeso(){
        return peso;
    }
     
     public void setAltura(float altura) {
        this.altura = altura;
    }
     public float getAltura(){
        return altura;
    }
     
     public void setEspecie(int numero) {
        this.numero = numero;
    }
     public int getNumero(){
        return numero;
    }
}
