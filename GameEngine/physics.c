#include <math.h>

#include "physics.h"

/*
    @param mass1 This is mass of first object
    @param mass2 This is mass of second object
    @param center This is the distance from the Gravity center
*/
static inline float gravity(float mass1, float mass2, float center)
{
    if(center == NULL)return -1.1111;
    if(mass1 ||  mass2 == NULL) return 0;
    return GRAV_CONST *((mass1 * mass2)/center);
}

//void checkCrash(float x, float y)
//{}

static inline float speed(int x)
{
    time_t time;
    if(x == NULL)return 0;
    return x/time;
}

static inline float weight(float mass)
{
    if(mass == NULL)return 0;
        return mass * GravConst;
}

static inline float acceleration(float speed)
{
    time_t time;
    if(speed == NULL)return 0;
    return speed/time;
}

static inline float momentum(float mass, float velocity)
{
    if(mass || velocity == NULL) return 0;
    return mass * velocity;
}

static inline float Force( float mass,float accel)
{
    if(mass || accel == NULL)return 0;
    return mass  * accel ;

}

static inline float FrictionForce(float frict, float NetForce)
{
    if(frict || NetForce == NULL)return 0;

    return frict * NetForce;

}

static inline float ForceSubstraction(float mass, float mass2, float accel, float accel2)
{
    if(mass && mass2 ==NULL || accel && accel2 == NULL)return 0;
    return Force(mass,accel) - Force(mass2,accel2);
}
