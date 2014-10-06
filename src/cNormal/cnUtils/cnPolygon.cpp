
// cnPolygon.h implementation

#include "cnPolygon.h"

cnPolygon::cnPolygon()
        : a(0),
          b(0),
          c(0) {
}

cnPolygon::cnPolygon(uint a, uint b, uint c)
        : a(a),
          b(b),
          c(c) {
}

void cnPolygon::assign(uint& a_, uint& b_, uint& c_) const {
    a_ = a;
    b_ = b;
    c_ = c;
}
