# Game Loop v2
In this Game Loop's verion the QApplication's event loop are replaced with the GameLoop class defined in the
previous verion so to guarantee a greater stability in accordance with the number of items over the screen.

In the `Game::run` method a `QApplication` is runned and the view and world parametes are defined. For now
all options are hard-coded but the future verions will build a *configure system* to add more flexibility at
the program.

The intent to use a `QApplication` is semplify the render aspect (like the update step) withouth lose the
possibility to extend the architecture (using *OpenGL Widget* viewport to lead in bigger rendering perfomance).

## UML
[![game_loop_v2.png](https://s5.postimg.org/l2zzu6u1z/game_loop_v2.png)](https://postimg.org/image/ecjikr6w3/)

**Result**: *positive*

**Derived from**: [game_loop_v1](https://github.com/korut94/MakeQtGame/tree/game_loop_v1)

