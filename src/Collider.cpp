#include "Collider.h"


Collider::Collider(RectangleShape& corpo)
:corpo(corpo)
{

}

Collider::~Collider()
{
    //dtor
}

void Collider::Movimento(float dx,float dy){
    corpo.move(dx,dy);
 }
bool Collider::CheckColisao(Collider outro,Vector2f& direction, float push){

    Vector2f outraposicao = outro.GetPosicao();
    Vector2f outroMeiaMedida = outro.GetMeiaMedida();
    Vector2f thisposicao = GetPosicao();
    Vector2f thisMeiaMedida = GetMeiaMedida();

    float deltax = outraposicao.x - thisposicao.x;
    float deltay = outraposicao.y - thisposicao.y;
    float intersecX = abs(deltax) - (outroMeiaMedida.x + thisMeiaMedida.x);
    float intersecY = abs(deltay) - (outroMeiaMedida.y + thisMeiaMedida.y);

    if(intersecX<0.0f && intersecY<0.0f){

        push = min(max(push,0.0f), 1.0f);

        if((intersecX)>(intersecY)){
            if(deltax>0.0f){
                Movimento(intersecX*(1.0f-push),0.0f);
                outro.Movimento(-intersecX*push,0.0f);

                direction.x=1.f;
                direction.y=0.f;
            }
            else{
                Movimento(-intersecX*(1.0f-push),0.0f);
                outro.Movimento(intersecX*push,0.0f);
                direction.x=-1.f;
                direction.y=0.f;
            }
        }
        else{
            if(deltay>0.0f){
                Movimento(0.0f,intersecY*(1.0f-push));
                outro.Movimento(0.0f,-intersecY*push);
                direction.x=0.f;
                direction.y=1.f;
            }
            else{
                Movimento(0.0f,-intersecY*(1.0f-push));
                outro.Movimento(0.0f,intersecY*push);
                direction.x=0.f;
                direction.y=-1.f;
            }
        }
        return true;
    }
    return false;
}

Vector2f Collider:: GetPosicao(){
    return corpo.getPosition();
}
Vector2f Collider::GetMeiaMedida(){
    return corpo.getSize()/2.0f;
}
