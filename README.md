# wolf3d
C implementation of raycasting from wolfenstein

Try make && ./wolf3d doom

You can make your own labyrinths, altough the parsing only accepts rectangle maps right now.
Rules to follow:
1 - '1' are for walls '5' are goals
2 - '-1' is where the player spawns
3 - all numbers must be have 1 space between them

e.g.

0 0 0 0 0 -1
0 0 1 1 1 1
0 0 1 1 1 1
0 0 0 0 0 0
1 0 0 0 0 0
1 1 1 1 1 5

the file containing your map, (and only your map) can then be passed as an argument to the program.

./wolf3d "your_map"
