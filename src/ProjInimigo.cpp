#include "ProjInimigo.h"

ProjInimigo::ProjInimigo(Texture* texture, Vector2f size, Vector2f posicao)
{
    bala.setSize(size);
    bala.setOrigin(size/2.0f);
    bala.setTexture(texture);
    bala.setPosition(posicao);
}

ProjInimigo::~ProjInimigo()
{
    //dtor
}

void ProjInimigo::Atualiza(){

    bala.move(-1.f,0.f);
}

void ProjInimigo::Desenha(RenderWindow& window){
    window.draw(bala);
}

Collider ProjInimigo::GetCollider(){
    return Collider(bala);
}
