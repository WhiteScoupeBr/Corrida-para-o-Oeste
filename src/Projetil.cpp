#include "Projetil.h"

Projetil::Projetil(Texture* texture, Vector2f size, Vector2f posicao,Jogador jogador)
{
    bala.setSize(size);
    bala.setOrigin(size/2.0f);
    bala.setTexture(texture);
    bala.setPosition(posicao);

    direcaoD= jogador.GetDireita();
}

Projetil::~Projetil()
{
    //dtor
}

void Projetil::Atualiza(){

    if(direcaoD)
        bala.move(1.5f,0.f);
    if(direcaoD==false)
        bala.move(-1.5f,0.f);
}
void Projetil::Desenha(RenderWindow&window){
    window.draw(bala);
}

Collider Projetil::GetCollider(){
    return Collider (bala);
}
Vector2f Projetil::GetPosition(){
    return bala.getPosition();
}
