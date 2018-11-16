#include "Principal.h"

Principal::Principal()
{

}

Principal::~Principal()
{
    //dtor
}

void Principal::Executar(){

    RenderWindow window(sf::VideoMode(800, 600), "Corrida para o Oeste",Style::Close|Style::Titlebar);

    Texture testeTexture;
    testeTexture.loadFromFile("sprite2.png");
    Jogador jogador1(&testeTexture,Vector2u(8,12),0.1f,200.0f,128.f);

    Vector2u textureSize = testeTexture.getSize();
    textureSize.x/=8;
    textureSize.y/=12;

    Fase1 fase1;

    View view(Vector2f(0.0f,0.0f), Vector2f(800.f,600.f));

    float deltaTime=0.0f;
    Clock relogio;

    while (window.isOpen())
    {
        deltaTime = relogio.restart().asSeconds();
        if(deltaTime>1.f/20.f)
            deltaTime=1.f/20.f;

        Event evt;
        while (window.pollEvent(evt))
        {
            if (evt.type == Event::Closed)
                window.close();
        }
        jogador1.Atualiza(deltaTime);
        fase1.Executar(window,deltaTime,jogador1,view);
        jogador1.Desenha(window);
        window.display();
        window.clear();
    }
}
