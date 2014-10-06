
// cnAABB implementation

#include "cnAABB.h"

cnAABB::cnAABB(cnVector boxMin, cnVector boxMax) {
    if (boxMax.x < boxMin.x and
        boxMax.y < boxMin.y and
        boxMax.z < boxMin.z) {
            cnVector temp = boxMin;
            boxMin = boxMax;
            boxMax = temp;
    }

    boxMin_ = boxMin;
    boxMax_ = boxMax;
}

cnAABB::~cnAABB() {
}

bool cnAABB::computeIntersection(cnRay& ray, cnVector& tNear, cnVector& tFar) const {
}
