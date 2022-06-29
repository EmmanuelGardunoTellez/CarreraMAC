publc void  Eventos extends Applet implements adjusmentListener{
private Scrollbar barraDeslizable;
private Scrollbar barrita;
private int barra1;
private int barra2;
float celcius;
float fare;
Label  cel,fa;
public void init()
{
 barraDeslizable=new Scrollbar(Scrollbar.HORIZONTAL,1,0,1,100);
 barrita=new Scrollbar(Scrollbar.VERTICAL,0,1,0,100);
 add(barraDeslizable);
  add(barrita);
 barraDeslizable.addAddjustmentListener(this);
 barrita.addAddjustmentListener(this);
 cel=new label("centigrados"); 
 fa=new label("farenheit");
 add(cel);
 add(fa);
 }
 public void paint(Graphics g)
 {
  g.drawString("farenheit=  "+barra1);
  celcius=(barra1+32)/(9/5);
  g.drawString("celcius=  "celcius);
 }
 public void adjusmentValueChanged(adjusmentEvent e,Graphics g)
 {
 barra1=barraDeslizable.getValue();
 barra2=barrita.getValue();
 }
 }