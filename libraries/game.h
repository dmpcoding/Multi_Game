#ifndef Game_Class
#define Game_Class

#include <SFML/Graphics.hpp>


class P_Game: public sf::Drawable, public sf::Transformable{

private:
    sf::CircleShape player;
    std::vector<sf::RectangleShape> game_map;


public:
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	P_Game();
  void addMapElement(int x,int y,int w,int h,int r);
  void setUpMap(int i,int x,int y,int w,int h,int r);


};

#endif
