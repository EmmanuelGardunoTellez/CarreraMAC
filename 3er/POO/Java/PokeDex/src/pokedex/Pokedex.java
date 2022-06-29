package pokedex;

import java.awt.Color;
import java.awt.Font;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class Pokedex extends JFrame implements ActionListener{
    JButton eeveeB, pikachuB, poplioB, mudkipB, snivyB, totodileB, torchicB, chincharB, frokieB, littenB ;
    JPanel eeveeP, pikachuP, poplioP, mudkipP, snivyP, totodileP, torchicP, chincharP, frokieP, littenP;  
    public Pokedex(){
       setDefaultCloseOperation(EXIT_ON_CLOSE);
       setSize(800, 550);
       setTitle("PokeDex");
       setLayout(null);
       
       setLocationRelativeTo(null);
       
       iniciarcomponentes();
    }
    
    private void iniciarcomponentes(){
        
        
       eeveeP = new JPanel();
       eeveeP.setBackground(Color.WHITE);
       eeveeP.setBounds(100, 0, 700, 550);
       eeveeP.setLayout(null);
       eevee();
       
       pikachuP = new JPanel();
       pikachuP.setBackground(Color.WHITE);
       pikachuP.setBounds(100, 0, 700, 550);
       pikachuP.setLayout(null);
       pikachu();
       
       poplioP = new JPanel();
       poplioP.setBackground(Color.WHITE);
       poplioP.setBounds(100, 0, 700, 550);
       poplioP.setLayout(null);
       poplio();
       
       mudkipP = new JPanel();
       mudkipP.setBackground(Color.WHITE);
       mudkipP.setBounds(100, 0, 700, 550);
       mudkipP.setLayout(null);
       mudkip();
       
       snivyP = new JPanel();
       snivyP.setBackground(Color.WHITE);
       snivyP.setBounds(100, 0, 700, 550);
       snivyP.setLayout(null);
       snivy();
       
       totodileP = new JPanel();
       totodileP.setBackground(Color.WHITE);
       totodileP.setBounds(100, 0, 700, 550);
       totodileP.setLayout(null);
       totodile();
       
       torchicP = new JPanel();
       torchicP.setBackground(Color.WHITE);
       torchicP.setBounds(100, 0, 700, 550);
       torchicP.setLayout(null);
       torchic();
       
       chincharP = new JPanel();
       chincharP.setBackground(Color.WHITE);
       chincharP.setBounds(100, 0, 700, 550);
       chincharP.setLayout(null);
       chinchar();
       
       frokieP = new JPanel();
       frokieP.setBackground(Color.WHITE);
       frokieP.setBounds(100, 0, 700, 550);
       frokieP.setLayout(null);
       frokie();
       
       littenP = new JPanel();
       littenP.setBackground(Color.WHITE);
       littenP.setBounds(100, 0, 700, 550);
       littenP.setLayout(null);
       litten();
       
       eeveeB = new JButton("Eevee");
       eeveeB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       pikachuB = new JButton("Pikachu");
       pikachuB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       poplioB = new JButton("Poplio");
       poplioB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       mudkipB = new JButton("Mudkip");
       mudkipB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       snivyB = new JButton("Snivy");
       snivyB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       totodileB = new JButton("Totodile");
       totodileB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       torchicB = new JButton("Torchic");
       torchicB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       chincharB = new JButton("Chimchar");
       chincharB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       frokieB = new JButton("Frokie");
       frokieB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       littenB = new JButton("Litten");
       littenB.setFont(new Font("Comic Sans MS", Font.PLAIN, 15));
       
       eeveeB.setBounds(0, 0, 100, 50);
       pikachuB.setBounds(0, 50, 100, 50);
       poplioB.setBounds(0, 100, 100, 50);
       mudkipB.setBounds(0, 150, 100, 50);
       snivyB.setBounds(0, 200, 100, 50);
       totodileB.setBounds(0, 250, 100, 50);
       torchicB.setBounds(0, 300, 100, 50);
       chincharB.setBounds(0, 350, 100, 50);
       frokieB.setBounds(0, 400, 100, 50);
       littenB.setBounds(0, 450, 100, 50);
        
       eeveeB.addActionListener(this);
       pikachuB.addActionListener(this);
       poplioB.addActionListener(this);
       mudkipB.addActionListener(this);
       snivyB.addActionListener(this);
       totodileB.addActionListener(this);
       torchicB.addActionListener(this);
       chincharB.addActionListener(this);
       frokieB.addActionListener(this);
       littenB.addActionListener(this);
       
       add(eeveeB);
       add(pikachuB);
       add(poplioB);
       add(mudkipB);
       add(snivyB);
       add(totodileB);
       add(torchicB);
       add(chincharB);
       add(frokieB);
       add(littenB);
    }
    
    
    private void eevee(){
        DataPokedex eevee = new DataPokedex(
                        "Eevee", //   Nombre
                        "Evolución", //categoria
                        "Normal", //Tipo1
                        " ", //Tipo 2
                        "La configuración genética de Eevee le permite mutar y adaptarse",
                        "enseguida a cualquier medio en el que viva. La evolución de este",
                        "Pokémon suele ser posible gracias a las radiaciones emitidas",//Descripcion
                        "por varias piedras.",
                        "Adaptable", //Habilidad
                        6.5, //peso
                        0.3, //Altura
                        133, //Numero
                        "133.png"); //imagen

        this.getContentPane().add(eeveeP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(eevee.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        eeveeP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(eevee.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        eeveeP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(eevee.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        eeveeP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ eevee.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        eeveeP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ eevee.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        eeveeP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + eevee.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        eeveeP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + eevee.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        eeveeP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(eevee.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        eeveeP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(eevee.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        eeveeP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(eevee.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        eeveeP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(eevee.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        eeveeP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ eevee.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        eeveeP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(eevee.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        eeveeP.add(imagen2);
        
        
    }
    private void pikachu(){
        DataPokedex pikachu = new DataPokedex(
                        "Pikachu", //   Nombre
                        "Ratón", //categoria
                        "Electrico", //Tipo1
                        " ", //Tipo 2
                        "Cada vez que un Pikachu se encuentra con algo nuevo, le lanza",
                        "una descarga eléctrica. Cuando se ve alguna baya chamuscada,",
                        " es muy probable que sea obra de un Pikachu, ya que a veces ",
                        "no controlan la intensidad de la descarga.",//Descripcion
                        "Elec. Estática", //Habilidad
                        6.0, //peso
                        0.4, //Altura
                        25, //Numero
                        "025.png"); //imagen

        this.getContentPane().add(pikachuP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(pikachu.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        pikachuP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(pikachu.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        pikachuP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(pikachu.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        pikachuP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ pikachu.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        pikachuP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ pikachu.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        pikachuP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + pikachu.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        pikachuP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + pikachu.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        pikachuP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(pikachu.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        pikachuP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(pikachu.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        pikachuP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(pikachu.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        pikachuP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(pikachu.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        pikachuP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ pikachu.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        pikachuP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(pikachu.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        pikachuP.add(imagen2);
        
        
    }
    private void poplio(){
        DataPokedex poplio = new DataPokedex(
                        "Popplio", //   Nombre
                        "León Marino", //categoria
                        "Agua", //Tipo1
                        " ", //Tipo 2
                        "Se le conoce por su diligencia y predisposición. Segrega agua ",
                        "por la nariz para hinchar globos con los que golpea a sus rivales.",
                        "", //Descripcion
                        "",
                        "Torrente", //Habilidad
                        7.5, //peso
                        0.4, //Altura
                        728, //Numero
                        "728.png"); //imagen

        this.getContentPane().add(poplioP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(poplio.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        poplioP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(poplio.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        poplioP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(poplio.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        poplioP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ poplio.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        poplioP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ poplio.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        poplioP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + poplio.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        poplioP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + poplio.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        poplioP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(poplio.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        poplioP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(poplio.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        poplioP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(poplio.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        poplioP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(poplio.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        poplioP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ poplio.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        poplioP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(poplio.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        poplioP.add(imagen2);
        
        
    }
    private void mudkip(){
        DataPokedex mudkip = new DataPokedex(
                        "Mudkip", //   Nombre
                        "Pez lodo", //categoria
                        "Agua", //Tipo1
                        "", //Tipo 2
                        "La aleta que tiene Mudkip en la cabeza actúa de radar y es muy",
                        "sensible. Puede captar movimientos que se produzcan en el agua",
                        "y en el aire, y todo lo que ocurra a su alrededor, sin ",
                        "necesidad de abrir los ojos.",//Descripcion
                        "Torrente", //Habilidad
                        7.6, //peso
                        0.4, //Altura
                        258, //Numero
                        "258.png"); //imagen

        this.getContentPane().add(mudkipP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(mudkip.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        mudkipP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(mudkip.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        mudkipP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(mudkip.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        mudkipP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ mudkip.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        mudkipP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ mudkip.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        mudkipP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + mudkip.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        mudkipP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + mudkip.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        mudkipP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(mudkip.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        mudkipP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(mudkip.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        mudkipP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(mudkip.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        mudkipP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(mudkip.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        mudkipP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ mudkip.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        mudkipP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(mudkip.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        mudkipP.add(imagen2);
        
        
    }
    private void snivy(){
        DataPokedex snivy = new DataPokedex(
                        "Snivy", //   Nombre
                        "Serp. Hierba", //categoria
                        "Planta", //Tipo1
                        " ", //Tipo 2
                        "Cuando recibe los rayos de sol, se mueve mucho más rápido que",
                        " de costumbre. Usa mejor sus lianas que sus manos.",
                        "", //Descripcion
                        "",
                        "Espesura", //Habilidad
                        8.1, //peso
                        0.6, //Altura
                        495, //Numero
                        "495.png"); //imagen

        this.getContentPane().add(snivyP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(snivy.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        snivyP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(snivy.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        snivyP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(snivy.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        snivyP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ snivy.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        snivyP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ snivy.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        snivyP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + snivy.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        snivyP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + snivy.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        snivyP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(snivy.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        snivyP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(snivy.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        snivyP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(snivy.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        snivyP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(snivy.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        snivyP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ snivy.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        snivyP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(snivy.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        snivyP.add(imagen2);
        
        
    } 
    private void totodile(){
        DataPokedex totodile = new DataPokedex(
                        "Totodile", //   Nombre
                        "Fauces", //categoria
                        "Agua", //Tipo1
                        " ", //Tipo 2
                        "Totodile tiene cuerpo pequeño, pero fuertes mandíbulas. A veces,",
                        " piensa que solo está dando un mordisquito y hace unas heridas ",
                        "bastante considerables.", //Descripcion
                        "",
                        "Torrente", //Habilidad
                        9.5, //peso
                        0.6, //Altura
                        158, //Numero
                        "158.png"); //imagen

        this.getContentPane().add(totodileP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(totodile.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        totodileP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(totodile.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        totodileP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(totodile.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        totodileP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ totodile.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        totodileP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ totodile.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        totodileP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + totodile.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        totodileP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + totodile.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        totodileP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(totodile.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        totodileP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(totodile.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        totodileP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(totodile.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        totodileP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(totodile.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        totodileP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ totodile.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        totodileP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(totodile.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        totodileP.add(imagen2);
        
        
    }
    private void torchic(){
        DataPokedex torchic = new DataPokedex(
                        "Torchic", //   Nombre
                        "Polluelo", //categoria
                        "Fuego", //Tipo1
                        " ", //Tipo 2
                        "Torchic no se separa de su Entrenador. Siempre va tras él con ",
                        "sus pasitos inseguros. Este Pokémon escupe bolas de fuego que ",
                        "pueden alcanzar los 1000 °C y carbonizar al enemigo.", //Descripcion
                        "",
                        "Mar Llamas", //Habilidad
                        2.5, //peso
                        0.4, //Altura
                        255, //Numero
                        "255.png"); //imagen

        this.getContentPane().add(torchicP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(torchic.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        torchicP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(torchic.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        torchicP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(torchic.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        torchicP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ torchic.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        torchicP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ torchic.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        torchicP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + torchic.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        torchicP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + torchic.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        torchicP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(torchic.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        torchicP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(torchic.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        torchicP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(torchic.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        torchicP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(torchic.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        torchicP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ torchic.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        torchicP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(torchic.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        torchicP.add(imagen2);
        
        
    }
    private void chinchar(){
        DataPokedex chinchar = new DataPokedex(
                        "Cimchar", //   Nombre
                        "Chimpancé", //categoria
                        "Fuego", //Tipo1
                        " ", //Tipo 2
                        "El gas de su panza alimenta el fuego de su parte trasera, que",
                        "ni la lluvia puede extinguir.",
                        "",
                        "", //Descripcion
                        "Mar llamas", //Habilidad
                        6.2, //peso
                        0.5, //Altura
                        390, //Numero
                        "390.png"); //imagen

        this.getContentPane().add(chincharP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(chinchar.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        chincharP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(chinchar.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        chincharP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(chinchar.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        chincharP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ chinchar.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        chincharP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ chinchar.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        chincharP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + chinchar.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        chincharP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + chinchar.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        chincharP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(chinchar.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        chincharP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(chinchar.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        chincharP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(chinchar.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        chincharP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(chinchar.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        chincharP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ chinchar.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        chincharP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(chinchar.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        chincharP.add(imagen2);
        
        
    }
    private void frokie(){
        DataPokedex frokie = new DataPokedex(
                        "Froakie", //   Nombre
                        "Burburrana", //categoria
                        "Agua", //Tipo1
                        " ", //Tipo 2
                        "Secreta burbujas tanto por la espalda como por el pecho.",
                        "Gracias a la elasticidad de estas, puede parar ataques y",
                        "reducir el daño recibido.",
                        "", //Descripcion
                        "Torrente", //Habilidad
                        7.0, //peso
                        0.3, //Altura
                        656, //Numero
                        "656.png"); //imagen

        this.getContentPane().add(frokieP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(frokie.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        frokieP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(frokie.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        frokieP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(frokie.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        frokieP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ frokie.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        frokieP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ frokie.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        frokieP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + frokie.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        frokieP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + frokie.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        frokieP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(frokie.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        frokieP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(frokie.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        frokieP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(frokie.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        frokieP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(frokie.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        frokieP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ frokie.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        frokieP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(frokie.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        frokieP.add(imagen2);
        
        
    }
    private void litten(){
        DataPokedex litten = new DataPokedex(
                        "Litten", //   Nombre
                        "Gato Fuego", //categoria
                        "Fuego", //Tipo1
                        " ", //Tipo 2
                        "Prende las bolas de pelo que se forman en su estómago tras",
                        "acicalarse. Las llamas que escupe tienen formas variopintas.",
                        "", //Descripcion
                        "",
                        "Mar llamas", //Habilidad
                        4.3, //peso
                        0.4, //Altura
                        725, //Numero
                        "725.png"); //imagen

        this.getContentPane().add(littenP);
        int letra =15;

        JLabel pokemon = new JLabel();
        pokemon.setHorizontalAlignment(SwingConstants.CENTER);
        pokemon.setText(litten.especie);
        pokemon.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        pokemon.setBounds(300, 10, 100, 30);
        littenP.add(pokemon);
        
        JLabel tipo1 = new JLabel();
        tipo1.setHorizontalAlignment(SwingConstants.CENTER);
        tipo1.setText(litten.tipo01);
        tipo1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo1.setBounds(200, 60, 150, 30);
        littenP.add(tipo1);
        
        JLabel tipo2 = new JLabel();
        tipo2.setHorizontalAlignment(SwingConstants.CENTER);
        tipo2.setText(litten.tipo02);
        tipo2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        tipo2.setBounds(500, 60, 150, 30);
        littenP.add(tipo2);
        
        JLabel habilidad = new JLabel();
        habilidad.setHorizontalAlignment(SwingConstants.CENTER);
        habilidad.setText("Habilidad: "+ litten.habilidad);
        habilidad.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        habilidad.setBounds(200, 110, 450, 30);
        littenP.add(habilidad);
        
        JLabel categoria = new JLabel();
        categoria.setHorizontalAlignment(SwingConstants.CENTER);
        categoria.setText("Categoria: "+ litten.categoria);
        categoria.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        categoria.setBounds(200, 160, 450, 30);
        littenP.add(categoria);
        
        JLabel peso = new JLabel();
        peso.setHorizontalAlignment(SwingConstants.CENTER);
        peso.setText("Peso: " + litten.peso + "kg");
        peso.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        peso.setBounds(200, 210, 100, 30);
        littenP.add(peso);
        
        JLabel altura = new JLabel();
        altura.setHorizontalAlignment(SwingConstants.CENTER);
        altura.setText("Altura:" + litten.altura + " mt");
        altura.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        altura.setBounds(550, 210, 100, 30);
        littenP.add(altura);
        
        JLabel descripcion1 = new JLabel();
        descripcion1.setText(litten.descripcion1);
        descripcion1.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion1.setBounds(200, 260, 450, 30);
        littenP.add(descripcion1);
        
        JLabel descripcion2 = new JLabel();
        descripcion2.setText(litten.descripcion2);
        descripcion2.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion2.setBounds(200, 290, 450, 30);
        littenP.add(descripcion2);
        
        JLabel descripcion3 = new JLabel();
        descripcion3.setText(litten.descripcion3);
        descripcion3.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion3.setBounds(200, 320, 450, 30);
        littenP.add(descripcion3);
        
        JLabel descripcion4 = new JLabel();
        descripcion4.setText(litten.descripcion4);
        descripcion4.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        descripcion4.setBounds(200, 350, 450, 30);
        littenP.add(descripcion4);
        
        JLabel numero= new JLabel();
        numero.setText("Numero: "+ litten.numero);
        numero.setFont(new Font("Comic Sans MS", Font.PLAIN, letra));
        numero.setBounds(200, 400, 100, 30);
        littenP.add(numero);
        
        //Imagen
        ImageIcon imagen = new ImageIcon(litten.imagen);
        JLabel imagen2 = new JLabel(imagen);
        imagen2.setBounds(0, 150, 200, 200);
        imagen2.setIcon(new ImageIcon (imagen.getImage().getScaledInstance(imagen2.getWidth(), imagen2.getHeight(), Image.SCALE_SMOOTH)));
        littenP.add(imagen2);
        
        
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == pikachuB){
            pikachuP.setVisible(true);
            eeveeP.setVisible(false);
            poplioP.setVisible(false);
            mudkipP.setVisible(false);
            snivyP.setVisible(false);
            totodileP.setVisible(false);
            torchicP.setVisible(false);
            chincharP.setVisible(false);
            frokieP.setVisible(false);
            littenP.setVisible(false);
        }
        if(e.getSource() == eeveeB){
            pikachuP.setVisible(false);
            eeveeP.setVisible(true);
            poplioP.setVisible(false);
            mudkipP.setVisible(false);
            snivyP.setVisible(false);
            totodileP.setVisible(false);
            torchicP.setVisible(false);
            chincharP.setVisible(false);
            frokieP.setVisible(false);
            littenP.setVisible(false);
        }
        if(e.getSource() == poplioB){
            pikachuP.setVisible(false);
            eeveeP.setVisible(false);
            poplioP.setVisible(true);
            mudkipP.setVisible(false);
            snivyP.setVisible(false);
            totodileP.setVisible(false);
            torchicP.setVisible(false);
            chincharP.setVisible(false);
            frokieP.setVisible(false);
            littenP.setVisible(false);
        }
        if(e.getSource() == mudkipB){
            pikachuP.setVisible(false);
            eeveeP.setVisible(false);
            poplioP.setVisible(false);
            mudkipP.setVisible(true);
            snivyP.setVisible(false);
            totodileP.setVisible(false);
            torchicP.setVisible(false);
            chincharP.setVisible(false);
            frokieP.setVisible(false);
            littenP.setVisible(false);
        }
        if(e.getSource() == snivyB){
            pikachuP.setVisible(false);
            eeveeP.setVisible(false);
            poplioP.setVisible(false);
            mudkipP.setVisible(false);
            snivyP.setVisible(true);
            totodileP.setVisible(false);
            torchicP.setVisible(false);
            chincharP.setVisible(false);
            frokieP.setVisible(false);
            littenP.setVisible(false);
        }
        if(e.getSource() == totodileB){
            pikachuP.setVisible(false);
            eeveeP.setVisible(false);
            poplioP.setVisible(false);
            mudkipP.setVisible(false);
            snivyP.setVisible(false);
            totodileP.setVisible(true);
            torchicP.setVisible(false);
            chincharP.setVisible(false);
            frokieP.setVisible(false);
            littenP.setVisible(false);
        }
        if(e.getSource() == torchicB){
            pikachuP.setVisible(false);
            eeveeP.setVisible(false);
            poplioP.setVisible(false);
            mudkipP.setVisible(false);
            snivyP.setVisible(false);
            totodileP.setVisible(false);
            torchicP.setVisible(true);
            chincharP.setVisible(false);
            frokieP.setVisible(false);
            littenP.setVisible(false);
        }
        if(e.getSource() == chincharB ){
            pikachuP.setVisible(false);
            eeveeP.setVisible(false);
            poplioP.setVisible(false);
            mudkipP.setVisible(false);
            snivyP.setVisible(false);
            totodileP.setVisible(false);
            torchicP.setVisible(false);
            chincharP.setVisible(true);
            frokieP.setVisible(false);
            littenP.setVisible(false);
        }
        if(e.getSource() == frokieB){
            pikachuP.setVisible(false);
            eeveeP.setVisible(false);
            poplioP.setVisible(false);
            mudkipP.setVisible(false);
            snivyP.setVisible(false);
            totodileP.setVisible(false);
            torchicP.setVisible(false);
            chincharP.setVisible(false);
            frokieP.setVisible(true);
            littenP.setVisible(false);
        }
        if(e.getSource() == littenB){
            pikachuP.setVisible(false);
            eeveeP.setVisible(false);
            poplioP.setVisible(false);
            mudkipP.setVisible(false);
            snivyP.setVisible(false);
            totodileP.setVisible(false);
            torchicP.setVisible(false);
            chincharP.setVisible(false);
            frokieP.setVisible(false);
            littenP.setVisible(true);
        }
    }
}
