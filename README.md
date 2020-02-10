# wolf3d
C implementation of raycasting from wolfenstein

![wolf3d screenshot](https://i.imgur.com/XxOEu9p.png)

Try: make && ./wolf3d doom

or: make && ./wolf3d mario

Will soon have a make feature to safely use your own labyrinths, the current implementation is a bit shakey

You can make your own labyrinths, altough the parsing only accepts rectangular maps right now.
Rules to follow:
* 1 '1' are for walls '5' are goals
* 2 '-1' is where the player spawns
* 3 All numbers must have 1 space between them

e.g.

0 0 0 0 0 -1

0 0 1 1 1 1

0 0 1 1 1 1

0 0 0 0 0 0

1 0 0 0 0 0

1 1 1 1 1 5

The file containing your map, (and only your map) can then be passed as an argument to the program.

./wolf3d "your_map"
