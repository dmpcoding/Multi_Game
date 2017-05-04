#ifndef Game_Class
#define Game_Class

#include <SFML/Graphics.hpp>
#include <fstream>

struct map_element_value{
	int x;
	int y;
	int w;
	int h;
	int r;
};

class P_Game: public sf::Drawable, public sf::Transformable{

private:
    sf::CircleShape player;
    std::vector<sf::RectangleShape> game_map;
		sf::Sprite meta;
		sf::Texture meta_texture;
		sf::Clock clock;
		sf::Font *font;
		sf::RenderWindow* game_window;
		std::ifstream map_file;
		map_element_value value;
		double speed;


public:
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
	P_Game();
	void setRnderWindow(sf::RenderWindow* window){game_window = window;};
  void addMapElement(int x,int y,int w,int h,int r);
  void addMapElement(map_element_value values);
  void setUpMap(int i,int x,int y,int w,int h,int r);
	void readMapFromFile(std::string file);
	void refresh();
	void setUpMapEnd(int x,int y);
	void resetClock();
	void setFont(sf::Font *f){font = f;};
	void nextLeve();

};

#endif
