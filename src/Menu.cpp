#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Carnevalee Freakshow.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Fase 1");
	menu[0].setPosition(sf::Vector2f(width / 2 -30, height / (ITENS_MENU+5 ) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Fase 2 ");
	menu[1].setPosition(sf::Vector2f(width / 2-30, height / (ITENS_MENU+5 ) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Continuar Save");
	menu[2].setPosition(sf::Vector2f(width / 2-30, height / (ITENS_MENU+5 ) * 3));

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("Ranking");
	menu[3].setPosition(sf::Vector2f(width / 2-25, height / (ITENS_MENU+5 ) * 4));

	menu[4].setFont(font);
	menu[4].setColor(sf::Color::White);
	menu[4].setString("Sair");
	menu[4].setPosition(sf::Vector2f(width / 2-25, height / (ITENS_MENU+5 ) * 5));

	selectedItemIndex = 0;
	maximo=5;
}


Menu::~Menu()
{
}

void Menu::Desenha(sf::RenderWindow &window)
{
	for (int i = 0; i < maximo; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < ITENS_MENU)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::Altera(float width, float height){
    menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Jogador 1");
	menu[0].setPosition(sf::Vector2f(width / 2 -30, height / (ITENS_MENU+4 ) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Jogador 2");
	menu[1].setPosition(sf::Vector2f(width / 2-30, height / (ITENS_MENU+4 ) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Sair");
	menu[2].setPosition(sf::Vector2f(width / 2-25, height / (ITENS_MENU+4 ) * 3));

    maximo=3;

	selectedItemIndex = 0;

}
void Menu::Altera2(float width, float height){

    maximo=5;

    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Fase 1");
    menu[0].setPosition(sf::Vector2f(width / 2 -30, height / (ITENS_MENU+5 ) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Fase 2 ");
    menu[1].setPosition(sf::Vector2f(width / 2-30, height / (ITENS_MENU+5 ) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Continuar Save");
    menu[2].setPosition(sf::Vector2f(width / 2-30, height / (ITENS_MENU+5 ) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Ranking");
    menu[3].setPosition(sf::Vector2f(width / 2-25, height / (ITENS_MENU+5 ) * 4));

    menu[4].setFont(font);
    menu[4].setColor(sf::Color::White);
    menu[4].setString("Sair");
    menu[4].setPosition(sf::Vector2f(width / 2-25, height / (ITENS_MENU+5 ) * 4));

    selectedItemIndex = 0;
}
void Menu::setPosition(float dx,float dy)
{

    menu[0].setPosition(sf::Vector2f(dx+100, dy-300));
    menu[1].setPosition(sf::Vector2f(dx+100, dy-200));
    menu[2].setPosition(sf::Vector2f(dx+100, dy-100));
    menu[3].setPosition(sf::Vector2f(dx+100, dy-0));
    menu[4].setPosition(sf::Vector2f(dx+100, dy+100));

}
