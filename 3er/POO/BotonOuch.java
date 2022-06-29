 import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class BotonOuch extends Applet implements ActionListener {

	private Button evaluador;
	private boolean oprimidoYa = false;

	public void init() {
		evaluador = new Button("Oprima aquí");
		add(evaluador);
		evaluador.addActionListener(this);
	}

	public void paint(Graphics g) {
		if (oprimidoYa)
			g.drawString("OUCH", 100, 50);
	}

	public void actionPerformed(ActionEvent event) {
		oprimidoYa = true;
		repaint();
	}
}
