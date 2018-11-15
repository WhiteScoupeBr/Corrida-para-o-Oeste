#include "Fase1.h"

Fase1::Fase1()
{
    background.loadFromFile("fundofase.jpg");
    chao.loadFromFile("chao.png");
    cacto.loadFromFile("cacto.png");
    tnt.loadFromFile("tnt.png");
    fonte.loadFromFile("Carnevalee Freakshow.ttf");
    //sprite(background);

    invPlataforma.push_back(Plataforma(nullptr,Vector2f(400.f,1000.f),Vector2f(-200.f,-50.f)));
    plataformas.push_back(Plataforma(&chao , Vector2f(5600.f, 450.f), Vector2f(2550.f, 200.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(400.f,50.f),Vector2f(500.f,-50.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(200.f,50.f),Vector2f(950.f,-100.f)));

    obs.push_back((Obstaculo*)new Cacto(&cacto,Vector2f(30.f,80.f),Vector2f(200.f,-60.f)));
    obs.push_back((Obstaculo*)new Cacto(&cacto,Vector2f(30.f,80.f),Vector2f(1600.f,-60.f)));
    obs.push_back((Obstaculo*)new Tnt(&tnt,Vector2f(30.f,80.f),Vector2f(1600.f,-60.f)));

}

Fase1::~Fase1()
{
    //dtor
}

void Fase1::Executar(RenderWindow& window,float deltaTime, Jogador& jogador1,View& view){

    Sprite sprite(background);
    sprite.setPosition(-250.f,-800.f);

    std::string aux ("vidas: ");
    std::stringstream aux2;
    aux2 << jogador1.getVida();
    aux += aux2.str();
    vidas.setString(aux);
    vidas.setFont(fonte);
    int antiga=jogador1.getVida();



  for(Plataforma& plataforma : plataformas){
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

    window.draw(sprite);

    for(Plataforma& plataforma : plataformas)
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

    view.setCenter(jogador1.GetPosition().x+150.f,jogador1.GetPosition().y-(100.f));
    vidas.setPosition(jogador1.GetPosition().x-240, jogador1.GetPosition().y-400);

    window.setView(view);
    window.draw(vidas);

}
