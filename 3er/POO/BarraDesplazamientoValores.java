import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class BarraDesplazamientoValores extends Applet
	implements AdjustmentListener {
	private Scrollbar barraDeslizable;
	private int xActual = 0;
	private int yActual = 5;

	public void init () {
		barraDeslizable = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
		add(barraDeslizable);
		barraDeslizable.addAdjustmentListener(this);
	}
	
public void adjustmentValueChanged (AdjustmentEvent e) {
	Graphics g = getGraphics();
	xActual = barraDeslizable.getValue();
	g.drawLine(0, yActual, xActual, yActual);
	yActual = yActual+5;
	}
}
