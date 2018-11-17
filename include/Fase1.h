#ifndef FASE1_H
#define FASE1_H
#include<SFML/Graphics.hpp>
#include"Animacao.h"
#include"Collider.h"
#include"Cacto.h"
#include"Tnt.h"
#include"BolaFeno.h"
#include"jogador.h"
#include "Projetil.h"
#include"Plataforma.h"
#include"Apache.h"
#include "JJ.h"
#include "ProjInimigo.h"
#include<string>
#include<sstream>
#include<vector>
#include "Jogador2.h"
#include "Projetil2.h"

class Fase1
{
    public:
        Fase1();
        virtual ~Fase1();
        void Executar(RenderWindow& window,float deltaTime,Jogador& jogador1,View& view);
        void Executar2(RenderWindow& window,float deltaTime,Jogador& jogador1,View& view, Jogador2& jogador2);

    protected:

    private:
        Texture background,bar,jj,chao,bola,cacto,tnt,bala1,bala22;
        Font fonte;
        Text vidas;
        Font fonte2;
        Text vidas2;

        Vector2f direction;

        std::vector<Plataforma> plataformas;
        std::vector<Plataforma>invPlataforma;
        std::vector<Plataforma>invChao;
        std::vector<Obstaculo*>obs;
        std::vector<Projetil>bala;
        std::vector<Projetil2>bala2Jog;
        std::vector<ProjInimigo>bala2;
        std::vector<Inimigo*>inimigos;
        //Plataforma invChao(nullptr,Vector2f(400.f,1000.f),Vector2f(-200.f,-50.f)));
};

#endif // FASE1_H
