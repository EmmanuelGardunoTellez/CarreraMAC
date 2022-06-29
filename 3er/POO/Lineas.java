import java.awt.*;
import java.applet.Applet;

public class Lineas extends Applet {

	public void paint(Graphics g) {
		int n = 0;
		int x = 20;
		int y = 20;
		while (n < 5) {
			g.drawLine(x, y, x + 100, y);
			y = y + 10;
			n++;
		}
	}
}
