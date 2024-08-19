#pragma once 
#define BOX_HEIGHT 12
#define BOX_WIDTH 4
#define BALL_SIZE 2
struct Ball {
  int8_t x;
  int8_t y;
  bool right;
  bool down;
  bool up;
  uint8_t color;
};

struct Player {
  uint8_t x;
  uint8_t y;
  uint8_t score;
};

struct Opponent {
  uint8_t x;
  uint8_t y;
  uint8_t score;
  
};
extern uint8_t buzzer;
extern uint8_t gamestate;

enum class CurrentScreen : uint8_t {
  Title,
  Game,
  Gameover,
  Win
};

extern Ball ball;
extern CurrentScreen screen;
extern Player player;
extern Opponent oppo;