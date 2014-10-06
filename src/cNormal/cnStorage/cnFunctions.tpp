
// cnFunctions.h template implementation

template<class T> void cnFreePointers(T& pointer) {
    // check wether the pointer is null or not
    // and free it
    if (not pointer == null)
        delete pointer;
}
