import java.awt.*;
	import java.applet.Applet;

	public class LineasAleatorias extends Applet {

		public void paint(Graphics g) {
			int n = 1;
			int x, xFin;
			int y, yFin;
			while (n <= 10) {
				x = (int)(Math.random() * 100) + 10;
				y = (int)(Math.random() * 100) + 10;
				xFin = (int)(Math.random() * 100) + 10;
				yFin = (int)(Math.random() * 100) + 10;

				g.drawLine (x, y, xFin, yFin);
				n++;
			}
		}
	}

