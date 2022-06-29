import java.awt.*;
import java.applet.Applet;

public class Arroz extends Applet {

	public void paint(Graphics g) {
		int contadorDeCuadros = 0;
		int arrozEnEsteCuadro = 1;
		int totalArroz = 0;
		int y = 20;
		do {
			contadorDeCuadros++;
			g.drawString("En el cuadro "+contadorDeCuadros + " hay " + arrozEnEsteCuadro, 10, y);
			totalArroz = totalArroz + arrozEnEsteCuadro;
			arrozEnEsteCuadro = arrozEnEsteCuadro * 2;
			y = y +20;
		} while (totalArroz < 100);

		g.drawString("El número de cuadros necesarios es " + contadorDeCuadros, 10, y + 20);
	}
}
