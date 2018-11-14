#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "Entidade.h"
#include "Collider.h"

class Obstaculo:public Entidade
{
    public:
        Obstaculo();
        ~Obstaculo();
        virtual void Desenha(RenderWindow& janela)=0;
        virtual Collider GetCollider() =0;

    protected:

    private:
};

#endif // OBSTACULO_H
