import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class BotonesContar extends Applet implements ActionListener {
	private Button evaluador;
	private int cuenta = 0;

	public void init() {
		evaluador = new Button("Oprima aquí");
		add(evaluador);
		evaluador.addActionListener(this);
	}

	public void actionPerformed(ActionEvent event) {
		cuenta++;
		repaint();
	}

	public void paint(Graphics g) {
		g.drawString("El número de botones oprimidos es " + cuenta, 10, 50);
	}
}
