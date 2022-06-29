import java.awt.*;
import java.applet.Applet;
public class ReturnDemo extends Applet {
	public void paint(Graphics g) {
		int respuesta = areaRectangulo(30, 40);
		g.drawString("el área del rectángulo es "+respuesta, 100, 100);
	}
	private int areaRectangulo(int lado1, int lado2) {
		int area = lado1 * lado2;
		return area;
	}
}
