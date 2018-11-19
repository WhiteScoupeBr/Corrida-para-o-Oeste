#include "BTK.h"


BTK::BTK(Texture* texture,Vector2f posicao, float trocaTempo)
{
    fileira=0;
    corpo.setSize(Vector2f(56.0f,96.0f));
    corpo.setOrigin(corpo.getSize()/2.f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
    btkAtira=false;
    vida=10;
    id=3;
};
BTK::~BTK()
{
    //dtor
}

void BTK::Desenha(RenderWindow& window){
    window.draw(corpo);
}

 Vector2f BTK::GetPosition(){
    return corpo.getPosition();
 }

Collider BTK::GetCollider(){
    return Collider(corpo);
}

void BTK::setPosition(float dx,float dy){
    corpo.setPosition(dx, dy);
}

void BTK::Atualiza(float deltaTime){

     counter++;
    if(counter<4000){
       corpo.move(0.f,.1f);
    }

    if(counter>4000){
        corpo.move(0.f,-0.1f);
    }

    if(counter >8000)
        counter=0;

}

bool BTK::GetAtira(){

    counter++;
     btkAtira=false;
     if(counter>2000){
        btkAtira=true;
        counter=0;
     }
}

void BTK::setVida(int x){
     vida=x;
}
int BTK::getVida(){
    return vida;
}
int BTK::getId(){
    return id;
}
