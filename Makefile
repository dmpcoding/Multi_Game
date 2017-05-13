app: main.cpp libraries/menu.cpp libraries/game.cpp libraries/game_selector.cpp libraries/pong.cpp
	g++ -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system main.cpp libraries/menu.cpp libraries/game.cpp libraries/game_selector.cpp libraries/pong.cpp -o app
