
// The cnMesh class represents an object in 3 dimensional space
// built of vertices (3d points and uv coordinated) and polygons.
// Make sure you use pointers or references to a mesh as the
// copy constructors always copy the vertices and polygons.

#ifndef _CNORMAL_UTILS_MESH_H
#define _CNORMAL_UTILS_MESH_H

    #include "../cnDefinitions.h"
    #include "../cnExceptions.h"
    #include "cnVector.h"
    #include "cnVertex.h"
    #include "cnMatrix.h"
    #include "cnPolygon.h"

    #include <vector>

    class cnMesh {

        public:

            // Construct a cnMesh object with the given size.
            // @param unsigned int vertexCount: The number of vertices of the mesh.
            // @param unsigned int polygonCount: The number of polygons of the mesh.
            cnMesh(uint vertexCount, uint polygonCount);

            // These copy constructors copy all vertecies and polygons
            // from one mesh to another. Use pointers or refernces
            // when you don't want to make a whole copy of a mesh
            cnMesh(const cnMesh& other);
            cnMesh(const cnMesh* other);
            ~cnMesh();

            // Return a reference to the 3d point at given index.
            // @param unsigned int index: The 3d points index.
            // @throw cnIndexOutOfBoundsException: If index is not in range.
            // @return cnVector&
            cnVector& point(uint index);
            const cnVector& point(uint index) const;

            // Return a reference to the UV point at given index.
            // @param unsigned int index: The UV points index.
            // @throw cnIndexOutOfBoundsException: If index is not in range.
            // @return cnVector&
            cnVector& uvpoint(uint index);
            const cnVector& uvpoint(uint index) const;

            // Return a reference to the vertex at given index.
            // @param unsigned int index: The vertices index.
            // @throw cnIndexOutOfBoundsException: If index is not in range.
            // @return cnVertex&
            cnVertex& vertex(uint index);
            const cnVertex& vertex(uint index) const;

            // Return a reference to the polygon at given index.
            // @param unsigned int index: The polygon index.
            // @throw cnIndexOutOfBoundsException: If index is not in range.
            // @return cnPolygon&
            cnPolygon& polygon(uint index);
            const cnPolygon& polygon(uint index) const;

            // Return the number of vertecies in the mesh.
            // @return unsigned int
            uint getVertexCount() const;

            // Return the number of polygons in the mesh.
            // @return unsigned int
            uint getPolygonCount() const;

            // Returns a copy of the mesh.
            cnMesh* getCopy() const;

        private:
            std::vector<cnVertex> verts;
            std::vector<cnPolygon> polygons;
    };

#endif // _CNORMAL_UTILS_MESH_H
