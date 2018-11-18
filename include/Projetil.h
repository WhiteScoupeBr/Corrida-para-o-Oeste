#ifndef PROJETIL_H
#define PROJETIL_H
#include<SFML/Graphics.hpp>
#include "jogador.h"
#include"Collider.h"


class Projetil
{
    public:
        Projetil(Texture* texture, Vector2f size, Vector2f posicao, Jogador jogador);
        virtual ~Projetil();
        void Atualiza();
        void Desenha(RenderWindow&window);
        Collider GetCollider();
        Vector2f GetPosition();
    protected:

    private:
       RectangleShape bala;
       bool direcaoD;

};

#endif // PROJETIL_H
