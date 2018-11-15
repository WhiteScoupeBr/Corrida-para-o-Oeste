#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <SFML/Graphics.hpp>
#include "Animacao.h"
//#include "Collider.h"
//#include"jogador.h"
//#include"Plataforma.h"
#include"Entidade.h"
//#include "Cacto.h"
//#include "Tnt.h"
//#include "BolaFeno.h"
#include "Fase1.h"
#include<string>
#include<sstream>
#include<vector>

using namespace sf;


class Principal
{
    public:
        Principal();
        virtual ~Principal();
        void Executar();

    protected:

    private:

};

#endif // PRINCIPAL_H
