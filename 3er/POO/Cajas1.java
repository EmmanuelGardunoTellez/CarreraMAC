	import java.awt.*;
	import java.applet.Applet;

	public class Cajas1 extends Applet{
	
		public void paint(Graphics g) {
			int x = 20;
			int y = 20;
			int anchura = 10;
			int altura  = 10;
			for (int contador = 1; contador <= 5; contador++) {
				g.drawRect(x, y, anchura, altura);
				y = y + 15;
			}
		}
	}

