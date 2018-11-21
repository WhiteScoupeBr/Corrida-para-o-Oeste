#include "Menu2.h"

Menu2::Menu2(float width, float height,std::string rank1[],std::string rank2[])
{
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
    menu[0].setString(rank1[0]);
	menu[0].setPosition(sf::Vector2f(width , height ));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString(rank1[1]);
	menu[1].setPosition(sf::Vector2f(width ,height));

    menu[2].setFont(font);
	menu[2].setColor(sf::Color::Red);
	menu[2].setString(rank1[2]);
	menu[2].setPosition(sf::Vector2f(width , height ));

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString(rank1[3]);
	menu[3].setPosition(sf::Vector2f(width ,height));

    menu[4].setFont(font);
	menu[4].setColor(sf::Color::Red);
	menu[4].setString(rank1[4]);
	menu[4].setPosition(sf::Vector2f(width , height ));

	menu[5].setFont(font);
	menu[5].setColor(sf::Color::White);
	menu[5].setString(rank1[5]);
	menu[5].setPosition(sf::Vector2f(width ,height));

    menu[6].setFont(font);
	menu[6].setColor(sf::Color::White);
	menu[6].setString(rank1[6]);
	menu[6].setPosition(sf::Vector2f(width ,height));

    menu[7].setFont(font);
	menu[7].setColor(sf::Color::White);
	menu[7].setString(rank1[7]);
	menu[7].setPosition(sf::Vector2f(width ,height));

	menu[8].setFont(font);
	menu[8].setColor(sf::Color::White);
	menu[8].setString(rank1[8]);
	menu[8].setPosition(sf::Vector2f(width ,height));

	menu[9].setFont(font);
	menu[9].setColor(sf::Color::White);
	menu[9].setString(rank1[9]);
	menu[9].setPosition(sf::Vector2f(width ,height));

    menu2[0].setFont(font);
	menu2[0].setColor(sf::Color::Red);
	menu2[0].setString(rank2[0]);
	menu2[0].setPosition(sf::Vector2f(width , height ));

	menu2[1].setFont(font);
	menu2[1].setColor(sf::Color::White);
	menu2[1].setString(rank2[1]);
	menu2[1].setPosition(sf::Vector2f(width ,height));

    menu2[2].setFont(font);
	menu2[2].setColor(sf::Color::Red);
	menu2[2].setString(rank2[2]);
	menu2[2].setPosition(sf::Vector2f(width , height ));

	menu2[3].setFont(font);
	menu2[3].setColor(sf::Color::White);
	menu2[3].setString(rank2[3]);
	menu2[3].setPosition(sf::Vector2f(width ,height));

    menu2[4].setFont(font);
	menu2[4].setColor(sf::Color::Red);
	menu2[4].setString(rank2[4]);
	menu2[4].setPosition(sf::Vector2f(width , height ));

	menu2[5].setFont(font);
	menu2[5].setColor(sf::Color::White);
	menu2[5].setString(rank2[5]);
	menu2[5].setPosition(sf::Vector2f(width ,height));

    menu2[6].setFont(font);
	menu2[6].setColor(sf::Color::White);
	menu2[6].setString(rank2[6]);
	menu2[6].setPosition(sf::Vector2f(width ,height));

    menu2[7].setFont(font);
	menu2[7].setColor(sf::Color::White);
	menu2[7].setString(rank2[7]);
	menu2[7].setPosition(sf::Vector2f(width ,height));

	menu2[8].setFont(font);
	menu2[8].setColor(sf::Color::White);
	menu2[8].setString(rank2[8]);
	menu2[8].setPosition(sf::Vector2f(width ,height));

	menu2[9].setFont(font);
	menu2[9].setColor(sf::Color::White);
	menu2[9].setString(rank2[9]);
	menu2[9].setPosition(sf::Vector2f(width ,height));

	menu3[0].setFont(font);
	menu3[0].setColor(sf::Color::White);
    menu3[0].setString("Voltar");
	menu3[0].setPosition(sf::Vector2f(width ,height));

	menu3[1].setFont(font);
	menu3[1].setColor(sf::Color::White);
    menu3[1].setString("Sair");
	menu3[1].setPosition(sf::Vector2f(width ,height));


	selectedItemIndex = 0;
}


Menu2::~Menu2()
{
}

void Menu2::Desenha(RenderWindow &window)
{
	for (int i = 0; i < 10; i++)
	{
		window.draw(menu[i]);
	}

    for (int i = 0; i < 10; i++)
	{
		window.draw(menu2[i]);
	}
	    for (int i = 0; i < 2; i++)
	{
		window.draw(menu3[i]);
	}
}

void Menu2::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu3[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu3[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu2::MoveDown()
{
	if (selectedItemIndex + 1 < 2)
	{
		menu3[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu3[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu2::setPosition(float dx,float dy)
{
//    menu[0].setPosition(sf::Vector2f(dx, dy));
    //menu[1].setPosition(sf::Vector2f(dx+100, dy-100));

}
