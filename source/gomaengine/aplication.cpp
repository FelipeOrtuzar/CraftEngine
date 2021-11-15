#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>

#include "aplication.h"
#include "model.h"
#include "root_directory.h"

namespace gomaengine {


	int Aplication::update() {

        sf::RenderWindow window(sf::VideoMode(window_app.window_size_x, window_app.window_size_y), "My windoow");

        window.setFramerateLimit(60);


        Model* clicked_model = nullptr;

        //LOADING THE TEXTURES
        for (Model* model : model_vct) {
            model->get_texture().load_resources();
        }



   
        /*for (Model* model : model_vct) {
            model->get_sound_component()->reload_sound();
        }*/

        //Listener
        int listener_pos_x = 0.0f; int listener_pos_y = 0.0f;
        int listener_dir_x = 1.0f; int listener_dir_y = 1.0f;
        sf::Listener::setPosition(listener_pos_x, listener_pos_y, 0.0f);
        sf::Listener::setGlobalVolume(10.f);

        //SOUND
        //sf::SoundBuffer buffer;

        //if (!buffer.loadFromFile(getPath("assets/sounds/melee sound.wav").string())) {
        //    printf("Could load sound");
        //}
        //sf::Sound sound;
        //sound.setBuffer(buffer);
        //sound.setPosition(300.0, 4.00, 0.f);
        //sound.setAttenuation(10.f);


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
            printf("could load font");
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
                //printf("update: 3\n");
                switch (event.type)
                {
                    // window closed
                case sf::Event::Closed:
                    window.close();

                    // key pressed
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }

                    

                    /*
                    // boo
                    if (event.key.code == sf::Keyboard::A)
                    {
                        text1.setString("Last input P1: A");
                        model_vct.at(4)->translate(Vector(-20.0, 0));

                    }
                    if (event.key.code == sf::Keyboard::D)
                    {
                        text1.setString("Last input P1: D");
                        model_vct.at(4)->translate(Vector(20.0, 0));
                    }
                    if (event.key.code == sf::Keyboard::W)
                    {
                        text1.setString("Last input P1: W");
                        model_vct.at(4)->translate(Vector(0.0, -20.0));
                    }
                    if (event.key.code == sf::Keyboard::S)
                    {
                        text1.setString("Last input P1: S");
                        model_vct.at(4)->translate(Vector(0.0, 20.0));
                    }
                    
                    ////////////////////////////////////////
                    
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        text2.setString("Last input P2: Left");
                        model_vct.at(3)->translate(Vector(-20.0, 0));

                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        text2.setString("Last input P2: Right");
                        model_vct.at(3)->translate(Vector(20.0, 0));
                    }
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        text2.setString("Last input P2: UP");
                        model_vct.at(3)->translate(Vector(0.0, -20.0));
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        text2.setString("Last input P2: Down");
                        model_vct.at(3)->translate(Vector(0.0, 20.0));
                    }
                    //sf::Listener::setPosition(boo_pos_x, boo_pos_y, 0.0f);
                    */
                    
                    //// heavy cavalry
                    //if (event.key.code == sf::Keyboard::Left)
                    //{
                    //    text2.setString("Last input P2: Left");
                    //    cavalry_heavy_pos_x -= 1 * cavalry_heavy_speed;
                    //    cavalry_heavy_dir = -1;

                    //}
                    //if (event.key.code == sf::Keyboard::Right)
                    //{
                    //    text2.setString("Last input P2: Right");
                    //    cavalry_heavy_pos_x += 1 * cavalry_heavy_speed;
                    //    cavalry_heavy_dir = 1;
                    //}
                    //if (event.key.code == sf::Keyboard::Up)
                    //{
                    //    text2.setString("Last input P2: UP");
                    //    cavalry_heavy_pos_y -= 1 * cavalry_heavy_speed;
                    //}
                    //if (event.key.code == sf::Keyboard::Down)
                    //{
                    //    text2.setString("Last input P2: Down");
                    //    cavalry_heavy_pos_y += 1 * cavalry_heavy_speed;
                    //}
                    //sound.setPosition(cavalry_heavy_pos_x, cavalry_heavy_pos_y, 0.f);
                    //std::cout << "x: " << sound.getPosition().x << " y: " << sound.getPosition().y << "\n";

                    //listener_dir_x = boo_pos_x; listener_dir_y = boo_pos_y;
                    //sf::Listener::setPosition(listener_dir_x, listener_dir_y, 0.0f);

                    //sound.setRelativeToListener(true);
                    if (event.key.code == sf::Keyboard::Space)
                    {

                        /*Vector obj1 = model_vct.at(3)->get_position();
                        Vector obj2 = model_vct.at(4)->get_position();
                        sound.setRelativeToListener(true);
                        int dif_x = obj1.x - obj2.x; int dif_y = obj1.y- obj2.y;
                        int distance = std::sqrt(dif_x * dif_x + dif_y * dif_y);
                        int total_distance = std::sqrt(window_app.window_size_x * window_app.window_size_x + window_app.window_size_y * window_app.window_size_y);
                        float coef = (distance * 1.0) / (total_distance * 1.0);
                        sound.setVolume(100.0 * (1.0 - coef));
                        std::cout << "Dynamic volumen: " << 100.0 * (1.0 - coef) << "\n";
                        sound.play();*/
                        //std::cout << "xS: " << sound.getPosition().x << " yS: " << sound.getPosition().y << "\n";
                        //std::cout << "xL: " << sf::Listener::getPosition().x << " y:: " << sf::Listener::getPosition().y << "\n";
                    }
                    
                    

                    // we don't process other types of events
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
                    Model* min_model = nullptr;
                    // left mouse button is pressed
                    for (Model* model : model_vct) {
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
            for (Model* model : model_vct) {
                model->update();
                //model->get_position().print();
            }


            //model_vct.at(2)->set_position((Vector::to_Vector(sf::Mouse::getPosition())).sum(Vector(-90.0, -120.0)));
            window.clear(sf::Color::Cyan);

            for (Model* model : model_vct) {
                window.draw(*(model->get_texture().get_sprite()));
            }

            
            this->was_Mouse_Left_pressed_before = sf::Mouse::isButtonPressed(sf::Mouse::Left);
            this->was_Mouse_Right_pressed_before = sf::Mouse::isButtonPressed(sf::Mouse::Right);


            //TEXT
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            
            window.display();

            //TIME
            sf::Time elapsed_time = clock.getElapsedTime();
            int fps_f =  (int) 1.0 / elapsed_time.asSeconds() ;


            std::string fps_s = "FPS: "; std::string fps = std::to_string(fps_f);
            text3.setString(fps_s + fps );
            
        }
        printf("Update: Out\n");
        return 0;
	}


	Aplication::Aplication(Window _window, std::vector<Model*> _model_vct){
        printf("Constructor: 1\n");

        this->window_app = _window;
        this->model_vct = _model_vct;
       
	}
}