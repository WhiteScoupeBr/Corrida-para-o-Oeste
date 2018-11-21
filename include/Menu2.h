#ifndef MENU2_H
#define MENU2_H
#include<SFML/Graphics.hpp>
#include<string>
using namespace sf;

class Menu2
{
    public:
        Menu2(float width, float height,std::string rank1[],std::string rank2[]);
        virtual ~Menu2();
        void Desenha(RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() { return selectedItemIndex; }
        void setPosition(float dx,float dy);

private:
	int selectedItemIndex;
	Font font;
	Text menu[10];
	Text menu2[10];
	Text menu3[2];

};

#endif // MENU2_H
