
// cnMeshHelper.h implementation

#include "cnMeshHelper.h"
#include <iostream>
using namespace std;

#if 1 // print functions
namespace {
    void print(cnVector v) {
        cout << "cnVector(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
    }
    void print(cnVertex v) {
        cout << "cnVertex {\n";
        cout << "    "; print(v.WORLD);
        cout << "    "; print(v.UV);
        cout << "}\n";
    }
    void print(cnMatrix m) {
        cout << "cnMatrix {\n";
        cout << "    "; print(m.T);
        cout << "    "; print(m.B);
        cout << "    "; print(m.N);
        cout << "    "; print(m.M);
        cout << "}\n";
    }
}
#endif

cnMeshHelper::cnMeshHelper() {
    vertexMatrices = null;
    polygonMatrices = null;
    vertexPolygons = null;
}

cnMeshHelper::~cnMeshHelper() {
    if (! vertexPolygons == null) {
        vertexPolygons->free(cnFreePointers);
    }
    delete vertexMatrices;
    delete vertexPolygons;
    delete polygonMatrices;
    vertexMatrices = null;
    vertexPolygons = null;
    polygonMatrices = null;
}


void cnMeshHelper::initialize(cnMesh& mesh,
                              cnMatrix (*polyMatrixFunc)(const cnVertex&,
                                                         const cnVertex&,
                                                         const cnVertex&) ) {
    // get the number of points and vertecies in the mesh
    int vertexCount  = mesh.getVertexCount();
    int polygonCount = mesh.getPolygonCount();

    // used to store the indices in a flexible way
    // but will be converted to an array of arrays later
    // and assigned to `vertexPolygons`.
    cnList<uint>* vertPolys = new cnList<uint>[vertexCount];

    // initialize the storage elements in the mesh helper
    vertexMatrices  = new cnMatrixArray(vertexCount);
    polygonMatrices = new cnMatrixArray(polygonCount);

    cnPolygon currentPolygon;
    cnVertex  v1, v2, v3;
    uint      a, b, c;

    for (int i = 0; i < polygonCount; i++) {
        currentPolygon = mesh.polygon(i);
        currentPolygon.assign(a, b, c);

        // add the polygons index to the
        // vertexPolygons indices
        // note: prepending is faster than appending
        vertPolys[a].prepend(i);
        vertPolys[b].prepend(i);
        vertPolys[c].prepend(i);

        v1 = mesh.vertex(a);
        v2 = mesh.vertex(b);
        v3 = mesh.vertex(c);

        (*polygonMatrices)[i] = polyMatrixFunc(v1, v2, v3);
    }

    // convert the indices of the polygons of the vertices
    // to an array.
    vertexPolygons  = new cnArray< cnArray<uint>* >(vertexCount);

    for (int i = 0; i < vertexCount; i++) {
        cnArray<uint>* arr = new cnArray<uint>( vertPolys[i].toArray() );
        (*vertexPolygons)[i] = arr;
    }

    delete [] vertPolys;

    cnArray<uint>* currentVertexPolygons;
    cnMatrix currentVertexMatrix;
    for (int i = 0; i < vertexCount; i++) {
        currentVertexPolygons = (*vertexPolygons)[i];
        int numPolygons = currentVertexPolygons->getLength();

        if (numPolygons == 0) {
            // the vertex is free and is not connected to any polygons
            currentVertexMatrix = cnMatrix();
        }
        else {
            currentVertexMatrix = cnMatrix(0);

            for (int j = 0; j < numPolygons; j++) {
                int currentPolygonIndex = (*currentVertexPolygons)[j];
                cnMatrix currentPolygonsMatrix;
                currentPolygonsMatrix = (*polygonMatrices)[currentPolygonIndex];
                currentVertexMatrix = currentVertexMatrix + currentPolygonsMatrix;
            }

            currentVertexMatrix = currentVertexMatrix.getNormalized();
        }

        currentVertexMatrix.M = mesh.point(i);
        (*vertexMatrices)[i] = currentVertexMatrix;
    }
}

cnMatrix cnMeshHelper::getVertexMatrix(uint index) const {
    return (*vertexMatrices)[index];
}

cnMatrix cnMeshHelper::getPolygonMatrix(uint index) const {
    return (*polygonMatrices)[index];
}

cnArray<uint>* cnMeshHelper::getVertexPolygons(uint i) const {
    return (*vertexPolygons)[i];
}

