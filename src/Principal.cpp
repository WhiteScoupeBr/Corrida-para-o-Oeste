#include "Principal.h"


Principal::Principal()
{

}

Principal::~Principal()
{
    //dtor
}


void Principal::Executar()
{

    RenderWindow window(sf::VideoMode(800, 600), "Corrida para o Oeste",Style::Close|Style::Titlebar);

    Texture textureJogador1, textureJogador2;;
    textureJogador1.loadFromFile("sprite2.png");
    textureJogador2.loadFromFile("sprite22.png");
    Jogador jogador1(&textureJogador1,Vector2u(8,12),0.1f,200.0f,128.f);
    Jogador2 jogador2(&textureJogador2,Vector2u(8,12),0.1f,200.0f,128.f);

    View view(Vector2f(0.0f,0.0f), Vector2f(800.f,600.f));

    Vector2u textureSize = textureJogador1.getSize();
    textureSize.x/=8;
    textureSize.y/=12;

    Vector2u textureSize2 = textureJogador2.getSize();
    textureSize2.x/=8;
    textureSize2.y/=12;

    Music music,music2;
    music.openFromFile("Cash.wav");
    music2.openFromFile("Good.wav");

    Fase1 fase1;
    Fase2 fase2;

    Menu menu1(window.getSize().x, window.getSize().y);
    //Menu2 menu2(window.getSize().x, window.getSize().y);

    Pause pause (window.getSize().x, window.getSize().y);



    float deltaTime=0.0f;
    Clock relogio;


    while (window.isOpen())
    {
        deltaTime = relogio.restart().asSeconds();
        if(deltaTime>1.f/20.f)
            deltaTime=1.f/20.f;

        Event event;

        if(desenhaMenu==true||desenhaMenu2==true){
            music2.play();
        }

        while (window.pollEvent(event))
        {
            if(desenhaMenu==true)
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        menu1.MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        menu1.MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menu1.GetPressedItem())
                        {
                        case 0:
                            fase1Pronta=true;
                            menu1.Altera(window.getSize().x, window.getSize().y);
                            desenhaMenu=false;
                            desenhaMenu2=true;
                            break;
                        case 1:
                            fase1Pronta=false;
                            menu1.Altera(window.getSize().x, window.getSize().y);
                            desenhaMenu2=true;
                            desenhaMenu=false;
                            Sleep(500);
                            break;
                        case 2:
                            {
                                _game =true;
                                desenhaMenu=false;
                                _save=true;
                                string line;
                                ifstream save("save.txt");
                                if(save.is_open()){
                                    while (getline(save,line)){
                                        stringstream ss(line);
                                        getline(ss,fase1t,',');
                                        getline(ss,jog2,',');
                                        getline(ss,posx,',');
                                        getline(ss,posy,',');
                                    }
                                }
                                else
                                    printf("Error opening save!");
                              istringstream(fase1t) >> fase1Pronta;
                              istringstream(jog2) >> jogoPronto2;
                              _posx = std::stof(posx);
                              _posy = std::stof (posy);
                            }
                            break;
                        case 3:
                            window.close();
                            break;
                        }
                        break;
                    }
                }

            }

              if(desenhaMenu2==true)
            {

                switch (event.type)
                {
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        menu1.MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        menu1.MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menu1.GetPressedItem())
                        {
                        case 0:
                            jogoPronto2=false;
                            _game =true;
                            desenhaMenu=false;
                            desenhaMenu2=false;
                            break;
                        case 1:
                            jogoPronto2=true;
                            _game =true;
                            desenhaMenu=false;
                            desenhaMenu2=false;
                            break;
                        case 2:
                            window.close();
                            break;

                        }
                        break;
                    }
                }
            }

            if (event.type == sf::Event::Closed)
                window.close();



            if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
            {
                _pause=true;
                Sleep(500);
            }

            if(_pause==true){
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        pause.MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        pause.MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (pause.GetPressedItem())
                        {
                        case 0:
                            _pause=false;
                            break;
                        case 1:
                            {
                                ofstream myfile ("save.txt");
                                if (myfile.is_open())
                                {
                                  myfile << fase1Pronta;
                                  myfile << ",";
                                  myfile << jogoPronto2;
                                  myfile << ",";
                                  myfile << jogador1.GetPosition().x;
                                  myfile << ",";
                                  myfile << jogador1.GetPosition().y;
                                myfile.close();
                                printf("Saved!");
                                }

                                else
                                    printf("Unable to save!");

                            }
                            break;
                        case 2:
                            window.close();
                            break;

                        }
                        break;
                    }
                }
            }

        }

        if(_game){


        if (jogoPronto2==false && fase1Pronta)
        {
            if(_save){
                jogador1.setPosition(_posx,_posy);
                _save=false;
            }
            fase1.Executar(window,deltaTime,jogador1,view);
            jogador1.Desenha(window);
            if(_pause==false)
            {
                jogador1.Atualiza(deltaTime);
                fase1.Atualiza(deltaTime);

            }
        }
        else if (jogoPronto2==true && fase1Pronta)
        {
            if(_save){
                jogador1.setPosition(_posx,_posy);
                jogador2.setPosition(_posx,_posy);
                _save=false;
            }
            fase1.Executar2(window,deltaTime,jogador1,view,jogador2);
            jogador2.Desenha(window);
            jogador1.Desenha(window);

            if(_pause==false)
            {
                jogador1.Atualiza(deltaTime);
                jogador2.Atualiza(deltaTime);
                fase1.Atualiza2(deltaTime);

            }
        }
        else if (jogoPronto2==false && fase1Pronta==false)
        {
            if(_save){
                jogador1.setPosition(_posx,_posy);
                _save=false;
            }
            fase2.Executar(window,deltaTime,jogador1,view);
            jogador1.Desenha(window);
            if(_pause==false){
                jogador1.Atualiza(deltaTime);
                fase2.Atualiza(deltaTime);
            }
        }
         else if (jogoPronto2==true && fase1Pronta==false)
        {
            if(_save){
                jogador1.setPosition(_posx,_posy);
                jogador2.setPosition(_posx,_posy);
                _save=false;
            }
            fase2.Executar2(window,deltaTime,jogador1,view,jogador2);
            jogador2.Desenha(window);
            jogador1.Desenha(window);

            if(_pause==false)
            {
                jogador1.Atualiza(deltaTime);
                jogador2.Atualiza(deltaTime);
                fase2.Atualiza2(deltaTime);
            }
        }
        }

        if (desenhaMenu==true)
        {
            menu1.Desenha(window);
        }
        if (desenhaMenu2==true)
        {
            menu1.Desenha(window);
        }

        if(_pause)
        {
            pause.setPosition(jogador1.GetPosition().x,jogador1.GetPosition().y);
            pause.Desenha(window);
        }

        window.display();
        window.clear();
    }
}
