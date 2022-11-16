// Here is the definition of data structures used in our project.

#ifndef _STRUCTURES_IS_DEFINED_
#define _STRUCTURES_IS_DEFINED_
// These pro-compilation instructions are used to avoid redefinition of the structures below.

#include "const.h"
#include <string>

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

class Bot{
    // This is the class of the bot we can control.
private:
    Position m_pos;
    Direction m_dir;
    // These are the private variables of the class Bot, They can't be changed directly without using the methods below.
public:
    void move_up(){m_pos.y += 1;}
    void move_down(){m_pos.y -= 1;}
    void move_right(){m_pos.x += 1;}
    void move_left(){m_pos.x -= 1;}
    void jump_up(){m_pos.h += 1;}
    void jump_down(){m_pos.h -= 1;}
    // We can call these methods to change the position of the bot.
    
    void turn(enum Direction d){m_dir = d;}
    // we can call this method to change the direction of the bot.
    
    Bot(Position & pos, Direction dir);
    // This function is used to construct an example of bot using the initial value of its position and its direction.
    ~Bot();
};

class Map{
    // This is the class of the map in our game.
private:
    std::string m_name;
    // This is the name of the map.
    
    Cell * m_cells;
    // These are the cells on the map, which at most counts 100 rows and 100 columns.
    
    int m_row, m_col;
    // These are the rows and columns actually used in the exact map.
    
    Light * m_lights;
    // This is the list of the lights on the map.
    
    int m_light_count;
    // This is the number of lights still remains on the map.
    
public:
    void Light_lit(Position & pos){}
    // This function is called when the player uses the "LIT" command.
    // This will light the light at that position, and decreases the light_count by 1.
    
    int is_cleared(){return m_light_count;}
    // This function is used to judge whether the lights in the map are all lit up. Its return value is used as the type bool.
    
    Map(Cell * cells, Light * lights, int light_count, std::string name);
    // This function is used to construct the map of the game using the initial values of the related variables.
    
    ~Map();
};

class Game{
    // This is the class of the whole game process.
private:
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
    
    int m_cmd_lim;
    // This is the remaining limit of the cammands.
    
public:
    void cin_cmd(){}
    // This function is called to input the command to be processed next.
    
    void process(){}
    // This function is called to process and update the situation of the game.
    // And it will bring about different results due to the variable m_cmd.
    // This is mainly be done in the seperated modules.
    
    void op_map(){}
    // This method is called to draw and store the condition of the map.
    // It'll mainly be done in the file imgdraw.cpp.
    
    Game(Map * map, Bot * bot, std::string path, int cmd_lim);
    // This function is called to generate the whole game process with the initial value of the related variables.
    
    ~Game();
};

Game::Game(Map * map, Bot * bot, std::string path, int cmd_lim){
    m_map = map;
    m_bot = bot;
    m_path = path;
    m_cmd_lim = cmd_lim;
}

Map::Map(Cell * cells, Light * lights, int light_count, std::string name){
    m_cells = cells;
    m_lights = lights;
    m_light_count = light_count;
    m_name = name;
}

Bot::Bot(Position & pos, Direction dir){
    m_pos = pos;
    m_dir = dir;
}

#endif
