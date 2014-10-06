
// The cnAABB class implements an axis aligned bounding box that
// can be tested on intersection.

#include "../cnUtils/cnVector.h"
#include "cnRay.h"

#ifndef _CNORMAL_MATHS_AABB_H
#define _CNORMAL_MATHS_AABB_H

    class cnAABB {

        public:
            cnAABB(cnVector boxMin, cnVector boxMax);
            ~cnAABB();

            inline bool pointWithin(cnVector& point) const;
            bool computeIntersection(cnRay& ray, cnVector& tNear, cnVector& tFar) const;

        private:
            cnVector boxMin_,
                     boxMax_;
    };

    inline bool cnAABB::pointWithin(cnVector& p) const {
        return p.in(boxMin_, boxMax_);
    }

#endif // _CNORMAL_MATHS_AABB_H

