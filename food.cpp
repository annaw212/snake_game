#include "food.h"
#include <cstdlib>

void Food::generateFood() {
  position.x = (rand() % (WIDTH - 3)) + 1;
  position.y = (rand() % (HEIGHT - 3)) + 1;
}

Coords Food::getPosition() { return position; }