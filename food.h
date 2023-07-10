
#ifndef FOOD_H
#define FOOD_H

#include "coordinate.h"

class Food {
  public:
    void generateFood();
    Coords getPosition();

  private:
    Coords position;
};

#endif // FOOD_H