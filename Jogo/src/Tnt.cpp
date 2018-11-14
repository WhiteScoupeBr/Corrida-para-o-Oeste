#include "Tnt.h"

Tnt::Tnt(Texture* texture, Vector2f size, Vector2f posicao)
{
    corpo.setSize(size);
    corpo.setOrigin(size/2.0f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
}

Tnt::~Tnt()
{
    //dtor
}
 void Tnt::Desenha(RenderWindow& janela){
    janela.draw(corpo);
}

 Collider Tnt::GetCollider(){
    return Collider (corpo);
}
