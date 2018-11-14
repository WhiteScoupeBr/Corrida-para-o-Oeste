#include "Entidade.h"

Entidade::Entidade()
{
    //m_collisions=NULL;
    //ctor
}

Entidade::~Entidade()
{
    //dtor
}
void Entidade::setVelocidade(Vector2f vel)
{
 entVel = vel;
}
void Entidade::setVelocidade(float vx, float vy)
{
 entVel.x = vx;
 entVel.y = vy;
}
sf::Vector2f Entidade::getVelocidade() const
{
 return entVel;
}
