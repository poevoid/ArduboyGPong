#include "common.hpp"
#include "vars.h"
static bool dir;
uint8_t ox;
uint8_t oy;


void resetGame() {
  player.score = 0;
  oppo.score = 0;
  player.y = HEIGHT / 2 - BOX_HEIGHT;
  ball.x = 64;
  ball.right = false;
}

void bip() {
  tone(buzzer, 988, 20);
}
void beep() {
  tone(buzzer, 880, 20);
}
void boop() {
  tone(buzzer, 784, 40);
}
void ding() {
  tone(buzzer, 1175, 60);
}

void update() {
  uint8_t b = arduboy.buttonsState();
  if (ball.right) {
    ball.x++;
  } else {
    ball.x--;
  }
  if (ball.down) {
    ball.y++;
  }
  if (ball.up) {
    ball.y--;
  }
  if (ball.y == 0) {
    ball.down = true;
    ball.up = false;
    /*if (random(0,3)==1){
          ball.right=true;
        } else {ball.right=false;}*/
  }
  if (ball.y == HEIGHT - BALL_SIZE) {
    ball.down = false;
    ball.up = true;
    /*if (random(0,3)==1){
          ball.right=true;
        }
        else {ball.right=false;}*/
  }

  switch (screen) {
    case CurrentScreen::Title:

      if (ball.x == 0) {
        ball.right = true;
      }
      if (ball.x == WIDTH - BALL_SIZE) {
        ball.right = false;
      }
      if (b & A_BUTTON || b & B_BUTTON) {
        screen = CurrentScreen::Game;
      }
      break;

    case CurrentScreen::Game:

      //-----player bounds-----------|
      if (player.y > HEIGHT - BOX_HEIGHT) {  //|
        player.y = HEIGHT - BOX_HEIGHT;      //|
      }                                      //|
      if (player.y < 0) {                    //|
        player.y = 0;                        //|
      }                                      //|
      //---------------------------//|
      if (player.y > 0 && (b & UP_BUTTON)) --player.y;
      if (player.y < 64 && (b & DOWN_BUTTON)) ++player.y;
      //-------paddle physics/bounds--------|
      if (ball.x == player.x + BOX_WIDTH && player.y < ball.y + BALL_SIZE && player.y + BOX_HEIGHT > ball.y) {
        bip();
        if (player.y + BOX_HEIGHT / 2 == ball.y + BALL_SIZE / 2) {  //if player hits dead center
          ball.down = false;
          ball.up = false;
        }
        if (player.y + BOX_HEIGHT / 2 > ball.y + BALL_SIZE / 2) {
          ball.down = false;
          ball.up = true;
        }
        if (player.y + BOX_HEIGHT / 2 < ball.y + BALL_SIZE / 2) {
          ball.up = false;
          ball.down = true;
        }

        ball.right = true;

      }  //if player paddle touches the ball, change directions



      if (ball.x + BALL_SIZE == oppo.x && oppo.y < ball.y + BALL_SIZE && oppo.y + BOX_HEIGHT > ball.y) {
        beep();

        if (oppo.y + BOX_HEIGHT / 2 == ball.y + BALL_SIZE / 2) {
          ball.down = false;
          ball.up = false;
        }
        if (oppo.y + BOX_HEIGHT / 2 > ball.y + BALL_SIZE / 2) {
          ball.down = false;
          ball.up = true;
        }
        if (oppo.y + BOX_HEIGHT / 2 < ball.y + BALL_SIZE / 2) {
          ball.down = true;
          ball.up = false;
        }

        ball.right = false;



      }  //if opponent touches the ball, change directions

      if (ball.x + BALL_SIZE <= 0) {
        oppo.score++;
        ball.x = WIDTH / 2 - BALL_SIZE;
        boop();
      }
      if (ball.x >= WIDTH - BALL_SIZE) {
        player.score++;
        ball.x = WIDTH / 2 - BALL_SIZE;
        beep();
        delay(18);
        bip();
        delay(18);
        beep();
        delay(18);
        bip();
        delay(25);
        ding();
      }
      if (oppo.score == 11) {
        boop();
        delay(30);
        tone(buzzer, 698, 60);
        delay(30);
        tone(buzzer, 587, 60);
        delay(30);
        tone(buzzer, 554, 70);
        delay(30);
        screen = CurrentScreen::Gameover;
      }
      if (player.score == 11) {
        ding();
        delay(30);
        tone(buzzer, 880, 60);
        delay(30);
        ding();
        delay(30);
        tone(buzzer, 1397, 60);
        delay(30);
        tone(buzzer, 1568, 60);
        delay(30);
        screen = CurrentScreen::Win;
      }
      //-------------------------------------------------|


      //-----------Opponent "AI" --------------------|
      if (ball.x > 100 || random(0, 20) == 1) {
        if (ball.y < oppo.y || random(0, 20) == 8 && oppo.y > 1)
          oppo.y--;
        if (ball.y + BALL_SIZE > oppo.y + BOX_HEIGHT && oppo.y < HEIGHT - BOX_HEIGHT || random(0, 20) == 7 && oppo.y < HEIGHT - BOX_HEIGHT)
          oppo.y++;
      }
      //---------------------------------------------|
      break;

    case CurrentScreen::Gameover:
      if (ball.x == 0) {
        ball.right = true;
      }
      if (ball.x == WIDTH - BALL_SIZE) {
        ball.right = false;
      }
      

      if (b & A_BUTTON || b & B_BUTTON) {
        resetGame();screen = CurrentScreen::Title;
      }
      break;

    case CurrentScreen::Win:
      if (ball.x == 0) {
        ball.right = true;
      }
      if (ball.x == WIDTH - BALL_SIZE) {
        ball.right = false;
      }
      
      if (b & A_BUTTON || b & B_BUTTON) {
        resetGame();screen = CurrentScreen::Game;
      }
      break;
  }
  /*
  if (player.x > 0 && (b & LEFT_BUTTON)) --player.x;
  if (player.y > 0 && (b & UP_BUTTON)) --player.y;
  if (player.x < 128 && (b & RIGHT_BUTTON)) ++player.x;
  if (player.y < 64 && (b & DOWN_BUTTON)) ++player.y;*/
}
