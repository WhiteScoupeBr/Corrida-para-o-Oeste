#include "Principal.h"

Principal::Principal()
{
    //ctor
}

Principal::~Principal()
{
    //dtor
}

void Principal::Executar(){


    RenderWindow window(sf::VideoMode(800, 600), "Corrida para o Oeste",Style::Close|Style::Titlebar);
    Texture testeTexture,background,chao;
    View view(Vector2f(0.0f,0.0f), Vector2f(800.f,600.f));
    testeTexture.loadFromFile("sprite1.png");
    background.loadFromFile("fundogrande.jpg");
    chao.loadFromFile("chao.png");
    Vector2u textureSize=testeTexture.getSize();
    textureSize.x/=8;
    textureSize.y/=12;
    Sprite sprite(background);
    sprite.setPosition(-250.f,-800.f);
    Jogador jogador1(&testeTexture,Vector2u(8,12),0.1f,200.0f,128.f);
    //jogador1.setPosicao(2500.f,300.f);
    float deltaTime=0.0f;
    Clock relogio;



   // Plataforma plataforma1(,Vector2f (400.f,100.f),Vector2f(jogador1.GetPosition().x-150.f,jogador1.GetPosition().y-(150.f)));
    vector<Plataforma>vPlataforma;
    vector<Plataforma>invPlataforma;

    vPlataforma.push_back(Plataforma(&chao,Vector2f(5600.f,450.f),Vector2f(2550.f,200.f)));
    invPlataforma.push_back(Plataforma(nullptr,Vector2f(400.f,1000.f),Vector2f(-200.f,-50.f)));
    vPlataforma.push_back(Plataforma(&chao,Vector2f(400.f,50.f),Vector2f(500.f,-50.f)));
     vPlataforma.push_back(Plataforma(&chao,Vector2f(200.f,50.f),Vector2f(950.f,-100.f)));



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

        //Collider (plat1)=jogador1.GetCollider();
        //plataforma1.GetCollider().CheckColisao(plat1,1.f);

        jogador1.Atualiza(deltaTime);

        Vector2f direction;


        for(Plataforma& plataforma : vPlataforma){
            Collider(plat1)=jogador1.GetCollider();
            if(plataforma.GetCollider().CheckColisao(plat1,direction,1.f))
                jogador1.OnColisao(direction);
        }
        for(Plataforma& plataforma : invPlataforma){
            Collider(plat1)=jogador1.GetCollider();
            if(plataforma.GetCollider().CheckColisao(plat1,direction,1.f))
                jogador1.OnColisao(direction);
        }

        view.setCenter(jogador1.GetPosition().x+150.f,jogador1.GetPosition().y-(100.f));
        window.clear();
        window.draw(sprite);
        window.setView(view);
        jogador1.Desenha(window);
        for(Plataforma& plataforma : vPlataforma)
            plataforma.Desenha(window);
        window.display();
    }


}
