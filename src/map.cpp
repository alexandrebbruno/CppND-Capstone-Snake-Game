#include "map.h"
#include <iostream>

Map::Map(Map_type current_map, std::size_t grid_width, std::size_t grid_height)
  : current_map(current_map){
   this->CreateMaps(grid_width, grid_height);
}

void Map::Update(int score){
    if (score < 10){
        this->current_map = Map_type::no_walls;
    }else if (score < 20)
    {
        this->current_map = Map_type::room;
    }else if (score < 30)
    {
        this->current_map = Map_type::four_rooms;
    }else 
    {
        this->current_map = Map_type::cave;
    }
}   

std::vector<SDL_Point> Map::GetWall() {
    return default_maps[current_map];
}

bool Map::MapCell(int x, int y){
    const auto &map = default_maps[current_map];
    for (auto const &item: map){
        if (item.x == x && item.y == y){
            return true;
        }
    }
    return false;
}

void Map::CreateMaps(std::size_t grid_width, std::size_t grid_height){
    // create nowall
    std::vector<SDL_Point> nowall{};
    this->default_maps[Map_type::no_walls] = nowall;

    //create room
    std::vector<SDL_Point> room;
    for (int i = 0; i < grid_width; i++){
        SDL_Point point_top;
        point_top.x = i;
        point_top.y = 0;
        room.push_back(point_top);
        SDL_Point point_bottom;
        point_bottom.x = i;
        point_bottom.y = grid_height-1;
        room.push_back(point_bottom);
    }
    for (int i = 0; i < grid_height; i++){
        SDL_Point point_left;
        point_left.x = 0;
        point_left.y = i;
        room.push_back(point_left);
        SDL_Point point_right;
        point_right.x = grid_width-1;
        point_right.y = i;
        room.push_back(point_right);
    }
    this->default_maps[Map_type::room] = room;
    
    //create four_rooms
    std::vector<SDL_Point> four_rooms;
    int half_height = grid_height/2;
    int half_width = grid_width/2;
    for (int i = 0; i < grid_width; i++){
        SDL_Point point;
        point.x = i;
        point.y = half_height;
        four_rooms.push_back(point);
    }
    for(int i = 0; i < grid_height; i++){
        SDL_Point point;
        point.x = half_width;
        point.y = i;
        four_rooms.push_back(point);
    }
    this->default_maps[Map_type::four_rooms] = four_rooms;

    //create skull
    std::vector<std::vector<int>> skull {{0, 0,  1, 1 , 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                                            {0, 0,  1, 1 , 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                                            {1, 1,  1, 1 , 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                            {1, 1,  1, 1 , 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                            {1, 1,  0, 0 , 0, 0, 1, 1, 0, 0, 0, 0, 1, 1},
                                            {1, 1,  0, 0 , 0, 0, 1, 1, 0, 0, 0, 0, 1, 1},
                                            {1, 1,  0, 0 , 0, 0, 1, 1, 0, 0, 0, 0, 1, 1},
                                            {1, 1,  0, 0 , 0, 0, 1, 1, 0, 0, 0, 0, 1, 1},
                                            {1, 1,  1, 1 , 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                            {1, 1,  1, 1 , 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                            {0, 0,  1, 1 , 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                                            {0, 0,  1, 1 , 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                                            {0, 0,  1, 1 , 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
                                            {0, 0,  1, 1 , 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},};
  
    std::vector<SDL_Point> skull_wall;
    for (int i = 0 ; i < skull[0].size() ; i++){
        for( int j = 0; j < skull.size(); j++){
            if (skull[i][j] == 1){
            SDL_Point point;
            point.x = j + (grid_width/4)+1;
            point.y = i + (grid_height/4)+1;
            skull_wall.push_back(point);
            }
        }
    }
    this->default_maps[Map_type::cave] = skull_wall;
}

