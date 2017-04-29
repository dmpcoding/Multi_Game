#include "menu.h"

void Menu::draw(sf::RenderTarget& target,sf::RenderStates states)const{

	for(sf::Text x: menu_options)
		target.draw(x,states);

}

void  Menu::refresh(){

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&*isKeyPressed){ select_option--; }
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&*isKeyPressed){ select_option++; }
	select_option = (select_option < 0)?2:select_option;
	select_option = (select_option > 2)?0:select_option;
	for(int i = 0;i<3;i++)
		menu_options[i].setFillColor(sf::Color::White);
	menu_options[select_option].setFillColor(sf::Color::Cyan);

}

Menu::Menu(sf::RenderWindow* window,bool* keyPressed){

	font.loadFromFile("font/Oxygen-Light.ttf");

	for(int i = 0;i<3;i++)
		menu_options[i].setFont(font);

	game_window = window;
	menu_options[0].setString("Start Game");
	menu_options[0].setPosition((game_window->getSize().x-menu_options[0].getGlobalBounds().width)/2,game_window->getSize().y/2);
	menu_options[1].setString("Options");
	menu_options[1].setPosition((game_window->getSize().x-menu_options[1].getGlobalBounds().width)/2,menu_options[0].getPosition().y+menu_options[0].getGlobalBounds().height+10);
	menu_options[2].setString("Quit");
	menu_options[2].setPosition((game_window->getSize().x-menu_options[2].getGlobalBounds().width)/2,menu_options[1].getPosition().y+menu_options[1].getGlobalBounds().height+10);

	select_option = 0;
	isKeyPressed = keyPressed;

}
