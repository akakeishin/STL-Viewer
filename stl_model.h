#ifndef STLVIEWER_STL_MODEL_H
#define STLVIEWER_STL_MODEL_H

#include <string>
#include <vector>

// 3D vector
class Vec3d {

private:
    double x;
    double y;
    double z;

public:
    Vec3d() {

    }

    Vec3d(double x0, double y0, double z0) {
        x = x0;
        y = y0;
        z = z0;
    }
};

// Triangle in 3D space
class Triangle {

private:
    Vec3d normal;
    Vec3d points[3];

public:
    Triangle(Vec3d n, Vec3d p[3]) {
        normal = n;
        *points = *p;
    }
};

// STL Model
class STLModel {

private:
    std::string name;
    std::vector<Triangle> facets;

public:
    STLModel(std::vector<Triangle> f) {
        name = "";
        facets = f;
    }

    STLModel(std::string n, std::vector<Triangle> f) {
        name = n;
        facets = f;
    }
};

//STL reader from file
STLModel readStlModel(std::string filePath);

#endif //STLVIEWER_STL_MODEL_H
