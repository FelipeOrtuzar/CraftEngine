
#include <gomaengine/aplication.h>
#include <gomaengine/model.h>
#include <gomaengine/root_directory.h>

float main() {
    namespace ge = gomaengine;
    

	// Se hace la ventana
	float win_size_x = 1200;
	float win_size_y = 600;
	ge::Window window = { win_size_x, win_size_y };

    

	/////////////////textures////////////////
    //boo def
    //std::string boo_path = absolute_path + "imgs\\CABALLO_1.png";

    std::string boo_path = ge::getPath("assets/imgs/CABALLO_1.png").string();
    float boo_pos_x = 200.0; float boo_pos_y = 300.0;
    float boo_scale_x = 4; float boo_scale_y = 4;
    float boo_speed = 20;
    float boo_dir = 1;
    ge::Model* boo_model = new ge::Model(
        ge::Vector(boo_pos_x, boo_pos_y),
        ge::Texture(boo_path,
            ge::Vector(boo_pos_x, boo_pos_y),
            ge::Vector(boo_scale_x, boo_scale_y)), 
        boo_dir
    
    );


 //   //pony def

    std::string pony_path = ge::getPath("assets/imgs/CABALLO_2.png").string();
    float pony_pos_x = 600.0; float pony_pos_y = 200.0;
    float pony_scale_x = 4; float pony_scale_y = 4;
    float pony_speed = 20;
    float pony_dir = 1;
    ge::Model* pony_model = new ge::Model(
        ge::Vector(pony_pos_x, pony_pos_y),
        ge::Texture(pony_path,
            ge::Vector(pony_pos_x, pony_pos_y),
            ge::Vector(pony_scale_x, pony_scale_y)), 
        pony_dir
    );


 //   //mouse def
    
    std::string mouse_path = ge::getPath("assets/imgs/CABALLO_3.png").string();
    float mouse_pos_x = 200.0; float mouse_pos_y = 300.0;
    float mouse_scale_x = 4; float mouse_scale_y = 4;
    float mouse_speed = 20;
    float mouse_dir = 1;
    ge::Model* mouse_model = new ge::Model(
        ge::Vector(mouse_pos_x, mouse_pos_y),
        ge::Texture(mouse_path,
            ge::Vector(mouse_pos_x, mouse_pos_y),
            ge::Vector(mouse_scale_x, mouse_scale_y)), 
        mouse_dir
    );

 //   //rectUI def
    std::string rectUI_path = ge::getPath("assets/imgs/RECTANGULO_1.png").string();
    float rectUI_pos_x = 5.0; float rectUI_pos_y = 450.0;
    float rectUI_scale_x = 2.85; float rectUI_scale_y = 1.0;
    float rectUI_speed = 20;
    float rectUI_dir = 1;
    ge::Model* rectUI_model = new ge::Model(
        ge::Vector(rectUI_pos_x, rectUI_pos_y),
        ge::Texture(rectUI_path,
            ge::Vector(rectUI_pos_x, rectUI_pos_y),
            ge::Vector(rectUI_scale_x, rectUI_scale_y)),
        rectUI_dir
    );

    //  grass def
    std::string grass_path = ge::getPath("assets/imgs/grass.png").string();
    float grass_pos_x = 0.0; float grass_pos_y = 0.0;
    float grass_scale_x = 9; float grass_scale_y = 9;
    float grass_speed = 20;
    float grass_dir = 1;
    ge::Model* grass_model = new ge::Model(
        ge::Vector(grass_pos_x, grass_pos_y),
        ge::Texture(grass_path,
            ge::Vector(grass_pos_x, grass_pos_y),
            ge::Vector(grass_scale_x, grass_scale_y)), 
        grass_dir
    );



    std::vector<ge::Model*> model_vector = { grass_model, rectUI_model, boo_model, pony_model, mouse_model };

 




	ge::Aplication ge_app = ge::Aplication(window, model_vector);
	ge_app.update();

    for (ge::Model* model : model_vector ) {
        delete model;
    }
}