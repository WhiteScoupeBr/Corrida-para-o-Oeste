#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <SFML/Graphics.hpp>
#include "Animacao.h"
#include "Collider.h"
#include"jogador.h"
#include"Plataforma.h"
#include"ListaEnt.h"
#include"Entidade.h"
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
        ListaEnt listaEnt;



};

#endif // PRINCIPAL_H
