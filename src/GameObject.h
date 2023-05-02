#ifndef SPACEINVADERS_GAMEOBJECT_H
#define SPACEINVADERS_GAMEOBJECT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include "Vector2.h"

class GameObject
{
 public:
  bool isVisible() const;
  void setIsVisible(bool isVisible);
  //Game object functions
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();
  // Getters and Setters for speed and direction
  int getSpeed() const;
  void setSpeed(int speed);
  const Vector2& getDirection() const;
  void setDirection(const Vector2& direction);
  Vector2 laser_direction = {0,0};

 protected:
  sf::Sprite* sprite = nullptr;
 private:
  bool is_visible = true;
  // Practice speed and Vector movement details
  int speed = 200;
  Vector2 direction{0,0};
};

#endif // SPACEINVADERS_GAMEOBJECT_H