#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "aplication.h"
#include "model.h"
#include <string>
#include "model.h"
namespace gomaengine {


	int Aplication::update() {

        std::string absolute_path = "C:\\Felipe\\Universidad\\Arquitectura de motores de juegos\\GomaeronEngine\\git\\assets\\";
        //printf("update: 1\n");
        //sf::RenderWindow window = app.render_window;
        sf::RenderWindow window(sf::VideoMode(window_app.window_size_x, window_app.window_size_y), "My window");

        //boo def
        std::string boo_path = absolute_path + "imgs\\CABALLO_2.png";
        int boo_pos_x = 200.0; int boo_pos_y = 300.0;
        int boo_scale = 4;
        int boo_speed = 20;
        int boo_dir = 1;


        // Cavalry heavy
        std::string cavalry_heavy_path = absolute_path + "imgs\\CABALLO_1.png";
        int cavalry_heavy_pos_x = 600.0; int cavalry_heavy_pos_y = 200.0;
        int cavalry_heavy_scale = 4;
        int cavalry_heavy_speed = 20;
        int cavalry_heavy_dir = 1;


        //boo def
        std::string tres_path = absolute_path + "imgs\\CABALLO_3.png";
        int tres_pos_x = 200.0; int tres_pos_y = 300.0;
        int tres_scale = 4;
        int tres_speed = 20;
        int tres_dir = 1;


        //UI
        std::string rect_path = absolute_path + "imgs\\RECTANGULO_1.png";
        int rect_pos_x = 0.0; int rect_pos_y = 450.0;
        int rect_scale = 1.40;
        int rect_speed = 10;

        //Grass
        std::string grass_path = absolute_path + "imgs\\grass.png";
        int grass_pos_x = 0.0; int grass_pos_y = 0.0;
        int grass_scale = 7;
        int grass_speed = 10;



        //Listener
        int listener_pos_x = 0.0f; int listener_pos_y = 0.0f;
        int listener_dir_x = 1.0f; int listener_dir_y = 1.0f;
        sf::Listener::setPosition(listener_pos_x, listener_pos_y, 0.0f);
        sf::Listener::setGlobalVolume(10.f);

        //SOUND
        sf::SoundBuffer buffer;

        if (!buffer.loadFromFile(absolute_path + "sounds\\melee sound.wav")) {
            printf("Could load sound");
        }
        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.setPosition(cavalry_heavy_pos_x, cavalry_heavy_pos_y, 0.f);
        //sound.setAttenuation(10.f);


        //MUSIC
        sf::Music music;
        if (!music.openFromFile("C:\\Felipe\\Universidad\\Arquitectura de motores de juegos\\GomaeronEngine\\git\\assets\\sounds\\field_theme_1.wav"))
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
                    // boo
                    if (event.key.code == sf::Keyboard::A)
                    {
                        text1.setString("Last input P1: A");
                        boo_pos_x -= 1 * boo_speed;
                        boo_dir = -1;
                    }
                    if (event.key.code == sf::Keyboard::D)
                    {
                        text1.setString("Last input P1: D");
                        boo_pos_x += 1 * boo_speed;
                        boo_dir = 1;
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
                    sf::Listener::setPosition(boo_pos_x, boo_pos_y, 0.0f);


                    // heavy cavalry
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        text2.setString("Last input P2: Left");
                        cavalry_heavy_pos_x -= 1 * cavalry_heavy_speed;
                        cavalry_heavy_dir = -1;

                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        text2.setString("Last input P2: Right");
                        cavalry_heavy_pos_x += 1 * cavalry_heavy_speed;
                        cavalry_heavy_dir = 1;
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
                    sound.setPosition(cavalry_heavy_pos_x, cavalry_heavy_pos_y, 0.f);
                    //std::cout << "x: " << sound.getPosition().x << " y: " << sound.getPosition().y << "\n";

                    //listener_dir_x = boo_pos_x; listener_dir_y = boo_pos_y;
                    //sf::Listener::setPosition(listener_dir_x, listener_dir_y, 0.0f);

                    //sound.setRelativeToListener(true);
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        sound.setRelativeToListener(true);
                        int dif_x = boo_pos_x - cavalry_heavy_pos_x; int dif_y = boo_pos_y - cavalry_heavy_pos_y;
                        int distance = std::sqrt(dif_x * dif_x + dif_y * dif_y);
                        int total_distance = std::sqrt(window_app.window_size_x * window_app.window_size_x + window_app.window_size_y * window_app.window_size_y);
                        float coef = (distance * 1.0) / (total_distance * 1.0);
                        sound.setVolume(100.0 * (1.0 - coef));
                        sound.play();
                        std::cout << "xS: " << sound.getPosition().x << " yS: " << sound.getPosition().y << "\n";
                        std::cout << "xL: " << sf::Listener::getPosition().x << " y:: " << sf::Listener::getPosition().y << "\n";
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
            //boo_sprite.setScale(boo_scale, boo_scale);
            boo_sprite.setOrigin(10.0, 10.0);
            boo_sprite.setScale(boo_scale* boo_dir, boo_scale);
            
            window.draw(boo_sprite);


            //SPRITE TRES
            sf::Texture tres_texture;
            if (!tres_texture.loadFromFile(tres_path)) {
                printf("error");
            }
            sf::Sprite tres_sprite;
            
            tres_sprite.setTexture(tres_texture);
            sf::Vector2i mouse_pos = sf::Mouse::getPosition();
            tres_sprite.setPosition(mouse_pos.x * 1.0 - 90.0, mouse_pos.y * 1.0 - 100.0);
            tres_sprite.setOrigin(10.0, 10.0);
            tres_sprite.setScale(tres_scale * tres_dir, tres_scale);

            window.draw(tres_sprite);


            // SPRITE CAVALRY 
            sf::Texture cavalry_heavy_texture;
            if (!cavalry_heavy_texture.loadFromFile(cavalry_heavy_path)) {
                printf("error");
            }
            sf::Sprite cavalry_heavy_sprite;
            cavalry_heavy_sprite.setTexture(cavalry_heavy_texture);
            cavalry_heavy_sprite.setPosition(cavalry_heavy_pos_x, cavalry_heavy_pos_y);
            cavalry_heavy_sprite.setScale(cavalry_heavy_scale * cavalry_heavy_dir, cavalry_heavy_scale);
            cavalry_heavy_sprite.setOrigin(10.0, 10.0);
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
            window.draw(text3);

            window.display();

            sf::Time elapsed_time = clock.getElapsedTime();
            int fps_f =  (int) 1.0 / elapsed_time.asSeconds() ;


            std::string fps_s = "FPS: "; std::string fps = std::to_string(fps_f);
            text3.setString(fps_s + fps );
            
        }
        printf("Update: Out\n");
        return 0;
	}

    Aplication::Aplication(Window _window) {
	//Aplication::Aplication(Window _window, std::map<std::string, Model> _model_map){
        printf("Constructor: 1\n");

        this->window_app = _window;
        //this->model_map = _model_map;
       
	}
}