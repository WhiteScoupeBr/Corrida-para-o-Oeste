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

    counter++;
    float velocidade = 90.f;
    if(counter<2000){
        corpo.move(0.06f,0.f);
        //vel.x+=velocidade;
    }
    if(counter>2000){
        corpo.move(-.06f,0.f);
    }

    if(counter >4000)
        counter=0;
}


