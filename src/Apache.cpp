#include "Apache.h"

Apache::Apache(Texture* texture, Vector2f posicao, float trocaTempo)
{
    fileira=0;
    corpo.setSize(Vector2f(56.0f,96.0f));
    corpo.setOrigin(corpo.getSize()/2.f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
};
Apache::~Apache()
{
    //dtor
}

void Apache::Desenha(RenderWindow& window){
    window.draw(corpo);
}

 Vector2f Apache::GetPosition(){
    return corpo.getPosition();
 }

Collider Apache::GetCollider(){
    return Collider(corpo);
}

void Apache::setPosition(float dx,float dy){
    corpo.setPosition(dx, dy);
}

void Apache::Atualiza(float deltaTime){

     counter++;
    float velocidade = 90.f;
    if(counter<4000){
        corpo.move(0.06f,0.f);
        //vel.x+=velocidade;
    }
    if(counter>4000){
        corpo.move(-.06f,0.f);
    }

    if(counter >8000)
        counter=0;

}

bool Apache::GetAtira(){
    return false;
}

