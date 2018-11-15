#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "Entidade.h"
#include "Collider.h"
#include "jogador.h"

class Obstaculo:public Entidade
{
    public:
        Obstaculo();
        ~Obstaculo();
        virtual void Desenha(RenderWindow& window)=0;
        virtual Collider GetCollider()=0;
        virtual void Atualiza(float deltaTime)=0;
    protected:

    private:
};

#endif // OBSTACULO_H
