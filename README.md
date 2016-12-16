# Game Loop v1

## Summary
The goal of the experiment is remove all calls to virtual methods or signal/slot
binding, so not leading the performance downward along the execution time.

For this reason a traditional game loop was writed using the Qt's process
events to handle both internal events (render window, update scene, ...) and
external inputs (mouse, keyboard, ...) in a lightweigth and easy way. Instead
the `World` and the `GameClock` (rename it in `GameLoop`) wasn't subject to
big changes.

However in absence of a logic to limited the CPU's cycles the program sends the
processor speed at the maximum level also if it be in indle.

**Result**: *negative*
**Derived from**: [header_source](https://github.com/korut94/MakeQtGame/tree/header_source)

