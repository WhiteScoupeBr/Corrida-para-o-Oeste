#ifndef ANIMACAO_H
#define ANIMACAO_H
#include <SFML/Graphics.hpp>

class Jogador;

using namespace sf;

class Animacao
{
    public:
        Animacao(Texture* texture, Vector2u contImg, float trocaTempo);
        virtual ~Animacao();
        void Atualiza(int fileira, float deltaTime, bool direita);

        IntRect uvRect;


    private:
        Vector2u contImg;
        Vector2u atualImg;

        float tempoTotal;
        float trocaTempo;

};

#endif // ANIMACAO_H
