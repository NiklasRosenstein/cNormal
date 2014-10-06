
// The cnVertex class combines a 3 dimensional and 2 dimensional point
// to define a vertex in a 3d mesh.

#include "cnVector.h"
#include "../cnStorage/cnArray.h"

#ifndef _CNORMAL_UTILS_VERTEX_H
#define _CNORMAL_UTILS_VERTEX_H

    class cnVertex {

        public:
            cnVector WORLD, UV;

            cnVertex();
            cnVertex(cnVector WORLD, cnVector UV);

            // Basic math operations.
            // @param const cnVertex& vOther: The other operand.
            // @return cnVertex
            cnVertex operator + (const cnVertex& vOther) const;
            cnVertex operator - (const cnVertex& vOther) const;
            cnVertex operator * (const cnVertex& vOther) const;
            cnVertex operator / (const cnVertex& vOther) const;
    };

    typedef cnArray<cnVertex> cnVertexArray;

#endif // _CNORMAL_UTILS_VERTEX_H

