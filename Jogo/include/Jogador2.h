#ifndef JOGADOR2_H
#define JOGADOR2_H
#include "Animacao.h"
#include "Collider.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Jogador2
{
    public:
        Jogador2(){};
        Jogador2(Texture* texture, Vector2u contImg, float trocaTempo,float velocidade,float jumpHeight);
        virtual ~Jogador2();
        void Atualiza(float deltaTime);
        void Desenha(RenderWindow& janela);
        Vector2f GetPosition();
        Collider GetCollider();
        void OnColisao(Vector2f direction);
        void setPosition(float dx, float dy);
        int getVida();
        void setVida(int x);
        void Move(float dx,float dy);
        bool GetDireita();
        bool GetAtira();

    protected:

    private:
        RectangleShape corpo;
        Animacao anima;
        unsigned int fileira;
        float velocidade;
        Vector2f vel;
        bool canJump;
        float jumpHeight;
        int vida;
        bool direita;
        bool atira;
        float counter;
};

#endif // JOGADOR2_H
