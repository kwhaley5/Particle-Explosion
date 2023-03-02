#pragma once
#include "Particle.h"
class Swarm
{
private:
	Particle* m_pParticles;

public:
	const static int nParticles = 5000;
	const Particle* const getParticles() {
		return m_pParticles;
	}

	Swarm();
	virtual ~Swarm();
	void update();
};
