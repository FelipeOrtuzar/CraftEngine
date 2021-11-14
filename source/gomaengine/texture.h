#pragma once
#include <SFML/Graphics.hpp>

namespace gomaengine {

    /// <summary>
    /// Estructura de un vector en 2D (x, y)
    /// </summary>
    struct Vector {
        /// <summary>
        /// Float x, usualmente visto como ancho (izquierda hacia derecha)
        /// </summary>
        float x = 0.0;
        /// <summary>
        /// Float y, usualmente visto como altura (arriba hacia abajo)
        /// </summary>
        float y = 0.0;
        /// <summary>
        /// Funcion que transforma el vector a un vector de la libreria SFML
        /// </summary>
        /// <returns>sf::Vector como las propiedades del vector</returns>
        sf::Vector2f to_sfVector() { return sf::Vector2f(x, y); };
        /// <summary>
        /// Sum between this vector and another
        /// </summary>
        /// <param name="_vector">Vector that will be summed to this one</param>
        Vector sum(Vector _vector) { this->x += _vector.x, this->y += _vector.y; return *this; };
        /// <summary>
        /// Static function to generate a Vector from a sf::Vector2f
        /// </summary>
        /// <param name="_sf_vector">The original sf::Vector2f</param>
        /// <returns>The output Vector</returns>
        static Vector to_Vector(sf::Vector2f _sf_vector) { return Vector(_sf_vector.x, _sf_vector.y); };
        /// <summary>
        /// Static function to generate a Vector from a sf::Vector2i
        /// </summary>
        /// <param name="_sf_vector">The original sf::Vector2i</param>
        /// <returns>The output Vector</returns>
        static Vector to_Vector(sf::Vector2i _sf_vector) { return Vector((float)_sf_vector.x, (float)_sf_vector.y); };
        /// <summary>
        /// Funcion que multiplica el Vector por una constante y lo devuelve.
        /// </summary>
        /// <param name="k">Constante a multiplicar</param>
        /// <returns>Vector (this)</returns>
        Vector multiply(float k) { x *= k, y *= k; return *this; };
        /// <summary>
        /// Funcion que multiplica el Vector por otro, punto a punto, y lo devuelve.
        /// </summary>
        /// <param name="_vector">Vector a multiplicar punto a punto</param>
        /// <returns>Vector (this)</returns>
        Vector multiply(Vector _vector) { x *= _vector.x, y *= _vector.y; return *this; };
        /// <summary>
        /// Funcion que aplica el valor absoluto sobre todas la dimensiones del Vector
        /// </summary>
        /// <returns>Vector (this)</returns>
        Vector abs() { x = std::abs(x), y = std::abs(y); return *this; };

        /// <summary>
        /// Funcion que calcula la distancia euclidiana entre dos vectores
        /// </summary>
        /// <param name="_vector1">Primer vector</param>
        /// <param name="_vector2">Segundo vector</param>
        /// <returns>Un float de la distancia entre ambos vectores</returns>
        static float distance(Vector _vector1, Vector _vector2) {
            float dif_x = _vector1.x - _vector2.x;
            float dif_y = _vector1.y - _vector2.y;

            return sqrt(dif_x * dif_x + dif_x * dif_y);
        }
    };

    /// <summary>
    /// Class para definir la textura de un objeto
    /// </summary>
    class Texture {
    private:
        /// <summary>
        /// Textura de la libreria SFML
        /// </summary>
        sf::Texture* texture;
        /// <summary>
        /// Sprite de la libreria SFML
        /// </summary>
        sf::Sprite* sprite;
        /// <summary>
        /// String de la direccion en memoria del archivo usado para la textura
        /// </summary>
        std::string path_to_texture = "";
        /// <summary>
        /// Vector de la libreria SFML referente a la posicion de la textura
        /// </summary>
        sf::Vector2f position;
        /// <summary>
        /// Vector de la libreria SFML sobre el escalamiento de la textura
        /// </summary>
        sf::Vector2f scale;

    public:
        /// <summary>
        /// Constructor de la clase Texture
        /// </summary>
        /// <param name="_path_to_texture">String de la direccion en memoria del archivo</param>
        /// <param name="_position">Vector con la posicion de la textura en pantalla</param>
        /// <param name="_scale">Vector con el escalamiento de la textura</param>
        Texture(std::string _path_to_texture, Vector _position, Vector _scale);
        /// <summary>
        /// Funcion que obtiene la textura 
        /// </summary>
        /// <returns>Textura de la libreria SFML</returns>
        sf::Texture* get_texture();
        /// <summary>
        /// Funcion que devuelve el sprite
        /// </summary>
        /// <returns>El sprite de la libreria SFML</returns>
        sf::Sprite* get_sprite();
        /// <summary>
        /// Funcion que retorna el string de la direccion en memoria del archivo de la textura
        /// </summary>
        /// <returns></returns>
        std::string get_path_to_texture();
        /// <summary>
        /// Funcion que retorna el @see Vector de la posicion de la textura
        /// </summary>
        /// <returns>Vector de la posicion</returns>
        Vector get_position();
        /// <summary>
        /// Funcion que retorna el Vector del escalamiento de la textura
        /// </summary>
        /// <returns>Vector de escalamiento</returns>
        Vector get_scale();

        /// <summary>
        /// Funcion que establece la textura 
        /// </summary>
        /// <param name="_texture">La textura a establecer</param>
        void set_texture(sf::Texture* _texture);
        /// <summary>
        /// Funcion que establece el sprite
        /// </summary>
        /// <param name="_sprite">Sprite a establecer</param>
        void set_sprite(sf::Sprite* _sprite);
        /// <summary>
        /// Funcion que establece el string de la direccion de memoria del archivo usado en la textura
        /// </summary>
        /// <param name="_path_to_texture">String de la direccion</param>
        void set_path_to_texture(std::string _path_to_texture);
        /// <summary>
        /// Funcion que establece la posicion del sprite de la textura
        /// </summary>
        /// <param name="_position">Vector de la nueva posicion</param>
        void set_sprite_position(Vector _position);
        /// <summary>
        /// Funcion que establece la escala del sprite en la textura
        /// </summary>
        /// <param name="_scale">Vector de la escala</param>
        void set_sprite_scale(Vector _scale);

        /// <summary>
        /// Funcion que carga los atributos y genera lo objetos en la textura
        /// </summary>
        void load_resources();
        /// <summary>
        /// Funcion para mover de posicion la posicion de la textura
        /// </summary>
        /// <param name="_vector">Delta distancia</param>
        void translate(Vector _vector);
	};



}