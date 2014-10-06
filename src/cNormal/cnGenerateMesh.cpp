
// cnGenerateMesh.h implementation

#include <cassert>
#include "cnGenerateMesh.h"

template <typename T>
static double rdiv(T dividend, T divisor) {
    return static_cast<double>(dividend) / static_cast<double>(divisor);
}

bool cnCreatePlane(cnMesh& mesh, uint useg, uint vseg, double udim, double vdim) {
    const uint vertexCount = (useg + 1) * (vseg + 1);
    const uint polygonCount = useg * vseg;
    if (!mesh.resize(vertexCount, polygonCount * 2))
        return false;

    for (uint i=0; i <= useg; ++i) {
        const double xcoord = rdiv(i, useg);
        for (uint j=0; j <= vseg; ++j) {
            const double ycoord = rdiv(j, vseg);
            const uint vindex = i * vseg + j;
            mesh.point(vindex) = cnVector(xcoord * udim, 0, ycoord * vdim);
            mesh.uvpoint(vindex) = cnVector(xcoord, ycoord);
        }
    }

    uint pindex = 0;
    for (uint i=0; i < useg; ++i) {
        for (uint j=0; j < vseg; ++j) {
            const uint vindex = i * vseg + j;
            const uint a = i;
            const uint b = i + 1;
            const uint c = i + vseg + 1;
            const uint d = i + vseg + 1 + 1;
            mesh.polygon(pindex++) = cnPolygon(i, i + 1, i + vseg);
            mesh.polygon(pindex++) = cnPolygon(i + vseg, i + vseg + 1, i + 1);
        }
    }

    assert(mesh.validate());
    return true;
}

bool cnCreateCube(cnMesh& mesh, cnVector size) {
    if (!mesh.resize(8, 12))
        return false;

    size = size * 0.5;
    const cnVertex verts[8] = {
        cnVertex(cnVector(-size.x, -size.y, -size.z), cnVector(0.649, 0.649)),
        cnVertex(cnVector(-size.x,  size.y, -size.z), cnVector(0.018, 0.982)),
        cnVertex(cnVector( size.x, -size.y, -size.z), cnVector(0.649, 0.685)),
        cnVertex(cnVector( size.x,  size.y, -size.z), cnVector(0.315, 0.982)),
        cnVertex(cnVector( size.x, -size.y,  size.z), cnVector(0.649, 0.982)),
        cnVertex(cnVector( size.x,  size.y,  size.z), cnVector(0.315, 0.685)),
        cnVertex(cnVector(-size.x, -size.y,  size.z), cnVector(0.351, 0.982)),
        cnVertex(cnVector(-size.x,  size.y,  size.z), cnVector(0.649, 0.018))
    };
    static const cnPolygon polys[12] = {
        cnPolygon(0, 1, 3),
        cnPolygon(2, 3, 5),
        cnPolygon(4, 5, 7),
        cnPolygon(6, 7, 1),
        cnPolygon(1, 7, 5),
        cnPolygon(6, 0, 2),
        cnPolygon(0, 3, 2),
        cnPolygon(2, 5, 4),
        cnPolygon(4, 7, 6),
        cnPolygon(6, 1, 0),
        cnPolygon(1, 5, 3),
        cnPolygon(6, 2, 4)
    };

    for (int i = 0; i < 8; i++) {
        mesh.vertex(i) = verts[i];
    }
    for (int i = 0; i < 12; i++) {
        mesh.polygon(i) = polys[i];
    }

    assert(mesh.validate());
    return true;
}
