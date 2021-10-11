#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "aplication.h"
#include "model.h"
#include <string>

namespace gomaengine {


	int Aplication::update() {

        std::string absolute_path = "C:\\Felipe\\Universidad\\Arquitectura de motores de juegos\\GomaeronEngine\\git\\assets\\";
        //printf("update: 1\n");
        //sf::RenderWindow window = app.render_window;
        sf::RenderWindow window(sf::VideoMode(window_app.window_size_x, window_app.window_size_y), "My window");

        //boo def
        std::string boo_path = absolute_path + "imgs\\boo.png";
        int boo_pos_x = 600.0; int boo_pos_y = 300.0;
        int boo_scale = 3;
        int boo_speed = 10;


        // Cavalry heavy
        std::string cavalry_heavy_path = absolute_path + "imgs\\cavalry_heavy.png";
        int cavalry_heavy_pos_x = 400.0; int cavalry_heavy_pos_y = 200.0;
        int cavalry_heavy_scale = 4;
        int cavalry_heavy_speed = 10;


        //UI
        std::string rect_path = absolute_path + "imgs\\rectUI.png";
        int rect_pos_x = 0.0; int rect_pos_y = 470.0;
        int rect_scale = 1.5;
        int rect_speed = 10;

        //Grass
        std::string grass_path = absolute_path + "imgs\\grass.png";
        int grass_pos_x = 0.0; int grass_pos_y = 0.0;
        int grass_scale = 7;
        int grass_speed = 10;



        //Listener
        int listener_pos_x = 300.0f; int listener_pos_y = 450.0f;
        int listener_dir_x = 1.0f; int listener_dir_y = 1.0f;
        sf::Listener::setPosition(listener_dir_x, listener_dir_y, 0.0f);
        sf::Listener::setGlobalVolume(50.f);

        //SOUND
        sf::SoundBuffer buffer;

        if (!buffer.loadFromFile(absolute_path + "sounds\\melee sound.wav")) {
            printf("Could load sound");
        }
        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.setPosition(cavalry_heavy_pos_x, cavalry_heavy_pos_y, 0.f);
        


        //MUSIC
        sf::Music music;
        if (!music.openFromFile("C:\\Felipe\\Universidad\\Arquitectura de motores de juegos\\GomaeronEngine\\git\\assets\\sounds\\field_theme_1.wav"))
            printf("Could load music");
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
        text1.setPosition(200.0, 520.0);

        //TEXTO2
        //fonts
        sf::Text text2;
        // select the font
        text2.setFont(font); // font is a sf::Font
        // set the string to display

        text2.setString("Last input P2: None");
        // set the character size
        text2.setCharacterSize(24);
        text2.setPosition(500.0, 520.0);






        // run the program as long as the window is open
        while (window.isOpen())
        {
            
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
                    // boo
                    if (event.key.code == sf::Keyboard::A)
                    {
                        text1.setString("Last input P1: A");
                        boo_pos_x -= 1 * boo_speed;
                    }
                    if (event.key.code == sf::Keyboard::D)
                    {
                        text1.setString("Last input P1: D");
                        boo_pos_x += 1 * boo_speed;
                    }
                    if (event.key.code == sf::Keyboard::W)
                    {
                        text1.setString("Last input P1: W");
                        boo_pos_y -= 1 * boo_speed;
                    }
                    if (event.key.code == sf::Keyboard::S)
                    {
                        text1.setString("Last input P1: S");
                        boo_pos_y += 1 * boo_speed;
                    }

                    // heavy cavalry
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        text2.setString("Last input P2: Left");
                        cavalry_heavy_pos_x -= 1 * cavalry_heavy_speed;

                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        text2.setString("Last input P2: Right");
                        cavalry_heavy_pos_x += 1 * cavalry_heavy_speed;
                    }
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        text2.setString("Last input P2: UP");
                        cavalry_heavy_pos_y -= 1 * cavalry_heavy_speed;
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        text2.setString("Last input P2: Down");
                        cavalry_heavy_pos_y += 1 * cavalry_heavy_speed;
                    }



                    //listener_dir_x = boo_pos_x; listener_dir_y = boo_pos_y;
                    //sf::Listener::setPosition(listener_dir_x, listener_dir_y, 0.0f);
                    sound.setRelativeToListener(true);

                    if (event.key.code == sf::Keyboard::Space)
                    {
                        
                        sound.play();
                    }
                    
                    

                    // we don't process other types of events
                default:
                    break;
                }
            }
            window.clear(sf::Color::Blue);
            //printf("update: 4\n");
            /*for (int i = 0; i < gomaengine::Aplication::spriteVector.size(); i++) {
                window.draw(gomaengine::Aplication::spriteVector.at(i));
            }*/


            // Grass
            sf::Texture grass_texture;
            if (!grass_texture.loadFromFile(grass_path)) {
                printf("error loadung grass");
            }
            sf::Sprite grass_sprite;
            grass_sprite.setTexture(grass_texture);
            grass_sprite.setPosition(grass_pos_x, grass_pos_y);
            grass_sprite.setScale(grass_scale * 1.5, grass_scale);
            window.draw(grass_sprite);


            //SPRITE BOO
            sf::Texture boo_texture;
            if (!boo_texture.loadFromFile(boo_path)) {
                printf("error");
            }
            sf::Sprite boo_sprite;
            boo_sprite.setTexture(boo_texture);
            boo_sprite.setPosition(boo_pos_x, boo_pos_y);
            boo_sprite.setScale(boo_scale, boo_scale);
            window.draw(boo_sprite);

            // SPRITE CAVALRY 
            sf::Texture cavalry_heavy_texture;
            if (!cavalry_heavy_texture.loadFromFile(cavalry_heavy_path)) {
                printf("error");
            }
            sf::Sprite cavalry_heavy_sprite;
            cavalry_heavy_sprite.setTexture(cavalry_heavy_texture);
            cavalry_heavy_sprite.setPosition(cavalry_heavy_pos_x, cavalry_heavy_pos_y);
            cavalry_heavy_sprite.setScale(cavalry_heavy_scale, cavalry_heavy_scale);
            window.draw(cavalry_heavy_sprite);
            
            // UI RECT
            sf::Texture rect_texture;
            if (!rect_texture.loadFromFile(rect_path)) {
                printf("error loadung rectangle");
            }
            sf::Sprite rect_sprite;
            rect_sprite.setTexture(rect_texture);
            rect_sprite.setPosition(rect_pos_x, rect_pos_y);
            rect_sprite.setScale(rect_scale*2.9, rect_scale);
            window.draw(rect_sprite);


            

            //TEXT
            window.draw(text1);
            window.draw(text2);




            window.display();
        }
        printf("Update: Out\n");
        return 0;
	}

    //Aplication::Aplication(Window _window, Model_vect _model_vector) {
	Aplication::Aplication(Window _window){
        printf("Constructor: 1\n");

        //gomaengine::Window win = {window_size_x, window_size_y};
        this->window_app = _window;
        //this->model_vector = _model_vector;
        
        /*for (int i = 0; i < path_list.size(); i++) {
            sf::Texture texture;
            if (!texture.loadFromFile(path_list.at(i))){
                printf("error");
            }
            sf::Sprite sprite;
            sprite.setTexture(texture);
            spriteVector.push_back(sprite);
        }*/
        //printf("Constructor: 2\n");
	}
}