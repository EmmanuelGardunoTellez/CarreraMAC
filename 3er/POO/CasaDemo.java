import java.awt.*;
import java.applet.Applet;
public class CasaDemo extends Applet {
	public void paint(Graphics g) {
		dibujarCasa(g,50,50,70,30);
		dibujarCasa(g,100,50,60,20);
	}

	private void dibujarTriangulo(Graphics g, int inferiorX, int inferiorY, int base, int altura) {
		g.drawLine(inferiorX, inferiorY, inferiorX+base, inferiorY);
		g.drawLine(inferiorX+base, inferiorY, inferiorX+base/2, inferiorY-altura);
		g.drawLine(inferiorX+base/2, inferiorY-altura, inferiorX, inferiorY);
}

	private void dibujarCasa(Graphics g, int inferiorX, int inferiorY, int anchura, int altura) {
		g.drawRect(inferiorX, inferiorY-altura, anchura, altura);
		dibujarTriangulo(g, inferiorX, inferiorY-altura, anchura, altura/2);
	}
}
