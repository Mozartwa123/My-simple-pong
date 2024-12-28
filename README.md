Hello everyone, this c++ pong game is not really programistic-advanced one, it was only exercise.

I created it with raylib (https://www.raylib.com/)

I was also inspired by this video https://www.youtube.com/watch?v=VLJlTaFvHo4

How to open it? If you have linux system, you need only to click on the executive file. But if you really want to compile code you need to have raylib on your computer. It is really hard to install it, so ask ChatGPT for help (it was also my source of information how to istall it).

When you install raylib, compile the cpp file by following command:

g++ -Wall -Wextra -Werror -o pong pong.cpp -lm -lraylib

Of course, g++ pong.cpp -lm -lraylib would be enough propably, but previous command would make you sure, if everything is fine and executive file's name will be pong, not a.out

How to play?

You can move second (blue) pond by pressing up and down key to hit the ball. Your opponent is a bot, who knows almost ideal algorithm to hot every ball. But sometimes it gots wrong. It is your opportunity! Don't miss it!

The game ends when the bot get 10 points (then you lose) or you score one point more than bot (then you win). After 5 seconds the game is ending and window is closed.

Happy and succesful playing!
