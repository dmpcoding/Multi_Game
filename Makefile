app: main.cpp libraries/menu.cpp libraries/game.cpp
	g++ -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system main.cpp libraries/menu.cpp libraries/game.cpp -o app

