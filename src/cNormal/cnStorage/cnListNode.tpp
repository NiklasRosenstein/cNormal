
// cnListNode.h template implementation

#include <stdio.h>

template<class T> cnListNode<T>::cnListNode(T data, cnListNode<T>* next)
        : nodeData(data),
          nextNode(next) {
}

template<class T> cnListNode<T>::~cnListNode() {
    delete nextNode;
    nextNode = null;
}

template<class T> T& cnListNode<T>::getData() {
    return nodeData;
}

template<class T>cnListNode<T>*& cnListNode<T>::getNextNode() {
    return nextNode;
}

template<class T> cnListNode<T>* cnListNode<T>::getNumNode(uint num) {
    if (num == 0) {
        return this;
    }
    else if (nextNode == null)
        return null;
    else {
        return nextNode->getNumNode(num - 1);
    }
}

template<class T> cnListNode<T>* cnListNode<T>::getLastNode() {
    if (nextNode == null) {
        return this;
    }
    else {
        return nextNode->getLastNode();
    }
}

template<class T> void cnListNode<T>::fill(cnArray<T>* arr, uint index) const {
    (*arr)[index] = nodeData;
    if (! nextNode == null) {
        nextNode->fill(arr, index + 1);
    }
}

template<class T> void cnListNode<T>::free(void (*freeFunc)(T&)) {
    freeFunc(nodeData);
    if (not nextNode == null) {
        nextNode->free(freeFunc);
    }
}
