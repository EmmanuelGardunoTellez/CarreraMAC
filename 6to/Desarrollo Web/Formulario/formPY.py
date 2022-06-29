from flask import *
import sqlite3

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/agregar")
def agregar():
    return render_template("agregar.html")

@app.route("/guardar", methods = ["POST","GET"])
def saveDatails():
    msg = "msg"
    if request.method == "POST":
        try:
            tit = request.form["titulo"]
            ani = request.form["anio"]
            with sqlite3.connect("beatles.db") as con:
                cur = con.cursor()