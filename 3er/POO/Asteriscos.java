import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class Asteriscos extends Applet implements AdjustmentListener {
    private Scrollbar barra;
    private int numeroRequerido = 8;

    public void init() {
        barra = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
        add(barra);
        barra.addAdjustmentListener(this);
    }
    public void adjustmentValueChanged(AdjustmentEvent event) { 
        numeroRequerido = barra.getValue();
        repaint();
    }

    public void paint(Graphics g) {
        int contador;
        int x = 10;
        for (contador = 0; contador < numeroRequerido; contador++) {
            g.drawString ("*", x, 30);
            x = x + 10;
        }
    }
}
