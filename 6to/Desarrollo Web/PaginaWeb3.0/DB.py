import sqlite3

con = sqlite3.connect("usuarios.db")
print("Base creada")

con.execute("create table Usuarios (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT UNIQUE NOT NULL, password TEXT NOT NULL, lr INTEGER)")
print("tabla creada")

con.close()
