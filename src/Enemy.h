#ifndef SPACEINVADERSSFML_ENEMY_H
#define SPACEINVADERSSFML_ENEMY_H
#include "GameObject.h"

class Enemy : public GameObject
{
 public:
  bool isVisible() const;
  void setIsVisible(bool isVisible);
 private:
  bool is_visible = true;
};

#endif // SPACEINVADERSSFML_ENEMY_H
