#include "Apache.h"

Apache::Apache(Texture* texture, Vector2u contImg, float trocaTempo,float velocidade,float jumpHeight):
anima(texture,contImg,trocaTempo)
{
    this->velocidade=velocidade;
    this->jumpHeight=jumpHeight;
    fileira=0;
    direita=true;
    corpo.setSize(Vector2f(56.0f,96.0f));
    corpo.setOrigin(corpo.getSize()/2.f);
    corpo.setTexture(texture);
};
Apache::~Apache()
{
    //dtor
}
