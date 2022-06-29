import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class VerificarEdad extends Applet
    implements ActionListener {

    private TextField edadCampo;
    private int edad;

    public void init() {
        edadCampo=new TextField(10);
        add(edadCampo);
        edadCampo.addActionListener(this);
    }

    public void actionPerformed(ActionEvent event) {
        edad=Integer.parseInt(edadCampo.getText());
        repaint();
    }

    public void paint (Graphics g) {
        g.drawString("La edad es " + edad, 50, 50);
        if (edad >= 18)
            g.drawString("Puede votar", 50, 100);
        else
            g.drawString("No puede votar", 50,100);
    }
}
