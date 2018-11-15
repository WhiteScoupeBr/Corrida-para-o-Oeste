#ifndef APACHE_H
#define APACHE_H
#include "Collider.h"
#include "Animacao.h"
#include "Inimigo.h"

class Apache:public Inimigo
{
    public:
        Apache(Texture* texture, Vector2u contImg, float trocaTempo,float velocidade,float jumpHeight);
        virtual ~Apache();

        //void Atualiza(float deltaTime);
        //void Desenha(RenderWindow& janela);
        //Vector2f GetPosition();
        //Collider GetCollider();
        //void OnColisao(Vector2f direction);
        //void setPosition();
    protected:

    private:
        RectangleShape corpo;
        Animacao anima;
        unsigned int fileira;
        float velocidade;
        bool direita;
        Vector2f vel;
        bool canJump;
        float jumpHeight;
};
#endif // APACHE_H
