#ifndef BTK_H
#define BTK_H
#include "Collider.h"
#include "Animacao.h"
#include "Inimigo.h"

class BTK
{
    public:
        BTK(Texture* texture, Vector2f posicao,Vector2u contImg, float trocaTempo);
        virtual ~BTK();

        void Atualiza(float deltaTime);
        void Desenha(RenderWindow& window);
        Vector2f GetPosition();
        Collider GetCollider();
        void setPosition(float dx, float dy);
        bool GetAtira();

    protected:

    private:

        RectangleShape corpo;
        Animacao anima;
        unsigned int fileira;
        Vector2f vel;
        int counter=0;
        bool btkAtira;
};

#endif // BTK_H
