#ifndef TYPE_HPP
#define TYPE_HPP

/*
Define the type of the buildings and entities used in the game
*/

#include <SFML/System.hpp>
#include <cmath>
#include <map>

enum class BuildingType { TownCenter, Fort, Stable,MaxBuildingType };
enum class EntityType { Villager, Warrior, Horse, MaxEntityType };
enum class Direction { Up, Down, Left, Right, MaxDirection };
enum class Ressource { Wood, Food, Gold, MaxRessources };

#define TILESIZE 16

bool rectCollide(const sf::Vector2f& pos1, const sf::Vector2f& size1,
                 const sf::Vector2f& pos2, const sf::Vector2f& size2);
bool rectCollide(const sf::Vector2f& pos1, const sf::Vector2f& pos2);
bool rectInCircle(const sf::Vector2f pos1, int radius, sf::Vector2f pos2);

using buildMap = std::map<BuildingType, std::map<Ressource, int>>;
using entMap = std::map<EntityType, std::map<Ressource, int>>;

#endif
