#include "Projetil2.h"

Projetil2::Projetil2(Texture* texture, Vector2f size, Vector2f posicao,Jogador2 jogador)
{
    bala.setSize(size);
    bala.setOrigin(size/2.0f);
    bala.setTexture(texture);
    bala.setPosition(posicao);

    direcaoD= jogador.GetDireita();
}

Projetil2::~Projetil2()
{
    //dtor
}

void Projetil2::Atualiza(){

    if(direcaoD)
        bala.move(1.5f,0.f);
    if(direcaoD==false)
        bala.move(-1.5f,0.f);
}
void Projetil2::Desenha(RenderWindow&window){
    window.draw(bala);
}

Collider Projetil2::GetCollider(){
    return Collider (bala);
}
