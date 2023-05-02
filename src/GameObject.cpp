#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
  sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
  if (sprite != nullptr)
  {
    delete sprite;
    sprite = nullptr;
  }
}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if (!texture.loadFromFile(filename))
  {
    std::cout  <<"texture did not load";
  }
  sprite->setTexture(texture);
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}
const Vector2& GameObject::getDirection() const
{
  return direction;
}
void GameObject::setDirection(const Vector2& direction)
{
  GameObject::direction = direction;
}
int GameObject::getSpeed() const
{
  return speed;
}
void GameObject::setSpeed(int speed)
{
  GameObject::speed = speed;
}
bool GameObject::isVisible() const
{
  return is_visible;
}

void GameObject::setIsVisible(bool isVisible)
{
  is_visible= isVisible;
}