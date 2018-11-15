#include "BolaFeno.h"

BolaFeno::BolaFeno(Texture* texture, Vector2f size, Vector2f posicao)
{
    corpo.setSize(size);
    corpo.setOrigin(size/2.0f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
}


BolaFeno::~BolaFeno()
{
    //dtor
}

 void BolaFeno::Desenha(RenderWindow& window){
    window.draw(corpo);
}

 Collider BolaFeno::GetCollider(){
    return Collider (corpo);
}

void BolaFeno::Atualiza(float deltaTime){
    Vector2f vel;
    int i;
    if(i<200)
        corpo.move(1.f,0.f);
    else if(i<400)
        corpo.move(1.f,0.f);
}


