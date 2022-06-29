	import java.awt.*;
	import java.applet.Applet;
	import java.awt.event.*;

	public class LineasVariables extends Applet implements AdjustmentListener {
		private Scrollbar lineas;
		private int numeroDeLineas;

		public void init() {
			lineas = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
			add(lineas);
			lineas.addAdjustmentListener(this);
		}
		
		public void paint(Graphics g) {
			int contador = 1;
			int x = 20;
			int y = 20;
			while (contador < numeroDeLineas) {
				g.drawLine(x, y, x + 100, y);
				y = y + 10;
				contador++;
			}
		}
		
		public void adjustmentValueChanged(AdjustmentEvent event) {
			numeroDeLineas = lineas.getValue();
			repaint();
		}

	}
