#ifndef Game_Selector
#define Game_Selector

#include "game.h"
#include "pong.h"

class GameSelector: public sf::Drawable, public sf::Transformable{

enum Games{Labirynth = 0,Pong,None};

private:
  sf::Font *font;
  bool *isKeyPressed;
  P_Game labirynth;
  G_Pong pong;
  bool start_clock;
  sf::RenderWindow *game_window;
  Games which_game;
  Games game_to_run;
  void runLabyrinth();
  void runPong();
  void Menu();

public:
  GameSelector();
  void runGame();
  void setFont(sf::Font *f);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void setRnderWindow(sf::RenderWindow *window);
  void setKeyPressed(bool *keyPressed){ isKeyPressed = keyPressed; };
  std::array<sf::Text,2> options;
  void reset(){ which_game = None; };


};

#endif
