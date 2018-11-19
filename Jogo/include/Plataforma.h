#ifndef PLATAFORMA_H
#define PLATAFORMA_H
#include "Collider.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Plataforma
{
    public:
        Plataforma(Texture* texture, Vector2f size, Vector2f posicao);
        ~Plataforma();
        void Desenha(RenderWindow& window);
        Collider GetCollider();

    protected:

    private:
        RectangleShape corpo;
};

#endif // PLATAFORMA_H
