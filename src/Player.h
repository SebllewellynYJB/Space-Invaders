#ifndef SPACEINVADERSSFML_PLAYER_H
#define SPACEINVADERSSFML_PLAYER_H

#include "GameObject.h"

class Player : public GameObject
{
 public:
  // Player speed details
  Vector2 ship_direction = {0,0};
 private:
};

#endif // SPACEINVADERSSFML_PLAYER_H
