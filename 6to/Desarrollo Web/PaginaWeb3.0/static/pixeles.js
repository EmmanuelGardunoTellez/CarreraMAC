var can1;
var ctx1;
function inicio(){
	can1 = document.getElementById("canvas1");
	ctx1 = can1.getContext("2d");
	imagen();
}
function imagen(){
  // Crear objeto imagen y cargar una fotografía
  var foto = new Image();
  foto.scr = "{{url_for('static', filename='images/Yume_no_Tobira.png')}}" 
  // Desplegar la foto
	foto.addEventListener('load', function() {
		drawImage(imagen, dx, dy);
  //  ctx1.drawImage(foto, 0, 0);
  var imagenData = ctx1.getImageData(0, 0, 70, 70); 

		for (var i = 0; i < imagenData.data.length; i += 4) {
      gris=(imagenData.data[i]+imagenData.data[i+1]+imagenData.data[i+2])/3;
      imagenData.data[i]     = gris;  // red
      imagenData.data[i + 1] = gris; // green
      imagenData.data[i + 2] = gris; // blue
      imagenData.data[i+3]=50




    }
    ctx1.putImageData(imagenData, 70, 0);
	//	ctx1.drawImage(imagenData,400,0);
		}, false);

}
	
addEventListener("DOMContentLoaded", inicio, false);