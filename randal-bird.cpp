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


  const float gravedad = 0.1f;

  mov jugador;
  jugador.y = player.getPosition().y;
  jugador.yv = 0.0f;
  jugador.ya = gravedad;

  while (f.isOpen()){
   sf::Event cerrar;
   while (f.pollEvent(cerrar)){
    if (cerrar.type == sf::Event::Closed)
      f.close();

  }

  jugador.yv += jugador.ya;
  jugador.y += jugador.yv;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    jugador.yv = -30.f;

  player.setPosition(50,jugador.y);

  f.clear(sf::Color::Yellow);
  f.draw(player);
  f.display();
 }

 return 0;
 }

