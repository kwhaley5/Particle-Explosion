#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Screen.h"
#include "Particle.h"
#include "Swarm.h"
using namespace std;

int main(int argc, char* args[]) {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error useing SDL.\n";
	}

	Swarm swarm;

	while (true) {
		//update particles
		int elapsed = SDL_GetTicks();

		screen.clear();
		swarm.update();

		unsigned char red = (1 + sin(elapsed * .0001)) * 128;
		unsigned char green = (1 + sin(elapsed * .0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * .0003)) * 128;

		const Particle* const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::nParticles; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x ) * Screen::SCREEN_WIDTH;
			int y = (particle.m_y ) * Screen::SCREEN_HEIGHT;

			//cout << x << endl;

			screen.setPixel(x, y, red, green, blue);

			

		}
		
		//draw particles

		//Draw the screen
		
		screen.update();

		//check for messages/events
		if (screen.processEvents() == false) {
			break;
		}
	}

	screen.close();
	
	return 0;
}