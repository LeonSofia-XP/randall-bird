#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
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

  while (f.isOpen()){
   sf::Event cerrar;
   while (f.pollEvent(cerrar)){
    if (cerrar.type == sf::Event::Closed)
      f.close();

  }
  f.clear(sf::Color::Yellow);
  f.draw(player);
  f.display();
 }

 return 0;
 }


