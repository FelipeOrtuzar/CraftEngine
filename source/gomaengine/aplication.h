#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include <gomaengine/model.h>
#include <vector>

namespace gomaengine {

    struct Window {
        int window_size_x;
        int window_size_y;
    };
    
    //struct Model_vect {
    //    //std::map<Model>
    //    std::vector<Model> model_vector;
    //};

    class Aplication {
        private:
            Window window_app;
            //Model_vect model_vector;
        public:
            //Aplication(Window _window, Model_vect _model_vector);
            Aplication(Window _window);
            int update();
    };


 /*   Aplication::Aplication(int window_size_x, int window_size_y, std::vector<sf::Sprite> sv) {
        render_window = rw;
        spriteVector = sv;
    }*/
    //int Aplication::update();

    /*struct Aplication {
        sf::RenderWindow render_window;
        std::vector<sf::Sprite> spriteVector;
    };*/
    //public:
    //    sf::RenderWindow render_window;
    //    //int spriteArrSize = 1;
    //    std::vector<sf::Sprite> spriteVector;


    //};
    //Aplication(sf::RenderWindow rw, std::vector<sf::Sprite> vs):
    //    render_window(rw),
    //    spriteVector(vs)
    //{}


    //Aplication app = Aplication set_up();
	//int gomaengine::Aplication::update();
	


} //namespace gomaengine