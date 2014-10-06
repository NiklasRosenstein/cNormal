
// The cnArray<class T> class is a simple wrapper for C++ array pointers.
// Initialize the cnArray<class T> instance with an unsigned integer
// that defines the length of the array.
// The internal C++ array is automatically deallocated when the constructor
// is called.
// Note that copy-assignment does not copy the internal C++ array. Use
// cnArray<class T>::getCopy() instead.

#include "../cnDefinitions.h"
#include "../cnExceptions.h"

#ifndef _CNORMAL_STORAGE_ARRAY_H
#define _CNORMAL_STORAGE_ARRAY_H


    template <class T>
    class cnArray {

        public:
            // Construct a cnArray<T> instance with the number of fields
            // the array should have.
            // @param unsigned int length: The length of the array.
            cnArray(uint length);

            ~cnArray();

            // Operator access to the items in the array. This function is inlined
            // for more speed.
            // Throws cnIndexOutOfBoundsException when `index` is greate than
            // the maximum index. (cnArray.getLength() - 1)
            // @param unsigned int index: unsigned int
            // @return T&
            inline T& operator [] (uint);

            // Returns the length of the array.
            // @return unsigned int
            inline uint getLength() const;

            // Return a copy of the array. Copys the whole internal array.
            // @return cnArray<T>
            cnArray<T>* getCopy() const;

            // Use this function, if you store pointers in your array, to free them.
            // @param void (*freeFunc)(T): The function that frees the instance of T.
            void free(void (*freeFunc)(T&));

        private:
            // the internal array pointer
            T* interArray;
            uint length;
    };

    #include "cnArray.tpp"

#endif // _CNORMAL_STORAGE_ARRAY_H
