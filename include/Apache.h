#ifndef APACHE_H
#define APACHE_H
#include "Collider.h"
#include "Animacao.h"
#include "Inimigo.h"

class Apache:public Inimigo
{
    public:
        Apache(Texture* texture, Vector2f posicao, Vector2u contImg,float trocaTempo);
        virtual ~Apache();

        void Atualiza(float deltaTime);
        void Desenha(RenderWindow& window);
        Vector2f GetPosition();
        Collider GetCollider();
        //void OnColisao(Vector2f direction);
        void setPosition(float dx, float dy);
        bool GetAtira();

    protected:

    private:
        RectangleShape corpo;
        Animacao anima;
        unsigned int fileira;
        float velocidade;
        Vector2f vel;
        bool direita;
        int counter=0;

};
#endif // APACHE_H
