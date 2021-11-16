#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <vector>
#include "Utils.h"

namespace gomaengine {

    /// <summary>
    /// Estructura con atributos de la pantalla de visualizacion
    /// </summary>
    struct Window {

        /// <summary>
        /// Ancho de la pantalla
        /// </summary>
        int window_size_x;

        /// <summary>
        /// Alto de la pantalla
        /// </summary>
        int window_size_y;
    };
    /// <summary>
    /// Clase que define y organiza los modelos y clases del game engine
    /// </summary>
    class Aplication {
        private:
            /// <summary>
            /// Estructura referente a la ventana de visualizacion
            /// </summary>
            Window window_app;

            /// <summary>
            /// Vector con un listado de modelos que estaran en la aplicacion
            /// </summary>
            std::vector<GameObject*> model_vct;

            /// <summary>
            /// Booleano sobre si se ha apretado el boton izquierdo antes
            /// </summary>
            bool was_Mouse_Left_pressed_before = 0;

            /// <summary>
            /// Booleano sobre si se ha apretado el boton derecho antes
            /// </summary>
            bool was_Mouse_Right_pressed_before = 0;

            float previous_dt = 1.0f / 60.0f;

        public:
            /// <summary>
            /// Constructor de la aplicacion
            /// </summary>
            /// <param name="_window">Ventana de visualizacion</param>
            /// <param name="_model_vct">Vector con los modelos a usar</param>
            Aplication(Window _window, std::vector<GameObject*> _model_vct);

            /// <summary>
            /// Funcion con el ciclo del juego
            /// </summary>
            /// <returns>Int de retorno de correctitud del programa</returns>
            int update();
    };

} //namespace gomaengine