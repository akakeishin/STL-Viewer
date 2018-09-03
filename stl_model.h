#ifndef STLVIEWER_STL_MODEL_H
#define STLVIEWER_STL_MODEL_H

#include <string>
#include <vector>

// 3D vector
class Vec3d {

    double x;
    double y;
    double z;
};

// Triangle in 3D space
class Triangle {

    Vec3d normal;
    Vec3d points[3];
};

// STL Model
class STLModel {

    std::string name;
    std::vector<Triangle> facets;
};


#endif //STLVIEWER_STL_MODEL_H
