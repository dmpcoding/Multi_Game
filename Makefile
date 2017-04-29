app: main.cpp menu.h menu.cpp
	g++ -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system main.cpp menu.h menu.cpp -o app

