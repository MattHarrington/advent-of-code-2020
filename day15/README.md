# Advent of Code 2020
## Day 15

Solution to https://adventofcode.com/2020/day/15

Wrote 3 different solutions:

1. `play_game_map_to_vector()` uses `std::map` with `size_t` keys and `std::vector` values. It's slow.
2. Refactored it to `play_game_map_to_size_t()` to speed it up. Still slow. `app.exe` runs in about 20 seconds.
3. Refactored it to `play_game_with_vectors()`. Now `app.exe` runs in about 700 milliseconds.

Conclusion: `std::map` is slow.
