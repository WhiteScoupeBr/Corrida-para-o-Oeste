#include "ListaEnt.h"

ListaEnt::ListaEnt()
 {
    pPrimeiro = NULL;
    pUltimo = NULL;
}

ListaEnt::~ListaEnt()
 {
    pPrimeiro = NULL;
    pUltimo = NULL;
    limpar();
}
void ListaEnt::incluir(Entidade* pi)
{
    ElementoEnt* pEl= NULL;
    pEl = new ElementoEnt();
    pEl->setEntidade(pi);

    if (pi != NULL)
    {
        if (NULL == pUltimo)
        {
            pUltimo = pEl;
            pPrimeiro = pEl;
        }
        else
        {
            pEl->setAnterior(pUltimo);
            pUltimo = pEl;
        }
    }
}
void ListaEnt::percorrer(RenderWindow& window,float deltaTime)
{
    ElementoEnt* pEl = NULL;
    pEl = pUltimo;

    while (pEl)
    {
        (pEl->getEntidade())->Atualiza(deltaTime);
        //(pEl->getEntidade())->GetCollider();
        (pEl->getEntidade())->Desenha(window);
        pEl = pEl->getAnterior();
    }
}
void ListaEnt::limpar()
{

    ElementoEnt* pEl = NULL;
    pEl = pUltimo;

    while (pEl)
    {
        delete pEl->getEntidade();

        pUltimo = pUltimo->getAnterior();

        delete pEl;

        pEl = pUltimo;
    }
}
