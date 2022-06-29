import java.awt.*;
import java.applet.Applet;

public class Arroz1 extends Applet {
	
	public void paint(Graphics g) {
		int contadorDeCuadros = 1;
		int arrozEnEsteCuadro = 1;
		int totalArroz = 1;
		while (totalArroz < 10000 && contadorDeCuadros <= 64) {
			contadorDeCuadros++;
			arrozEnEsteCuadro = arrozEnEsteCuadro * 2;
			totalArroz = totalArroz + arrozEnEsteCuadro;
		}
		g.drawString("el número de cuadros es " + contadorDeCuadros, 100, 100);
		g.drawString("el número de granos es " + totalArroz, 100, 120);
	}
}
