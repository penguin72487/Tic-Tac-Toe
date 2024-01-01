#include "SettingsMenu.h"
#include <iostream>

SettingsMenu::SettingsMenu(sf::RenderWindow& window) : UIComponent(window), MenuButton(57, 36, 160, 70, "MENU", font) {
    colorset = sf::Text("SETTING COLOR", font, 50);
    colorset.setFillColor(sf::Color(255, 255, 255));
    colorset.setPosition(50, 377);

    timeset = sf::Text("SETTING TIME", font, 50);
    timeset.setFillColor(sf::Color(255, 255, 255));
    timeset.setPosition(50, 622);
}

UIComponent::Screen SettingsMenu::render() {
    std::cout << "Settings Menu: [Settings Options]" << std::endl;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // check if buttons are clicked
            if (MenuButton.isClicked(event)) {
                return Screen::MAIN_MENU;
            }
        }

        window.clear(color);
        // draw title and buttons
        window.draw(colorset);
        window.draw(timeset);
        window.draw(MenuButton.shape);
        window.draw(MenuButton.text);
        window.display();
    }
    return Screen::MAIN_MENU;
}