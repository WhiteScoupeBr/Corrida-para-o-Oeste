#ifndef PAUSE_H
#define PAUSE_H
#include <SFML/Graphics.hpp>
#define ITENS_MENU 3

using namespace sf;

class Pause
{
    public:
    Pause(float width, float height);
	~Pause();

	void Desenha(RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void setPosition(float dx,float dy);

private:
	int selectedItemIndex;
	Font font;
	Text menu[ITENS_MENU];
};

#endif // PAUSE_H
