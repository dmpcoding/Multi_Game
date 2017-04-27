#ifndef
#define Menu_Class

#include <iostream>
#include <SFML/Graphics.hpp>

class Menu: public Drawable,public Transformable{

	sf::Font font;

public:
	void draw(sf::RenderTarget& target,sf:RenderStates 
states)const{ 
		sf::Text text(font,"abcABC");
		target.draw(text) 
	}
	Menu(){font.loadFromFile("font/Oxygen-Light.ttf");}

}

#endif
