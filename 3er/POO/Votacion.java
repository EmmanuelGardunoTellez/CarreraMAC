import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class Votacion extends Applet implements AdjustmentListener {

	private Scrollbar barra;
	private int edad = 0;

	public void init() {
		barra = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
		add(barra);
		barra.addAdjustmentListener(this);
	}

	public void paint(Graphics g) {
		if (edad > 17)
			g.drawString ("Puede votar", 50, 50);
		g.drawString("La edad es " + edad, 50, 70);
	}
	public void adjustmentValueChanged(AdjustmentEvent event) {
	edad = barra.getValue();
	repaint();
	}
}


