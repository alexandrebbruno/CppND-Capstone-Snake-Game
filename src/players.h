#ifndef PLAYERS_H
#define PLAYERS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>

class Players
{
public:

Players(std::string file_name);

void AddPlayer(std::string player, int score, std::string file_name);

void OutPutPlayers();

private:

std::vector<std::tuple<std::string, int> > history_of_player;

};

#endif