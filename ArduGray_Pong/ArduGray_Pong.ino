#define ABG_IMPLEMENTATION
#include "vars.h"
#include "common.hpp"
ArduboyG_Config<ABG_Mode::L4_Triplane> arduboy;

uint8_t buzzer =5;
uint8_t gamestate = 0;
Player player = {0, 0, 0};
Ball ball = {WIDTH / 2 - BALL_SIZE, HEIGHT / 2 - BALL_SIZE, true, true, false, WHITE};
CurrentScreen screen = { CurrentScreen::Title };
Opponent oppo {WIDTH-BOX_WIDTH, 0, 0 };
void loop()
{
    arduboy.waitForNextPlane();
    if(arduboy.needsUpdate())
        update();
    render();
}

void setup()
{  
    arduboy.boot();
    arduboy.startGray();
}
