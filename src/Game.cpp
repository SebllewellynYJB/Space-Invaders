#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  //Menu information
  in_menu = true;
  //Font information
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  // Background load information
  if (game_background.loadFromFile("Data/Images/SpaceShooterRedux/Backgrounds/darkPurple.png"))
  {
    std::cout << "background did not load\n";
  }
  gameb.setTexture(game_background);
  gameb.setScale(5,4);

  // Menu text information
  title_text.setString("Space Invaders");
  title_text.setFont(font);
  title_text.setCharacterSize(70);
  title_text.setFillColor(sf::Color(255,0,0));
  title_text.setPosition(275,0);

  play.setString("Play");
  play.setFont(font);
  play.setCharacterSize(40);
  play.setFillColor(sf::Color(0, 100, 0));
  play.setPosition(360,200);

  quit.setString("Quit");
  quit.setFont(font);
  quit.setCharacterSize(40);
  quit.setFillColor(sf::Color(100, 0, 0));
  quit.setPosition(560,200);

  menui.setString("Use left and right arrows to navigate menu, press enter to move on");
  menui.setFont(font);
  menui.setCharacterSize(20);
  menui.setFillColor(sf::Color(200,200,200));
  menui.setPosition(10,350);

  quitany.setString("Press Q to quit at any time");
  quitany.setFont(font);
  quitany.setCharacterSize(20);
  quitany.setFillColor(sf::Color(100,0,200));
  quitany.setPosition(10,400);

  instructions.setString("How to play");
  instructions.setFont(font);
  instructions.setCharacterSize(40);
  instructions.setFillColor(sf::Color(200,50,20));
  instructions.setPosition(10,275);

  shipi.setString("Ship- Left to move left, Right to move right , Space to shoot");
  shipi.setFont(font);
  shipi.setCharacterSize(20);
  shipi.setFillColor(sf::Color(0,0,200));
  shipi.setPosition(10,450);

  //Game objects information
  // Loads Player texture, sets position and sets speed
  ship.initialiseSprite(ship_texture, "Data/Images/SpaceShooterRedux/PNG/playerShip1_blue.png");
  ship.getSprite()->setPosition(440,650);
  ship.setSpeed(200);

  // Loads Enemy array texture, sets position, creates grid , sets scale and sets speed, direction and visibility
  for (int i = 0; i < no_of_enemies; i++)
  {
    for (int j = 0; j < no_of_enemies; j++)
    {
      enemy[i * no_of_enemies + j].initialiseSprite(enemy_texture , "Data/Images/SpaceShooterRedux/PNG/Enemies/enemyBlack1.png");
      enemy[i * no_of_enemies + j].getSprite()->setScale(
        64 / enemy[i * no_of_enemies + j].getSprite()->getGlobalBounds().width,
        64 / enemy[i * no_of_enemies + j].getSprite()->getGlobalBounds().height);
      enemy[i * no_of_enemies + j].getSprite()->setPosition(300 + 75 * i, 50 + 75 * j);
      enemy[i * no_of_enemies + j].setSpeed(100);
      enemy[i * no_of_enemies + j].setDirection(Vector2{1,0});
    }
  }
  // Sets these numbers in the array to false
  enemy[3].setIsVisible(false);
  enemy[15].setIsVisible(false);

  player.initialiseSprite(player_texture , "Data/Images/SpaceShooterRedux/PNG/playerShip2_red.png");
  player.getSprite()->setPosition(500,500);
  player.setSpeed(200);
  player.setDirection(Vector2{1,0});

  // Loads Laser texture, sets position , scale and sets speed and visibility
  for (int i = 0; i < no_of_shots; i++)
  {
    lasers[i].initialiseSprite(lasers_texture , "Data/Images/SpaceShooterRedux/PNG/Lasers/laserBlue01.png");
    lasers[i].initialiseSprite(lasers_texture, "Data/Images/SpaceShooterRedux/PNG/Lasers/laserBlue02.png");
    lasers[i].getSprite()->setPosition( 530, 500 + 75 * i);
    lasers[i].getSprite()->setScale(0.5,0.5);
    //lasers[i].getSprite()->setPosition(ship.getSprite()->getPosition().x,600 * i);
    lasers[i].setSpeed(200);
    lasers[i].setIsVisible(false);
  }

    e.initialiseSprite(e_t , "Data/Images/SpaceShooterRedux/PNG/playerShip1_blue.png");
    e.getSprite()->setTexture(e_t);
    e.getSprite()->setPosition(500,500);
    e.getSprite()->setScale(0.5,0.5);

    // Plays music on load
  if(!music.openFromFile("Data/641413__victor_natas__another-dimension (1).wav"))
  {
    std::cout << "Music did not load\n";
  }
  music.play();
  music.setVolume(10);

  return true;
}

