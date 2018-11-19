#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Collider
{
    public:
        Collider(RectangleShape& corpo);
        virtual ~Collider();

        void Movimento (float dx,float dy);
        bool CheckColisao(Collider outro,Vector2f& direction, float push);
        Vector2f GetPosicao();
        Vector2f GetMeiaMedida();

    protected:

    private:
        RectangleShape& corpo;
};

#endif // COLLIDER_H
