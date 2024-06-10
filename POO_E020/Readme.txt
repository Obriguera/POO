Ejercicio 20:
    -Crear un proyecto Qt Widget Application con un QWidget que sea la clase Ventana
    -Crear una clase Boton que hereda de QWidget
    -Redefinir paintEvent en Boton y usar fillRect para dibujarlo de algún color
    -Definir el siguiente método en Boton:

Boton * boton = new Boton;
boton->colorear( Boton::Azul );

// Este método recibe como parámetro una enumeración que puede ser:
// Boton::Azul  Boton::Verde  Boton::Magenta

    -Usar QtDesigner para Ventana y Boton. Es decir, Designer Form Class
    -Definir la enumeración en Boton
    -Abrir el designer de Ventana y agregar 5 botones (objetos de la clase Boton). Promocionarlos
    -Que esta Ventana con botones quede lo más parecido a la siguiente imagen:
	
	*Imagen en el repositorio de https://github.com/cosimani/Curso-POO-2024/blob/main/Clase14.rst*
    
	-Usar para Ventana grid layout, usar espaciadores y usar todos los recursos posibles del QtDesigner
    -Dibujar un fondo agradable con paintEvent y drawImage
    -Que Boton tenga la señal signal_clic()