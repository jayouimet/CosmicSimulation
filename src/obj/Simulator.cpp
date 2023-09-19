#include "Simulator.h"

F4DEngine::F4DVector3 Simulator::getGravityPull(Particle& particle)
{
    F4DEngine::F4DVector3 resVec = F4DEngine::F4DVector3();

    std::vector<Entity> *entities = this->mUniverse.getEntitiesPtr();

    for (int i = 0; i < entities->size(); i++) 
    {
        if (&(entities->at(i)) != &particle)
        {
            Particle* p = dynamic_cast<Particle*>(&(entities->at(i)));
            if (p != nullptr) 
            {
                F4DEngine::F4DVector3 dstVec;
                dstVec = particle.getPosition() - p->getPosition();

                float dst = dstVec.magnitude();

                float f = GRAVITY_CONSTANT * (p->getMass() * particle.getMass())/(dst * dst * dst);
                F4DEngine::F4DVector3 unitDstVec = dstVec.getNormalizedVector();

                resVec += unitDstVec * f;
            }
        }
    }

    return resVec;
}