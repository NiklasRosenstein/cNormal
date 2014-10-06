
// The cnMatrix class represents a 3-by-3 rotation matrix with an
// additional offset attribute.

#include "cnVector.h"
#include "../cnStorage/cnArray.h"

#ifndef _CNORMAL_UTILS_MATRIX_H
#define _CNORMAL_UTILS_MATRIX_H

    class cnMatrix {

        public:
            // Tangent, Bi-Tangent, Normal and Offset
            cnVector T, B, N, M;

            // Construct a standart matrix, e.g.
            //  T | 1 0 0 |
            //  B | 0 1 0 |
            //  N | 0 0 1 |
            //  M | 0 0 0 |
            cnMatrix();

            // Construct a matrix from 3 vectors.
            // @param cnVector T: The Tangent.
            // @param cnVector B: The Bi-Tangent.
            // @param cnVector N: The Normal.
            cnMatrix(cnVector T, cnVector B, cnVector N);

            // Construct a matrix from 4 vectors.
            // @param cnVector T: The Tangent.
            // @param cnVector B: The Bi-Tangent.
            // @param cnVector N: The Normal.
            // @param cnVector M: The Offset.
            cnMatrix(cnVector T, cnVector B, cnVector N, cnVector M);

            // Construct a zero matrix. The parameter is just
            // for indication purpose.
            // E.g. T | 0 0 0 |
            //      B | 0 0 0 |
            //      N | 0 0 0 |
            //      M | 0 0 0 |
            // @param int /**/: Unused, indicating index.
            explicit cnMatrix(int);

            // Simple math operators.
            // @param const cnMatrix&: The other matrix.
            // @return cnMatrix
            cnMatrix operator + (const cnMatrix& mOther) const;
            cnMatrix operator - (const cnMatrix& mOther) const;
            cnMatrix operator * (const cnMatrix& mOther) const;
            cnMatrix operator / (const cnMatrix& mOther) const;

            // Scale the matrix by a scalar.
            // @param double scalar: The scalar.
            // @return cnMatrix
            cnMatrix operator / (const double& scalar) const;

            // Return the determinant of the matrix.
            // @return double: The determinant.
            double det() const;

            // Return the normalized matrix.
            // @return cnMatrix
            cnMatrix getNormalized() const;
    };

    // Mulitply a vector with a matrix. The matrix will serve
    // as rotation matrix and will give the following multiplication:
    // | x | | Tx Ty Tz | + | Mx |   | x*Tx + y*Ty + z*Tz + Mx |
    // | y | | Bx By Bz | + | My | = | x*Bx + y*By + z*Bz + My |
    // | z | | Nx Ny Nz | + | Mz |   | x*Nx + y*Ny + z*Nz + Mz |
    // @param const cnVector& v: The vector.
    // @param const cnMatrix& m: The matrix.
    // @return cnVector: The new vector.
    cnVector operator * (const cnVector& v, const cnMatrix& m);

    typedef cnArray<cnMatrix> cnMatrixArray;

#endif // _CNORMAL_UTILS_MATRIX_H
