#ifndef CACTO_H
#define CACTO_H
#include "Obstaculo.h"

class Cacto:public Obstaculo
{
    public:
        Cacto(Texture* texture, Vector2f size, Vector2f posicao);
        virtual ~Cacto();
         Collider GetCollider();
         void Desenha(RenderWindow& janela);

    protected:

    private:
        RectangleShape corpo;
};

#endif // CACTO_H
