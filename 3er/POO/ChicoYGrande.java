import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;

public class ChicoYGrande extends Applet implements ActionListener {
	private int diametro = 20;
	private Button chico, grande;
	
	public void init() {
		chico = new Button("Chico");
		add(chico);
		chico.addActionListener(this);
		grande = new Button("Grande");
		add(grande);
		grande.addActionListener(this);
	}

	public void paint(Graphics g) {
		g.drawOval(25, 25, diametro, diametro);
	}

	public void actionPerformed(ActionEvent event) {	
		if (event.getSource() == chico)
			diametro = diametro - 10;
		if (event.getSource() == grande)
			diametro = diametro + 10;
		repaint();
	}
}
