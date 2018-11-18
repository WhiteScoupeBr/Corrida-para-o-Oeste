#include "Pause.h"


Pause::Pause(float width, float height)
{
	if (!font.loadFromFile("Carnevalee Freakshow.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Continuar");
	menu[0].setPosition(sf::Vector2f(width / 2 -30, height / (ITENS_MENU+4 ) ));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Salvar");
	menu[1].setPosition(sf::Vector2f(width / 2-30, height / (ITENS_MENU+4 ) +5));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Sair");
	menu[2].setPosition(sf::Vector2f(width / 2-25, height / (ITENS_MENU+4 ) +50));

	selectedItemIndex = 0;
}


Pause::~Pause()
{
}

void Pause::Desenha(sf::RenderWindow &window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(menu[i]);
	}
}

void Pause::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Pause::MoveDown()
{
	if (selectedItemIndex + 1 < ITENS_MENU)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}


void Pause::setPosition(float dx, float dy)
{
    menu[0].setPosition(sf::Vector2f(dx+100, dy -200 ));
    menu[1].setPosition(sf::Vector2f(dx+100, dy -100));
    menu[2].setPosition(sf::Vector2f(dx+100, dy ));
}

