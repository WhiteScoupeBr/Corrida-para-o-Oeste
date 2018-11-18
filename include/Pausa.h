#ifndef PAUSA_H
#define PAUSA_H
#define ITENS_MENU 3
#include <SFML/Graphics.hpp>

using namespace sf;

class Pausa
{
    public:
        Pausa(float width, float height);
        virtual ~Pausa();
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

#endif // PAUSA_H
