#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"

#define ITENS_MENU 4
using namespace sf;

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void Desenha(RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void Altera(float width, float height);

private:
	int selectedItemIndex;
	Font font;
	Text menu[ITENS_MENU];
	int maximo =4;

};

#endif // MENU_H
