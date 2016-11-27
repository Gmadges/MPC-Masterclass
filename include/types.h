#ifndef TYPES_H
#define TYPES_H 

enum BodyConstraintType 
{
    FIXED,
    SLIDER,
    SIX_DOF,
    SPRING
};

//basic struct for returning sphere data doesnt really conform to std::pair and things
// maybe i should put this somewhere else?
struct SphereData
{
    float x;
    float y;
    float z;
    float radius;
};

#endif 