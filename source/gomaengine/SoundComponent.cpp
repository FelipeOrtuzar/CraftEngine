#include "SoundComponent.h"
#include <iostream>



namespace gomaengine {


    SoundComponent::SoundComponent() {
        // load something into the sound buffer...

        std::cout << "Constructor SoundComponent\n";
        //reload_sound();

    }

    void SoundComponent::insert_data(std::string path_to_sound_when_clicked) {
        std::cout << "Inserting data\n";
        this->path_clicked = path_to_sound_when_clicked;

        bool loaded = sound_buffer.loadFromFile(this->path_clicked);
        if (loaded) {
            sound.setBuffer(sound_buffer);
            std::cout << "CraftEngine: Sound loaded succesfully in: " << path_clicked << "\n";
        }
        else {
            std::cout << "CraftEngine: Couldn't load sound in: " << path_clicked << "\n";
        }
    }

    SoundComponent::~SoundComponent() {
        std::cout << "Destructor of SoundComponent\n";

        
    }


    void SoundComponent::reload_sound() {
        std::cout << "reload_sound\n";

        
    }
    void SoundComponent::play_sound() {
        std::cout << "play_sound\n";
        
        sound.play();
        
    };

}