
// cnVertex.h implementation

#include "cnVertex.h"

cnVertex::cnVertex()
: WORLD(), UV() {
}

cnVertex::cnVertex(cnVector WORLD, cnVector UV)
: WORLD(WORLD), UV(UV) {
}


cnVertex cnVertex::operator + (const cnVertex& vOther) const {
    return cnVertex(
        WORLD + vOther.WORLD,
        UV + vOther.UV );
}

cnVertex cnVertex::operator - (const cnVertex& vOther) const {
    return cnVertex(
        WORLD - vOther.WORLD,
        UV - vOther.UV );
}

cnVertex cnVertex::operator * (const cnVertex& vOther) const {
    return cnVertex(
        WORLD * vOther.WORLD,
        UV * vOther.UV );
}

cnVertex cnVertex::operator / (const cnVertex& vOther) const {
    return cnVertex(
        WORLD / vOther.WORLD,
        UV / vOther.UV );
}
