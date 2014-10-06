
// The cnVector class represents a point in 3 dimensional space.
// It is also used to store 2 dimensional UV data.

#ifndef _CNORMAL_UTILS_VECTOR_H
#define _CNORMAL_UTILS_VECTOR_H

    class cnVector {

        public:
            double x, y, z;

            cnVector();
            cnVector(double xyz);
            cnVector(double x, double y);
            cnVector(double x, double y, double z);

            // These operators do their operation and return a new object.
            // @param const cnVector& vOther: The other vector.
            // @return cnVector
            cnVector operator + (const cnVector& vOther) const;
            cnVector operator - (const cnVector& vOther) const;
            cnVector operator * (const cnVector& vOther) const;
            cnVector operator / (const cnVector& vOther) const;

            // These operators do their operation with a double value
            // applied to all 3 components and return a new object.
            // @param const double& dValue: The value.
            // @return cnVector
            cnVector operator + (const double& dValue) const;
            cnVector operator - (const double& dValue) const;
            cnVector operator * (const double& dValue) const;
            cnVector operator / (const double& dValue) const;

            // These operators do their operation and modify the original object.
            // @param const cnVector& vOther: The other vector.
            // @return cnVector&
            cnVector& operator += (const cnVector& vOther);
            cnVector& operator -= (const cnVector& vOther);
            cnVector& operator *= (const cnVector& vOther);
            cnVector& operator /= (const cnVector& vOther);

            // These operators do their operation with a double value
            // applied to all 3 components and modify the original object.
            // @param const double& dValue: The value.
            // @return cnVector&
            cnVector& operator += (const double& dValue);
            cnVector& operator -= (const double& dValue);
            cnVector& operator *= (const double& dValue);
            cnVector& operator /= (const double& dValue);

            // Returns the inverted vector.
            // @return cnVector
            cnVector operator ~ () const;

            // Returns true if the vector is within the volume
            // the other vetors define.
            // @param cnVector min: The minimum-vector.
            // @param cnVector max: The maximum-vector.
            // @return bool
            bool in(cnVector min, cnVector max) const;

            // Returns the length of the vector.
            // @return double
            double getLength() const;

            // Returns the dot-product of two vectors.
            // @param const cnVector& vOther: The other vector.
            // @return double
            double dot(const cnVector& vOther) const;

            // Returns the cross-product of two vectors.
            // @param const cnVector& vOther: The other vector.
            // @return cnVector
            cnVector cross(const cnVector& vOther) const;

            // Returns the normalized vector.
            // @throw cnZeroDivisionException: if calling object is a 0-vector.
            // @return cnVector
            cnVector getNormalized() const;

            // Normalize this vector.
            // @throw cnZeroDivisionException: if calling object is a 0-vector.
            cnVector& normalize();
    };

#endif // _CNORMAL_UTILS_VECTOR_H
