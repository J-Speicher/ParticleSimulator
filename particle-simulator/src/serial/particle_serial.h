#ifndef PARTICLE_H
#define PARTICLE_H

// #include <cuda_runtime.h>

#include "vector_serial.h"

#define VEL_MIN -2.0
#define VEL_MAX 2.0
#define X_MIN -1.0
#define X_MAX 1.0
#define Y_MIN -1.0
#define Y_MAX 1.0

class Particle {
    public:
        // Constructors
        Particle();
        Particle(Vector position, Vector velocity, float mass, float radius);

        // Getters and Setters
        const Vector& getPosition() const;
        void setPosition(const Vector& position);

        const Vector& getVelocity() const;
        void setVelocity(const Vector& velocity);

        float getMass() const;
        void setMass(float mass);

        float getRadius() const;
        void setRadius(float radius);

        // Other methods
        void updatePosition(float dt);
        void render();
        void wallBounce();

        bool collidesWith(const Particle& other) const;
        void resolveCollision(Particle& other);
        // void updateVelocity(const Vector& force, float deltaTime);
    private:
        Vector position;
        Vector velocity;
        float mass;
        float radius;
};



#endif // PARTICLE_H