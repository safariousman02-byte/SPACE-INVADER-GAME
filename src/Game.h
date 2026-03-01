#ifndef GAME_H
#define GAME.H

#include "raylib.h"

enum GameState {
    MENU,
    PLAYING,
    PAUSE,
    GAMEOVER
};

class Game {

    public:
        Game();
        ~Game();

        void Run();

    private:

        void Update();
        void Draw();

        void DrawMenu();
        void DrawGame();
        void DrawPause();

        GameState currentstate;
        int screenwidth;
        int screenheight;

};

#endif