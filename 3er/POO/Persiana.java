//  Ejemplo de barra de desplazamiento - simulador de persiana
import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class Persiana extends Applet
	implements AdjustmentListener {
	private Scrollbar barraDeslizable;
	private int barraDeslizableValor;

	public void init () {
		barraDeslizable = new Scrollbar(Scrollbar.VERTICAL, 0, 1, 0, 100);
		add(barraDeslizable);
		barraDeslizable.addAdjustmentListener(this);
	}
	
public void paint (Graphics g) {
	showStatus("El valor de la barra de desplazamiento es " + barraDeslizableValor);
	g.drawRect(40, 80, 60, 100);
	g.fillRect(40, 80, 60, barraDeslizableValor);
	}

	public void adjustmentValueChanged(AdjustmentEvent e) {
		barraDeslizableValor = barraDeslizable.getValue();
		repaint();
	}
}
