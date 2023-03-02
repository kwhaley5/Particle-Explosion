#include "Swarm.h"

Swarm::Swarm() {
	m_pParticles = new Particle[nParticles];
}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update() {
	for (int i = 0; i < Swarm::nParticles; i++) {
		m_pParticles[i].update();
	}
}
