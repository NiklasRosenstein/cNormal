
// cnTangentSpace.h implementation

#include "cnTangentSpace.h"

cnMatrix cnComputeTangentSpace(const cnVertex& v1,
                               const cnVertex& v2,
                               const cnVertex& v3) {
    cnVertex e12 = v2 - v1;
    cnVertex e13 = v3 - v1;

    cnMatrix mat;

    mat.T = e12.WORLD.getNormalized();
    mat.N = e12.WORLD.cross(e13.WORLD).getNormalized();
    mat.B = mat.T.cross(mat.N);

    return mat;
}
