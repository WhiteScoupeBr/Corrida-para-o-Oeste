#ifndef CACTO_H
#define CACTO_H
#include "Obstaculo.h"


class Cacto:public Obstaculo
{
    public:
        Cacto(Texture* texture, Vector2f size, Vector2f posicao);
        ~Cacto();
         Collider GetCollider();
         void Desenha(RenderWindow& window);
         void Atualiza(float deltaTime){}

    protected:

    private:
        RectangleShape corpo;
};

#endif // CACTO_H
