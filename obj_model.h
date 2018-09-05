#ifndef STLVIEWER_OBJ_MODEL_H
#define STLVIEWER_OBJ_MODEL_H

#include <string>
#include <vector>

// 3D vector
class Vec3d {

private:
    double _x;
    double _y;
    double _z;

public:
    Vec3d(double x, double y, double z) {
        _x = x;
        _y = y;
        _z = z;
    }

    Vec3d() = default;
};

// Triangle in 3D space
class Triangle {

private:
    Vec3d _normal;
    Vec3d _points[3];

public:
    Triangle(Vec3d& normal, Vec3d& points[3]) {
        _normal = normal;
        *_points = *points;
    }
};

// OBJ Model
class OBJModel {

private:
    std::string _name;
    std::vector<Triangle> _facets;

public:
    OBJModel(std::vector<Triangle>& f) {
        _name = "";
        _facets = f;
    }

    OBJModel(std::string n, std::vector<Triangle>& f) {
        _name = n;
        _facets = f;
    }

    OBJModel() = default;

    std::vector<Triangle> showFacets();
};

#endif //STLVIEWER_OBJ_MODEL_H
