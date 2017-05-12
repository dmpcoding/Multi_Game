#include "game_selector.h"

void GameSelector::runLabyrinth(){

  if (start_clock) {
      start_clock = false;
      single.readMapFromFile("libraries/level_1");
      single.resetClock(true);
  }

  single.refresh();


}

void GameSelector::runGame(){

  switch (which_game) {
    case None:
      Menu();
      break;
    case Labirynth:
      runLabyrinth();
      break;
    case Pong:
      break;
  }

}

void GameSelector::Menu(){

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && *isKeyPressed) {
  int i = int(game_to_run) - 1;
  i = (i < 0) ? 1 : i;
  game_to_run = (Games)i;
}

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && *isKeyPressed) {
    int i = int(game_to_run) + 1;
    i = (i > 1) ? 0 : i;
    game_to_run = (Games)i;
}

for (int i = 0; i < options.size(); i++) {
    options[i].setFillColor(sf::Color::White);
}

options[(int)game_to_run].setFillColor(sf::Color::Cyan);

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && *isKeyPressed) {
  switch (game_to_run) {
    case Labirynth:
        which_game = Labirynth;
        start_clock = true;
        break;
    case Pong:
        which_game = Pong;
        break;

    };
  }

}

void GameSelector::setFont(sf::Font *f){
  font = f;
  single.setFont(font);
  for(int i = 0;i<options.size();i++)
    options[i].setFont(*font);
};

void GameSelector::setRnderWindow(sf::RenderWindow *window){
  game_window = window;
  single.setRnderWindow(window);
  options[0].setPosition((game_window->getSize().x-options[0].getGlobalBounds().width)/2,game_window->getSize().y/2);
  options[1].setPosition((game_window->getSize().x-options[1].getGlobalBounds().width)/2,options[0].getPosition().y+options[0].getGlobalBounds().height+10);
}

GameSelector::GameSelector(){

  start_clock = false;
  which_game = None;

  options[0].setString("Labirynth");
  options[1].setString("Pong");
  game_to_run = Labirynth;

}

void GameSelector::draw(sf::RenderTarget &target, sf::RenderStates states) const{

  switch (which_game){
    case None:
      for (sf::Text x: options)
        target.draw(x,states);
      break;
    case Labirynth:
      target.draw(single,states);
      break;
    case Pong:
      break;
  };

}
