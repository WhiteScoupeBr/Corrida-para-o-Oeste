#include "Fase1.h"

Fase1::Fase1()
{
    background.loadFromFile("fundofase.jpg");
    bar.loadFromFile("Saloon.png");
    chao.loadFromFile("chao.png");
    cacto.loadFromFile("cacto.png");
    tnt.loadFromFile("tnt.png");
    bola.loadFromFile("bola.png");
    bala1.loadFromFile("bala.png");
    bala22.loadFromFile("bala2.png");
    jj.loadFromFile("jj.png");
    fonte.loadFromFile("Carnevalee Freakshow.ttf");


    invChao.push_back(Plataforma(nullptr,Vector2f(10000.f,100.f),Vector2f(90.f,350.f)));

    invPlataforma.push_back(Plataforma(nullptr,Vector2f(400.f,1000.f),Vector2f(-200.f,-50.f)));

    plataformas.push_back(Plataforma(&chao,Vector2f(1000.f, 450.f), Vector2f(90.f, 200.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(100.f,50.f),Vector2f(500.f,-100.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(400.f,50.f),Vector2f(850.f,-180.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(100.f,50.f),Vector2f(1400.f,-100.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(400.f,50.f),Vector2f(1820.f,-180.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(500.f,50.f),Vector2f(2500.f,-230.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(60.f,50.f),Vector2f(3000.f,-100.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(60.f,50.f),Vector2f(3100.f,-180.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(100.f,50.f),Vector2f(3400.f,-240.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(200.f,50.f),Vector2f(3600.f,-240.f)));
    plataformas.push_back(Plataforma(&chao,Vector2f(100.f,50.f),Vector2f(3850.f,-240.f)));


    //obs.push_back((Obstaculo*)new Cacto(&cacto,Vector2f(46.f,80.f),Vector2f(200.f,-60.f)));
    obs.push_back((Obstaculo*)new Cacto(&cacto,Vector2f(46.f,80.f),Vector2f(3025.f,-160.f)));
    obs.push_back((Obstaculo*)new BolaFeno(&bola,Vector2f(30.f,30.f),Vector2f(3500.f,-290.f)));
    obs.push_back((Obstaculo*)new Tnt(&tnt,Vector2f(30.f,30.f),Vector2f(1000.f,-210.f)));

    inimigos.push_back((Inimigo*)new Apache(&cacto,Vector2f(3500.f,-290.f),0.1f));
    inimigos.push_back((Inimigo*)new JJ(&jj,Vector2f(600.f,-150.f),0.1f));

}

Fase1::~Fase1()
{
    //dtor
}

void Fase1::Executar(RenderWindow& window,float deltaTime, Jogador& jogador1,View& view){

    Sprite saloon(bar);
    saloon.setPosition(-260.f,-385.f);
    Sprite sprite(background);
    sprite.setPosition(-250.f,-800.f);

    std::string aux ("vidas: ");
    std::stringstream aux2;
    aux2 << jogador1.getVida();
    aux += aux2.str();
    vidas.setString(aux);
    vidas.setFont(fonte);
    int antiga=jogador1.getVida();
    int caux=0;

    if(jogador1.GetAtira()==true){
        bala.push_back(Projetil(&bala1,Vector2f(10.0f,4.f),Vector2f(jogador1.GetPosition().x+22.f,jogador1.GetPosition().y-19.f),jogador1));
    }

    for(Inimigo* inimigo1 : inimigos){
        if(inimigo1->GetAtira())
            bala2.push_back(ProjInimigo(&bala22,Vector2f(10.f,4.f),Vector2f(inimigo1->GetPosition().x-22.f,inimigo1->GetPosition().y-22.f)));
    }

  for(Projetil& tiro : bala)
        tiro.Atualiza();
  for(ProjInimigo& tiro : bala2)
        tiro.Atualiza();

    for(Inimigo* inimigo1 : inimigos)
        inimigo1->Atualiza(deltaTime);

  for(Projetil& tiro : bala){
        for(caux=0;caux<inimigos.size(); caux++){
            tiro.Atualiza();
            Collider(plat1)=inimigos[caux]->GetCollider();
            if(tiro.GetCollider().CheckColisao(plat1,direction,1.f)){
               inimigos.erase(inimigos.begin()+caux);
            }
        }
  }

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
        obstaculo->Atualiza(deltaTime);
        if(obstaculo->GetCollider().CheckColisao(plat1,direction,1.f)){
            jogador1.OnColisao(direction);
            for(int cMove =0;cMove<10000;cMove++)
                jogador1.Move(-.005f,-.001f);
            jogador1.setVida((jogador1.getVida())-1);
            if(jogador1.getVida()==-1)
            {
                jogador1.setPosition(0.f,-400.f);
                jogador1.setVida(2);
            }
        }
    }

    for(Inimigo* inimigo1: inimigos){
        Collider(plat1)=jogador1.GetCollider();
        inimigo1->Atualiza(deltaTime);
        if(inimigo1->GetCollider().CheckColisao(plat1,direction,1.f)){
            jogador1.OnColisao(direction);
            for(int cMove =0;cMove<10000;cMove++)
                jogador1.Move(-.005f,-.001f);
            jogador1.setVida((jogador1.getVida())-1);
            if(jogador1.getVida()==-1)
            {
                jogador1.setPosition(0.f,-400.f);
                jogador1.setVida(5);
            }
        }
    }

     for(caux=0; caux<bala2.size();caux++){
        Collider(plat1)=jogador1.GetCollider();
        bala2[caux].Atualiza();
        if(bala2[caux].GetCollider().CheckColisao(plat1,direction,1.f)){
            jogador1.OnColisao(direction);
            bala2.erase(bala2.begin() +caux);
            for(int cMove =0;cMove<10000;cMove++)
                jogador1.Move(-.005f,-.001f);
            jogador1.setVida((jogador1.getVida())-2);
            if(jogador1.getVida()==-1)
            {
                jogador1.setPosition(0.f,-400.f);
                jogador1.setVida(5);
            }
        }
    }

     for(Plataforma plataforma: invChao){
        Collider(plat1)=jogador1.GetCollider();
        if(plataforma.GetCollider().CheckColisao(plat1,direction,1.f)){
            jogador1.OnColisao(direction);
            jogador1.setVida((jogador1.getVida())-1);
            if(jogador1.getVida()==-1)
            {
                jogador1.setPosition(0.f,-400.f);
                jogador1.setVida(2);
            }
        }
    }

    window.draw(sprite);
    window.draw(saloon);

    for(Plataforma& plataforma : plataformas)
        plataforma.Desenha(window);
    for(Obstaculo* obstaculo : obs)
        obstaculo->Desenha(window);
    for(Projetil tiro : bala)
        tiro.Desenha(window);
    for(Inimigo* inimigo : inimigos)
        inimigo->Desenha(window);
    for(ProjInimigo tiro : bala2)
        tiro.Desenha(window);


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
