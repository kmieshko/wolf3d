# wolf3d

Wolf3d is a pseudo-3d game. The project was developed as a part of 42 school program. It parses maps from files, visualizes them using ray-casting technique.

**Map file format**

It's a very simple format. Open a file in your favorite text editor, make sure you have a grid of integers (each one being it's block ID), and it should work right out of the box. Spawn position is the first empty space available from the down right.

```
1 1 1 1 1
1 0 2 0 1
1 0 0 0 1
1 1 1 1 1
```
Numbers `1-6` is a kind of textures view
