import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class TomYJerry extends Applet implements AdjustmentListener {

	private Scrollbar tom, jerry;
	private int tomValor = 0, jerryValor = 0;

	public void init() {
		Label toms = new Label("Tom:");
		add(toms);
		tom = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
		add(tom);
		tom.addAdjustmentListener(this);

		Label jerrys = new Label("Jerry:");
		add(jerrys);
		jerry = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
		add(jerry);
		jerry.addAdjustmentListener(this);
	}

	public void paint(Graphics g) {
		g.drawString("Tom", 5, 70);
		g.fillRect(40, 60, tomValor, 10);
		g.drawString("Jerry", 5, 85);
		g.fillRect(40, 75, jerryValor, 10);
		if (tomValor > jerryValor)
			g.drawString("Tom es mayor", 50, 50);
		else
			g.drawString("Jerry es mayor", 50, 50);
	}

	public void adjustmentValueChanged(AdjustmentEvent event) {
		tomValor = tom.getValue();
		jerryValor = jerry.getValue();
		repaint();
	}
}
