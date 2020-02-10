# fillit
Hive - fillit

> Fillit is a project which involves discovering and getting acquainted with a recurrent problem in programming: the search of an optimal solution among a very large number of possibilities in a reasonable amount of time. In this project, you will arrange Tetriminos among them and determine the smallest square that can fit all of them.

Usage:

```
make
./fillit [source file]
```

Fillit fits the given tetris pieces to the smallest possible square. The format of the tetris piece is

```
..##
.##.
....
....
```

so that there is 4 rows and 4 columns. The piece can be anywhere. There can be max 26 tetris pieces in the input file (26 alphabets to represent each piece).

This project was a pair project. Our fillit works recursively and has a couple optimizing techniques: before trying to fit the piece, it finds the first available starting place and the first starting size of the map is pieces squared divided by two, as the pieces can't fit in a smaller map.

See [subject](fillit.en.pdf) for more details.
