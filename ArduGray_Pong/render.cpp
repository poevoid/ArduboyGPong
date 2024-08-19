#define SPRITESU_IMPLEMENTATION
#include "common.hpp"
#include "vars.h"
void render() {
  switch (screen) {
    case CurrentScreen::Title:
      arduboy.setCursor(50, 24);
      arduboy.setTextColor(DARK_GRAY);
      arduboy.print(F("PONG!"));
      //SpritesU::fillRect_i8(ball.x, ball.y, BALL_SIZE, BALL_SIZE, arduboy.color(WHITE));

      break;

    case CurrentScreen::Game:
      arduboy.setTextColor(WHITE);
      arduboy.setCursor(20, 0);
      arduboy.print(player.score);
      arduboy.setCursor(100, 0);
      arduboy.print(oppo.score);
      for (int i=0; i <HEIGHT; i+=8){
        arduboy.drawFastVLine(WIDTH/2, i, 4, DARK_GRAY);
      };
      //SpritesU::fillRect_i8(ball.x, ball.y, BALL_SIZE, BALL_SIZE, arduboy.color(WHITE));
      SpritesU::fillRect_i8(player.x, player.y, BOX_WIDTH, BOX_HEIGHT, arduboy.color(DARK_GRAY));
      SpritesU::fillRect_i8(oppo.x, oppo.y, BOX_WIDTH, BOX_HEIGHT, arduboy.color(DARK_GRAY));

      
      break;

    case CurrentScreen::Gameover:
      arduboy.setCursor(0, 0);
      
      arduboy.setTextColor(LIGHT_GRAY);
      arduboy.print("HAHA! \nI WIN, \nLOSER!");
      break;

    case CurrentScreen::Win:
      arduboy.setCursor(5, 24);
      arduboy.setTextColor(LIGHT_GRAY);
      arduboy.print("YOU FUCKIN DID IT,\n      CHAMP!!");
      
      //SpritesU::fillRect_i8(ball.x, ball.y, BALL_SIZE, BALL_SIZE, arduboy.color(WHITE));
      break;
  }
  
    SpritesU::fillRect_i8(ball.x, ball.y, BALL_SIZE, BALL_SIZE, arduboy.color(WHITE));
}
