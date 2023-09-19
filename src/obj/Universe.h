#ifndef SRC_OBJ_UNIVERSE_H_
#define SRC_OBJ_UNIVERSE_H_

#include <vector>
#include "Entity.h"

class Universe 
{
private:
    std::vector<Entity> mEntities;
public:
    std::vector<Entity>* getEntitiesPtr();
};


#endif