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
Numbers `1-6` is a kind of textures

**Bonuses**

1. Music in game
2. Button `S` on keyboard switching the textures set.
3. Button `W` on keyboard - on/off weapon
4. Texturing floor and ceiling
5. Button `L` on keyboard run system command leaks and show memory leaks in program.

# Usage

```
git clone https://github.com/kmieshko/wolf3d.git
cd wolf3d
make
./wolf3d [map]
```

*Notice*: Project using SDL2 graphic library and it's needed to run this project

# Some examples

<p align="center">
<img src="https://github.com/kmieshko/wolf3d/blob/master/examples/1.png" width=600>
<img src="https://github.com/kmieshko/wolf3d/blob/master/examples/2.png" width=600>
<img src="https://github.com/kmieshko/wolf3d/blob/master/examples/3.png" width=600>
</p>
