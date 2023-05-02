#include "Enemy.h"
//Visibility information
bool Enemy::isVisible() const
{
  return is_visible;
}

void Enemy::setIsVisible(bool isVisible)
{
  is_visible= isVisible;
}