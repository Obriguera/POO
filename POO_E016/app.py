<<<<<<< HEAD
from fastapi import FastAPI, HTTPException
from pymongo import MongoClient

app = FastAPI()

# Conectar a la base de datos de MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['POO_E16']
usuarios_collection = db['Primero']

@app.get("/validar_usuario")
async def validar_usuario(usuario: str, clave: str):
    usuario_db = usuarios_collection.find_one({"usuario": usuario, "clave": clave})
    if usuario_db:
        return {"mensaje": "Usuario válido"}
    else:
        raise HTTPException(status_code=404, detail="Usuario no encontrado")
=======
from fastapi import FastAPI, HTTPException
from pymongo import MongoClient

app = FastAPI()

# Conectar a la base de datos de MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['POO_E16']
usuarios_collection = db['Primero']

@app.get("/validar_usuario")
async def validar_usuario(usuario: str, clave: str):
    usuario_db = usuarios_collection.find_one({"usuario": usuario, "clave": clave})
    if usuario_db:
        return {"mensaje": "Usuario válido"}
    else:
        raise HTTPException(status_code=404, detail="Usuario no encontrado")
>>>>>>> c0a71fc (01 06 24 update)
