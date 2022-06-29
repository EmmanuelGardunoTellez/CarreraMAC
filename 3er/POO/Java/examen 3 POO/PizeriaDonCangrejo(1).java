import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class PizeriaDonCangrejo extends Applet
    implements AdjustmentListener {
private Scrollbar barra;
	private int pizzas = 0;
   private int pizzaVal = 150;
   private Repartidor omar;
   private Cocinero sebastian;
   private Cajero arturo;
   double salarioT = 0;
	public void init() {
		barra = new Scrollbar(Scrollbar.HORIZONTAL, 0, 1, 0, 100);
		add(barra);
		barra.addAdjustmentListener(this);
      
      omar = new Repartidor("Omar", 19, 1000, .1); //Propina de las pizas
      arturo = new Cajero("Arturo", 21, 1100.0, .15);
      sebastian = new Cocinero("Sebastian", 17, 1250.0, .2);
	}

	public void paint(Graphics g) {
		g.drawString("Pizzas vendidas " + pizzas, 50, 50);
      g.drawString ("Costo de pizza: " + pizzaVal, 50, 70);
      g.drawString ("Ganancas del dia: " + (pizzas * pizzaVal) , 50, 90);
      g.drawString ("Salarios de los empleados:", 50, 110);
      
      g.drawString ("Nombre: " + omar.getNombre() + "  Edad: "+ omar.getEdad()+ " Trabajo: Repartidor", 50, 130);
      g.drawString ("Salario fijo: " + omar.getSalario() + "   Propina: "+ omar.getPropina(), 50, 150);
      salarioT = omar.getSalario() + (omar.getPropina() * (pizzas * pizzaVal));
      g.drawString ("Salario total: "+ salarioT , 50, 170);
      
      g.drawString ("Nombre: " + arturo.getNombre() + "  Edad: "+ arturo.getEdad() + " Trabajo: Cajero", 50, 200);
      g.drawString ("Salario fijo: " + arturo.getSalario()  + "   Comicion: "+ arturo.getComicion(), 50, 220);
      salarioT = arturo.getSalario() + (arturo.getComicion() * (pizzas * pizzaVal));
      g.drawString ("Salario total: "+ salarioT , 50, 240);
      
      g.drawString ("Nombre: " + sebastian.getNombre() + "  Edad: "+ sebastian.getEdad() + " Trabajo: Cocinero", 50, 270);
      g.drawString ("Salario fijo: " + sebastian.getSalario() + "   Comicion: "+ sebastian.getComicion(), 50, 290);
      salarioT = sebastian.getSalario() + (sebastian.getComicion() * (pizzas * pizzaVal));
      g.drawString ("Salario total: "+ salarioT , 50, 310);
      
      g.drawString ("Nota: las propinas y comisiones se " , 50, 350);
      g.drawString ("basan en la cantidad de pizzas compradas." , 50, 370);
      
	}
	public void adjustmentValueChanged(AdjustmentEvent event) {
	pizzas = barra.getValue();
	repaint();
	}
}
