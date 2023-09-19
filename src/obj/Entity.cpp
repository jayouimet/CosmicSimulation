#include "Entity.h"

int Entity::__id_counter = 0;

Entity::Entity()
{
    this->__id = Entity::__id_counter++;
}

int Entity::getId()
{
    return this->__id;
}

float Entity::getSpeed() 
{
    return this->mSpeed;
}

void Entity::setSpeed(float s)
{
    this->mSpeed = s;
}

F4DEngine::F4DVector3 Entity::getPosition() 
{
    return this->mDirection;
}

void Entity::setPosition(F4DEngine::F4DVector3 p)
{
    this->mPosition = p;
}

F4DEngine::F4DVector3 Entity::getDirection() 
{
    return this->mDirection;
}

void Entity::setDirection(F4DEngine::F4DVector3 d)
{
    this->mDirection = d;
}