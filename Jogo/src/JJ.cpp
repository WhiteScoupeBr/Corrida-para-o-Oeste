#include "JJ.h"


JJ::JJ(Texture* texture,Vector2f posicao, float trocaTempo)
{
    fileira=0;
    corpo.setSize(Vector2f(56.0f,96.0f));
    corpo.setOrigin(corpo.getSize()/2.f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
    jjAtira=false;
    vida=1;
    id=2;
};
JJ::~JJ()
{
    //dtor
}

void JJ::Desenha(RenderWindow& window){
    window.draw(corpo);
}

 Vector2f JJ::GetPosition(){
    return corpo.getPosition();
 }

Collider JJ::GetCollider(){
    return Collider(corpo);
}

void JJ::setPosition(float dx,float dy){
    corpo.setPosition(dx, dy);
}

void JJ::Atualiza(float deltaTime){

     counter++;
     jjAtira=false;
     if(counter>4000){
        jjAtira=true;
        counter=0;
     }
}

bool JJ::GetAtira(){
    return jjAtira;
}

void JJ::setVida(int x){
     vida=x;
}
int JJ::getVida(){
    return vida;
}
int JJ::getId(){
    return id;
}
