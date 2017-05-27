#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"
#include "GameServer.hpp"

int main() {
  sf::RenderWindow window;

  unsigned currentId = 0;
<<<<<<< HEAD
  Server server(53000);


  Game game;

  if (!game.loadFile("ressources/GreatLake.txt")) {
    std::cout << "Error loading file" << std::endl;
    return -1;
  }

  game.addPlayer(sf::Color::Blue, sf::Vector2f(2, 8));
  game.addPlayer(sf::Color::Red, sf::Vector2f(35, 35));

  auto map = game.getMap();
  unsigned n = map.size();
  unsigned m = map[0].size();

  std::vector<sf::RectangleShape> rects;

=======

  std::shared_ptr<Game> game = std::make_shared<Game>();
  game->loadFile("ressources/level.txt");
  game->addPlayer(sf::Color::Blue, sf::Vector2f(2, 7));
  game->addPlayer(sf::Color::Red, sf::Vector2f(28, 28));
  GameServer gameServer(53000, game);

  std::vector<sf::RectangleShape> rects;

  auto map = game->getMap();
  auto n = map.size();
  auto m = map[0].size();
>>>>>>> origin/advancedServerImplement
  for (unsigned i{0}; i < n; i++) {
    for (unsigned j{0}; j < m; j++) {
      sf::RectangleShape rect(sf::Vector2f(TILESIZE, TILESIZE));
      if (map[j][i] == 1) rect.setFillColor(sf::Color(70, 190, 70));
      if (map[j][i] == 2) rect.setFillColor(sf::Color(0, 50, 10));
      if (map[j][i] == 3) rect.setFillColor(sf::Color(0, 100, 255));
<<<<<<< HEAD
      if (map[j][i] == 4) rect.setFillColor(sf::Color(0, 100, 10));
      if (map[j][i] == 5) rect.setFillColor(sf::Color(193, 172, 81));
=======
>>>>>>> origin/advancedServerImplement
      rect.setPosition(sf::Vector2f(i * TILESIZE, j * TILESIZE));
      rects.push_back(rect);
    }
  }

  window.create(sf::VideoMode(n * TILESIZE, m * TILESIZE), "Serveur");
<<<<<<< HEAD
  std::string input;
=======
>>>>>>> origin/advancedServerImplement

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;

        case sf::Event::KeyPressed:
          switch (event.key.code) {
            case sf::Keyboard::Up:
              game->moveEntity(Direction::Up, sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::Down:
              game->moveEntity(Direction::Down, sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::Left:
              game->moveEntity(Direction::Left, sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::Right:
              game->moveEntity(Direction::Right, sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::Space:
              game->collectRessource(Direction::Up, sf::Color::Blue, currentId);
              game->collectRessource(Direction::Down, sf::Color::Blue,
                                    currentId);
              game->collectRessource(Direction::Left, sf::Color::Blue,
                                    currentId);
              game->collectRessource(Direction::Right, sf::Color::Blue,
                                    currentId);
              break;

            case sf::Keyboard::Return:
              game->putRessourcesInTown(Direction::Up, sf::Color::Blue,
                                       currentId);
              game->putRessourcesInTown(Direction::Down, sf::Color::Blue,
                                       currentId);
              game->putRessourcesInTown(Direction::Left, sf::Color::Blue,
                                       currentId);
              game->putRessourcesInTown(Direction::Right, sf::Color::Blue,
                                       currentId);
              std::cout << "player wood : "
                        << game->getPlayer(sf::Color::Blue)
                               .getRessources(Ressource::Wood)
                        << std::endl;
              break;

            case sf::Keyboard::B:
              game->addBuilding(BuildingType::Fort, sf::Color::Blue, currentId);
              std::cout << "player wood : "
                        << game->getPlayer(sf::Color::Blue)
                               .getRessources(Ressource::Wood)
                        << std::endl;
              break;

            case sf::Keyboard::V:
              game->addEntity(EntityType::Villager, sf::Color::Blue, 0);
              std::cout << "player wood : "
                        << game->getPlayer(sf::Color::Blue)
                               .getRessources(Ressource::Wood)
                        << std::endl;
              break;

            case sf::Keyboard::W:
              game->addEntity(EntityType::Warrior, sf::Color::Blue, 1);
              std::cout << "player wood : "
                        << game->getPlayer(sf::Color::Blue)
                               .getRessources(Ressource::Wood)
                        << std::endl;
              break;

            case sf::Keyboard::A:
              game->attack(sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::Add:
              currentId++;
              if (currentId >=
                  game->getPlayer(sf::Color::Blue).getEntities().size()) {
                currentId = 0;
              }
              break;

            case sf::Keyboard::Subtract:
              currentId--;
              if (currentId < 0) {
                currentId =
                    game->getPlayer(sf::Color::Blue).getEntities().size() - 1;
              }
              break;

            default:
              break;
          }
          break;

        case sf::Event::KeyPressed:
          switch (event.key.code) {
            case sf::Keyboard::Up:
              game.moveEntity(Direction::Up, sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::Down:
              game.moveEntity(Direction::Down, sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::Left:
              game.moveEntity(Direction::Left, sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::Right:
              game.moveEntity(Direction::Right, sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::Space:
              game.collectRessource(Direction::Up, sf::Color::Blue, currentId);
              game.collectRessource(Direction::Down, sf::Color::Blue,
                                    currentId);
              game.collectRessource(Direction::Left, sf::Color::Blue,
                                    currentId);
              game.collectRessource(Direction::Right, sf::Color::Blue,
                                    currentId);
              break;

            case sf::Keyboard::Return:
              game.putRessourcesInTown(Direction::Up, sf::Color::Blue,
                                       currentId);
              game.putRessourcesInTown(Direction::Down, sf::Color::Blue,
                                       currentId);
              game.putRessourcesInTown(Direction::Left, sf::Color::Blue,
                                       currentId);
              game.putRessourcesInTown(Direction::Right, sf::Color::Blue,
                                       currentId);
              std::cout << "food : "
                        << game.getPlayer(sf::Color::Blue)
                               .getRessources(Ressource::Food)
                        << std::endl;
              std::cout << "wood : "
                        << game.getPlayer(sf::Color::Blue)
                               .getRessources(Ressource::Wood)
                        << std::endl;
              std::cout << "gold : "
                        << game.getPlayer(sf::Color::Blue)
                               .getRessources(Ressource::Gold)
                        << std::endl;
              break;
              
            case sf::Keyboard::B:
              game.addBuilding(BuildingType::Fort, sf::Color::Blue, currentId);
              break;

            case sf::Keyboard::S:
              game.addBuilding(BuildingType::Stable, sf::Color::Blue,
                               currentId);
              break;

            case sf::Keyboard::V: {
              for (unsigned i{0};
                   i < game.getPlayer(sf::Color::Blue).getBuildings().size();
                   i++) {
                if (game.getPlayer(sf::Color::Blue)
                        .getBuildings()[i]
                        .getType() == BuildingType::TownCenter) {
                  game.addEntity(EntityType::Villager, sf::Color::Blue, i);
                  break;
                }
              }
            } break;

            case sf::Keyboard::W: {
              for (unsigned i{0};
                   i < game.getPlayer(sf::Color::Blue).getBuildings().size();
                   i++) {
                if (game.getPlayer(sf::Color::Blue)
                        .getBuildings()[i]
                        .getType() == BuildingType::Fort) {
                  game.addEntity(EntityType::Warrior, sf::Color::Blue, i);
                  break;
                }
              }
            } break;

            case sf::Keyboard::H: {
              for (unsigned i{0};
                   i < game.getPlayer(sf::Color::Blue).getBuildings().size();
                   i++) {
                if (game.getPlayer(sf::Color::Blue)
                        .getBuildings()[i]
                        .getType() == BuildingType::Stable) {
                  game.addEntity(EntityType::Horse, sf::Color::Blue, i);
                  break;
                }
              }
            } break;

            case sf::Keyboard::A:
              game.attack(sf::Color::Blue, currentId, Direction::Up);
              game.attack(sf::Color::Blue, currentId, Direction::Down);
              game.attack(sf::Color::Blue, currentId, Direction::Left);
              game.attack(sf::Color::Blue, currentId, Direction::Right);
              break;

            case sf::Keyboard::Add:
              currentId++;
              if (currentId >=
                  game.getPlayer(sf::Color::Blue).getEntities().size()) {
                currentId = 0;
              }
              break;

            case sf::Keyboard::Subtract:
              currentId--;
              if (currentId < 0) {
                currentId =
                    game.getPlayer(sf::Color::Blue).getEntities().size() - 1;
              }
              break;

            default:
              break;
          }
          break;

        default:
          break;
      }
    }
<<<<<<< HEAD
    server.receive();
=======

    gameServer.receive();
>>>>>>> origin/advancedServerImplement

    window.clear();
    for (auto& r : rects) {
      window.draw(r);
    }

<<<<<<< HEAD
    auto buildings = game.getBuildings();
=======
    auto buildings = game->getBuildings();
>>>>>>> origin/advancedServerImplement
    for (auto& b : buildings) {
      sf::RectangleShape r(
          sf::Vector2f(b.getSize().x * TILESIZE, b.getSize().y * TILESIZE));
      r.setFillColor(b.getColor());
      r.setPosition(b.getPosition().x * TILESIZE, b.getPosition().y * TILESIZE);
      window.draw(r);
    }

<<<<<<< HEAD
    auto enttity = game.getEntities();
=======
    auto enttity = game->getEntities();
>>>>>>> origin/advancedServerImplement
    for (auto& e : enttity) {
      sf::CircleShape c(TILESIZE / 2);
      c.setFillColor(e.getColor());
      c.setPosition(e.getPosition().x * TILESIZE, e.getPosition().y * TILESIZE);
      window.draw(c);
    }

    window.display();

<<<<<<< HEAD
    game.updateCachePlayer();
    game.clearPlayer();
=======
    game->clearPlayer();
>>>>>>> origin/advancedServerImplement
  }

  return 0;
}