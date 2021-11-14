#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "model.h"
#include <vector>

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
            std::vector<Model*> model_vct;


            bool was_Mouse_Left_pressed_before = 0;
        public:
            /// <summary>
            /// Constructor de la aplicacion
            /// </summary>
            /// <param name="_window">Ventana de visualizacion</param>
            /// <param name="_model_vct">Vector con los modelos a usar</param>
            Aplication(Window _window, std::vector<Model*> _model_vct);
            /// <summary>
            /// Funcion con el ciclo del juego
            /// </summary>
            /// <returns>Int de retorno de correctitud del programa</returns>
            int update();
    };

} //namespace gomaengine