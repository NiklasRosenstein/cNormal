
// cnArray.h template implementation

template<class T> cnArray<T>::cnArray(uint length) : length(length) {
    interArray = new T[length];
};

template<class T> cnArray<T>::~cnArray() {
    delete [] interArray;
    interArray = null;
    length = 0;
};

template<class T> T& cnArray<T>::operator [] (uint index) {
    if (index >= length)
        // throw an exception if the index is
        // out of the arrays bounds
        throw cnIndexOutOfBoundsException(index, length);
    else
        return interArray[index];
};

template<class T> uint cnArray<T>::getLength() const {
    return length;
};

template<class T> cnArray<T>* cnArray<T>::getCopy() const {
    // create a new cnArray<T> object
    cnArray<T>* arr = new cnArray(length);

    // copy every field to the array
    for (uint i = 0; i < length; i++ )  {
        arr->interArray[i] = interArray[i];
    }

    return arr;
}

template<class T> void cnArray<T>::free(void (*freeFunc)(T&)) {
    // call the function for every item
    // in the array
    for (uint i = 0; i < this->length; i++) {
        freeFunc(interArray[i]);
    }
}
