
// The cnTangenSpace header defines functions to calculate tangent space
// matrices.

#include "../cnUtils/cnUtils.h"

#ifndef _CNORMAL_MATHS_TANGENTSPACE_H
#define _CNORMAL_MATHS_TANGENTSPACE_H

    // Calculates the tangent-space matrix of a polygon defined
    // with the vertices v1, v2 and v3.
    // @param const cnVertex& v1: The first vertex defining the polygon.
    // @param const cnVertex& v2: The second vertex.
    // @param const cnVertex& v3: The third vertex.
    cnMatrix cnComputeTangentSpace(const cnVertex& v1,
                                   const cnVertex& v2,
                                   const cnVertex& v3);

#endif // _CNORMAL_MATHS_TANGENTSPACE_H

