#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include "GraphicComponent.h"
#include "SoundComponent.h"
//#include "CR_MovableComponent.h"
#include <SFML/Audio.hpp>

//class CR_MovableComponent;

namespace gomaengine {





	/** 
	* Clase que define los modelos del engine.
	*
	* GameObject define las caracteristicas intrinsecas de una unidad en el game engine.
	*
	*/
	class GameObject {
		private:
			/// <summary>
			/// Vector que identifica la posicion abstracta del modelo en el juego.
			/// </summary>
			Vector position = Vector(0.0f, 0.0f);

			/// <summary>
			/// Int que define si mira hacia la derecha o la izquierda
			/// </summary>
			int orientation = 1;

			/// <summary>
			/// Componente de graficos del modelo
			/// </summary>
			GraphicComponent graphicComponent = GraphicComponent("", Vector(0.0, 0.0), Vector(0.0, 0.0));

			/// <summary>
			/// Componente de sonido del modelo
			/// </summary>
			SoundComponent sound_component;

			/// <summary>
			/// Posicion objetivo en la que deberia estar el modelo en pantalla
			/// </summary>
			Vector target_position = Vector(0.0f, 0.0f);

			/// <summary>
			/// Velocidad del modelo
			/// </summary>
			float velocity = 1.0f;
			
			/// <summary>
			/// Nombre del modelo
			/// </summary>
			std::string name = "";
			

		public:
			/// <summary>
			/// Funcion que retorna la posicion del modelo
			/// </summary>
			/// <returns> Un vector de la posicion del modelo</returns>
			Vector get_position();

			/// <summary>
			/// Funcion que retorna la textura usada por el modelo.
			/// </summary>
			/// <returns>Una textura.</returns>
			GraphicComponent get_texture();

			/// <summary>
			/// Funcion que retorna la orientacion de hacia donde mira el modelo.
			/// </summary>
			/// <returns>Un 1 o -1 dependiendo</returns>
			int get_orientation();
			
			/// <summary>
			/// Funcion que define la posicion en el modelo
			/// </summary>
			/// <param name="_position">Posicion a settear </param>
			void set_position(Vector _position);

			/// <summary>
			/// Funcion que define la textura en el modelo
			/// </summary>
			/// <param name="_texture">Textura a settear </param>
			void set_graphicComponent(GraphicComponent _graphicComponent);

			/// <summary>
			/// Funcion que define la orientacion en el modelo
			/// </summary>
			/// <param name="_orientation"> Int a settear referente a la orientacion del modelo</param>
			void set_orientation(int _orientation); 

			/// <summary>
			/// Constructor de GameObject.
			/// </summary>
			/// <param name="_position">Posicion abstracta del modelo</param>
			/// <param name="_texture"> Textura del modelo</param>
			/// <param name="_orientation">Orientacion del modelo</param>
			/// <param name="_soundComponent">Componente de sonido</param>
			GameObject(Vector _position, std::string _name, GraphicComponent _graphicComponent, SoundComponent _soundComponent);
			
			/// <summary>
			/// Destructor de GameObject.
			/// </summary>
			~GameObject();

			/// <summary>
			/// Funcion que traslada la posicion abstracta del modelo
			/// </summary>
			/// <param name="_delta_pos">Vector con cambio en la posicion</param>
			void translate(Vector _delta_pos);

			/// <summary>
			/// Funcion que te da el nombre del modelo
			/// </summary>
			/// <returns>Un std string del modelo</returns>
			std::string get_name();

			/// <summary>
			/// Funcion que devuelve el componente de sonido
			/// </summary>
			/// <returns>SoundComponent devuelto</returns>
			SoundComponent get_sound_component();

			/// <summary>
			/// Funcion que define la velocidad en el modelo
			/// </summary>
			/// <param name="_velocity"></param>
			void set_velocity(float _velocity);

			/// <summary>
			/// Funcion que define algoritmos para cuando el objeto se cliquea
			/// </summary>
			void is_clicked();

			/// <summary>
			/// Funcion que se devuelve a si mismo
			/// </summary>
			/// <returns>This</returns>
			GameObject* get_me();

			/// <summary>
			/// Funcion que define la actualizacion del modelo en el gameloop
			/// </summary>
			/// <param name="_delta_time">Tiempo entre cada frame</param>
			/// <param name="_window">Ventana de visualizacion</param>
			void update(float _delta_time, sf::RenderWindow& _window);

			/// <summary>
			/// Funcion que mueve el objeto al vector objetivo target
			/// </summary>
			void move_to_target(float _delta_time);

			/// <summary>
			/// Funcion que settea la posicion objetivo del modelo
			/// </summary>
			/// <param name="_target">Vector del nuevo objetivo</param>
			void set_target(Vector _target);
	};
	


};