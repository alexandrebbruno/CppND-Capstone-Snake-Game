#include "players.h"

Players::Players(std::string file_name)
{
  std::fstream log_file(file_name);
  std::string line;
  while(std::getline(log_file, line))
  {
    std::stringstream ss(line);
    std::string player;
    int score;
    ss >> player >> score;
    std::tuple<std::string, int> pair(player, score);
    std::cout << "plartt = "<< player << std::endl;
    history_of_player.push_back(pair);
  }
  log_file.close();
}

void Players::AddPlayer(std::string player, int score, std::string file_name){
    std::ofstream log_file(file_name, std::ios_base::app);
    log_file << player << " " << score << std::endl;
    std::tuple<std::string, int> pair(player, score);
    history_of_player.push_back(pair);
}

void Players::OutPutPlayers(){
    std::cout << "--------- LOG ---------------\n";
    for (auto const& log: history_of_player){
        std::cout << "User Name = " << std::get<0>(log) << " Score = " << std::get<1>(log) << std::endl;
    }
}