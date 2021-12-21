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

        sf::RenderWindow window(sf::VideoMode(window_app.window_size_x, window_app.window_size_y), "My window");

        sf::View terrain_view(sf::Vector2f(window_app.window_size_x/2.f, window_app.window_size_y / 2.f),
            sf::Vector2f(window_app.window_size_x , window_app.window_size_y));
        

        //sf::View down_ui_view(sf::Vector2f(50, 50), sf::Vector2f(100, 100));

        //terrain_view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
        //down_ui_view.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));

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


        //TEXTO2
        //fonts
        sf::Text text2;
        // select the font
        text2.setFont(font); // font is a sf::Font
        // set the string to display

        text2.setString("Clicked object: None");
        // set the character size
        text2.setCharacterSize(24);
        text2.setPosition(800.0, 10.0);


        //TEXTO3
        sf::Text text3;
        // select the font
        text3.setFont(font); // font is a sf::Font
        // set the string to display

        text3.setString("FPS: None");
        // set the character size
        text3.setCharacterSize(24);
        text3.setPosition(50.0, 10.0);

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
                    if (event.key.code == sf::Keyboard::Escape) { window.close(); }
                    if (event.key.code == sf::Keyboard::P) {
                        if (!music.openFromFile(getPath("assets/sounds/background_musicwav.wav").string()))
                            printf("Could load music");
                        music.setLoop(true);
                        music.play();
                    }
                    if (event.key.code == sf::Keyboard::O) {
                        if (!music.openFromFile(getPath("assets/sounds/field_theme_1.wav").string()))
                            printf("Could load music");
                        music.setLoop(true);
                        music.play();
                    }
                    if (event.key.code == sf::Keyboard::A) { terrain_view.move(-20.f, 0.f); }
                    if (event.key.code == sf::Keyboard::S) { terrain_view.move(0.f,  20.f); }
                    if (event.key.code == sf::Keyboard::D) { terrain_view.move(20.f,  0.f); }
                    if (event.key.code == sf::Keyboard::W) { terrain_view.move(0.f, -20.f); }

                default:
                    break;
                }
            }

            if (!(this->was_Mouse_Left_pressed_before) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                text2.setString("Left mouse key has been pressed.");
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

                    std::string one_text = "Clicked object's name: ";
                    one_text.append(clicked_model->get_name());
                    text2.setString(one_text);
                    clicked_model->is_clicked();
                }
            }

            if (!(this->was_Mouse_Right_pressed_before) && sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                text2.setString("Right mouse key has been pressed.");
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

                model->update(this->previous_dt, window);
            }

            this->was_Mouse_Left_pressed_before = sf::Mouse::isButtonPressed(sf::Mouse::Left);
            this->was_Mouse_Right_pressed_before = sf::Mouse::isButtonPressed(sf::Mouse::Right);

            //TEXT
            window.draw(text2);
            window.draw(text3);
            window.setView(terrain_view);
            //window.setView(down_ui_view);

            window.display();

            //TIME
            sf::Time elapsed_time = clock.getElapsedTime();

            int fps_f =  (int) 1.0 / elapsed_time.asMilliseconds()  ;
            previous_dt = fps_f;

            std::string fps_s = "FPS: "; std::string fps = std::to_string(fps_f);
            text3.setString(fps_s + fps );        }
        return 0;
	}

	Aplication::Aplication(Window _window, std::vector<GameObject*> _model_vct){

        this->window_app = _window;
        this->model_vct = _model_vct;
	}
}