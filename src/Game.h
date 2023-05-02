#ifndef SPACEINVADERS_GAME_H
#define SPACEINVADERS_GAME_H

#include "Enemy.h"
#include "GameObject.h"
#include "Player.h"
#include "Vector2.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  // Functions
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  bool collision(GameObject & object);
  bool CO(GameObject p, GameObject e);
  // Game Objects
  GameObject e;
  sf::Texture e_t;
  GameObject player;
  sf::Texture player_texture;
  Player ship;
  sf::Texture ship_texture;
  int no_of_enemies = 5;
  Enemy enemy[25];
  sf::Texture enemy_texture;
  int no_of_shots = 5;
  int current_shot_number = 0;
  GameObject lasers[5];
  sf::Texture lasers_texture;
 private:
  sf::FloatRect boundingbox = player.getSprite()->getGlobalBounds();
  sf::FloatRect otherbox = e.getSprite()->getGlobalBounds();
  bool C(GameObject laser, GameObject e);
  sf::RenderWindow& window;
  // Menu information
  sf::Font font;
  sf::Text title_text;
  bool play_selected = true;
  bool in_menu;
  sf::Text play;
  sf::Text quit;
  sf::Text quitany;
  sf::Text instructions;
  sf::Text shipi;
  sf::Text menui;
  // Game screen information
  sf::Sprite gameb;
  sf::Texture game_background;
  sf::Music music;

};

#endif // SPACEINVADERS_GAME_H
