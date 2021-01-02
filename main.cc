#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int getGeneration(int** map, int x, int y);

int main(int argc, char const *argv[]) {
	//Catching no seed passed
	if (argc != 2) {
		cout << "\nWrong argument passed. Run again using:\n\n\t> a.out <any random number>\n\n";
		exit(1);
	}

	//Same seed  will give same result (remember: srand is just pseudorandom)
	int seed = atoi(argv[1]);
	srand(seed);

	ofstream out("output.txt");
	ofstream format("outputformat.txt");

	ofstream in("input.txt");
	ofstream informat("inputformat.txt");

	//Init of the dynamic matrix map
	int x = 48;
	int y = 48;

	int **map = (int**)malloc(x*sizeof(int*));

	for (int i = 0; i < x; ++i) {
		map[i] = (int*)malloc(y*sizeof(int));
		for (int j = 0; j < y; ++j) {
			//if the cell is on the border assign 2, else a random valued generated 
			//from the seed, multiplied by a large prime number and moduled by 2.
			map[i][j] = (i == 0 || j == 0 || i == x-1 || j == y-1) ? 2 : (abs(rand()) * 610933)%2;
			//Also fill the input and the formatted input of the map
			in << (map[i][j]+1)/2 << " ";
			informat << ((map[i][j] == 0) ? "  " : "\u2588\u2588");
		}
		in << "\n";
		informat << "\n";
	}

	in.close();
	informat.close();

	//ACTUAL CODE
	int generations = 200;
	for (int i = 0; i < generations; ++i) {
		int **copy = (int**)malloc(x*sizeof(int*));

		for (int i = 0; i < x; ++i) {
			copy[i] = (int*)malloc(y*sizeof(int));
			for (int j = 0; j < y; ++j) {
				copy[i][j] = getGeneration(map,i,j);
			}
		}
		free(map);
		map = copy;
	}

	//fill the txt file and the formatted version of the same
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			out << (map[i][j]+1)/2 << " ";
			format << ((map[i][j] == 0) ? "  " : "\u2588\u2588");
		}
		out << "\n";
		format << "\n";
	}

	out.close();
	format.close();
	return 0;
}

int getGeneration(int** map, int x, int y) {
	if (map[x][y] == 2)
		return 2;

	int sx = x-1;
	int ex = x+1;

	int sy = y-1;
	int ey = y+1;

	int count = 0 - map[x][y];

	for (int i = sx; i <= ex; ++i)
		for (int j = sy; j <= ey; ++j)
			count += (map[i][j]+1)/2;

	if (count > 5)  
		return 1;
	else if (count < 4) 
		return 0;
	else
		return map[x][y];
}