#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

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

        Vector substract(Vector _vector) { this->x -= _vector.x, this->y -= _vector.y; return *this; };


        Vector subs(Vector _vector) { return Vector(this->x - _vector.x, this->y - _vector.y); };

        Vector normalize() {
            float dist = distance(*this, Vector(0.0f, 0.0f));
            return this->multiply(1.0 / dist);
        };


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

            return sqrt(dif_x * dif_x + dif_y * dif_y);
        }

        float magnitude() {
            return sqrt(x * x + y * y);
        }

        void print() {
            std::cout << "x: " << x << ". y: " << y << "\n";
        }

        bool eq(Vector _vector) {
            return x == _vector.x && y == _vector.y;
        }
    };

    struct CP {
        std::string GRAPHIC = "Graphic_component";
        std::string SOUND   = "Sound_component";
        std::string MOVABLE = "Movable_component";

    };

    const CP Component_types;




}