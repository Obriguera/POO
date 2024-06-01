<<<<<<< HEAD
from fastapi import FastAPI, HTTPException
from pymongo import MongoClient

app = FastAPI()

# Conexión a la base de datos MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['POO_E16']
collection = db['Primero']

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
        return usuario_validado
    else:
        raise HTTPException(status_code=401, detail="Acceso denegado")

# Endpoint para validar usuarios
@app.post("/validar_usuario/")
def validar_usuario_endpoint(usuario: str, clave: str):
    try:
        usuario_validado = validar_usuario(usuario, clave)
        return {"mensaje": "Acceso concedido", "usuario": usuario_validado}
    except HTTPException as e:
        return {"error": str(e)}

# Ejemplo de registro de usuarios
registrar_usuario("Juan", "Carlos", "juancarlos", "clave123")

# Ejecutar la aplicación con Uvicorn
if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)
=======
from fastapi import FastAPI, HTTPException
from pymongo import MongoClient

app = FastAPI()

# Conexión a la base de datos MongoDB
client = MongoClient('mongodb://localhost:27017/')
db = client['POO_E16']
collection = db['Primero']

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
        return usuario_validado
    else:
        raise HTTPException(status_code=401, detail="Acceso denegado")

# Endpoint para validar usuarios
@app.post("/validar_usuario/")
def validar_usuario_endpoint(usuario: str, clave: str):
    try:
        usuario_validado = validar_usuario(usuario, clave)
        return {"mensaje": "Acceso concedido", "usuario": usuario_validado}
    except HTTPException as e:
        return {"error": str(e)}

# Ejemplo de registro de usuarios
registrar_usuario("Juan", "Carlos", "juancarlos", "clave123")

# Ejecutar la aplicación con Uvicorn
if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="127.0.0.1", port=8000)
>>>>>>> c0a71fc (01 06 24 update)
