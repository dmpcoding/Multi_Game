app: main.cpp libraries/menu.h libraries/menu.cpp libraries/game.cpp libraries/game.h
	g++ -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system main.cpp libraries/menu.h libraries/menu.cpp libraries/game.cpp libraries/game.h -o app

