#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animacao.h"
#include "Entidade.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Menu.h"
#include "Menu2.h"
#include "Pause.h"
#include"Jogador2.h"
#include"jogador.h"
//#include "MenuFinal.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace sf;

struct HighScore{
    int score;
    string nome;
};

class Principal
{
    public:
        Principal();
        virtual ~Principal();
        void Executar();

    protected:

    private:
    bool jogoPronto2 = false, desenhaMenu = false, desenhaMenu2 = false,fase1Pronta = false,desenhaFinal=false;
    bool _nome=true,_pause=false,_save=false, _fase1=false,_jog2 =false,_game=false, _fimFase1=false, _fimFase2=false;
    string fase1t,jog2,posx,posy,nome1,texto,scoreSave;
    std::stringstream ss2;
    String nome;
    float _posx,_posy;
    int _score;
    Text nomeJog;
    HighScore scoreFinal[10];

};

#endif // PRINCIPAL_H
