#include "menu.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main(){

	sf::RenderWindow game_window(sf::VideoMode(500,500),"L_S");
	
	bool isKeyPressed = false;
	Menu menu(&game_window,&isKeyPressed);

	while(game_window.isOpen()){
		isKeyPressed = false;
		sf::Event e;
		while(game_window.pollEvent(e)){

			switch(e.type){

				case sf::Event::Closed:
					game_window.close();
				case sf::Event::KeyPressed:
					isKeyPressed = true;

			}

		}

		menu.refresh();

		game_window.clear();
		game_window.draw(menu);
		game_window.display();

	}

	return 0;

}
