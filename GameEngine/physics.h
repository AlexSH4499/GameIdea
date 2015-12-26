#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED

#define GRAV_CONST (0.00000000000667)
#define GravConst  (9.8000000000)

/*
    @param mass1 This is mass of first object
    @param mass2 This is mass of second object
    @param center This is the distance from the Gravity center
*/
static inline float gravity(float mass1, float mass2, float center);
static inline float acceleration(float speed);
static inline float speed(float x);
static inline float Force(float mass,float accel);
static inline float FrictionForce(float frict, float NetForce);
static inline float ForceSubstraction(float mass, float mass2, float accel, float accel2);
static inline float momentum(float mass, float velocity);

//void checkCrash(float x, float y);


#endif // PHYSICS_H_INCLUDED
