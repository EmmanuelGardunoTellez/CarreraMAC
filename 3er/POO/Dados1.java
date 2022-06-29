import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class Dados1 extends Applet implements AdjustmentListener {
	private Scrollbar dado1, dado2;
	private int valor1 = 1, valor2 = 1;

	public void init() {
		dado1 = new Scrollbar(Scrollbar.HORIZONTAL, 1, 1, 1, 6);
		add(dado1);
		dado1.addAdjustmentListener(this);
		dado2 = new Scrollbar(Scrollbar.HORIZONTAL, 1, 1, 1, 6);
		add(dado2);
		dado2.addAdjustmentListener(this);
}

	public void paint(Graphics g) {
		int total;
		total = valor1 + valor2;
		g.drawString("el total es "+total, 50, 50);
		if (total == 6)
			g.drawString("¡ha ganado!", 50, 60);
	}

	public void adjustmentValueChanged(AdjustmentEvent event) {
		valor1 = dado1.getValue();
		valor2 = dado2.getValue();
		repaint();
	}
}
