
// cnRay.h implementation

#include "cnRay.h"

cnRay::cnRay(cnVector O, cnVector D)
        : origin_(O),
          direction_(D.getNormalized()) {
}

cnVector cnRay::getOrigin() const {
    return origin_;
}

void cnRay::setOrigin(cnVector O) {
    origin_ = O;
}

cnVector cnRay::getDirection() const {
    return direction_;
}

void cnRay::setDirection(cnVector D) {
    direction_ = D.getNormalized();
}

cnVector cnRay::compute(double t) const {
    // R(t) = O + tD == R(t) = O + Dt
    return origin_ + (direction_ * t);
}


// See "Fast MinimumStorage-Ray-Triangle-Intersection Algorithm" by
// Thomas Müller and Ben Trumbore  for details.
// <cNormal/references/RayTriangleIntersection.pdf>
bool cnComputeTriangleIntersection(const cnRay& ray,
                                   const cnVector& v1, const cnVector& v2, const cnVector& v3,
                                   double& t, double& u, double& v,
                                   cnVector& intersection) {
    cnVector edge1 = v2 - v1;
    cnVector edge2 = v3 - v1;

    cnVector pvec = ray.getDirection().cross(edge2);
    double det = edge1.dot(pvec);

    // calculate distance from v1 to ray origin
    cnVector tvec = ray.getOrigin() - v1;

    // calculate U parameter
    u = tvec.dot(pvec);

    cnVector qvec = tvec.cross(edge1);

    v = ray.getDirection().dot(qvec);
    t = edge2.dot(qvec);

    // scale values
    double inv_det = 1.0 / det;
    t *= inv_det;
    u *= inv_det;
    v *= inv_det;

    intersection = v1 * (1 - u - v) + v2 * u + v3 * v;

    if (u < 0.0 or v < 0.0 or u + v > 1.0) {
        return false;
    }
    else {
        return true;
    }
}
