#include "menu.h"

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (run == menu) {
        for (sf::Text x: menu_options) {
            target.draw(x, states);
        }
    }

    if (run == single_player) {
        target.draw(single);
    }
}

void Menu::refresh() {
    if (run == menu) {
        Display();
    }

    if (run == options) {
        Options();
    }

    if (run == single_player) {
        Game();
    }
}

void Menu::Options() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && *isKeyPressed) {
        run = menu;
    }
}

void Menu::Display() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && *isKeyPressed) {
        int i = int(select_option) - 1;
        i = (i < 0) ? 2 : i;
        select_option = (options_in_menu)i;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && *isKeyPressed) {
        int i = int(select_option) + 1;
        i = (i > 2) ? 0 : i;
        select_option = (options_in_menu)i;
    }

    for (int i = 0; i < 3; i++) {
        menu_options[i].setFillColor(sf::Color::White);
    }

    menu_options[(int)select_option].setFillColor(sf::Color::Cyan);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && *isKeyPressed) {
        switch (select_option) {
        case quit:
            game_window->close();
            break;
        case single_player:
            run = single_player;
            start_clock = true;
            break;
        case options:
            run = options;
            break;
        }
    }
}

void Menu::Game() {
    if (start_clock) {
        start_clock = false;
        single.resetClock();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && *isKeyPressed) {
        run = menu;
    }

    single.refresh();
}

Menu::Menu(sf::RenderWindow *window, bool *keyPressed) {
    font.loadFromFile("font/Oxygen-Light.ttf");
    single.setFont(&font);

    for (int i = 0; i < 3; i++) {
        menu_options[i].setFont(font);
    }

    game_window = window;
    menu_options[0].setString("Start Game");
    menu_options[0].setPosition(
        (game_window->getSize().x - menu_options[0].getGlobalBounds().width) / 2,
        game_window->getSize().y / 2);
    menu_options[1].setString("Options");
    menu_options[1].setPosition(
        (game_window->getSize().x - menu_options[1].getGlobalBounds().width) / 2,
        menu_options[0].getPosition().y +
            menu_options[0].getGlobalBounds().height + 10);
    menu_options[2].setString("Quit");
    menu_options[2].setPosition(
        (game_window->getSize().x - menu_options[2].getGlobalBounds().width) / 2,
        menu_options[1].getPosition().y +
            menu_options[1].getGlobalBounds().height + 10);

    select_option = single_player;
    isKeyPressed = keyPressed;
    run = menu;
    file.open("libraries/abc");
    int lines = 0;
    file >> lines;

    for (int i = 0; i < lines; i++) {
        file >> value.x;
        file >> value.y;
        file >> value.w;
        file >> value.h;
        file >> value.r;

        single.addMapElement(value);
    }

    int x = 0;
    int y = 0;

    file >> x;
    file >> y;

    single.setUpMapEnd(x, y);
    single.setRnderWindow(game_window);

    start_clock = false;
}
