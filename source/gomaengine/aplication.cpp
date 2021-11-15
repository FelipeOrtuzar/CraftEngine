#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>

#include "aplication.h"
#include "root_directory.h"

namespace gomaengine {


	int Aplication::update() {

        sf::RenderWindow window(sf::VideoMode(window_app.window_size_x, window_app.window_size_y), "My windoow");


        sf::View terrain_view(sf::Vector2f(window_app.window_size_x/2.f, window_app.window_size_y / 2.f),
            sf::Vector2f(window_app.window_size_x , window_app.window_size_y));
        
        window.setFramerateLimit(60);


        GameObject* clicked_model = nullptr;


        //LOADING THE TEXTURES
        for (GameObject* model : model_vct) {
            model->get_texture().load_resources();
        }



   
        /*for (Model* model : model_vct) {
            model->get_sound_component()->reload_sound();
        }*/


        //MUSIC
        sf::Music music;
        if (!music.openFromFile(getPath("assets/sounds/field_theme_1.wav").string()))
            printf("Could load music");
        music.setLoop(true);
        music.play();



        //FONTS 1
        sf::Font font;
        if (!font.loadFromFile("C:\\Windows\\Fonts\\comic.ttf"))
        {
            printf("Couldn't load font");
        }

        //TEXTO1
        //fonts
        sf::Text text1;
        // select the font
        text1.setFont(font); // font is a sf::Font
        // set the string to display

        text1.setString("Last input P1: None");
        // set the character size
        text1.setCharacterSize(24);
        text1.setPosition(200.0, 500.0);

        //TEXTO2
        //fonts
        sf::Text text2;
        // select the font
        text2.setFont(font); // font is a sf::Font
        // set the string to display

        text2.setString("Last input P2: None");
        // set the character size
        text2.setCharacterSize(24);
        text2.setPosition(500.0, 500.0);


        //TEXTO3
        sf::Text text3;
        // select the font
        text3.setFont(font); // font is a sf::Font
        // set the string to display

        text3.setString("FPS: None");
        // set the character size
        text3.setCharacterSize(24);
        text3.setPosition(1050.0, 20.0);

        sf::Time elapsed_time = sf::seconds(0);

        // run the program as long as the window is open
        while (window.isOpen())
        {
            // Se toma el tiempo
            sf::Clock clock;
            
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed: // window closed
                    window.close();
                case sf::Event::KeyPressed: // key pressed
                    switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                    case sf::Keyboard::A:
                        terrain_view.move(-20.f, 0.f);
                    case sf::Keyboard::S:
                        terrain_view.move(0.f, 20.f);
                    case sf::Keyboard::D:
                        terrain_view.move(20.f, 0.f);
                    case sf::Keyboard::W:
                        terrain_view.move(0.f, -20.f);
                    default:
                        break;
                    }
                default:
                    break;
                }
            }

            if (!(this->was_Mouse_Left_pressed_before) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                text2.setString("key pressed");
                if (!model_vct.empty()) {

                    Vector local_position = Vector::to_Vector(sf::Mouse::getPosition(window));

                    float min_radio = 35.0f;
                    float min_distance = 100000000.0f;
                    GameObject* min_model = nullptr;
                    // left mouse button is pressed
                    for (GameObject* model : model_vct) {
                        float actual_dist = Vector::distance(model->get_position(), local_position);
                        min_model = min_radio > actual_dist ? model : min_model;
                    }
                    clicked_model = min_model;
                }

                if (clicked_model != nullptr) {
                    text2.setString(clicked_model->get_name());
                    clicked_model->is_clicked();
                }
            }

            if (!(this->was_Mouse_Right_pressed_before) && sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                if (clicked_model != nullptr) {
                    Vector mouse_pos = Vector::to_Vector(sf::Mouse::getPosition(window));
                    clicked_model->set_target(mouse_pos);

                }
            }


            //Updating MovableComponent
            for (GameObject* model : model_vct) {
                
                //model->get_position().print();
            }

            //model_vct.at(2)->set_position((Vector::to_Vector(sf::Mouse::getPosition())).sum(Vector(-90.0, -120.0)));
            window.clear(sf::Color::Cyan);

            //////////////UPDATE////////////////////
            for (GameObject* model : model_vct) {

                model->update(elapsed_time.asSeconds(), window);
            }

            this->was_Mouse_Left_pressed_before = sf::Mouse::isButtonPressed(sf::Mouse::Left);
            this->was_Mouse_Right_pressed_before = sf::Mouse::isButtonPressed(sf::Mouse::Right);

            //TEXT
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.setView(terrain_view);

            window.display();

            //TIME
            sf::Time elapsed_time = clock.getElapsedTime();
            int fps_f =  (int) 1.0 / elapsed_time.asSeconds() ;

            std::string fps_s = "FPS: "; std::string fps = std::to_string(fps_f);
            text3.setString(fps_s + fps );        }
        printf("Update: Out\n");
        return 0;
	}

	Aplication::Aplication(Window _window, std::vector<GameObject*> _model_vct){
        printf("Constructor: 1\n");

        this->window_app = _window;
        this->model_vct = _model_vct;
	}
}