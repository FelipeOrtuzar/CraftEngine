#pragma once

#include <SFML/Audio.hpp>



namespace gomaengine {

    /// <summary>
    /// Clase referente a un componente de sonido
    /// </summary>
    class SoundComponent {
    private:
        /// <summary>
        /// Ruta de archivo para cuando se haga click sobre el objeto
        /// </summary>
        std::string path_clicked = "";
        
        /// <summary>
        /// Ruta de archivo para cuando se desplaze el objeto
        /// </summary>
        std::string path_moved = "";

        /// <summary>
        /// Componente de sonido de la libreria sfml
        /// </summary>
        sf::Sound sound;

        /// <summary>
        /// Buffer del sonido de sfml
        /// </summary>
        sf::SoundBuffer sound_buffer;

    public:

        /// <summary>
        /// Constructor de la clase
        /// </summary>
        SoundComponent();

        /// <summary>
        /// Destructor de la clase
        /// </summary>
        ~SoundComponent();

        /// <summary>
        /// Funcion de actualizacion, que se llama en cada loop
        /// </summary>
        void update();

        /// <summary>
        /// Funcion que settea el valor de this.path_clicked
        /// </summary>
        /// <param name="path_to_sound_when_clicked">Ruta del archivo de sonido</param>
        void insert_clicked(std::string path_to_sound_when_clicked);

        /// <summary>
        /// Funcion que actualiza el sonido y el buffer segun los parametros del objeto
        /// </summary>
        void reload_sound();

        /// <summary>
        /// Funcion que hace sonar la musica precargada
        /// </summary>
        void play_sound();
    };
}