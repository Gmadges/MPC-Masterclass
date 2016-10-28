#include "openVDBTools.h"

#ifdef foreach
  #undef foreach
#endif
#include <openvdb/openvdb.h>
#include <openvdb/tools/MeshToVolume.h>
#include <openvdb/tools/VolumeToSpheres.h>
#include <openvdb/util/Util.h>

OpenVDBTools::OpenVDBTools()
{
}

OpenVDBTools::~OpenVDBTools()
{
}

std::vector<SphereData> OpenVDBTools::getSpheresForMesh(std::vector<QVector3D>& verts, std::vector<unsigned int>& indices)
{   
    openvdb::initialize();

    std::vector<openvdb::Vec3f> points;
    std::vector<openvdb::Vec3I> tris;

    //convert to their format
    for (auto it = verts.begin(); it != verts.end(); it++) {
        points.push_back(openvdb::Vec3s((*it).x(),(*it).y(),(*it).z()));
    }

    for (auto it = indices.begin(); it != indices.end();) {
        tris.push_back(openvdb::Vec3I((*it++),(*it++),(*it++)));
    }
    
    //testing 
    for (auto thing : points) 
    {
        std::cout << thing << "\n";
    }

    for (auto thing : tris) 
    {
        std::cout << thing << "\n";
    }


    //turn into grid
    openvdb::math::Transform::Ptr xform = openvdb::math::Transform::createLinearTransform();
    openvdb::tools::QuadAndTriangleDataAdapter<openvdb::Vec3f, openvdb::Vec3I> mesh(points, tris);

    openvdb::FloatGrid::Ptr grid = openvdb::FloatGrid::create();
    grid = openvdb::tools::meshToVolume<openvdb::FloatGrid>(mesh, *xform);

    // Fill volume with spheres
    std::vector<openvdb::Vec4s> spheres;
    openvdb::tools::fillWithSpheres<openvdb::FloatGrid>(*grid, spheres, 1000, false, 0.1f);

    //package data up and pass it back
    std::vector<SphereData> return_spheres;
    for (auto sphere : spheres) {
        std::cout << sphere.str() << "\n";

        SphereData tmp;

        tmp.x = sphere.x();
        tmp.y = sphere.y();
        tmp.z = sphere.z();

        tmp.radius = sphere.w();

        return_spheres.push_back(tmp);
    }

    return return_spheres;
}