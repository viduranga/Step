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

  auto Render() {
    return ftxui::Renderer([&] {
      ftxui::Elements elements;
      for (int y = 0; y < game.getLevel().grid_size; ++y) {
        ftxui::Elements row;
        for (int x = 0; x < game.getLevel().grid_size; ++x) {
          // Add borders around the edges
          if (x == 0 && y == 0) {
            row.push_back(ftxui::text("╔═"));
          } else if (x == game.getLevel().grid_size - 1 && y == 0) {
            row.push_back(ftxui::text("╗ "));
          } else if (x == 0 && y == game.getLevel().grid_size - 1) {
            row.push_back(ftxui::text("╚═"));
          } else if (x == game.getLevel().grid_size - 1 &&
                     y == game.getLevel().grid_size - 1) {
            row.push_back(ftxui::text("╝ "));
          } else if (x == 0) {
            row.push_back(ftxui::text("║ "));
          } else if (x == game.getLevel().grid_size - 1) {
            row.push_back(ftxui::text("║ "));
          } else if (y == 0 || y == game.getLevel().grid_size - 1) {
            row.push_back(ftxui::text("══"));
          } else if (std::make_tuple(x, y) == game.getLevel().player) {
            row.push_back(ftxui::text("󰚩 ") |
                          ftxui::color(ftxui::Color::Blue));
          } else {
            switch (game.getLevel()[x, y]) {
            case ITEM::EMPTY:
              row.push_back(ftxui::text(". ") | ftxui::dim | ftxui::dim |
                            ftxui::dim);
              break;
            case ITEM::BARRIER:
              row.push_back(ftxui::text("█▉") |
                            ftxui::color(ftxui::Color::Yellow));
              break;
            case ITEM::VOID:
              row.push_back(ftxui::text(" ") |
                            ftxui::color(ftxui::Color::Red));
              break;
            case ITEM::TREAT:
              row.push_back(ftxui::text(" ") |
                            ftxui::color(ftxui::Color::Green));
              break;
            }
          }
        }
        elements.push_back(ftxui::hbox(row));
      }
      return ftxui::vbox(elements) | ftxui::center;
    });
  }

  GameStatus tick() { return game.tick(); }

private:
  Game game;
};

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <input_file> <program>" << std::endl;
    return 1;
  }

  std::ifstream input_file(argv[1]);
  if (!input_file) {
    std::cerr << "Error: Could not open file " << argv[1] << std::endl;
    return 1;
  }

  // std::string program = "f(x)=<x>[a]rf(x-2)\nf(15)";
  std::string program_data = argv[2];
  program_data = program_data.replace(program_data.find("\\n"), 2, "\n");

  StepGameTUI game_TUI{};
  // std::string program_data;

  game_TUI.load(std::move(input_file), program_data);

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

  auto running = false;

  std::thread([&] {
    while (true) {
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
      screen.PostEvent(ftxui::Event::Custom);
      if (running && game_TUI.tick() == GameStatus::ENDED) {
        break;
      }
    }
  }).detach();

  auto textarea = ftxui::Input(&program_data);
  auto button = ftxui::Button("Run", [&] {
    // std::cout << "Running program: " << program_data << std::endl;
    std::ifstream input_file(argv[1]);
    game_TUI.load(std::move(input_file), program_data);
    running = true;
  });

  auto container = ftxui::Container::Vertical({
      textarea,
      button,
  });
  int size = 50;
  auto layout = ftxui::ResizableSplitRight(container, game_TUI.Render(), &size);

  auto component = ftxui::Renderer(layout, [&] {
    return ftxui::vbox({
               ftxui::text("Input:"),
               ftxui::separator(),
               layout->Render() | ftxui::flex,
           }) |
           ftxui::border;
  });

  screen.Loop(component);
  return 0;
}
