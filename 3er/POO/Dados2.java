import java.awt.*;
import java.applet.Applet;
import java.awt.event.*;

public class Dados2 extends Applet implements ActionListener {

	private Button tirarDados;
	private boolean tirados = false;

	public void init() {
		tirarDados = new Button("Tirar");
		add(tirarDados);
		tirarDados.addActionListener(this);
	}

	public void actionPerformed(ActionEvent event) {
		tirados = true;
		repaint();
	}

	public void paint(Graphics g) {
		int dado1, dado2;
		if (tirados) {
			dado1 = (int)(Math.random() * 6) + 1;
			dado2 = (int)(Math.random() * 6) + 1;
			g.drawString("Los dados son " + dado1 + " y " + dado2, 20, 40);
			if (dado1 == dado2)
				g.drawString("ha ganado", 20, 60);
			else
				g.drawString("lo siento", 20, 60);
		}
	}
}
