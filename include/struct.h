// Here is the definition of data structures used in our project.

#ifndef _STRUCTURES_ARE_DEFINED_
#define _STRUCTURES_ARE_DEFINED_
// These pro-compilation instructions are used to avoid redefinition of the structures below.

#include <string>
#include "raylib-cpp.hpp"

// MARK: Common Structures

struct Position{
    int x, y; // This is the position of the object, x refers to the columns and y the rows.
    int h; // This refers to the height of the object.
};

enum Direction{
    up, down, left, right
    // This is a enumeration of the direction that the bot faces towards.
    // You can assign any of these value to this kind of data structure.
    // And a expression like "dir == up" can be used in our program and that would return a bool value of whether it is true or not.
};

struct Light{
    Position pos;
    bool turned_on; // This describes whether the light is turned on or not.
};

struct Cell{
    Position pos;
    bool light_id; // This describes whether there is a light on this cell.
};

enum Op{
    TL, TR, MOV, JMP, LIT, CALL
    // These are the types of the posible command used by the player.
    // We can add something here if we want to add some new commands in our game.
};

// MARK: Main Classes

class Bot{
    // This is the class of the bot we can control.
private:
    Position m_pos;
    
    Direction m_dir;
    // These are the private variables of the class Bot, They can't be changed directly without using the methods below.
public:
    void move();
    // We can call these methods to change the position of the bot.
    
    void turn(enum Direction d);
    // we can call this method to change the direction of the bot.
    
    Position current_position(){return m_pos;}
    
    Direction current_direction(){return m_dir;}
    
    Bot(Position & pos, Direction dir);
    // This function is used to construct an example of bot using the initial value of its position and its direction.
};

class Map{
    // This is the class of the map in our game.
private:
    std::string m_name;
    // This is the name of the map.
    
    Cell * m_cells;
    // These are the cells on the map, which at most counts 100 rows and 100 columns.
    
    int m_cell_count;
    // This variable describes the number of the cells in our game.
    
    int m_row, m_col;
    // These are the rows and columns actually used in the exact map.
    
    Light * m_lights;
    // This is the list of the lights on the map.
    
    int m_light_count;
    // This is the number of lights still remains on the map.
    
public:
    void light_lit(Position & pos);
    // This function is called when the player uses the "LIT" command.
    // This will light the light at that position, and decreases the light_count by 1.
    
    int is_not_cleared(){return m_light_count;}
    // This function is used to judge whether the lights in the map are all lit up. Its return value is used as the type bool.
    
    Cell * cells(){return m_cells;}
    
    int cells_count(){return m_cell_count;}

    Map(Cell * cells, Light * lights, int light_count, std::string name);
    // This function is used to construct the map of the game using the initial values of the related variables.
    ~Map(){
        if(m_cells != NULL){delete[] m_cells;}
        if(m_lights != NULL){delete[] m_lights;}
    }
};

class Game{
    // This is the class of the whole game process.
protected:
    std::string m_cmd;
    // This is the current cmd inputed by the player.
    
    Map * m_map;
    // This is the map we loaded in our game.
    
    Bot * m_bot;
    // This is the bot controlled by the player.
    
    std::string m_path;
    // This is the path where we saves the map generated by the game.
    
    int m_auto_save_id;
    // This describes whether the auto_save ability is turned on, and at the same time restores the index of the save file.
    // It's also used to describe the name of the save file.
    
    int m_cmd_lim;
    // This is the remaining limit of the cammands.
    
    bool m_running;
    
public:
    void cin_cmd();
    // This function is called to input the command to be processed next.
    
    void op_info();
    // This function handles the output of the information due to the command sent in.
    
    void process();
    // This function is called to process and update the situation of the game.
    // And it will bring about different results due to the variable m_cmd.
    // This is mainly be done in the seperated modules.
    
    void set_map();
    // This function generates and sets the map for the game.
    
    void set_bot();
    // This function sets the bot in the game.
    
    void op_map(std::string file_name = "save.bmp");
    // This method is called to draw and store the condition of the map.
    // It'll mainly be done in the file imgdraw.cpp.
    
    void auto_op_map();
    // This function automatically saves and outputs the condition of the map.
    
    int is_running(){return m_running;}
    // This describes whether the game is still running.
    
    void end_game(){m_running = 0;}
    // This method ends the game.
    
    Game(std::string path, int cmd_lim, Map * map = NULL, Bot * bot = NULL);
    // This function is called to generate the whole game process with the initial value of the related variables.
};


// MARK: Module Related Structures

#pragma pack(1)
// These struct sets the header of the output file.
struct BMPFileHeader{
    short id;
    int size;
    short res1;
    short res2;
    int offset;
};

struct BMPInfoHeader{
    int head_length;
    int pic_width;
    int pic_height;
    short surfaces;
    short depth;
    int archive_method;
    int pic_size;
    int res[4]; // These data will not be used in our program.
};
#pragma pack()

struct pix{
    // This struct is used to store the data of the pixel in the picture.
    unsigned char blue;
    unsigned char green;
    unsigned char red;
};

// MARK: Extended structures

class Ex_game : public Game{
    
protected:
    
    raylib::Window * main_window;
    
    raylib::Vector2 mouse_pos;
    
    raylib::Rectangle * ver_line_0;
    
    raylib::Rectangle * ver_line_1;
    
    raylib::Rectangle * hor_line_0;
    
    raylib::Rectangle * hor_line_1;
    
    raylib::Rectangle * game_space;
    
    raylib::Rectangle * help_background;
    
    raylib::Rectangle * dynamic_curser;
    bool text_selected;
    // This plays the role of a text curser.
    
    raylib::Color help_text_color;
    
    raylib::Color help_background_color;
    
    int help_index, start_index;
    
public:
    
    void ex_process();
    
    void grid_init();
    
    void draw_grid();
    
    void draw_text();
    
    int should_show_help(){return help_index % 2;}
    
    void show_help_window();
    
    int should_show_start_window(){return start_index % 2;}
    
    void show_start_window();
    
    void set_main_window(int width, int height, std::string title);
    
    raylib::Window * get_main_window(){return main_window;}
    
    Ex_game(std::string path, int cmd_lim, Map * map = NULL, Bot * bot = NULL);
    
    ~Ex_game(){
        delete main_window;
        delete ver_line_0;
        delete ver_line_1;
        delete hor_line_0;
        delete hor_line_1;
        delete help_background;
        delete dynamic_curser;
    };
};

#endif
