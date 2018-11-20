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
    if(counter<1000){
       corpo.move(0.f,-0.1f);
    }

    if(counter>1000){
        corpo.move(0.f,0.1);
    }

    if(counter >2000)
        counter=0;

    btkAtira=false;

    if(counter%500==0)
    {
        btkAtira=true;
    }
}

bool BTK::GetAtira()const{
    return btkAtira;
}

void BTK::setVida(int x){
     vida=x;
}
int BTK::getVida()const{
    return vida;
}
int BTK::getId()const{
    return id;
}
