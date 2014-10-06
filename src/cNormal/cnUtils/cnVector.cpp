
// cnVector.h implementation

#include "cnVector.h"
#include "../cnDefinitions.h"
#include "../cnExceptions.h"
#include <math.h>

cnVector::cnVector()
: x(0), y(0), z(0) {
}

cnVector::cnVector(double xyz)
: x(xyz), y(xyz), z(xyz) {
}

cnVector::cnVector(double u, double v)
: x(u), y(v), z(0) {
}

cnVector::cnVector(double x, double y, double z)
: x(x), y(y), z(z) {
}

cnVector cnVector::operator + (const cnVector& vOther) const {
    return cnVector(
        x + vOther.x,
        y + vOther.y,
        z + vOther.z );
}

cnVector cnVector::operator - (const cnVector& vOther) const {
    return cnVector(
        x - vOther.x,
        y - vOther.y,
        z - vOther.z );
}

cnVector cnVector::operator * (const cnVector& vOther) const {
    return cnVector(
        x * vOther.x,
        y * vOther.y,
        z * vOther.z );
}

cnVector cnVector::operator / (const cnVector& vOther) const {
    if (vOther.x == 0 || vOther.y == 0 || vOther.z == 0)
        throw cnZeroDivisionException();

    return cnVector(
        x / vOther.x,
        y / vOther.y,
        z / vOther.z );
}

cnVector cnVector::operator + (const double& dValue) const {
    return cnVector(
        x + dValue,
        y + dValue,
        z + dValue );
}

cnVector cnVector::operator - (const double& dValue) const {
    return cnVector(
        x - dValue,
        y - dValue,
        z - dValue );
}

cnVector cnVector::operator * (const double& dValue) const {
    return cnVector(
        x * dValue,
        y * dValue,
        z * dValue );
}

cnVector cnVector::operator / (const double& dValue) const {
    return cnVector(
        x / dValue,
        y / dValue,
        z / dValue );
}

cnVector& cnVector::operator += (const cnVector& vOther) {
    x += vOther.x;
    y += vOther.y;
    z += vOther.z;
    return *this;
}

cnVector& cnVector::operator -= (const cnVector& vOther) {
    x -= vOther.x;
    y -= vOther.y;
    z -= vOther.z;
    return *this;
}

cnVector& cnVector::operator *= (const cnVector& vOther) {
    x *= vOther.x;
    y *= vOther.y;
    z *= vOther.z;
    return *this;
}

cnVector& cnVector::operator /= (const cnVector& vOther) {
    x /= vOther.x;
    y /= vOther.y;
    z /= vOther.z;
    return *this;
}

cnVector& cnVector::operator += (const double& dValue) {
    x += dValue;
    y += dValue;
    z += dValue;
    return *this;
}

cnVector& cnVector::operator -= (const double& dValue) {
    x -= dValue;
    y -= dValue;
    z -= dValue;
    return *this;
}

cnVector& cnVector::operator *= (const double& dValue) {
    x *= dValue;
    y *= dValue;
    z *= dValue;
    return *this;
}

cnVector& cnVector::operator /= (const double& dValue) {
    x /= dValue;
    y /= dValue;
    z /= dValue;
    return *this;
}

cnVector cnVector::operator ~ () const {
    return cnVector(-x, -y, -z);
}

bool cnVector::in(cnVector min, cnVector max) const {
    bool isX = min.x <= x && x <= max.x;
    bool isY = min.y <= y && y <= max.y;
    bool isZ = min.z <= z && z <= max.z;
    return isX && isY && isZ;
}

double cnVector::getLength() const {
    return pow((x * x) + (y * y) + (z * z), 0.5);
}

double cnVector::dot (const cnVector& vOther) const {
    return (x * vOther.x + y * vOther.y + z * vOther.z);
}

cnVector cnVector::cross (const cnVector& vOther) const {
    return cnVector(
        y * vOther.z - z * vOther.y,
        z * vOther.x - x * vOther.z,
        x * vOther.y - y * vOther.x );
}

cnVector cnVector::getNormalized() const {
    double len = this->getLength();
    if (len == 0.0) {
        throw cnZeroDivisionException();
    }

    double mult = 1.0 / len;
    return cnVector(
        x * mult,
        y * mult,
        z * mult );
}

cnVector& cnVector::normalize() {
    double len = this->getLength();
    if (len == 0.0) {
        throw cnZeroDivisionException();
    }

    double mult = 1.0 / len;
    x *= mult;
    y *= mult;
    z *= mult;
    return *this;
}
