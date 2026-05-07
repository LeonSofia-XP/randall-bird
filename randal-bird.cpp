#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

struct mov{
 float y;
 float yv;
 float ya;


};


int main()
 {

  sf::RenderWindow f;
  f.create(sf::VideoMode(400, 600), "RANDALL BIRD :P");

  sf::Texture rand;
  rand.loadFromFile("player.jpg");
  sf::Sprite player;
  player.setTexture(rand);
  player.setPosition(50, 150);
  player.setScale(0.2f, 0.2f);


  sf::Font Letra;
  if(!Letra.loadFromFile("LuckiestGuy-Regular.ttf")){
  return 1;
  }
  sf::Text go("¡PERDISTE! XD", Letra, 20);
   go.setFillColor(sf::Color::White);
   go.setPosition(60, 200);

  const float gravedad = 0.01f;

  mov jugador;
  jugador.y = player.getPosition().y;
  jugador.yv = 0.0f;
  jugador.ya = gravedad;

  bool gameover = false;

  while (f.isOpen()){
   sf::Event ev;
   while (f.pollEvent(ev)){
    if (ev.type == sf::Event::Closed)
      f.close();
   }

  if(gameover == false  && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    jugador.yv = -1.f;
  }

  if(gameover == false){
  jugador.yv +=  jugador.ya;
  jugador.y += jugador.yv;
  }

  if(jugador.y >= 600 || jugador.y <= 0){
  gameover = true;
  }

  player.setPosition(50, jugador.y);


  f.clear(sf::Color::Yellow);

  if(gameover){
  f.draw(go);
  }
  else{
  f.draw(player);
  }


 if(gameover && sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
   player.setPosition(50, 150);
   jugador.y = player.getPosition().y;
   jugador.yv = 0.0f;
   gameover = false;

 }


  f.display();


  }
 }


