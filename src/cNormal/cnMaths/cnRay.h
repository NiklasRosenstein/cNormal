
// The cnRay class represents a ray in 3 dimensional space.
// A vector can be calculated in dependency to a direction-vector
// and the origin of the ray.

#include "../cnUtils/cnVector.h"

#ifndef _CNORMAL_MATHS_RAY_H
#define _CNORMAL_MATHS_RAY_H

    class cnRay {

        public:
            cnRay(cnVector O, cnVector D);

            cnVector getOrigin() const;
            void setOrigin(cnVector O);

            cnVector getDirection() const;
            void setDirection(cnVector D);

            // R(t) = O + tD
            // Compute a vector with distance `t` from the rays origin.
            // @param double t: The rays variable parameter.
            // @return cnVector
            cnVector compute(double t) const;

        private:
            cnVector origin_;
            cnVector direction_;
    };

    // Calculates an intersection of a triangle given by
    // `v1`, `v2` and `v3` with the cnRay `ray`.
    // This fuction returns true if the ray intersects with
    // the triangle.
    // @param const cnRay& ray: The ray.
    // @param const cnVector& v1: The first vertex of the triangle.
    // @param const cnVector& v2: The second vertex.
    // @param const cnVector& v3: The third vertex.
    // @param double& t: A reference to store the distance from the rays origin to the intersection.
    // @param double& u: A reference to store the u coordinate of the intersection.
    // @param double& v: A reference to store the v coordinate of the intersection.
    // @param cnVector& u: A reference to store the final intersectionm in world space.
    // @return bool
    bool cnComputeTriangleIntersection(const cnRay& ray,
                                       const cnVector& v1, const cnVector& v2, const cnVector& v3,
                                       double& t, double& u, double& v,
                                       cnVector& intersection);

#endif // _CNORMAL_MATHS_RAY_H

