#ifndef BOLAFENO_H
#define BOLAFENO_H
#include"Obstaculo.h"

class BolaFeno:public Obstaculo
{
    public:
        BolaFeno(Texture* texture, Vector2f size, Vector2f posicao);
        ~BolaFeno();
        Collider GetCollider();
        void Desenha(RenderWindow& window);
        void Atualiza(float deltaTime);

    protected:

    private:
        RectangleShape corpo;
        int counter;
};

#endif // BOLAFENO_H
