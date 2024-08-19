#include <stdint.h>
#pragma once

#define ABG_TIMER4
//#define ABG_SYNC_PARK_ROW
#define ABG_PLANE_CONTRAST

#include "ArduboyG.h"

extern ArduboyG_Config<ABG_Mode::L4_Triplane> arduboy;
#define SPRITESU_OVERWRITE
#define SPRITESU_PLUSMASK
#define SPRITESU_RECT

#include "SpritesU.hpp"

extern uint8_t ox;
extern uint8_t oy;

void update();
void render();
