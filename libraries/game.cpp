#include "game.h"
void P_Game::draw(sf::RenderTarget& target,sf::RenderStates states)const{

	for(sf::RectangleShape x: game_map)
		target.draw(x,states);

	target.draw(player,states);

}

P_Game::P_Game(){

    player.setRadius(10);
    player.setFillColor(sf::Color::Red);
		player.setPosition(0,15);

}

void P_Game::refresh(){

	sf::CircleShape test = player;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		test.move(0.1,0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		test.move(0,0.1);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		test.move(-0.1,0);
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		test.move(0,-0.1);
	}

	bool off_the_screen = (test.getPosition().x > 0 &&
	test.getPosition().y > 0 && test.getPosition().x < 480
  && test.getPosition().y < 480);

	if(off_the_screen){

		bool collision = false;

			for(int i = 0;i < game_map.size()&&!collision;i++)
				collision = game_map[i].getGlobalBounds().intersects(
					test.getGlobalBounds());

					if(collision == false){
						player = test;
					}
	}

}

void P_Game::setUpMap(int i,int x,int y,int w,int h,int r){

	game_map[i].setPosition(x,y);
	game_map[i].setSize(sf::Vector2f(w,h));
	game_map[i].setRotation(r);
	game_map[i].setFillColor(sf::Color::White);

}

void P_Game::addMapElement(int x,int y,int w,int h,int r){

	sf::RectangleShape a;
	game_map.push_back(a);
	setUpMap(game_map.size()-1,x,y,w,h,r);

}

void P_Game::addMapElement(map_element_value values){

	addMapElement(values.x,values.y,values.w,values.h,values.r);

}
