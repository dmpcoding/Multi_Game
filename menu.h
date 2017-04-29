#ifndef Menu_Class
#define Menu_Class

#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>

class Menu: public sf::Drawable, public sf::Transformable{

private:
	sf::Font font;
	const sf::RenderWindow* game_window;
	std::array<sf::Text,3> menu_options;
	int select_option;
	bool* isKeyPressed;

public:
	void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	void refresh();
	Menu(sf::RenderWindow* window,bool* keyPressed);

};

#endif
