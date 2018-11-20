#ifndef JOGADOR_H
#define JOGADOR_H
#include "Animacao.h"
#include "Collider.h"
//#include "Personagem.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Jogador
{
    public:
        Jogador(){};
        Jogador(Texture* texture, Vector2u contImg, float trocaTempo,float velocidade,float jumpHeight);
        virtual ~Jogador();
        void Atualiza(float deltaTime);
        void Desenha(RenderWindow& janela);
        Vector2f GetPosition();
        Collider GetCollider();
        void OnColisao(Vector2f direction);
        void setPosition(float dx, float dy);
        int getVida()const;
        void setVida(int x);
        void Move(float dx,float dy);
        bool GetDireita()const;
        bool GetAtira()const;
        void setScore(int x);
        int GetScore()const;

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
        int score;

};

#endif // JOGADOR_H
