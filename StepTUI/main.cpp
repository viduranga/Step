#include "GameEngine/Game.h"
#include "Parser/Defs.h"
#include "Parser/Level.h"
#include <Parser/DataParser.h>
#include <chrono>
#include <fstream>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <thread>

class StepGameTUI {
public:
  StepGameTUI() {}

  void load(std::istream &&level_data, const std::string &program_data) {
    game.load(std::move(level_data), program_data);
  }

  ftxui::Component render() {
    return ftxui::Renderer([&] {
      ftxui::Elements elements;
      for (int y = 0; y < game.getLevel().grid_size; ++y) {
        ftxui::Elements row;
        for (int x = 0; x < game.getLevel().grid_size; ++x) {
          if (std::make_tuple(x, y) == game.getLevel().player) {
            row.push_back(ftxui::text(" "));
          } else {
            switch (game.getLevel()(x, y)) {
            case ITEM::EMPTY:
              row.push_back(ftxui::text("┼─"));
              break;
            case ITEM::BARRIER:
              row.push_back(ftxui::text("██"));
              break;
            case ITEM::VOID:
              row.push_back(ftxui::text(" "));
              break;
            case ITEM::TREAT:
              row.push_back(ftxui::text(" "));
              break;
            }
          }
        }
        elements.push_back(ftxui::hbox(row));
      }
      return ftxui::vbox({ftxui::text(std::format(
                              "Step treats: {}, player: x={}, y={}, facing: "
                              "{}, action: {}",
                              game.treat_count, std::get<0>(game.level.player),
                              std::get<1>(game.level.player),
                              static_cast<char>(game.level.facing),
                              static_cast<char>(game.action))),
                          ftxui::separator(), ftxui::vbox(elements)}) |
             ftxui::border;
    });
  }

  GameStatus tick() { return game.tick(); }

private:
  Game game;
};

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file> <program>" << std::endl;
    return 1;
  }

  std::ifstream input_file(argv[1]);
  if (!input_file) {
    std::cerr << "Error: Could not open file " << argv[1] << std::endl;
    return 1;
  }

  std::string program = "f(x)=<x>[a]rf(x-2)\nf(15)";

  StepGameTUI game_TUI{};

  game_TUI.load(std::move(input_file), program);

  auto screen = ftxui::ScreenInteractive::Fullscreen();

  auto key_listener = ftxui::CatchEvent([&](ftxui::Event event) {
    // if (event == ftxui::Event::ArrowUp)
    //   game.ChangeDirection(UP);
    // if (event == ftxui::Event::ArrowDown)
    //   game.ChangeDirection(DOWN);
    // if (event == ftxui::Event::ArrowLeft)
    //   game.ChangeDirection(LEFT);
    // if (event == ftxui::Event::ArrowRight)
    //   game.ChangeDirection(RIGHT);
    // if (event == ftxui::Event::Character('q'))
    //   screen.ExitLoopClosure();
    return true;
  });

  auto ui = ftxui::Container::Vertical({game_TUI.render()}) | key_listener;

  std::thread([&] {
    while (game_TUI.tick() != GameStatus::ENDED) {
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
      // game_TUI.Update();
      screen.PostEvent(ftxui::Event::Custom);
    }
  }).detach();

  screen.Loop(ui);
  return 0;
}
