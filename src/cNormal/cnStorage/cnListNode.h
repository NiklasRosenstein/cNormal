
// The cnListNode<class T> class represents a node in a single-linked list.
// You do not have to handle with it.
// Note that a cnListNode<class T> automatically deletes all following nodes
// when using its destructor.

#include "../cnDefinitions.h"
#include "../cnExceptions.h"
#include "cnArray.h"

#ifndef _CNORMAL_STORAGE_LISTNODE_H
#define _CNORMAL_STORAGE_LISTNODE_H

    template <class T>
    class cnListNode {

        public:
            // Construct the cnListNode<class T> instance. `next` may be a null pointer.
            // @param T data: The data the node should carry.
            // @param cnListNode<T>* next: The node next to this one or null.
            cnListNode(T data, cnListNode<T>* next);

            // Destroy the cnListNode<class T> instance. Includes deleting all following
            // nodes.
            ~cnListNode();

            // Return a reference to the data the node carries.
            // @return T&
            inline T& getData();

            // Return a reference to the next node.
            // @return cnListNode<class T>*&
            inline cnListNode<T>*& getNextNode();

            // Return a pointer to the node that is offset by `num` relative
            // the calling node.
            // @param unsigned int num: the offset of nodes
            // @return cnListNode<class T>* or null
            cnListNode<T>* getNumNode(uint num);

            // Return a pointer to the last node in the chain.
            // May be the same as the calling one.
            // @return cnListNode<class T>*
            cnListNode<T>* getLastNode();

            // Fill the cnArray<T> instance with the data stored in the nodes.
            // Make sure the array's length equals or is higher than the length
            // of the chain.
            // @param cnArray<T>* array: The array to fill.
            // @param unsigned int index: The index for the node.
            void fill(cnArray<T>* array, uint index) const;

            // Use this function when you store pointers in the list and you need to free them.
            // @param void (*freeFunc)(T& pointer): The function that takes an instance of T as
            //                                      argument and deletes it if necessary.
            void free(void (*freeFunc)(T& pointer));

        private:
            T nodeData;
            cnListNode<T>* nextNode;
    };

    #include "cnListNode.tpp"

#endif // _CNORMAL_STORAGE_LISTNODE_H
