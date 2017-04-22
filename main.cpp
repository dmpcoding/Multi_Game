#include <iostream>
#include <SFML/Graphics.hpp>

int main(){

	sf::RenderWindow game_window(sf::VideoMode(500,500),"L_S");
	
	while(game_window.isOpen()){

		sf::Event e;
		while(game_window.pollEvent(e)){
		
			switch(e.type){
				
				case sf::Event::Closed:
					game_window.close();
			
			}
		
		}
	
		game_window.clear();

		game_window.display();

	}

	return 0;

}
