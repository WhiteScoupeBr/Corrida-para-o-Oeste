#ifndef LISTA_ENTIDADE_H
#define LISTA_ENTIDADE_H
#include "Entidade.h"

class ListaEnt
{

    private:
        class ElementoEnt
        {
        private:
            Entidade* pEntidade;
            ElementoEnt* pAnterior;
        public:
            ElementoEnt()
            {
                pEntidade = NULL;
                pAnterior = NULL;
            }
            ~ElementoEnt()
            {
                pEntidade = NULL;
                pAnterior = NULL;
            }

            void setEntidade(Entidade* p) {pEntidade = p;}
            Entidade* getEntidade() {return pEntidade;}

            void setAnterior(ElementoEnt* pe) {pAnterior = pe;}
            ElementoEnt* getAnterior() {return pAnterior;}
        };

        protected:
            ElementoEnt* pPrimeiro;
            ElementoEnt* pUltimo;


        public:
            ListaEnt();
            ~ListaEnt();
            void incluir(Entidade* pi);
            void percorrer(RenderWindow& window,float deltaTime);
            void limpar();
};

#endif // LISTA_ENTIDADE_H
