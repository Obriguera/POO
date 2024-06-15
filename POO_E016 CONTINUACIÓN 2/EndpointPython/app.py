from fastapi import FastAPI, HTTPException
from pymongo import MongoClient
from pydantic import BaseModel

app = FastAPI()

# Conexión a la base de datos MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['POO_E16']
collection = db['Primero']

# Modelo de datos para la solicitud de validación
class User(BaseModel):
    usuario: str
    clave: str

# Registrar usuarios en MongoDB
def registrar_usuario(nombre, apellido, usuario, clave):
    nuevo_usuario = {
        "nombre": nombre,
        "apellido": apellido,
        "usuario": usuario,
        "clave": clave
    }
    collection.insert_one(nuevo_usuario)

# Validar usuarios en MongoDB
def validar_usuario(usuario, clave):
    usuario_validado = collection.find_one({"usuario": usuario, "clave": clave})
    if usuario_validado:
        return f"{usuario_validado['nombre']}::{usuario_validado['apellido']}"
    else:
        return "denegado"

# Endpoint para validar usuarios
@app.post("/validar_usuario/")
def validar_usuario_endpoint(user: User):
    resultado_validacion = validar_usuario(user.usuario, user.clave)
    if resultado_validacion != "denegado":
        return {"mensaje": "Acceso concedido", "usuario": resultado_validacion}
    else:
        raise HTTPException(status_code=401, detail="Acceso denegado")

# Ejemplo de registro de usuarios
registrar_usuario("Juan", "Carlos", "juancarlos", "clave123")

# Ejecutar la aplicación con Uvicorn
if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)
