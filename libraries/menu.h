#ifndef Menu_Class
#define Menu_Class

#include <iostream>
#include <array>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "game.h"

class Menu : public sf::Drawable, public sf::Transformable {
private:
  sf::Font font;
  sf::RenderWindow *game_window;
  bool *isKeyPressed;
  enum options_in_menu { single_player = 0, options, quit, menu };
  options_in_menu select_option;
  options_in_menu run;
  std::array<sf::Text, 3> menu_options;
  void Display();
  void Game();
  void Options();
  P_Game single;
  std::ifstream file;
  map_element_value value;
  bool start_clock;

public:
  Menu(sf::RenderWindow *window, bool *keyPressed);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void refresh();
};

#endif // Menu_Class
