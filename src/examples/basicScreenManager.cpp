#include "axle.h"

namespace Axle::Examples
{

    void basicScreenManager()
    {
        enum class GameScreen
        {
            LOGO,
            TITLE,
            GAMEPLAY,
            ENDING
        };

        Axle::Window window(850, 400, "Axle example - basic screen manager");
        window.setTargetFPS(60);

        GameScreen currentScreen = GameScreen::LOGO;
        int frameCounter = 0;

        Axle::Rectangle rec1(850 / 2, 400 / 2, 830, 380);
        rec1.color.setColor(Axle::ColorPreset::COLOR_LIGHTGRAY);

        while (!window.shouldClose())
        {

            // UPDATE
            switch (currentScreen)
            {
            case GameScreen::LOGO:
            {
                frameCounter++;
                if (frameCounter > 120) // 2 Seconds
                {
                    currentScreen = GameScreen::TITLE;
                    frameCounter = 0;
                    rec1.color.setColor(Axle::ColorPreset::COLOR_BROWN);
                }
                break;
            }
            case GameScreen::TITLE:
            {
                // Press ENTER to change to GAMEPLAY screen
                break;
            }
            case GameScreen::GAMEPLAY:
            {
                // Press ENTER to change to ENDING screen
                break;
            }
            case GameScreen::ENDING:
            {
                // Press ENTER to return to TITLE screen
                break;
            }
            }

            // DRAW
            window.beginDrawing();
            window.clearBackground(Axle::ColorPreset::COLOR_WHITE);

            switch (currentScreen)
            {
            case GameScreen::LOGO:
            {
                // window.drawRectangle(0, 0, window.getWidth(), window.getHeight(), Axle::ColorPreset::LIGHTGRAY);
                rec1.Draw();
                window.drawText("LOGO SCREEN", 20, 20, 40, Axle::ColorPreset::COLOR_DARKGRAY);
                break;
            }
            case GameScreen::TITLE:
            {
                // window.drawRectangle(0, 0, window.getWidth(), window.getHeight(), Axle::ColorPreset::GRAY);
                rec1.Draw();
                window.drawText("TITLE SCREEN", 20, 20, 40, Axle::ColorPreset::COLOR_DARKGRAY);
                break;
            }
            case GameScreen::GAMEPLAY:
            {
                // window.drawRectangle(0, 0, window.getWidth(), window.getHeight(), Axle::ColorPreset::DARKGRAY);
                rec1.Draw();
                window.drawText("GAMEPLAY SCREEN", 20, 20, 40, Axle::ColorPreset::COLOR_DARKGRAY);
                break;
            }
            case GameScreen::ENDING:
            {
                // window.drawRectangle(0, 0, window.getWidth(), window.getHeight(), Axle::ColorPreset::BLACK);
                rec1.Draw();
                window.drawText("ENDING SCREEN", 20, 20, 40, Axle::ColorPreset::COLOR_DARKGRAY);
                break;
            }
            }

            window.endDrawing();
        }
        window.close();
    }
} // namespace Axle::Examples
