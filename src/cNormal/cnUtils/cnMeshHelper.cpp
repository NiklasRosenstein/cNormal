
// cnMeshHelper.h implementation

#include "cnMeshHelper.h"

#include <iostream>

cnMeshHelper::cnMeshHelper()
: vertexMatrices(), vertexPolygons(), polygonMatrices() {
}

cnMeshHelper::~cnMeshHelper() {
}


void cnMeshHelper::initialize(cnMesh& mesh,
                              cnMatrix (*polyMatrixFunc)(const cnVertex&,
                                                         const cnVertex&,
                                                         const cnVertex&) ) {
    // get the number of points and vertecies in the mesh
    int vertexCount  = mesh.getVertexCount();
    int polygonCount = mesh.getPolygonCount();

    vertexPolygons.resize(vertexCount);
    vertexMatrices.resize(vertexCount);
    polygonMatrices.resize(polygonCount);

    uint      a, b, c;
    cnVertex  v1, v2, v3;
    cnPolygon currentPolygon;

    for (int i = 0; i < polygonCount; i++) {
        currentPolygon = mesh.polygon(i);
        currentPolygon.assign(a, b, c);

        // add the polygons index to the vertexPolygons indices
        // note: prepending is faster than appending
        vertexPolygons[a].push_back(i);
        vertexPolygons[b].push_back(i);
        vertexPolygons[c].push_back(i);

        v1 = mesh.vertex(a);
        v2 = mesh.vertex(b);
        v3 = mesh.vertex(c);

        polygonMatrices[i] = polyMatrixFunc(v1, v2, v3);
    }

    // compute the vertex matrices
    for (int i = 0; i < vertexCount; i++) {
        // get the list of polygon indecies that are attached to
        // the current vertex.
        std::vector<uint>& currVertexPolygons = vertexPolygons[i];

        // add all the polygon matrices of the current vertex together
        // and normalize it afterwards.
        cnMatrix vertexMatrix = cnMatrix();
        vertexMatrix.M = mesh.point(i);
        for (std::vector<uint>::iterator it=currVertexPolygons.begin(); it != currVertexPolygons.end(); ++it) {
            vertexMatrix += polygonMatrices[*it];
        }
        vertexMatrix.normalize();
        vertexMatrices[i] = vertexMatrix;
    }
}

cnMatrix cnMeshHelper::getVertexMatrix(uint index) const {
    return vertexMatrices[index];
}

cnMatrix cnMeshHelper::getPolygonMatrix(uint index) const {
    return polygonMatrices[index];
}

const std::vector<uint>& cnMeshHelper::getVertexPolygons(uint i) const {
    return vertexPolygons[i];
}

