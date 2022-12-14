// Here we'll define the constructors of the classes defined in struct.h

#include "struct.h"

Game::Game(std::string path, int cmd_lim, Map *map, Bot *bot) {
    m_map     = map;
    m_bot     = bot;
    m_path    = path;
    m_cmd_lim = cmd_lim;
    m_running = true;
}

Ex_game::Ex_game(std::string path, int cmd_lim, Map *map, Bot *bot)
    : Game(path, cmd_lim, map, bot) {
    moving_index   = 0;
    jumping_index  = 0;
    lighting_index = 0;
}

Map::Map(Cell *cells, Light *lights, int cell_count, int light_count,
         std::string name) {
    m_cells       = cells;
    m_lights      = lights;
    m_cell_count  = cell_count;
    m_light_count = light_count;
    m_name        = name;
}

Bot::Bot(Position &pos, Direction dir) {
    m_pos = pos;
    m_dir = dir;
}
