#ifndef SNAKE_H
#define SNAKE_H

#include "coordinate.h"
#include <vector>

using namespace std;


class Snake {

  public:
    Snake(Coords position, int velocity);
    void changeDirection(char direction);
    void moveSnake();
    Coords getPosition();
    vector<Coords> getBody();
    void growSnake();
    bool collided();
    bool foodEaten(Coords food_position);

  private:
    Coords position;
    vector<Coords> body;
    int snake_length;
    int velocity;
    char direction;

};

#endif // SNAKE_H