import java.awt.*;
import java.applet.Applet;

public class ProbarTriangulo extends Applet {
  	public void paint(Graphics g) {
		int inferiorX = 80;
		int inferiorY = 200;
		int base = 100;
		int altura = 110;

	g.drawLine(inferiorX, inferiorY, inferiorX+base, inferiorY);
		g.drawLine(inferiorX+base, inferiorY, inferiorX+base/2, inferiorY-altura);
		g.drawLine(inferiorX+base/2, inferiorY-altura, inferiorX, inferiorY);
	}
}
