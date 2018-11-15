#ifndef ENTIDADE_H
#define ENTIDADE_H
#include <SFML/Graphics.hpp>
#include "Collider.h"

using namespace sf;

class Entidade
{
    public:
        Entidade();
        ~Entidade();
        virtual void Atualiza(float deltaTime)=0;
        virtual void Desenha(RenderWindow& janela)=0;
        virtual Collider GetCollider ()=0;

    protected:
    private:

};

#endif // ENTIDADE_H
