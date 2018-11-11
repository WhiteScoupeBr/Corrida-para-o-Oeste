#include "Animacao.h"

Animacao::Animacao(Texture* texture, Vector2u contImg, float trocaTempo)
{
    this->contImg=contImg;
    this->trocaTempo=trocaTempo;
    tempoTotal=0.0f;
    atualImg.x=0;

    uvRect.width = texture->getSize().x/float(contImg.x);
    uvRect.height = texture->getSize().y/float(contImg.y);

}

Animacao::~Animacao()
{
    //dtor
}

void Animacao::Atualiza(int fileira, float deltaTime, bool direita){
    atualImg.y=fileira;
    tempoTotal+=deltaTime;

    if(tempoTotal>=trocaTempo){
        tempoTotal-=trocaTempo;
        atualImg.x++;
    }

    if(atualImg.x>=contImg.x){
        atualImg.x=0;
    }

    uvRect.left=atualImg.x*uvRect.width;
    uvRect.top= atualImg.y*uvRect.height;

    if(direita){
        uvRect.left=atualImg.x*uvRect.width;
        uvRect.width=abs(uvRect.width);
    }
    else{
        uvRect.left=(atualImg.x+1)*abs(uvRect.width);
        uvRect.width=-abs(uvRect.width);
    }

}
