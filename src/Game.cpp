#include "Game.h"

Game::Game() {

    screenwidth = 800;
    screenheight = 600;

    InitWindow(screenwidth, screenheight, "SPACE INVADER GAME");
    SetTargetFPS(60);

    currentstate = MENU;

}

Game::~Game() {

    CloseWindow();
}

void Game::Run() {

    while(!WindowShouldClose()) {

        Update();

        Draw();
    }
}

Game::Update() {

    switch(currentstate) {

        case MENU: 

            if (IsKeyDown(KEY_ENTER)) {
                currentstate = PLAYING;
            }

        break;

        case PLAYING: 

            player.Update();
            
            if (IsKeyDown(KEY_P)) {

                currentstate = PAUSE;
            }

        break;
        
        case PAUSE:

            if (IsKeyDown(KEY_P)) {

                currentstate = PLAYING;
            }

            if (IsKeyDown(KEY_M)) {

                currentstate = MENU;
            }

        break;

        case GAMEOVER: 

            if (IsKeyDown(KEY_ENTER)) {

                currentstate = MENU;
            }

        break;


    }

}

void Game::Draw() {

    BeginDrawing();
        ClearBackground(BLACK);

        switch(currentstate) {

            case MENU: 

                DrawMenu();
            
            break;

            case PLAYING: 

                DrawGame();

            break;

            case PAUSE: 

                DrawPause();

            break;

            case GAMEOVER: 


            break;
        }

    EndDrawing();

}

void DrawMenu() {

    DrawText("SPACE INVADER", 200, 150, 40, GREEN);
    DrawText("PRESS PRESS ENTER TO START", 230, 300, 20, RAYWHITE);
}

void DrawGame() {

    player.Draw();

    DrawText("USE, LEFT OR RIGHT ARROW TO MOVE JET", 10, 10, 20, GRAY );

    DrawText("GAMEPLAY ACTIVE", 10, 10, 20, RED);
    DrawText("PRESS 'P' TO PAUSE", 10, 40, 20, GRAY);

}

void Game::DrawPause() {

    DrawGame();

    DrawRectangle( 0, 0, screenwidth, screenheight, Fade(BLACK, 0.5F));
    DrawText("PAUSED", 350, 250, 30, WHITE);
}