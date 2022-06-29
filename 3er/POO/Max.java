import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class Max extends Applet implements AdjustmentListener {
	private Scrollbar controlVolumen;
	private int max = 0;
	private int volumen = 0;

	public void init() {
		controlVolumen = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
		add(controlVolumen);
		controlVolumen.addAdjustmentListener(this);
	}

	public void paint(Graphics g) {
		if (volumen > max)
			max = volumen;
		g.drawString("El valor máximo es " + max, 50, 50);
	}

	public void adjustmentValueChanged(AdjustmentEvent event) {
		volumen = controlVolumen.getValue();
		repaint();
	}
}
