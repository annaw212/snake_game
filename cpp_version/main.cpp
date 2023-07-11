#include <iostream>
#include <ncurses.h>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <cstdlib>

#include "coordinate.h"
#include "food.h"
#include "snake.h"

using namespace std;

// Variables & objects
Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;
int score = 0;

void setup() {
  initscr();             // Initialize ncurses screen
  clear();               // Clear the screen
  noecho();              // Disable automatic echoing of characters
  cbreak();              // Disable line buffering, making characters available immediately
  keypad(stdscr, TRUE);  // Enable reading special keys

  score = 0;
  srand(time(NULL));
  food.generateFood();
}

void draw() {
  clear();

  Coords snake_position = snake.getPosition();
  Coords food_position = food.getPosition();

  // mvprintw(snake_position.y, snake_position.x, "O");
  mvprintw(food_position.y, food_position.x, "*");
  vector<Coords> snake_body = snake.getBody();

  for (int i = 0; i < HEIGHT; i++) {
    mvprintw(i, 0, "#");
    for (int j = 0; j < WIDTH-2; j++) {
      if (i == 0 || i == HEIGHT-1) mvprintw(i, j, "#");
      else mvprintw(i, j, " ");
    }
    // TODO: for some reason, this overwrites the print that happens on the same row
    mvprintw(i, WIDTH-1, "#");
  }

  for (int i = 1; i < HEIGHT-1; i++) {
    // mvprintw(0, i, "#");
    for (int j = 1; j < WIDTH-2; j++) {
      // if (i == 0 || i == HEIGHT-1) mvprintw(i, j, "#");

      if (i == snake_position.y && j == snake_position.x) mvprintw(i, j, "O");
      
      else if (i == food_position.y && j == food_position.x) mvprintw(i, j, "*");
      
      else {
        bool isSnakeBody = false;
        for (int k = 0; k < snake_body.size()-1; k++) {
          if (i == snake_body.at(k).y && j == snake_body.at(k).x) {
            mvprintw(i, j, "o");
            isSnakeBody = true;
            break;
          }
        }

        if (!isSnakeBody) mvprintw(i, j, " ");
      }
    }
    // mvprintw(0, i,  "#\n");
  }
  mvprintw(HEIGHT + 1, 0, "Score: %d", score);
  refresh();
}

void logic() {

  bool game_over = false;
  int key;

  while (!game_over) {
    key = getch();
    if (key != ERR) {
      switch(key) {
        case 'w':
          snake.changeDirection('u');
          break;
        case KEY_UP:
          snake.changeDirection('u');
          break;
        case 's':
          snake.changeDirection('d');
          break;
        case KEY_DOWN:
          snake.changeDirection('d');
          break;
        case 'a':
          snake.changeDirection('l');
          break;
        case KEY_LEFT:
          snake.changeDirection('l');
          break;
        case 'd':
          snake.changeDirection('r');
          break;
        case KEY_RIGHT:
          snake.changeDirection('r');
          break;
        case 'q':
          game_over = true;
          break;
      }
    }

    if (snake.collided()) game_over = true;

    if (snake.foodEaten(food.getPosition())) {
      food.generateFood();
      snake.growSnake();
      score += 10;
    }

    snake.moveSnake();
    draw();
  }
}

void game_end() {
  endwin(); // restore the original terminal settings
  cout << "Final score: " << score << endl;
}

int main() {

  setup();
  draw();
  logic();
  game_end();  
  return 0;
}