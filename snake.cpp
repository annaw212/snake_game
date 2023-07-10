#include "snake.h"
#include <vector>

using namespace std;

Snake::Snake(Coords position, int velocity) {
  this->position = position;
  this->velocity = velocity;

  snake_length = 1;
  direction = 'n'; // no direction assigned at start
  body.push_back(position);
}

Coords Snake::getPosition() { return position; }

vector<Coords> Snake::getBody() { return body; }

void Snake::changeDirection(char direction) { this->direction = direction; }

void Snake::growSnake() { snake_length++; }

void Snake::moveSnake() {

  switch(direction) {
    case 'u':
      position.y -= velocity;
      break;
    case 'd':
      position.y += velocity;
      break;
    case 'l':
      position.x -= velocity;
      break;
    case 'r':
      position.x += velocity;
      break;
  }

  // Add this position to the vector
  body.push_back(position);

  // If the position is greater than the current length of the snake,
  // remove the "tail" element of the snake (the first element)
  if (body.size() > snake_length) body.erase(body.begin());
}

bool Snake::collided() {

  // Check if we have collided with the side of the board
  if (position.x < 1 || position.x > WIDTH - 2 || position.y < 1 || position.y > HEIGHT - 2) return true;
  
  // // Check if we have collided with any part of the snake's own body
  // if (body.size() > 1) {
  //   for (auto b : body) {
  //     if (position.x == b.x || position.y == b.y) return true;
  //   }
  // }
  
  return false;
}

bool Snake::foodEaten(Coords food_position) {
  if (position.x == food_position.x && position.y == food_position.y) return true;
  return false;
}

