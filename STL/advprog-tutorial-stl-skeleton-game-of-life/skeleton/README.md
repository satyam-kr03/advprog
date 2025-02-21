# Game of Life

An implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) using the C++ STL.

## Building

Build from your teminal using CMake:

```shell
mkdir build
cd build
cmake ..
make
```

## Running

Run from your terminal using `./game-of-life`.

The terminal will be erased and display ASCII-based graphics.

You can stop the program using `Ctrl`+`C`.

## Example output

```text
________________________________________
|                                      |
|                                      |
|                                      |
|                                      |
|                                      |
|                       +              |
|       +                 + +          |
|       +               + +            |
|       +                              |
|                                      |
|                                      |
|                                      |
|   + +                                |
|   +                                  |
|         +                            |
|       + +                            |
|                                      |
|                                      |
========================================
```

## Notes

The output of the skeleton never changes. You need to implement the update rules first.
