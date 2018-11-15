#include "Cacto.h"

Cacto::Cacto(Texture* texture, Vector2f size, Vector2f posicao)
{
    corpo.setSize(size);
    corpo.setOrigin(size/2.0f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
}

Cacto::~Cacto()
{
    //dtor
}

 void Cacto::Desenha(RenderWindow& window){
    window.draw(corpo);
}

 Collider Cacto::GetCollider(){
    return Collider (corpo);
}
