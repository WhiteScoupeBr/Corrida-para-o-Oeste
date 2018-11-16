#include "Plataforma.h"

Plataforma::Plataforma(Texture* texture, Vector2f size, Vector2f posicao)
{
    corpo.setSize(size);
    corpo.setOrigin(size/2.0f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
}

Plataforma::~Plataforma()
{
    //dtor
}

void Plataforma::Desenha(RenderWindow& window){
    window.draw(corpo);
}

Collider Plataforma::GetCollider(){
    return Collider (corpo);
}
