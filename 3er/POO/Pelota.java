import java.awt.*;
import java.applet.Applet;

public class Pelota extends Applet {

	private int x = 7, xCambio = 7;
	private int y = 2, yCambio = 2;
	private int diametro = 10;

	private int rectIzqX = 0, rectDerX = 100;
	private int rectSupY = 0, rectInfY = 100;

	public void paint(Graphics g) {

		for (int n = 1; n < 1000; n++) {
			g.setColor(Color.black);
			g.drawRect(rectIzqX, rectSupY, rectDerX - rectIzqX+15, rectInfY - rectSupY+10);
			
			for (int jj=0;jj<1000000;jj++) { }
			
			Color colorDeFondo = getBackground();
			g.setColor(colorDeFondo);
			g.fillOval(x, y, diametro, diametro);
			
			if (x <= rectIzqX)
				xCambio = -xCambio;
			if (x >= rectDerX)
				xCambio = -xCambio;
			
			if (y <= rectSupY)
				yCambio = -yCambio;
			if (y >= rectInfY)
				yCambio = -yCambio;

			x = x + xCambio;
			y = y + yCambio;

			g.setColor(Color.red);
			g.fillOval(x, y, diametro, diametro);
		}
	}
}
