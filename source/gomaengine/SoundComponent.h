#pragma once

#include <SFML/Audio.hpp>



namespace gomaengine {

    class SoundComponent {
    private:
        std::string path_clicked = "";
        sf::Sound sound;
        sf::SoundBuffer sound_buffer;

    public:
        SoundComponent();
        ~SoundComponent();

        void update();

        void insert_data(std::string path_to_sound_when_clicked);

        
        void reload_sound();
        void play_sound();
    };
}