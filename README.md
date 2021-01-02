# Cellular Automata

Challenged by a typical weird idea of my friend [Marco](https://github.com/marco-zani), I decided to implement a sort of random map generator. 
Of course, i should study, but this always is more fun. Actually this also reminds me that i didn't even finish the [Advent of Code](https://adventofcode.com/) of this year, i will never finish one in time I guess. 

Implementation is obviously in my beloved C++ (I guess i dont like to [KISS](https://en.wikipedia.org/wiki/KISS_principle) it).

### Usage

``` sh
> g++ main.cc -o plettro
> plettro <any random number>
```

### Output
The code outputs 4 files, 2 for input and 2 for output.
Both the input and output files are *raw* (a sequence of 0-1) and *formatted* (using the unicode \u2588 and the spaces).

### Curiosities
- As always the development of this project is fully powered by Linux
- The whole code (of the first working commit) has been developed in less than 1h30
- I listened to only Irish while developing the code ([Here](https://open.spotify.com/playlist/6SWC6SqLDNF2DKl0Ld3Can?si=KShMl-lESliOpx_sIwxfiA)). I guess I should have a Guinnes right now.
- The *slocs* are around 70, but the code is 100 perfect lines (didn't planned it, it just happened); 