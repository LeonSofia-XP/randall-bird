#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

struct mov{
 float y;
 float yv;
 float ya;

}


int main()
 {

  sf::RenderWindow f;
  f.create(sf::VideoMode(400, 600), "RANDALL BIRD :P");

  sf::Texture rand;
  rand.loadFromFile("player.jpg");
  sf::Sprite player;
  player.setTexture(rand);
  player.setPosition(50, 150),
  player.setScale(0.2f, 0.2f);


  const float gravedad;

  mov player;
  player.y = player.getPosition().y;
  player.yv = 0.0f;
  player.ya = gravedad;

  while (f.isOpen()){
   sf::Event cerrar;
   while (f.pollEvent(cerrar)){
    if (cerrar.type == sf::Event::Closed)
      f.close();

  }

  player.yv += player.ya;
  player.y += player.yv;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    player.yv = -10.f;


  f.clear(sf::Color::Yellow);
  f.draw(player);
  f.display();
 }

 return 0;
 }

