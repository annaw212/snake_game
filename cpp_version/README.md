# Snake Game
This is a simple version of the snake.io game available online.
It's a fun way to play around with basic animation in a terminal.


# How to Play
Run the game's executable using the command `./snake_game`.

* Use the arrow keys or WASD to move the snake in the respective direction.
* Food is depicted as `*`.
* The snake's head is depicted as `O`, and its body is depicted using `o` for the length of the snake.
* The borders are depicted with `#`.


The game will continue to run until the user chooses to quit the game using the `q` key, or runs into a wall, after which the user's final score will be displayed in the terminal.

# To-Dos/Future Ideas
* Fix the appearance of the game border. `mvprintw` seems to not want to print two characters in the same row, so it is overwriting the left-side border with the right-side border.
* Add collision functionality for when the snake collides with itself.
* Add in functionality that has the snake continue moving in the previous direction until a different direction key is provided, which would increase the difficulty of the game.
* Generate food at a certain time interval (instead of generating only after the previous food has been consumed).
