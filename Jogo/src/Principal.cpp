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
    Texture testeTexture,background,chao,cacto,tnt;
    View view(Vector2f(0.0f,0.0f), Vector2f(800.f,600.f));
    testeTexture.loadFromFile("sprite2.png");
    background.loadFromFile("fundofase.jpg");
    chao.loadFromFile("chao.png");
    cacto.loadFromFile("cacto.png");
    tnt.loadFromFile("tnt.png");
    Vector2u textureSize = testeTexture.getSize();
    textureSize.x/=8;
    textureSize.y/=12;
    Sprite sprite(background);
    sprite.setPosition(-250.f,-800.f);
    Jogador jogador1(&testeTexture,Vector2u(8,12),0.1f,200.0f,128.f);

    float deltaTime=0.0f;
    Clock relogio;

    Font fonte;
    fonte.loadFromFile("Carnevalee Freakshow.ttf");
    Text vidas;
    std::string aux ("vidas: ");
    std::stringstream aux2;
    aux2 << jogador1.getVida();
    aux += aux2.str();
    vidas.setString(aux);
    vidas.setFont(fonte);
    int antiga=jogador1.getVida();



   // Plataforma plataforma1(,Vector2f (400.f,100.f),Vector2f(jogador1.GetPosition().x-150.f,jogador1.GetPosition().y-(150.f)));
    vector<Plataforma>vPlataforma;
    vector<Plataforma>invPlataforma;
    vector<Obstaculo*>obs;

    vPlataforma.push_back(Plataforma(&chao,Vector2f(5600.f,450.f),Vector2f(2550.f,200.f)));
    invPlataforma.push_back(Plataforma(nullptr,Vector2f(400.f,1000.f),Vector2f(-200.f,-60.f)));
    vPlataforma.push_back(Plataforma(&chao,Vector2f(400.f,50.f),Vector2f(500.f,-50.f)));
    vPlataforma.push_back(Plataforma(&chao,Vector2f(200.f,50.f),Vector2f(950.f,-100.f)));

    obs.push_back((Obstaculo*)new Cacto(&cacto,Vector2f(30.f,80.f),Vector2f(1100.f,-60.f)));
    obs.push_back((Obstaculo*)new Cacto(&cacto,Vector2f(30.f,80.f),Vector2f(1400.f,-60.f)));
    obs.push_back((Obstaculo*)new Tnt(&tnt,Vector2f(30.f,30.f),Vector2f(1250.f,-60.f)));


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
        for(Obstaculo* obstaculo: obs){
            Collider(plat1)=jogador1.GetCollider();
            if(obstaculo->GetCollider().CheckColisao(plat1,direction,1.f)){
                jogador1.OnColisao(direction);
                jogador1.Move(-50.f,-100.f);
                jogador1.setVida((jogador1.getVida())-1);
                if(jogador1.getVida()==-1)
                {
                    jogador1.setPosition(0.f,-400.f);
                    jogador1.setVida(2);
                }
            }
        }


        view.setCenter(jogador1.GetPosition().x+150.f,jogador1.GetPosition().y-(100.f));
        vidas.setPosition(jogador1.GetPosition().x-240, jogador1.GetPosition().y-400);
        window.clear();
        window.draw(sprite);
        window.setView(view);
        jogador1.Desenha(window);
        for(Plataforma& plataforma : vPlataforma)
            plataforma.Desenha(window);
        for(Obstaculo* obstaculo : obs)
            obstaculo->Desenha(window);
        if (jogador1.getVida()!=antiga)
        {
            aux2.str("");
            aux2 << jogador1.getVida();
            aux = ("vidas: ");
            aux += aux2.str();
            vidas.setString(aux);
            antiga=jogador1.getVida();
        }
        window.draw(vidas);
        window.display();
    }


}
