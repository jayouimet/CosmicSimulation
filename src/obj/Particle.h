#ifndef SRC_OBJ_PARTICLE_H_
#define SRC_OBJ_PARTICLE_H_

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif

#include <math.h>
#include "Entity.h"
#include "../../math/F4DVector3.h"

class Particle : public Entity
{
private:
    // In KG
    float mMass;
    // In KG / M^3
    float mDensity;
public:
    Particle();

    float getMass();
    void setMass(float);
    float getDensity();
    void setDensity(float);
    // In meters
    float getRadius();
};

#endif