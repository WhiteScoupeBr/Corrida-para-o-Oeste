#ifndef JOGADOR_H
#define JOGADOR_H
#include "Animacao.h"
#include "Collider.h"
#include "Personagem.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Jogador:public Personagem
{
    public:
        Jogador(Texture* texture, Vector2u contImg, float trocaTempo,float velocidade,float jumpHeight);
        virtual ~Jogador();

        void Atualiza(float deltaTime);
        void Desenha(RenderWindow& janela);
        Vector2f GetPosition();
        Collider GetCollider();
        void OnColisao(Vector2f direction);
        void setPosition();
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

#endif // JOGADOR_H
