
// cnMatrix.h implementation

#include "cnMatrix.h"
#include "cnVector.h"

// 2-by-2 matrix determinant calculation
#define cnMatBy2(a, b, c, d) ( (a * d) - (b * c) )

cnMatrix::cnMatrix()
        : T( cnVector(1, 0, 0) ),
          B( cnVector(0, 1, 0) ),
          N( cnVector(0, 0, 1) ),
          M( cnVector() ) {
}

cnMatrix::cnMatrix(cnVector T, cnVector B, cnVector N)
        : T(T),
          B(B),
          N(N),
          M( cnVector() ) {
}

cnMatrix::cnMatrix(cnVector T, cnVector B, cnVector N, cnVector M)
        : T(T),
          B(B),
          N(N),
          M( M ) {
}

cnMatrix::cnMatrix(int)
        : T( cnVector() ),
          B( cnVector() ),
          N( cnVector() ),
          M( cnVector() ) {
}

cnMatrix cnMatrix::operator + (const cnMatrix& mOther) const {
    return cnMatrix (
        T + mOther.T,
        B + mOther.B,
        N + mOther.N,
        M + mOther.M );
}

cnMatrix cnMatrix::operator - (const cnMatrix& mOther) const {
    return cnMatrix (
        T - mOther.T,
        B - mOther.B,
        N - mOther.N,
        M - mOther.M );
}

cnMatrix cnMatrix::operator * (const cnMatrix& mOther) const {
    return cnMatrix (
        T * mOther.T,
        B * mOther.B,
        N * mOther.N,
        M * mOther.M );
}

cnMatrix cnMatrix::operator / (const cnMatrix& mOther) const {
    return cnMatrix (
        T / mOther.T,
        B / mOther.B,
        N / mOther.N,
        M / mOther.M );
}

cnMatrix cnMatrix::operator / (const double& scalar) const {
    return cnMatrix (
         T / scalar,
         B / scalar,
         N / scalar,
         M / scalar );
}

cnVector operator * (const cnVector& v, const cnMatrix& m) {
    return cnVector(
        (v.x * m.T.x) + (v.y * m.T.y) + (v.z * m.T.z) + m.M.x,
        (v.x * m.B.x) + (v.y * m.B.y) + (v.z * m.B.z) + m.M.y,
        (v.x * m.N.x) + (v.y * m.N.y) + (v.z * m.N.z) + m.M.z
    );
}

double cnMatrix::det() const {
    // calculate the determinant of this 3-by-3 matrix,
    // note that the offset (M) does not play a role here
    double a1 = T.x * cnMatBy2(B.y, B.z, N.y, N.z);
    double a2 = T.y * cnMatBy2(B.x, B.z, N.x, N.z);
    double a3 = T.z * cnMatBy2(B.x, B.y, N.x, N.y);
    return a1 - a2 + a3;
}

cnMatrix cnMatrix::getNormalized() const {
    return cnMatrix(
        T.getNormalized(),
        B.getNormalized(),
        N.getNormalized(),
        M );
}
