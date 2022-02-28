#include<iostream>
#include"Game.h"
#include<ctime>
void main() {
	srand(time(NULL));
	Game RunningMan;
	while (RunningMan.isRunning()) {
		//game updates
		RunningMan.update();


		//game renders
		RunningMan.render();
	}
}