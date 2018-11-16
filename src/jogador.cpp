#include "Jogador.h"

Jogador::Jogador(Texture* texture, Vector2u contImg, float trocaTempo,float velocidade,float jumpHeight):
    anima(texture,contImg,trocaTempo)
{
    this->velocidade=velocidade;
    this->jumpHeight=jumpHeight;
    fileira=0;
    direita=true;
    corpo.setSize(Vector2f(56.0f,96.0f));
    corpo.setOrigin(corpo.getSize()/2.f);
    corpo.setTexture(texture);
    vida=2;
    atira=false;
    counter=0;
}

Jogador::~Jogador()
{
    //dtor
}
void Jogador::OnColisao(Vector2f direction){

    if(direction.x<0.f){
        vel.x=0.f;
    }
    else if(direction.x>0.f){

        vel.x=0.f;//colisao direita
    }
    else if(direction.y<0.f){
        vel.y=0.f;
        canJump=true;
    }
    else if(direction.y>0.f){
        vel.y=0.f;
    }
}

 void Jogador::Atualiza(float deltaTime)
 {

    vel.x=0.f;

    atira=false;
    counter+=1.f;

     if(Keyboard::isKeyPressed(Keyboard::W)&&canJump)
    {
        canJump=false;
        vel.y=-sqrtf(2.f*981.f*jumpHeight);
    }

        vel.y+=981.f*deltaTime;

    if(Keyboard::isKeyPressed(Keyboard::A))
    {
         vel.x -= velocidade;
    }

    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        vel.x += velocidade;
    }

     if(Keyboard::isKeyPressed(Keyboard::Space))
    {
        if(counter>1000){
            atira=true;
            counter=0;
        }
    }
    if(vel.x==0.0f){
        fileira=0;
        if(canJump==false)
            fileira=2;
    }
    else
    {
        if(vel.x>0.f)
            direita=true;
        else
            direita=false;
        if(canJump==false)
            fileira=2;
        else
            fileira=1;
    }

    anima.Atualiza(fileira,deltaTime,direita);
    corpo.setTextureRect(anima.uvRect);
    corpo.move(vel*deltaTime);
 }

 Vector2f Jogador::GetPosition(){
    return corpo.getPosition();
 }

void Jogador::Desenha(RenderWindow& janela){
    janela.draw(corpo);
}

Collider Jogador::GetCollider(){
    return Collider(corpo);
}

int Jogador::getVida(){
    return vida;
}

void Jogador::setVida(int x){
    vida=x;
}

void Jogador::Move(float dx,float dy){
    corpo.move(dx,dy);
}

void Jogador::setPosition(float dx,float dy){
    corpo.setPosition(dx,dy);
}
bool Jogador::GetAtira(){
    return atira;
}
bool Jogador::GetDireita(){
    return direita;
}
