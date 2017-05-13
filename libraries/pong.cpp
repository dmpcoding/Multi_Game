#include "pong.h"

void G_Pong::draw(sf::RenderTarget &target, sf::RenderStates states) const{

  target.draw(pallet,states);
  sf::Time time = clock.getElapsedTime();
  int m = time.asSeconds() / 60;
  int s = int(time.asSeconds()) % 60;
  sf::Text textTime(std::to_string(m) + ":" + std::to_string(s), *font, 16);
  textTime.setPosition(game_window->getSize().x - textTime.getGlobalBounds().width, 0);
  target.draw(textTime, states);

}

G_Pong::G_Pong(){

pallet.setFillColor(sf::Color::White);
pallet.setSize(sf::Vector2f{10,50});

}

void G_Pong::refresh(){

double speed = 0.2;

sf::RectangleShape test = pallet;

if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
  test.move(0,speed);
}

if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
	test.move(0,-speed);
}

bool off_the_screen = (test.getPosition().y >= 0
                       && test.getPosition().y < game_window->getSize().y - test.getGlobalBounds().height);

if (off_the_screen)
  pallet = test;

}
