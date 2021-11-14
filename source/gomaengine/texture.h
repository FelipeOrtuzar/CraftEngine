#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"

namespace gomaengine {

    

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