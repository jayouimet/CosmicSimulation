#ifndef SRC_OBJ_SIMULATOR_H_
#define SRC_OBJ_SIMULATOR_H_

#include <vector>
#include "Universe.h"
#include "Particle.h"
#include "../../math/F4DMatrix3.h"

#define GRAVITY_CONSTANT 6.67384e-11

class Simulator 
{
private:
    Universe mUniverse;
public:
    F4DEngine::F4DVector3 getGravityPull(Particle&);
};

#endif