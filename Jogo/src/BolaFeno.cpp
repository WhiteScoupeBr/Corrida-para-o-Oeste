#include "BolaFeno.h"

BolaFeno::BolaFeno(Texture* texture, Vector2f size, Vector2f posicao)
{
    corpo.setSize(size);
    corpo.setOrigin(size/2.0f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
    corpo.Movimento();
}


BolaFeno::~BolaFeno()
{
    //dtor
}

 void BolaFeno::Desenha(RenderWindow& janela){
    janela.draw(corpo);
}

 Collider BolaFeno::GetCollider(){
    return Collider (corpo);
}

void BolaFeno::Movimento(){
    Vector2f vel;
    for()
    corpo.move(vel*deltaTime);
}


