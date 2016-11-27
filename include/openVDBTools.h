#ifndef OPENVDBTOOLS_H
#define OPENVDBTOOLS_H

#include <vector>
#include <QVector3D>

#include "types.h"

class OpenVDBTools
{
public:
    OpenVDBTools();
    virtual ~OpenVDBTools();

    // returns vector of positions and radius for spheres to fill mesh shape.
    static std::vector<SphereData> getSpheresForMesh(std::vector<QVector3D>& verts, std::vector<unsigned int>& indices);
};

#endif // OPENVDBTOOLS_H
