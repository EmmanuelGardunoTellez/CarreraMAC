import java.awt.*;
import java.applet.Applet;
public class ReturnDemo1 extends Applet {
	public void paint(Graphics g) {
		g.drawString("el área del rectángulo es "+areaRectangulo(30,40), 100, 100);
	}
	private int areaRectangulo(int lado1, int lado2) {
		return lado1*lado2;
	}
}
