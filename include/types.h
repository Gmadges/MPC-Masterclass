#ifndef TYPES_H
#define TYPES_H 

enum BodyConstraintType 
{
    FIXED,
    SLIDER,
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

struct ConstraintSettings
{
    double xLowerLimit = 0.0;
    double xUpperLimit = 0.0;
    bool xSpringEnabled = false;
    double xSpringStiffness = 0.0;
    double xSpringDamping = 0.0;

    double yLowerLimit = 0.0;
    double yUpperLimit = 0.0;
    bool ySpringEnabled = false;
    double ySpringStiffness = 0.0;
    double ySpringDamping = 0.0;

    double zLowerLimit = 0.0;
    double zUpperLimit = 0.0;
    bool zSpringEnabled = false;
    double zSpringStiffness = 0.0;
    double zSpringDamping = 0.0;
};

#endif 