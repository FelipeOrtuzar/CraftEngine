

# Modo de uso del engine.

De momento, el game engine (internamente le llamo gomaengine pero por fuera es CraftEngine (y para la iteración 2 le voy a dejar sólo un nombre)) de momento sólo muestra una pantalla de visualización, y es capaz de cargar Textures con sus sprites de la manera correcta.

Por otro lado, actualmente tiene mezclada un poco la funcionalidad de game engine con el ejemplo en aspectos que no sean las Textures, como los sonidos, la música, el texto y el input.

Por ello, en este documento sólo se ejemplificará el cómo usar las Textures.

# Primero un ejemplo.

```cpp
//Importamos las librerías que iremos a usar
// Aplication es para mostrar una ventana
#include <gomaengine/aplication.h>
// Model es para las entidades que estén presentes en el juego, y actualmente tiene la funcionad de las Texturas "lista"
#include <gomaengine/model.h>
// root directory es para obtener el path relativo
#include <gomaengine/root_directory.h>

// Debemos crear un main
int main() {

    // usamos esto para no escribir gomaengine todo el rato
    namespace ge = gomaengine;
    // Primero ponemos el path de la imagen que usaremos para nuestro modelo
    std::string boo_path = ge::getPath("assets/imgs/CABALLO_1.png").string();
    // Definimos su posicion...
    float boo_pos_x = 200.0; float boo_pos_y = 300.0;
    // El escalamiento de la textura..
    float boo_scale_x = 4; float boo_scale_y = 4;
    // La velocidad con la que el objeto se movera... (no funciona todavia)
    float boo_speed = 20;
    // La direccion a la que el objeto mira (valores de 1 o -1)
    float boo_dir = 1;
    // Aqui se crea el modelo e insertamos los datos usando Vector o Texture segun pida
    ge::Model* boo_model = new ge::Model(
        ge::Vector(boo_pos_x, boo_pos_y),
        ge::Texture(boo_path,
            ge::Vector(boo_pos_x, boo_pos_y),
            ge::Vector(boo_scale_x, boo_scale_y)), 
        boo_dir
    
    );

    // Aqui generamos un vector con todos los modelos que hayamos creado
    std::vector<ge::Model*> model_vector = { boo_model};


    // Creamos la aplicacion y le insertamos la ventana con nuestros modelos
    ge::Aplication ge_app = ge::Aplication(window, model_vector);
    // Lanzamos el game loop
	ge_app.update();


    //Despues de terminar la aplicacion, soltamos la memoria que usamos para los modelos
    for (ge::Model* model : model_vector ) {
        delete model;
    }
}
```

CONSIDERACION: Solo en esta iteracion, es necesario que hayan al menos 5 modelos.


# Sonidos, Música, Input y texto.
De momento estas cuatro funcionalidades están, pero dentro del game engine. Y de momento no se pueden usar
en los ejemplos.

Pero de momento el programa tiene música y se reproduce al abrir la ventana de visualizacion.

Los sonidos que están incluídos son de combate, y se pueden reproducir al apretar el botón ESPACIO en el ejemplo.
Este sistema de sonido es dinámico con respecto a la distancia en la que se encuentran los modelos unos con otros,
mientras más cerca estén, más fuerte será el sonido del combate.

El input de momento es automático y sirve para dos jugadores. El primero puede usar los botones A, S, D, W para moverse.
El segundo puede usar los botones de flechas, (arriba, izquierda, derecha, abajo).
Para cerrar la ventana se puede apretar la letra Q.

El texto viene incluído en la Aplicación. Y de momento muestra los FPS, y cuáles fueron los últimos INPUTS registrados por 
los usuarios.
