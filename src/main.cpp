#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "players.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  const std::string file_name_for_log{"../log.txt"};

  std::string username;
  std::cout << "Add your username: \n";
  std::cin >> username;

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);

  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  
  Players players(file_name_for_log);
  players.AddPlayer(username, game.GetScore(), file_name_for_log);
  players.OutPutPlayers();

  return 0;
}