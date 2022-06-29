var canva=document.getElementById("canva_animated");
    var ctx=canva.getContext("2d");
    canva.width=window.innerWidth;
    canva.height=window.innerHeight;
    var x=40;
    var y=40;
    var z=40;
    var w=40;
    var a=150;
    var b=150;
    var c=150;
    var d=150;
    var radius=35;
    var spx=7; 
    var spy=7;
    var spz=5;
    var spw=7;
    var spa=3; 
    var spb=5;
    var spc=3;
    var spd=3;
    var col1=1;
    var col2=2;
    var colours=["#3282B8","#1ed5f6","#f61ed5","#d5f61e","#E5B299","#053742"];
    
    function animation(){
        requestAnimationFrame(animation);
        ctx.clearRect(0,0,innerWidth,innerHeight);
        ctx.beginPath();
        ctx.arc(x,y,radius,0,2*Math.PI);
        ctx.fillStyle=colours[col2];
        ctx.fill();
        ctx.beginPath();
        ctx.arc(a,b,radius,0,2*Math.PI);
        ctx.fillStyle=colours[col2];
        ctx.fill();
        
         ctx.arc(z,w,radius,0,2*Math.PI);
        ctx.fillStyle=colours[col1];
        ctx.fill();
        ctx.beginPath();
        ctx.arc(c,d,radius,0,2*Math.PI);
        ctx.fillStyle=colours[col2];
        ctx.fill();
        
            if(x+radius>innerWidth || x-radius<0){
                col1=Math.floor(Math.random()*6);
                spx=-spx;

            }
            if(y+radius>innerHeight || y-radius<0){
                col1=Math.floor(Math.random()*6);
                spy=-spy;
            }
            if(a+radius>innerWidth || a-radius<0){
                col2=Math.floor(Math.random()*6);
                spa=-spa;
            }
            if(b+radius>innerHeight || b-radius<0){
                col2=Math.floor(Math.random()*6);
                spb=-spb;     
            }
          
        if(z+radius>innerWidth || z-radius<0){
                col1=Math.floor(Math.random()*6);
                spz=-spz;
            }
            if(w+radius>innerHeight || w-radius<0){
                col1=Math.floor(Math.random()*6);
                spw=-spw;
            }
          
        if(c+radius>innerWidth || c-radius<0){
                col1=Math.floor(Math.random()*6);
                spc=-spc;
            }
            if(d+radius>innerHeight || d-radius<0){
                col1=Math.floor(Math.random()*6);
                spd=-spd;                
            }           
        x+=spx;
        y+=spy;
        z+=spz;
        w+=spw;
        a+=spa;
        b+=spb;
        c+=spc;        
}
animation();