#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animacao.h"
//#include "Collider.h"
//#include"jogador.h"
//#include"Plataforma.h"
#include "Entidade.h"
//#include "Cacto.h"
//#include "Tnt.h"
//#include "BolaFeno.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Menu.h"
#include "Menu2.h"
#include "Pausa.h"
#include "Pause.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
#include <vector>

using namespace sf;


class Principal
{
    public:
        Principal();
        virtual ~Principal();
        void Executar();

    protected:

    private:
    bool jogoPronto2 = false, desenhaMenu = true, desenhaMenu2 = false,fase1Pronta = false;
    bool _pause=false,_save=false, _fase1=false,_jog2 =false,_game=false;
    string fase1t,jog2,posx,posy;
    float _posx,_posy;





};

#endif // PRINCIPAL_H