void Game::update(float dt)
{
  //if (CO(player,e))
  {
    e.setIsVisible(false);
  }
  for (int i = 0; i < no_of_shots; i++)
  {
    //if (C(lasers[i] , e))
    {
      //e.setIsVisible(false);
    }
  }
  for (int i = 0; i < no_of_enemies; i++)
  {
    for (int j = 0; j < no_of_enemies; j++)
    {
      collision(enemy[i * no_of_enemies + j]);
    }
  }
  // Moves Lasers every frame
  for (int i = 0; i < no_of_shots; i++)
  {
    lasers[i].getSprite()->move(0,lasers[i].laser_direction.y*lasers[i].getSpeed()*dt);
  }
  //player.getSprite()->move(player.getSpeed()*player.getDirection().x *dt,0);
  // Moves Player every frame
  ship.getSprite()->move(ship.ship_direction.x * ship.getSpeed() * dt, ship.ship_direction.y * ship.getSpeed() * dt);
  // Moves enemy array every frame
  for (int i = 0; i < no_of_enemies * no_of_enemies; i++)
  {
   enemy[i].getSprite()->move(enemy[i].getSpeed()*enemy[i].getDirection().x* dt, enemy[i].getSpeed()*enemy[i].getDirection().y* dt);
  }
}

void Game::render()
{
  // Renders menu
  if (in_menu)
  // Text that is rendered to the menu
  {
    window.draw(title_text);
    window.draw(play);
    window.draw(quit);
    window.draw(menui);
    window.draw(quitany);
    window.draw(instructions);
    window.draw(shipi);
  }
  else
  {
    //window.draw(*e.getSprite());
    window.draw(gameb);
    // Renders Player
    window.draw(*ship.getSprite());
    //window.draw(*player.getSprite());
    // Renders Lasers
    for (int i = 0; i < no_of_shots; i++)
    {
      if (lasers[i].isVisible())
      {
        window.draw(*lasers[i].getSprite());
      }
    }
    // Renders Enemy array
    for (int i = 0; i < no_of_enemies * no_of_enemies; i++)
    {
      if (enemy[i].isVisible())
      {
        window.draw(*enemy[i].getSprite());
      }
    }
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
}

void Game::keyPressed(sf::Event event)
{
  // menu keys for play and quit
  if ((event.key.code == sf::Keyboard::Left) ||
    (event.key.code == sf::Keyboard::Right))
  {
    play_selected = !play_selected;
    if (play_selected)
    {
      play.setString("> Play <");
      quit.setString("Quit");
    }
    else
    {
      play.setString("Play");
      quit.setString("> Quit <");
    }
  }
  // Menu keys for loading next screen
  else if (event.key.code == sf::Keyboard::Enter)
  {
    if (play_selected)
    {
      in_menu = false;
    }
    else
    {
      window.close();
    }
  }
  // Keys to close menu
  if (event.key.code == sf::Keyboard::Q)
  {
    window.close();
  }
  //Key details for ship movement in X axis
  if (event.key.code == sf::Keyboard::Left)
  {
    ship.ship_direction.x = -1;
  }
  else if (event.key.code == sf::Keyboard::Right)
  {
    ship.ship_direction.x = 1;
  }
  // Key details for Shooting in Y axis
  for (int i = 0; i < no_of_shots; i++)
  {
    if (event.key.code == sf::Keyboard::Space)
    {
      lasers[i].laser_direction.x = 0;
      lasers[i].laser_direction.y = -1;
      //lasers->laser_direction.y = -1;
      // Sets the lasers visible when key is pressed
      lasers[i].setIsVisible(true);
    }
  }

}
void Game::keyReleased(sf::Event event)
{
  //Key details for ship movement in X axis
  if ((event.key.code == sf::Keyboard::Left)||
      (event.key.code == sf::Keyboard::Right))
  {
    ship.ship_direction.x = 0;
    ship.ship_direction.y = 0;
  }
  // Key details for laser movement in Y axis
  for (int i = 0; i < no_of_shots; i++)
  {
    if (event.key.code == sf::Keyboard::Space)
    {
      // Keeps laser moving when key is released
      lasers[i].laser_direction.y = -1;
      //lasers->laser_direction.y = -1;
    }
  }
}
bool Game::collision(GameObject& object)
// Enemy array wall collision
{
  for (int i = 0; i < no_of_enemies; i++)
  {
    for (int j = 0; j < no_of_enemies; j++)
    {
      if ((object.getSprite()->getPosition().x < 0)||
          (object.getSprite()->getPosition().x + object.getSprite()->getGlobalBounds().width > window.getSize().x))
      {
        // Reverses enemy array back in the other direction
        object.setDirection(Vector2(-object.getDirection().x ,0));
        return true;
      }
      }
    }
}
bool Game::C(GameObject lasers, GameObject e)
{
  for (int i = 0; i < no_of_shots; i++)
  {
    if (lasers.getSprite()->getGlobalBounds().intersects(e.getSprite()->getGlobalBounds()))
    {
      std::cout << "Collision\n";
    }
    else
    {
      std::cout << "No Collision\n";
    }
  }
}
bool Game::CO(GameObject player, GameObject e)
{
  if (boundingbox.intersects(otherbox))
  {
    std::cout << "Collision\n";
  }
  return false;
}