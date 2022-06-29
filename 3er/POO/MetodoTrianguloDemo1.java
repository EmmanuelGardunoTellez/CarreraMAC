import java.awt.*;
import java.applet.Applet;
public class MetodoTrianguloDemo1 extends Applet {
	public void paint(Graphics g) {
		dibujarTriangulo(g,80,200,100,110);
		dibujarTriangulo(g,125,220,60,70);
	}
	private void dibujarTriangulo(Graphics g, int inferiorX, int inferiorY, int base, int altura) {
		int derechaX = inferiorX+base;
		int superiorX = inferiorX+base/2;
		int superiorY = inferiorY-altura;

		g.drawLine(inferiorX,inferiorY,derechaX,inferiorY);
		g.drawLine(derechaX,inferiorY,superiorX,superiorY);
		g.drawLine(superiorX,superiorY,inferiorX,inferiorY);
	}
}
