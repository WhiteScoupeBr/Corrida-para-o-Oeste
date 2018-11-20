#include "Menu2.h"

Menu2::Menu2(float width, float height)
{
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Ranking");
	menu[0].setPosition(sf::Vector2f(width / 2 -30, height / (ITENS_MENU+4 ) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Sair");
	menu[1].setPosition(sf::Vector2f(width / 2-30, height / (ITENS_MENU+4 ) * 2));

	selectedItemIndex = 0;
}


Menu2::~Menu2()
{
}

void Menu2::Desenha(RenderWindow &window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu2::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu2::MoveDown()
{
	if (selectedItemIndex + 1 < ITENS_MENU)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu2::setPosition(float dx,float dy)
{
    menu[0].setPosition(sf::Vector2f(dx+100, dy-200));
    menu[1].setPosition(sf::Vector2f(dx+100, dy-100));

}
