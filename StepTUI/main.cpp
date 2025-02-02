#include <chrono>
#include <deque>
#include <fstream>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <random>
#include <thread>

// Directions
enum Direction { UP, DOWN, LEFT, RIGHT };

struct Point {
  int x, y;
  bool operator==(const Point &other) const {
    return x == other.x && y == other.y;
  }
};

class SnakeGame {
public:
  SnakeGame(int w, int h)
      : width(w), height(h), rng(rd()), dist_x(1, w - 2), dist_y(1, h - 2) {
    Reset();
  }

  void Reset() {
    snake = {{width / 2, height / 2}};
    direction = RIGHT;
    alive = true;
    score = 0;
    PlaceFood();
  }

  void PlaceFood() {
    do {
      food = {dist_x(rng), dist_y(rng)};
    } while (std::find(snake.begin(), snake.end(), food) != snake.end());
  }

  void ChangeDirection(Direction new_direction) {
    if ((direction == UP && new_direction != DOWN) ||
        (direction == DOWN && new_direction != UP) ||
        (direction == LEFT && new_direction != RIGHT) ||
        (direction == RIGHT && new_direction != LEFT)) {
      direction = new_direction;
    }
  }

  void Update() {
    if (!alive)
      return;

    Point new_head = snake.front();
    switch (direction) {
    case UP:
      --new_head.y;
      break;
    case DOWN:
      ++new_head.y;
      break;
    case LEFT:
      --new_head.x;
      break;
    case RIGHT:
      ++new_head.x;
      break;
    }

    if (new_head.x <= 0 || new_head.x >= width - 1 || new_head.y <= 0 ||
        new_head.y >= height - 1 ||
        std::find(snake.begin(), snake.end(), new_head) != snake.end()) {
      alive = false;
      return;
    }

    snake.push_front(new_head);
    if (new_head == food) {
      ++score;
      PlaceFood();
    } else {
      snake.pop_back();
    }
  }

  ftxui::Component Render() {
    return ftxui::Renderer([&] {
      ftxui::Elements elements;
      for (int y = 0; y < height; ++y) {
        ftxui::Elements row;
        for (int x = 0; x < width; ++x) {
          if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
            row.push_back(ftxui::text("█"));
          } else if (Point{x, y} == food) {
            row.push_back(ftxui::text("🍎"));
          } else if (std::find(snake.begin(), snake.end(), Point{x, y}) !=
                     snake.end()) {
            row.push_back(ftxui::text("■"));
          } else {
            row.push_back(ftxui::text(" "));
          }
        }
        elements.push_back(ftxui::hbox(row));
      }
      return ftxui::vbox({ftxui::text("Score: " + std::to_string(score)),
                          ftxui::separator(), ftxui::vbox(elements)}) |
             ftxui::border;
    });
  }

  bool IsAlive() const { return alive; }

private:
  int width, height, score;
  bool alive;
  std::deque<Point> snake;
  Point food;
  Direction direction;
  std::random_device rd;
  std::mt19937 rng;
  std::uniform_int_distribution<int> dist_x, dist_y;
};

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  std::ifstream input_file(argv[1]);
  if (!input_file) {
    std::cerr << "Error: Could not open file " << argv[1] << std::endl;
    return 1;
  }

  const int width = 20, height = 10;
  SnakeGame game(width, height);
  auto screen = ftxui::ScreenInteractive::Fullscreen();

  auto key_listener = ftxui::CatchEvent([&](ftxui::Event event) {
    if (event == ftxui::Event::ArrowUp)
      game.ChangeDirection(UP);
    if (event == ftxui::Event::ArrowDown)
      game.ChangeDirection(DOWN);
    if (event == ftxui::Event::ArrowLeft)
      game.ChangeDirection(LEFT);
    if (event == ftxui::Event::ArrowRight)
      game.ChangeDirection(RIGHT);
    if (event == ftxui::Event::Character('q'))
      screen.ExitLoopClosure();
    return true;
  });

  auto ui = ftxui::Container::Vertical({game.Render()}) | key_listener;

  std::thread([&] {
    while (game.IsAlive()) {
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
      game.Update();
      screen.PostEvent(ftxui::Event::Custom);
    }
  }).detach();

  screen.Loop(ui);
  return 0;
}
