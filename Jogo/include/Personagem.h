#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include "Entidade.h"

class Personagem : public Entidade
{
    public:
        Personagem();
        virtual ~Personagem();

    protected:

    private:
        float x;
        float y;
};

#endif // PERSONAGEM_H
