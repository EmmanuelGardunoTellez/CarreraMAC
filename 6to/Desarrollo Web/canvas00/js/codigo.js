let can = document.getElementById("canvas1")
let con = can.getContext("2d")

let x=25;

let y=20
let incx = 5
let incy = 5
let buenas= 0
let malas=0
let mousex=400

function rebotapelota() {
  con.clearRect(0,0,800,400)
  
  con.fillStyle="darkgoldenrod"
  con.fillRect(0,0,800,400)

  con.fillStyle="blue"
  con.beginPath()

  con.arc(x, y, 20, 0, 2*Math.PI)

  con.fill()
  con.stroke()
    x+=incx
    y+=incy
    if(x>=780 || x<=10)
        incx=-incx
     
    if(y>=380 || y<=10)       
        incy=-incy
    
    con.canvas.addEventListener("mousemove",function(el){
        mousex=el.clientX
        })
    if(mousex!=null){
      con.fillStyle="red";
      con.fillRect(mousex-50,385,100,15)
    }
    if(y>=380){
       if(mousex<=x-50 || mousex>=x+50){
          buenas++
           document.getElementById("b").innerHTML="Malas: "+buenas
       }
        else{
            malas++
            document.getElementById("m").innerHTML="Buenas: "+malas
        } 
            
    }
  var ciclo=setTimeout(rebotapelota,20)
}
rebotapelota()