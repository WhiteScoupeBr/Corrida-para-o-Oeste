#ifndef TNT_H
#define TNT_H
#include "Obstaculo.h"

class Tnt:public Obstaculo
{
    public:
        Tnt(Texture* texture, Vector2f size, Vector2f posicao);
         ~Tnt();
        Collider GetCollider();
        void Desenha(RenderWindow& window);
        void Atualiza(float deltaTime){};

    protected:

    private:
        RectangleShape corpo;
};

#endif // TNT_H
