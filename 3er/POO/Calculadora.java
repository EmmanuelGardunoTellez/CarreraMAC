import java.applet.*;
import java.awt.*;
import java.awt.event.*;


// no es una calculadora con todas sus funciones, pero 
// sirve para el ejercicio del libro.

public class Calculadora extends Applet implements ActionListener {
	private Button borrar, suma, resta, total, cero, uno, dos;
	private Button tres, cuatro, cinco, seis, siete, ocho, nueve;
	private Label etiqueta, pantalla;
	private int totalOculto;
	private String resultado;

	public void init() {
		resultado = "0";
		totalOculto = 0;
		borrar = new Button("Borrar");
		add(borrar);
		borrar.addActionListener(this);

		suma = new Button("+");
		add(suma);
		suma.addActionListener(this);

		resta = new Button("-");
		add(resta);
		resta.addActionListener(this);

		total = new Button("=");
		add(total);
		total.addActionListener(this);

		etiqueta = new Label("------------------------------");
		add(etiqueta);

		cero = new Button("0");
		add(cero);
		cero.addActionListener(this);

		uno = new Button("1");
		add(uno);
		uno.addActionListener(this);

		dos = new Button("2");
		add(dos);
		dos.addActionListener(this);

		tres = new Button("3");
		add(tres);
		tres.addActionListener(this);

		cuatro = new Button("4");
		add(cuatro);
		cuatro.addActionListener(this);

		cinco = new Button("5");
		add(cinco);
		cinco.addActionListener(this);

		seis = new Button("6");
		add(seis);
		seis.addActionListener(this);

		siete = new Button("7");
		add(siete);
		siete.addActionListener(this);

		ocho = new Button("8");
		add(ocho);
		ocho.addActionListener(this);

		nueve = new Button("9");
		add(nueve);
		nueve.addActionListener(this);

		pantalla = new Label("0");
		add(pantalla);
	}

	public void actionPerformed(ActionEvent event) {
		if (event.getSource() == borrar) {
			totalOculto = 0;
			resultado = "0";
		}
		if (event.getSource() == uno)
			resultado = Integer.toString(Integer.parseInt(resultado + "1"));
		if (event.getSource() == dos)
			resultado = Integer.toString(Integer.parseInt(resultado + "2"));
		if (event.getSource() == tres)
			resultado = Integer.toString(Integer.parseInt(resultado + "3"));
		if (event.getSource() == cuatro)
			resultado = Integer.toString(Integer.parseInt(resultado + "4"));
		if (event.getSource() == cinco)
			resultado = Integer.toString(Integer.parseInt(resultado + "5"));
		if (event.getSource() == seis)
			resultado = Integer.toString(Integer.parseInt(resultado + "6"));
		if (event.getSource() == siete)
			resultado = Integer.toString(Integer.parseInt(resultado + "7"));
		if (event.getSource() == ocho)
			resultado = Integer.toString(Integer.parseInt(resultado + "8"));
		if (event.getSource() == nueve)
			resultado = Integer.toString(Integer.parseInt(resultado + "9"));

		if (event.getSource() == suma) {
			totalOculto = totalOculto + Integer.parseInt(resultado);
			resultado = "0";
		}
		if (event.getSource() == resta) {
			totalOculto = totalOculto - Integer.parseInt(resultado);
			resultado = "0";
		}
		if (event.getSource() == total) 
			resultado = Integer.toString(totalOculto);

		 pantalla.setText(resultado);
		repaint();
	}

	public void paint(Graphics g) {
		g.drawString(resultado, 50, 200);
	}
}
