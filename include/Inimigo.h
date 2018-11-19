#ifndef INIMIGO_H
#define INIMIGO_H
#include "Entidade.h"

class Inimigo:public Entidade
{
    public:
        Inimigo();
        ~Inimigo();
        virtual void Desenha(RenderWindow& window)=0;
        virtual Collider GetCollider()=0;
        virtual void Atualiza(float deltaTime)=0;
        virtual bool GetAtira()=0;
        virtual Vector2f GetPosition()=0;
        virtual int getVida()=0;
        virtual void setVida(int x)=0;
        virtual int getId()=0;

    protected:

    private:
};

#endif // INIMIGO_H
