
// The cnExceptions header declares exceptions that my
// be raised from doing operations on objects of the

#include "cnDefinitions.h"

#ifndef _CNORMAL_EXCEPTIONS_H
#define _CNORMAL_EXCEPTIONS_H

    // The base class for exceptions in the cNormal package.
    class cnException {
    };

    // This exception is thrown when an accessor-index is not
    // in ordinal range.
    class cnIndexOutOfBoundsException : public cnException {

        public:
            uint index;
            uint length;

            cnIndexOutOfBoundsException(uint index, uint length);
    };

    // This exception is thrown when for example dividing with a vector
    // with a zero-component.
    class cnZeroDivisionException : public cnException {
    };

    // This exceptions is thrown if the Uv of a mesh is invalid
    // for normal mapping.
    class cnInvalidUvException : public cnException {
    };

    // This exception is thrown if a method or function is not
    // already implemented.
    class cnNotImplemented : public cnException {
    };

#endif // _CNORMAL_EXCEPTIONS_H
