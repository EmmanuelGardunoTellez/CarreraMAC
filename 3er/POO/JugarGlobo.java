import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class JugarGlobo extends Applet 
    implements ActionListener {
    private Button agrandar, reducir;
    private Globo miGlobo;

    public void init() {
        agrandar = new Button ("Agrandar");
        add (agrandar);
        agrandar.addActionListener(this);
    
        reducir = new Button ("Reducir");
        add (reducir);
        reducir.addActionListener(this);
    
        miGlobo = new Globo (20, 50, 50);
    }

    public void actionPerformed(ActionEvent event) {
        if (event.getSource() == agrandar)
            miGlobo.cambiarTamaño(10);
        if (event.getSource() == reducir)
            miGlobo.cambiarTamaño(-10);
        repaint();
    }

    public void paint (Graphics g) {
        miGlobo.mostrar(g);
    }
}

class Globo{
    private int diametro;
    private int xCoord, yCoord;

    public Globo (int diametroInicial, int xInicial, int yInicial) {
        diametro = diametroInicial;
        xCoord = xInicial;
        yCoord = yInicial;
    }

    public void cambiarTamaño (int cambio) {
        diametro = diametro + cambio;
    }

    public void mostrar (Graphics g) {
        g.drawOval (xCoord, yCoord, diametro, diametro);
    }
}
