import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class PrimerEvento extends Applet
	implements AdjustmentListener {
	private Scrollbar barraDeslizable;
	private int barraDeslizableValor = 0;
	
	public void init() {
		barraDeslizable = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
		add(barraDeslizable);
		barraDeslizable.addAdjustmentListener(this);
	}

	public void paint(Graphics g) {
		g.drawString("El valor actual es " + barraDeslizableValor, 100, 100);
	}

	public void adjustmentValueChanged(AdjustmentEvent e) {
		barraDeslizableValor = barraDeslizable.getValue();
		repaint();
	}
}
