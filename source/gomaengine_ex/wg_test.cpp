
#include <gomaengine/aplication.h>
#include <gomaengine/GameObject.h>
#include <gomaengine/SoundComponent.h>
#include <gomaengine/GraphicComponent.h>
#include <gomaengine/root_directory.h>
//#include <gomaengine/CR_MovableComponent.h>

int main() {
    namespace ge = gomaengine;
    

	// Se hace la ventana
	int win_size_x = 1200;
	int win_size_y = 680;
	ge::Window window = { win_size_x, win_size_y };

    

    ////////////////////////BOO///////

    std::string boo_path = ge::getPath("assets/imgs/CABALLO_1.png").string();
    float boo_pos_x = 200.0; float boo_pos_y = 300.0;
    float boo_scale_x = 4; float boo_scale_y = 4;
    float boo_speed = 20;
    float boo_dir = 1;

    ge::SoundComponent boo_sc = ge::SoundComponent(); boo_sc.insert_clicked(ge::getPath("assets/sounds/horse_sound.wav").string());
    ge::GraphicComponent boo_gc = ge::GraphicComponent(boo_path, ge::Vector(boo_pos_x, boo_pos_y), ge::Vector(boo_scale_x, boo_scale_y));
    //
    ge::GameObject* boo_model = new ge::GameObject(
        ge::Vector(boo_pos_x, boo_pos_y),
        "boo",
        boo_gc,
        boo_sc
    );
    boo_model->set_velocity(5.0f);
    //boo_model->insert_movableComponent_data(5.f);
    


////////////////////////PONY///////

    std::string pony_path = ge::getPath("assets/imgs/CABALLO_2.png").string();
    float pony_pos_x = 600.0; float pony_pos_y = 200.0;
    float pony_scale_x = 4; float pony_scale_y = 4;
    float pony_speed = 20;
    float pony_dir = 1;

    ge::SoundComponent pony_sc = ge::SoundComponent(); pony_sc.insert_clicked(ge::getPath("assets/sounds/vill_sound.wav").string());
    ge::GraphicComponent pony_gc = ge::GraphicComponent(pony_path, ge::Vector(pony_pos_x, pony_pos_y), ge::Vector(pony_scale_x, pony_scale_y));


    ge::GameObject* pony_model = new ge::GameObject(
        ge::Vector(pony_pos_x, pony_pos_y),
        "Guy on a horse",
        pony_gc,
        pony_sc
        
    );
    pony_model->set_velocity(5.0f);


 //   //mouse def
    
    std::string mouse_path = ge::getPath("assets/imgs/CABALLO_3.png").string();
    float mouse_pos_x = 200.0; float mouse_pos_y = 300.0;
    float mouse_scale_x = 4; float mouse_scale_y = 4;
    float mouse_speed = 20;
    float mouse_dir = 1;

    ge::SoundComponent mouse_sc = ge::SoundComponent(); mouse_sc.insert_clicked(ge::getPath("assets/sounds/animal melee sound.wav").string());
    ge::GraphicComponent mouse_gc = ge::GraphicComponent(mouse_path, ge::Vector(mouse_pos_x, mouse_pos_y), ge::Vector(mouse_scale_x, mouse_scale_y));

    ge::GameObject* mouse_model = new ge::GameObject(
        ge::Vector(mouse_pos_x, mouse_pos_y),
        "Soldier awa",
        mouse_gc,
        mouse_sc

    );
    mouse_model->set_velocity(5.0f);



    //GX

    std::string gx_path = ge::getPath("assets/imgs/ACrossAnimations_fixed2.png").string();
    ge::Vector gx_pos = ge::Vector(200.0, 300.0);
    ge::Vector gx_sprite_shape = ge::Vector(50.0, 80.0);
    ge::Vector gx_start_position = ge::Vector(27.0,  20.0);
    ge::Vector gx_distance_between_textures = ge::Vector(100.0, 100.0);
    ge::Vector gx_scale = ge::Vector(1.0, 1.0);
    float gx_speed = 20;
    float gx_dir = 1;

    ge::SoundComponent gx_sc = ge::SoundComponent(); mouse_sc.insert_clicked(ge::getPath("assets/sounds/animal melee sound.wav").string());
    ge::AnimationComponent gx_ac = ge::AnimationComponent(gx_path, gx_pos,
        gx_sprite_shape, gx_start_position, 6, gx_scale, gx_distance_between_textures);
    
    gx_ac.link_dir_with_detail(0,   ge::Vector(1, 10), 8);
    gx_ac.link_dir_with_detail(45,  ge::Vector(1, 9), 8);
    gx_ac.link_dir_with_detail(90,  ge::Vector(1, 2), 8);
    gx_ac.link_dir_with_detail(135, ge::Vector(1, 3), 8);
    gx_ac.link_dir_with_detail(180, ge::Vector(1, 4), 8);
    gx_ac.link_dir_with_detail(225, ge::Vector(1, 5), 8);
    gx_ac.link_dir_with_detail(270, ge::Vector(1, 6), 8);
    gx_ac.link_dir_with_detail(315, ge::Vector(1, 11), 8);

    ge::GameObject* gx_model = new ge::GameObject(
        gx_pos,
        "Gx",
        gx_ac,
        gx_sc

    );
    gx_model->set_velocity(5.0f);

    /*
 //   //rectUI def
    std::string rectUI_path = ge::getPath("assets/imgs/RECTANGULO_1.png").string();
    float rectUI_pos_x = 35.0; float rectUI_pos_y = 460.0;
    float rectUI_scale_x = 2.85; float rectUI_scale_y = 1.0;
    float rectUI_speed = 20;
    float rectUI_dir = 1;
    ge::Model* rectUI_model = new ge::Model(
        ge::Vector(rectUI_pos_x, rectUI_pos_y),
        ge::Texture(rectUI_path,
            ge::Vector(rectUI_pos_x, rectUI_pos_y),
            ge::Vector(rectUI_scale_x, rectUI_scale_y)),
        rectUI_dir,
        ge::SoundComponent(ge::getPath("assets/sounds/horse_sound.wav").string())
    );
     */
    //  grass def
    std::string grass_path = ge::getPath("assets/imgs/grass.png").string();
    float grass_pos_x = 60.0; float grass_pos_y = 10.0;
    float grass_scale_x = 9; float grass_scale_y = 9;
    float grass_speed = 20;
    float grass_dir = 1;

    ge::SoundComponent grass_sc = ge::SoundComponent(); grass_sc.insert_clicked(ge::getPath("assets/sounds/animal melee sound.wav").string());
    ge::GraphicComponent grass_gc = ge::GraphicComponent(grass_path, ge::Vector(grass_pos_x, grass_pos_y), ge::Vector(grass_scale_x, grass_scale_y));

    ge::GameObject* grass_model = new ge::GameObject(
        ge::Vector(grass_pos_x, grass_pos_y),
        "Captain uwu",
        grass_gc,
        grass_sc

    );
    grass_model->set_velocity(0.0f);


   
    std::vector<ge::GameObject*> model_vector = { grass_model, boo_model, pony_model, mouse_model, gx_model};



	ge::Aplication ge_app = ge::Aplication(window, model_vector);
	ge_app.update();

    for (ge::GameObject* model : model_vector ) {
        delete model;
    }
}