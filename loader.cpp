#include "loader.h"

// STL Ascii file loader
OBJModel loadSTLAscii(std::string filePath) {

    std::ifstream ifs(filePath);

    // model name
    std::string name;

    //model
    std::vector<Triangle> facets;
    while(!ifs.eof()) {

        // stl command e.g. "loop"
        std::string command;
        ifs >> command;
        if (command == "solid") {
            ifs >> name;
        }

        if (command == "facet") {

            // 読み飛ばし用
            std::string buf[8];
//            Vec3d *point0, *point1, *point2;
            double x, y, z; // normalとfacetのx, y, z座標

            ifs >> buf[0]; // "normal"
            ifs >> buf[1] >> buf[2]; // "outer loop"
            ifs >> x >> y >> z;
            Vec3d *normal = new Vec3d(x, y, z);

            ifs >> buf[3] >> x >> y >> z; // "vertex"
            Vec3d *point0 = new Vec3d(x, y, z);
            ifs >> buf[4] >> x >> y >> z; // "vertex"
            Vec3d *point1 = new Vec3d(x, y, z);
            ifs >> buf[5] >> x >> y >> z; // "vertex"
            Vec3d *point2 = new Vec3d(x, y, z);

            Triangle *t = new Triangle(normal, {point0, point1, point2});

            ifs >> buf[6]; // endloop
            ifs >> buf[7]; // endfacet

        }

    }

    OBJModel *objModel = new OBJModel(name, facets);
    return *objModel;
}

// General Object model loader
OBJModel loadModel(std::string filePath) {

    std::ifstream ifs(filePath);
    if (!ifs) {
        std::cerr << "can' t open the file" << std::endl;
    }
    return loadSTLAscii(filePath);
}