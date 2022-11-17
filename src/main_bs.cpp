// this is the basic version of the project which only fulfills the least tasks of the whole project.


#include "struct.h"
#include "imgdraw.cpp"
#include "runtime.cpp"
#include "interaction.cpp"

int main_bs(){
    // This is the entrance of the standard version of the game, and will be called in main.cpp.
    
    Game game;
    
    while(game.is_running()){
        game.cin_cmd();
        game.process();
    }
    
    
    return 0;
}
