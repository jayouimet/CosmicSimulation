#ifndef SRC_OBJ_ENTITY_H_
#define SRC_OBJ_ENTITY_H_

#include "../../math/F4DVector3.h"

class Entity
{
private:
    static int __id_counter;
    int __id;
protected:
    float mSpeed;
    F4DEngine::F4DVector3 mPosition;
    F4DEngine::F4DVector3 mDirection;
public:
    Entity();
    virtual ~Entity() {};

    int getId();

    float getSpeed();
    void setSpeed(float);
    F4DEngine::F4DVector3 getPosition();
    void setPosition(F4DEngine::F4DVector3);
    F4DEngine::F4DVector3 getDirection();
    void setDirection(F4DEngine::F4DVector3);
};

#endif
