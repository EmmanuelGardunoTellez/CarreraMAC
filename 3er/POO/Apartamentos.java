import java.awt.*;
	import java.applet.Applet;

	public class Apartamentos extends Applet {

		public void paint(Graphics g) {
			int planos = 5;
			int pisos = 5;
			int yCoord = 10;
			for (int piso = 0; piso < pisos; piso++) {
				int xCoord = 10;
				for (int plano = 0; plano < planos; plano++) {
					g.drawString(xCoord, yCoord, 20, 20);
					xCoord = xCoord + 20;
				}
				yCoord = yCoord + 20;
			}
		}
	}

