#ifndef ENTIDADE_H
#define ENTIDADE_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Entidade
{
    public:
        Entidade();
        virtual ~Entidade();
        void setVelocidade(Vector2f vel);
        void setVelocidade(float vx,float vy);
        Vector2f getVelocidade()const;

    protected:
    private:
        Vector2f entVel;
};

#endif // ENTIDADE_H
