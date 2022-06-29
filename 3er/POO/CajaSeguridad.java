import java.applet.*;
import java.awt.*;
import java.awt.event.*;
public class CajaSeguridad extends Applet 
    implements ActionListener {

    private int adivinar = 0;
    private int combinacion = 321;
    private Button uno, dos, tres, denuevo;

    public void init() {
        uno = new Button("1");
        add (uno);
        uno.addActionListener(this);
        dos = new Button("2");
        add (dos);
        dos.addActionListener(this);
        tres = new Button ("3");
        add (tres);
        tres.addActionListener(this);
        denuevo = new Button("Intente de nuevo");
        add(denuevo);
        denuevo.addActionListener(this);
    }

    public void paint(Graphics g) {
        if (adivinar == combinacion)
            g.drawString ("Abierta", 50,50);
        else
            g.drawString ("Cerrada", 50,50);
    }

    public void actionPerformed(ActionEvent event) {
        if (event.getSource() == uno)
            adivinar = adivinar*10 + 1;
        if (event.getSource() == dos)
            adivinar = adivinar*10 + 2;
        if (event.getSource() == tres)
            adivinar = adivinar*10 + 3;
        if (event.getSource() == denuevo)
            adivinar=0;

        repaint();
    }
}
