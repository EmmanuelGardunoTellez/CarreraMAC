/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package poke;

import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author EMANUEL
 */
public class Pokedex extends JFrame {//implements ActionListener{
    JButton eevee, pikachu, poplio, mudkip, snivy, totodile, torchic, chinchar, frokie, litten;
    JButton eeveeB, pikachuB, poplioB, mudkipB, snivyB, totodileB, torchicB, chincharB, frokieB, littenB ;
    JPanel eeveeP, pikachuP, popli, mudkipP, snivyP, totodileP, torchicP, chincharP, frokieP, littenP;
    
    
    public Pokedex(){
       this.setSize(700, 500);
       this.setTitle("PokeDex");
       this.setLocationRelativeTo(null);
       this.setDefaultCloseOperation(EXIT_ON_CLOSE);
 /*panel1 = new JPanel();
 panel2 = new JPanel();
panel3 = new JPanel();
       
   anterior = new JButton("Anterior");
   siguiente = new JButton("Siguente");
        
        anterior.setBounds(50, 10, 100, 50);
       // anterior.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       // anterior.setText("Ultimo");
        this.add(anterior);
        siguiente.setBounds(550, 10 , 100, 50);
       // siguiente.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
        //siguiente.setText("Siguiente");
        this.add(siguiente);
        anterior.addActionListener(this);
        siguiente.addActionListener(this);
       poke494();
       panel1.setVisible(true);
      // poke495();
       panel2.setVisible(false);
     //  poke496();
       panel3.setVisible(false);*/
    }
    
    /*private void poke494(){
        DataPokedex victini = new DataPokedex(
                        "Victini", //   Nombre
                        "Victoria", //categoria
                        "Psíquico", //Tipo1
                        "Fuego", //Tipo 2
                        "Pokémon que atrae la victoria. Dicen que el Entrenador que lo ",
                        "lleve saldrá vencedor de cualquier batalla.",
                        "",
                        "", //Descripcion
                        "Tinovictoria", //Habilidad
                        4.0, //peso
                        0.4, //Altura
                        494, //Numero
                        "494.png"); //imagen

        
        panel1.setLayout(null);
        panel1.setBackground(Color.WHITE);
        this.getContentPane().add(panel1);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(victini.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        panel1.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(victini.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        panel1.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(victini.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        panel1.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ victini.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        panel1.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ victini.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        panel1.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + victini.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        panel1.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + victini.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        panel1.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(victini.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        panel1.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(victini.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        panel1.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(victini.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        panel1.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(victini.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        panel1.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ victini.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        panel1.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(victini.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        panel1.add(imagen2);
        
        
    }
    
   
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == anterior){
            panel1.setVisible(true);
            panel2.setVisible(false);
            panel3.setVisible(false);
        }
        if(e.getSource() == siguiente){
            panel1.setVisible(false);
            panel2.setVisible(true);
            panel3.setVisible(false);
        }
    }*/
}
