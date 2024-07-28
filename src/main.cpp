#include "raylib.h"

#define RAYGUI_IMPLEMENTATION

#include "raygui.h"

typedef enum GameScreen {
    TITLE, GAMEPLAY
} GameScreen;

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Example");

    GameScreen currentScreen = TITLE;

    // Ball properties
    Vector2 ballPosition = {(float) screenWidth / 2, (float) screenHeight / 2};
    Vector2 ballSpeed = {5.0f, 4.0f};
    int ballRadius = 20;

    // Button properties
    Rectangle startButton = {screenWidth / 2 - 50, screenHeight / 2 - 25, 100, 50};

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        switch (currentScreen) {
            case TITLE:
                if (GuiButton(startButton, "START")) {
                    currentScreen = GAMEPLAY;
                }
                break;
            case GAMEPLAY:
                // Update ball position
                ballPosition.x += ballSpeed.x;
                ballPosition.y += ballSpeed.y;

                // Check wall collision
                if ((ballPosition.x >= (screenWidth - ballRadius)) || (ballPosition.x <= ballRadius))
                    ballSpeed.x *= -1.0f;
                if ((ballPosition.y >= (screenHeight - ballRadius)) || (ballPosition.y <= ballRadius))
                    ballSpeed.y *= -1.0f;
                break;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentScreen) {
            case TITLE:
                DrawText("Bouncing Ball Game", 20, 20, 40, DARKGRAY);
                GuiButton(startButton, "START");
                break;
            case GAMEPLAY:
                DrawCircleV(ballPosition, ballRadius, MAROON);
                break;
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}