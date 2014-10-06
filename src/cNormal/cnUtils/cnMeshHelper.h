
// The cnMeshHelper class calculates and stores information about
// a cnMesh object, such as matrices of polygons and vertices and
// the indices of a vertices polygons.

#include "cnMesh.h"

#include "../cnDefinitions.h"
#include "../cnStorage/cnStorage.h"
#include "cnMatrix.h"

#ifndef _CNORMAL_UTILS_MESHHELPER_H
#define _CNORMAL_UTILS_MESHHELPER_H

    class cnMeshHelper {

        public:
            cnMeshHelper();
            ~cnMeshHelper();

            // Initialize the cnMeshHelper object. E.g. the polygon and vertex matrices
            // are calculated using the overloaded function.
            // Note that using functions like cnMeshHelper.:getVertexMatrix(uint index)
            // without initializing the mesh helper will give undefined results.
            // @param cnMesh& mesh: The mesh to use for calculations.
            // @param cnMatrix (*polyMatrixFunc)(const cnVertex&, const cnVertex&, const cnVertex&):
            //      A function that calculates a matrix from 3 vertices.
            // @return void
            void initialize(cnMesh& mesh,
                            cnMatrix (*polyMatrixFunc)(const cnVertex&,
                                                       const cnVertex&,
                                                       const cnVertex&) );

            // Returns a vertices matrix that has been calculated
            // on initialization. Calling this function before initialization
            // will give undefined results.
            // @param unsigned int index: The vertices index.
            // @throw cnIndexOutOfBoundsException: If `index` is out of bounds.
            // @return cnMatrix
            cnMatrix getVertexMatrix(uint) const;

            // Returns a polygons matrix that has been calculated
            // on initialization. Calling this function before initialization
            // will give undefined results.
            // @param unsigned int index: The polygons index.
            // @throw cnIndexOutOfBoundsException: If `index` is out of bounds.
            // @return cnMatrix
            cnMatrix getPolygonMatrix(uint) const;

            // Returns a pointer to an array of integers that tell you the
            // indices of the polygons a vertex is connected with.
            // Calling this function before initialization will give undefined results.
            // @param unsigned int index: The polygons index.
            // @throw cnIndexOutOfBoundsException: If `index` is out of bounds.
            // @return cnArray<int>*
            cnArray<uint>* getVertexPolygons(uint) const;


        private:
            // stores the matrices of every vertex in the
            // mesh the cnMeshHelper was initialized with
            cnMatrixArray* vertexMatrices;

            // stores the indices of the polygons a vertex
            // is connected with
            cnArray< cnArray<uint>* >* vertexPolygons;

            // stores the matrices of every polygon in the
            // mesh the cnMeshHelper was initialized with
            cnMatrixArray* polygonMatrices;

    };

#endif // _CNORMAL_UTILS_MESHHELPER_H

