import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class Escalones extends Applet
    implements AdjustmentListener {

    private Scrollbar escalones;
    private int contador, numeroDeEscalones;

    public void init() {
        escalones = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
        add(escalones);
        escalones.addAdjustmentListener( this);
    }

    public void paint(Graphics g) {
        int contador = 0;

        int x = 20;
        int y = 20;
        while (contador < numeroDeEscalones) {
            g.drawLine (x, y, x + 20, y);
            g.drawLine (x + 20, y, x + 20, y + 20);

            x = x + 20;
            y = y + 20;
            contador++;
        }
    }

    public void adjustmentValueChanged(AdjustmentEvent e) {
        numeroDeEscalones = escalones.getValue();
        repaint();
    }
}
