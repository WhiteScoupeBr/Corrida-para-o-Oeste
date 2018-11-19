#ifndef MENU2_H
#define MENU2_H
#include<SFML/Graphics.hpp>
#define ITENS_MENU 3

using namespace sf;

class Menu2
{
    public:
        Menu2(float width, float height);
        virtual ~Menu2();
        void Desenha(RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	Font font;
	Text menu[ITENS_MENU];

};

#endif // MENU2_H
