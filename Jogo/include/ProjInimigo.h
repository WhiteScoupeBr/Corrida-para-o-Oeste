#ifndef PROJINIMIGO_H
#define PROJINIMIGO_H
#include "Inimigo.h"
#include "Collider.h"
class ProjInimigo
{
    public:
        ProjInimigo(Texture* texture, Vector2f size, Vector2f posicao);
        virtual ~ProjInimigo();
        void Atualiza();
        void Desenha(RenderWindow&window);
        Collider GetCollider();
        Vector2f GetPosition();
    protected:

    private:
       RectangleShape bala;

};

#endif // PROJINIMIGO_H
