#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include <SFML/Window.hpp>

namespace gomaengine {

	/// <summary>
	/// Estructura para guardar el estado de una animacion
	/// </summary>
	struct Animation_detail {
	
		/// <summary>
		/// Cantidad de Frames totales
		/// </summary>
		int nframes;

		/// <summary>
		/// Posicion cardinal del sprite dentro de la imagen
		/// </summary>
		Vector sprite_pos;

		/// <summary>
		/// Frame actual siendo mostrado
		/// </summary>
		int cur_frame = 0;

		/// <summary>
		/// Funcion que aumenta el frame actual
		/// </summary>
		void next_frame() {
			if (cur_frame >= nframes) { 
				cur_frame = 0; 
			}
			else {
				cur_frame++; 
			}
			

		}

		/// <summary>
		/// Funcion que devuelve el Frame actual
		/// </summary>
		/// <returns>Frame actual</returns>
		int get_frame() { return cur_frame; }

		
			


	};


	class AnimationComponent {
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
		/// Vector de la libreria SFML sobre el escalamiento de la textura
		/// </summary>
		sf::Vector2f scale;
		
		/// <summary>
		/// Vector de la libreria SFML referente a la posicion de la textura
		/// </summary>
		sf::Vector2f position;

		/// <summary>
		/// Direccion local de la imagen con las animaciones
		/// </summary>
		std::string path_to_animation;

		/// <summary>
		/// Tamanho en pixeles de cada sprite individual dentro de la animacion
		/// </summary>
		Vector shape_size;

		/// <summary>
		/// Vector con la distancia entre sprites dentro de la imagen con las animaciones
		/// </summary>
		Vector dist_between_texture;

		/// <summary>
		/// Vector con el offset de la posicion de los sprites. Algo asi como la constante en una funcion lineal
		/// </summary>
		Vector offset_position;

		/// <summary>
		/// Numero de sprites de una animacion particular
		/// </summary>
		int n_sprites;

		//bool walkable = 0;

		/// <summary>
		/// Angulo que se debera representar en la animacion
		/// </summary>
		int object_angle = 0;

		/// <summary>
		/// Sensibilidad a los diferentes angulos
		/// </summary>
		int angle_delta = 10;

		/// <summary>
		/// Mapeo de un angulo particular a un Animation_detail
		/// </summary>
		std::map<int, Animation_detail> map_to_anim_detail = std::map<int, Animation_detail>();

		/// <summary>
		/// Tasa de cambio en la cual se avanza por la animacion
		/// </summary>
		float change_rate = 0.2f;

		/// <summary>
		/// Punto flotante para coordinar el cambio de las animaciones
		/// </summary>
		float start_change = 0.0f;

		 

	public:
		/// <summary>
		/// Componente de animacion que debera ser puesto en el modelo, tiene lo necesario para que el modelo provea una animacion
		/// </summary>
		/// <param name="_path_to_animation"> Path al archivo de animacion</param>
		/// <param name="_position_in_world"> Posicion de la animacion en el mundo</param>
		/// <param name="_shape_size"> tamanho de los sprites en la animacion</param>
		/// <param name="_start_position"> Posicion offset para ajustar los sprites </param>
		/// <param name="_n_sprites">Cantidad sprites por animacion</param>
		/// <param name="_scale"> tamanho de los sprites en el mundo</param>
		/// <param name="_dist_textures">Distancia entre diferentes sprites dentro de la animacion</param>
		AnimationComponent(std::string _path_to_animation, Vector _position_in_world, 
			Vector _shape_size, Vector _start_position, int _n_sprites, Vector _scale, Vector _dist_textures);

		/// <summary>
		/// Constructor default de la clase
		/// </summary>
		AnimationComponent();

		/// <summary>
		/// Funcion que carga un template inicial de la animacion al principio del update
		/// </summary>
		void load_resources();

		/// <summary>
		/// Funcion que actualiza el estado de la animacion
		/// </summary>
		/// <param name="_window">Ventana donde dibujar la animacion</param>
		/// <param name="_facing_angle">Angulo al que debe dibujarse la animacion</param>
		/// <param name="_new_pos">Nueva posicion donde debe dibujarse la animacion</param>
		void update_animation(sf::RenderWindow& _window, int _facing_angle, Vector _new_pos);

		/// <summary>
		/// Funcion que define el angulo de la animacion
		/// </summary>
		/// <param name="_angle">Nuevo angulo</param>
		void set_object_angle(float _angle);

		/// <summary>
		/// Funcion que conecta un angulo a un conjunto de caracteristicas, como la posicion y el numero de frames
		/// </summary>
		/// <param name="_angle">Angulo en grados que es la llave del mapeo</param>
		/// <param name="_position"> Posicion cardinal del sprite en la imagen de la animacion</param>
		/// <param name="_nframes">Cantidad de sprites que tiene esta par angulo-animacion</param>
		void link_dir_with_detail(int _angle, Vector _position, int _nframes);

		//static int get_closest(int _value, std::list<int> _list);
	};
}