//  Ejemplo de barra de desplazamiento - pulgadas a centímetros
import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class PulgACm extends Applet
	implements AdjustmentListener {
	private Scrollbar barraDeslizable;
	private float barraDeslizableValor;
	public void init () {
		barraDeslizable = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
		add(barraDeslizable);
		barraDeslizable.addAdjustmentListener(this);
	}
	
public void paint (Graphics g) {
	float cmEquivalente;
cmEquivalente = barraDeslizableValor*2.54f;
g.drawString("Pulgadas="+barraDeslizableValor+" Cm="+cmEquivalente, 100, 100);
	}

	public void adjustmentValueChanged(AdjustmentEvent e) {
		barraDeslizableValor = (float) barraDeslizable.getValue()/10;
		repaint();
	}
}
