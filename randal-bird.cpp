#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <iostream>


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


  const float gravedad = 0.01f;

  mov jugador;
  jugador.y = player.getPosition().y;
  jugador.yv = 0.3f;
  jugador.ya = gravedad;

  while (f.isOpen()){
   sf::Event ev;
   while (f.pollEvent(ev)){
    if (ev.type == sf::Event::Closed)
      f.close();
     if (ev.key.code == sf::Keyboard::Space && jugador.y >= 500){
    jugador.yv = - 0.9f;

   }


  jugador.yv +=  jugador.ya;
  jugador.y += jugador.yv;


  player.setPosition(50, jugador.y);


  f.clear(sf::Color::Yellow);
  f.draw(player);
  f.display();

  }
 }
}
