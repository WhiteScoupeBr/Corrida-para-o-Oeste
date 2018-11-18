#ifndef PROJETIL2_H
#define PROJETIL2_H
#include<SFML/Graphics.hpp>
#include "Jogador2.h"
#include"Collider.h"

class Projetil2
{
    public:
        Projetil2(Texture* texture, Vector2f size, Vector2f posicao, Jogador2 jogador);
        virtual ~Projetil2();
        void Atualiza();
        void Desenha(RenderWindow& window);
        Collider GetCollider();
        Vector2f GetPosition();
    protected:

    private:
       RectangleShape bala;
       bool direcaoD;

};

#endif // PROJETIL2_H
