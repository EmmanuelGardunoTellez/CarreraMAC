
import java.awt.*;
import java.applet.Applet;

public class MetodoTrianguloDemo extends Applet {
	public void paint(Graphics g) {
		dibujarTriangulo(g,80,200,100,110);
		dibujarTriangulo(g,125,220,60,70);
	}

private void dibujarTriangulo(Graphics g, int inferiorX, int inferiorY, int base, int altura) {
	g.drawLine(inferiorX, inferiorY, inferiorX+base, inferiorY);
	g.drawLine(inferiorX+base, inferiorY, inferiorX+base/2, inferiorY-altura);
	g.drawLine(inferiorX+base/2, inferiorY-altura, inferiorX, inferiorY);
}
}
