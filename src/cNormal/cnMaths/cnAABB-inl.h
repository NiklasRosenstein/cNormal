
// Inline implementation of cnAABB

inline bool cnAABB::pointWithin(cnVector& p) const {
    return p.in(boxMin_, boxMax_);
}
