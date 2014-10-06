
// cnList.h template implementaton

template<class T> cnList<T>::cnList() {
    firstNode = null;
    length = 0;
}

template<class T> cnList<T>::~cnList() {
    if (not firstNode == null)
        // invoke the deletion chain
        delete firstNode;

    firstNode = null;
    length = 0;
}

template<class T> T& cnList<T>::operator [] (uint index) {
    if (index >= length) {
        // throw an exception if index is
        // out of the lists bounds
        throw cnIndexOutOfBoundsException(index, length);
    }
    else {
        return firstNode->getNumNode(index)->getData();
    }
}

template<class T> uint cnList<T>::getLength() const {
    return length;
}

template<class T> void cnList<T>::prepend(T data) {
    firstNode = new cnListNode<T>(data, firstNode);
    length++;
}

template<class T> void cnList<T>::append(T data) {
    cnListNode<T>* node = new cnListNode<T>(data, null);

    if (firstNode == null) {
        firstNode = node;
    }
    else {
        cnListNode<T>* last = firstNode->getLastNode();
        last->getNextNode() = node;
    }

    length++;
}

template<class T> T cnList<T>::grab() {
    if (length == 0) {
        // throw an exception if index is
        // out of the lists bounds
        throw cnIndexOutOfBoundsException(0, 0);
    }
    else if (length == 1) {
        T data = firstNode->getData();

        delete firstNode;
        firstNode = null;
        length = 0;

        return data;
    }
    else {
        cnListNode<T>* tempNode = firstNode;
        T data = tempNode->getData();

        firstNode = firstNode->getNextNode();

        // free the node from the chain so its
        // deletion wont cause the others do be
        // deleted
        tempNode->getNextNode() = null;

        delete tempNode;
        length--;

        return data;
    }
}

template<class T> T cnList<T>::pop() {
    if (length == 0) {
        // throw an exception if index is
        // out of the lists bounds
        throw cnIndexOutOfBoundsException(0, 0);
    }
    else if (length == 1) {
        T data = firstNode->getData();

        delete firstNode;
        firstNode = null;
        length = 0;

        return data;
    }
    else {
        cnListNode<T>* node = firstNode->getNumNode(length - 2);
        T data = node->getNextNode()->getData();

        delete node->getNextNode();
        node->getNextNode() = null;
        length--;

        return data;
    }
}

template<class T> cnArray<T> cnList<T>::toArray() const {
    cnArray<T> arr(length); // = new cnArray<T>(length);

    // fill the array recursively
    if (not firstNode == null)
        firstNode->fill(&arr, 0);

    return arr;
}

template<class T> void cnList<T>::free(void (*freeFunc)(T&)) {
    if (not firstNode == null)
        firstNode->free(freeFunc);
}
