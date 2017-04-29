#ifndef Menu_Class
#define Menu_Class

#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>

class Menu: public sf::Drawable, public sf::Transformable{

private:
	enum options_in_menu{single_player=0,options,quit,menu};
	options_in_menu select_option;
	options_in_menu run;
	sf::Font font;
	sf::RenderWindow* game_window;
	std::array<sf::Text,3> menu_options;
	bool* isKeyPressed;
	void Display();
	void Game();
	void Options();

public:
	void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	void refresh();
	Menu(sf::RenderWindow* window,bool* keyPressed);

};

#endif
