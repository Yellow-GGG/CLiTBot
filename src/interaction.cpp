// This is the module that interacts with the user.

#include "const.h"
#include "struct.h"
#include <fstream>
#include <iostream>

// MARK: Standard features

void Game::cin_cmd() {
    // This function handles the interaction with the player.
    // It recieves the command and send it to the process method.
    std::cout << "请输入下一步指令" << std::endl;
    std::cin >> m_cmd;

    return;
}

void Game::show_help() {

    char         buff[1024];
    std::fstream text;
    
    std::cout << std::endl;
    
    for (int i = 0; i < 11; i++) {
        std::cout << "---";
    }
    std::cout << std::endl;
    text.open("../maps/help_cli.txt");

    while (text.getline(buff, sizeof(buff))) {
        std::cout << buff << std::endl;
    }
    
    for (int i = 0; i < 11; i++) {
        std::cout << "---";
    }
    std::cout << std::endl << std::endl;
    text.close();

    return;
}

void Game::op_info() {
    // This function handles the output of the information due to the command
    // sent in.

    return;
}

// MARK: Extended features

void Ex_game::show_help_window() {

    help_text->Draw(cst::game_view_pos.GetX() + 8.0f,
                    cst::game_view_pos.GetY() + 5.0f);

    return;
}

void Ex_game::show_start_window() {

    DrawText(TextSubtext(cst::start_message, 0, frame_count / 4), 340, 190, 26,
             cst::textcolor);

    return;
}
