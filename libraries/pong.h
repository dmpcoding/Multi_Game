#ifndef Pong_Class
#define Pong_Class

#include <SFML/Graphics.hpp>

class G_Pong: public sf::Drawable, public sf::Transformable{
private:
  sf::Clock clock;
  sf::Font *font;
  sf::RenderWindow *game_window;
  sf::RectangleShape pallet;
  sf::RectangleShape pallet2;

public:
  G_Pong();
  void setFont(sf::Font *f) { font = f;};
  void setRnderWindow(sf::RenderWindow *window) { game_window = window; };
  void draw(sf::RenderTarget &target,sf::RenderStates states) const;
  void resetClock() {clock.restart();};
  void refresh();


};

#endif
