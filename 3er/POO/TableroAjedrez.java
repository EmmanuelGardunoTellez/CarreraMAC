import java.awt.*;
	import java.applet.Applet;

	public class TableroAjedrez extends Applet {
		public void paint(Graphics g) {
			int x = 20;
			int y = 20;
			int horiz = 1;
			while (horiz <= 9) {
				g.drawLine(x, y, x + 80, y);
				y = y + 10;
				horiz++;
			}

			 x = 20;
			 y = 20;
			int vert = 1;
			while (vert <= 9) {
				g.drawLine (x, y, x, y + 80);
				x = x + 10;
				vert++;
			}
		}
	}

