from flask import Flask, render_template
import sqlite3

from flask.wrappers import Request
from werkzeug.wrappers import request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/loging")
def loging():
    return render_template("loging.html")

@app.route("/borrar")
def borrar():
    return render_template("borrar.html")

@app.route("/nintendo")
def nintendo():
    return render_template("nintendo.html")

@app.route("/xbox")
def xbox():
    return render_template("xbox.html")

@app.route("/play")
def play():
    return render_template("play.html")

@app.route("/pc")
def pc():
    return render_template("pc.html")

@app.route("/moviles")
def moviles():
    return render_template("moviles.html")

@app.route("/anime")
def anime():
    return render_template("anime.html")

@app.route("/lr")
def lr():
    con = sqlite3.connect("usuarios.db")
    con.row_factory = sqlite3.Row
    cur = con.cursor()
    cur.execute("select * from Usuarios order by lr")
    rows = cur.fetchall()
    return render_template("lr.html", filas=rows)

@app.route("/guardar", methods = ['POST'])
def guardar():
    msg="."
    con = sqlite3.connect("usuarios.db")
#    if request.methods == 'POST':
    try:
        nick = request.form['Apodo']
        contr = request.form['Contrasena']
        ir = 1 
        cur = con.cursor()
    
        cur.execute("INSERT into Usuarios (name, password, lr) values (?,?,?)",(nick,contr,ir) )
        con.commit()
        print('agregadodo')
        msg = "Record successfully added"
    except:
        con.rollback()
        print('no agregado')
        msg = "error in insert operation"
    finally:
        con.close()
        return render_template("guardar.html")
            
