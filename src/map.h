#ifndef MAP_H
#define MAP_H

#include <vector>
#include <unordered_map>
#include "SDL.h"

class Map {
 public:
  enum class Map_type {no_walls , room , four_rooms, cave};

  Map(Map_type current_map, std::size_t grid_width, std::size_t grid_height);

  bool MapCell(int x, int y);

  void Update(int score);

  std::vector<SDL_Point> GetWall();

 private:

  void CreateMaps(std::size_t grid_width, std::size_t grid_height);

  Map_type current_map;

  std::unordered_map<Map_type, std::vector<SDL_Point>> default_maps;
  
};

#endif