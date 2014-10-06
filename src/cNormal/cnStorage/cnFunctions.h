
// The cnFunctions header defines functions that may be used with
// storage classes like the cnArray and cnList.

#ifndef _CNORMAL_STORAGE_FUNCTIONS_H
#define _CNORMAL_STORAGE_FUNCTIONS_H

    // This is a convenient function that frees pointers in a storage element for you.
    // Use it within cnArray<class T>::free(void (*freeFunc)(T)) or
    // cnList<class T>::free(void (*freeFunc)(T)).
    // @param T object: an instance of T that will be freed using the
    //                  the `delete` operator.
    template <class T>
    void cnFreePointers(T& pointer);

    #include "cnFunctions.tpp"

#endif // _CNORMAL_STORAGE_FUNCTIONS_H
