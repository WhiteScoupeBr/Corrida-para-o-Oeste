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
#include "Menu.h"
#include "Menu2.h"
#include "Pausa.h"
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
    bool jogoPronto2 = false, jogoPronto1 = false,desenhaPause=false, desenhaMenu = true, desenhaMenu2 = false,fase1Pronta = false, fase2Pronta = false;
    bool _pause=false;




};

#endif // PRINCIPAL_H
