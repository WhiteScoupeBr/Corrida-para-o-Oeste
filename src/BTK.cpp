#include "BTK.h"


BTK::BTK(Texture* texture, Vector2f posicao,Vector2u contImg, float trocaTempo):
anima(texture,contImg,trocaTempo)
{
    fileira=0;
    corpo.setSize(Vector2f(56.0f,96.0f));
    corpo.setOrigin(corpo.getSize()/2.f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
    btkAtira=false;
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

    anima.Atualiza(0,deltaTime,direita);
    corpo.setTextureRect(anima.uvRect);

}

bool BTK::GetAtira(){

    counter++;
     btkAtira=false;
     if(counter>2000){
        btkAtira=true;
        counter=0;
     }
}
