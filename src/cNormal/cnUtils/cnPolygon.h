
// The cnPolygon class represents a triangular face. Its indecies
// are links to the vertecies in a mesh.

#include "../cnDefinitions.h"
#include "../cnStorage/cnArray.h"

#ifndef _CNORMAL_UTILS_POLYGON_H
#define _CNORMAL_UTILS_POLYGON_H

    class cnPolygon {

        public:
            uint a, b, c;

            cnPolygon();
            cnPolygon(uint a, uint b, uint c);

            // Assign all three indecies to variables
            // @param unsigned int& a: The variable recieving the a index.
            // @param unsigned int& b: The variable recieving the b index.
            // @param unsigned int& c: The variable recieving the c index.
            void assign(uint& a, uint& b, uint& c) const;
    };

    typedef cnArray<cnPolygon> cnPolygonArray;

#endif // _CNORMAL_UTILS_POLYGON_H
