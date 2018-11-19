#include "Apache.h"

Apache::Apache(Texture* texture, Vector2f posicao,Vector2u contImg, float trocaTempo):
anima(texture,contImg,trocaTempo)
{
    fileira=0;
    corpo.setSize(Vector2f(56.0f,96.0f));
    corpo.setOrigin(corpo.getSize()/2.f);
    corpo.setTexture(texture);
    corpo.setPosition(posicao);
    vida =2;
    id=1;
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
        direita = true;
    }
    if(counter>4000){
        corpo.move(-.06f,0.f);
        direita =false;
    }

    if(counter >8000)
        counter=0;

    anima.Atualiza(0,deltaTime,direita);
    corpo.setTextureRect(anima.uvRect);

}

bool Apache::GetAtira(){
    return false;
}

void Apache::setVida(int x){
     vida=x;
}
int Apache::getVida(){
    return vida;
}
int Apache::getId(){
    return id;
}
