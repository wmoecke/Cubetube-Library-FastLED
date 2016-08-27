#include "beta-cube-library-fastled.h"

Cube cube=Cube();
Color col;			// You need to keep it at ~20% brightness
					// at full brightness, i.e. (255,255,0), the LEDs will try to draw too much power, and the
					// cube's internal current-limiting circuitry will kick in.  
  int x, changex, changexa, decreasex;
  int y, changey, changeya, decreasey;
  int z, changez, changeza, decreasez;

void setup() {
	x = decreasex = 0;
	y = decreasey = 0;
	z = decreasez = 0;

	cube.begin();
	cube.clear();
}

void drawLine() {
	//decreasex = 0;
	//decreasey = 0;
	//decreasez = 0;

	changexa = rand()%2;
	changeya = rand()%2;
	changeza = rand()%2;
  
	while((changexa == changex) && (changeya == changey) && (changeza == changez)) {
		changexa = rand()%2;
		changeya = rand()%2;
		changeza = rand()%2;
	}
  
	changex = changexa;
	changey = changeya;
	changez = changeza;
  
	if (x == (cube.size-1)) decreasex = 1;
	if (y == (cube.size-1)) decreasey = 1;
	if (z == (cube.size-1)) decreasez = 1;
  
	for(int t = 0; t < cube.size; t++) {
		col = Color((cube.size-x)*18, (cube.size-y)*18, (cube.size-z)*18);

		if(changex == 0) {
			if(decreasex == 1)
				x = (cube.size-1)-t;
			else
				x = t;
		}
		if(changey == 0) {
			if(decreasey == 1)
				y = (cube.size-1)-t;
			else
				y = t;
		}
		if(changez == 0) {
			if(decreasez == 1)
				z = (cube.size-1)-t;
			else
				z = t;
		}
		cube.setVoxel(x, y, z, col);
		cube.show();
	}
}

bool areAllVoxelsFaded() {
	Color col;
	for(int x = 0; x < cube.size; x++)
		for(int y = 0; y < cube.size; y++)
			for(int z = 0; z < cube.size; z++) {
				col = cube.getVoxel(x, y, z);
				if((col.red + col.green + col.blue) > 0) return false;
			}
	return true;
}

void loop() {
	int iteration = rand()%9;
	for(int b=iteration+3; iteration >= 0; iteration--) {
		drawLine();
		delay(300);
	}

	decreasex = 0;
	decreasey = 0;
	decreasez = 0;
	
	delay(300);
	while(!areAllVoxelsFaded())
		cube.fade();
}