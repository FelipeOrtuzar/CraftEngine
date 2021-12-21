#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include "GraphicComponent.h"
#include "SoundComponent.h"
#include "AnimationComponent.h"
//#include "CR_MovableComponent.h"
#include <SFML/Audio.hpp>

//class CR_MovableComponent;

namespace gomaengine {

	/// <summary>
	/// Clase que define los modelos del engine. GameObject define las caracteristicas intrinsecas de una unidad en el game engine.
	/// </summary>
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

			/// <summary>
			/// Componente de animacion del modelo
			/// </summary>
			AnimationComponent animation_component;

			/// <summary>
			/// Booleano sobre si el modelo tiene componente grafico
			/// </summary>
			bool has_graphic_component = 0;

			/// <summary>
			/// Booleano sobre si el modelo tiene componente de animacion
			/// </summary>
			bool has_animation_component = 0;
			

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
			/// Constructor de GameObject cuando tiene un componente grafico.
			/// </summary>
			/// <param name="_position">Posicion en el que se dibujara el modelo</param>
			/// <param name="_name">Nombre del modelo</param>
			/// <param name="_graphicComponent">Componente grafico del modelo</param>
			/// <param name="_soundComponent">Componente de sonido del modelo</param>
			GameObject(Vector _position, std::string _name, GraphicComponent _graphicComponent, SoundComponent _soundComponent);

			/// <summary>
			/// Constructor de GameObject cuando tiene un componente animado.
			/// </summary>
			/// <param name="_position">Posicion en el que se dibujara el modelo</param>
			/// <param name="_name">Nombre del modelo</param>
			/// <param name="_graphicComponent">Componente de animacion del modelo</param>
			/// <param name="_soundComponent">Componente de sonido del modelo</param>
			GameObject(Vector _position, std::string _name, AnimationComponent _animationComponent, SoundComponent _soundComponent);
			
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

			/// <summary>
			/// Funcion que devuelve la direccion en angulos del objeto
			/// </summary>
			/// <returns>El angulo en grados</returns>
			float get_angle();
	};
	


};