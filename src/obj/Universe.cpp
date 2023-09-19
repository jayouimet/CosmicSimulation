#include "Universe.h"

std::vector<Entity>* Universe::getEntitiesPtr() 
{
    return &(this->mEntities);
}