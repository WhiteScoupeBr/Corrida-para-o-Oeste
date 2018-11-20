#ifndef FASE2_H
#define FASE2_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
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
#include"BTK.h"
#include "ProjInimigo.h"
#include<string>
#include<sstream>
#include<vector>
#include "Jogador2.h"
#include "Projetil2.h"

class Fase2
{
     public:
        Fase2();
        virtual ~Fase2();
        void Executar(RenderWindow& window,float deltaTime,Jogador& jogador1,View& view,bool& _fimFase2);
        void Executar2(RenderWindow& window,float deltaTime,Jogador& jogador1,View& view, Jogador2& jogador2,bool& _fimFase2);
        void Atualiza(float deltaTime);
        void Atualiza2(float deltaTime);

    protected:

    private:
        Texture background,bandeira,billy,textureApache,chao21,bar,jj,chao,bola,cacto,tnt,bala1,bala22;
        Font fonte;
        Text vidas;
        Font fonte2;
        Text vidas2;
        Text scoreT;
        SoundBuffer buffer2;
        Sound gun;

        Vector2f direction;

        std::vector<Plataforma> plataformas;
        std::vector<Plataforma>invPlataforma;
        std::vector<Plataforma>invChao;
        std::vector<Obstaculo*>obs;
        std::vector<Projetil>bala;
        std::vector<Projetil2>bala2Jog;
        std::vector<ProjInimigo>bala2;
        std::vector<Inimigo*>inimigos;
        std::vector<Vector2f>balaPos;
        std::vector<Vector2f>balaPos2;
};

#endif // FASE2_H
