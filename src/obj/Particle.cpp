#include "Particle.h"

Particle::Particle() 
{
    this->mMass = 1.0f;
    // KG per M^3
    this->mDensity = 5510;
}

float Particle::getMass() 
{
    return this->mMass;
}

void Particle::setMass(float m)
{
    this->mMass = m;
}

float Particle::getDensity() 
{
    return this->mDensity;
}

void Particle::setDensity(float d)
{
    this->mDensity = d;
}

float Particle::getRadius()
{
    float vol = this->mMass / this->mDensity;
    return std::pow((3 * vol)/(4 * M_PI), 1.0f/3.0f);
}