#ifndef BTK_H
#define BTK_H
#include "Collider.h"
#include "Animacao.h"
#include "Inimigo.h"

class BTK:public Inimigo
{
    public:
        BTK(Texture* texture,Vector2f posicao, float trocaTempo);
        ~BTK();
        void Atualiza(float deltaTime);
        void Desenha(RenderWindow& window);
        Vector2f GetPosition();
        Collider GetCollider();
        void setPosition(float dx, float dy);
        bool GetAtira();
        int getVida();
        void setVida(int x);
        int getId();

    protected:

    private:

        RectangleShape corpo;
        Animacao anima;
        unsigned int fileira;
        Vector2f vel;
        int counter=0;
        bool btkAtira;
        int vida ;
        int id;
};

#endif // BTK_H
