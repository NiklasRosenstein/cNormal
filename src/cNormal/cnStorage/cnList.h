
// The cnList<class T> class is an appendable set of data.
// It has very low overhead and is easy to use.

#include "../cnDefinitions.h"
#include "../cnExceptions.h"
#include "cnArray.h"
#include "cnListNode.h"

#ifndef _CNORMAL_STORAGE_LIST_H
#define _CNORMAL_STORAGE_LIST_H

    template <class T>
    class cnList {

        public:
            cnList();

            // Destroy the cnList<class T> instance.
            // Note: If you store pointers in the list, use
            // cnList::free(void (*)(T)) to free them.
            ~cnList();

            // Access an item in the list. (Get / Set)
            // @param unsigned int index: The items index
            // @throw cnIndexOutOfBoundsException if `index` is out of range.
            // @return T&
            inline  T& operator [] (uint index);


            // Return the length of the list.
            // @return unsigned int
            inline  uint getLength() const;

            // Add `item` of type `T` to the beginning of the list.
            // @param T item: The item to add.
            void prepend(T item);

            // Add `item` of type `T` to the end of the list.
            // @param T item: The item to add.
            void append(T item);

            // Remove the first item in the list and return it.
            // @return T
            // @throw cnIndexOutOfBoundsException: if the list is empty.
            T grab();

            // Remove the last item in the list and return it.
            // @return T
            // @throw cnIndexOutOfBoundsException: if the list is empty.
            T pop();

            // Convert the list to a cnArray instance.
            // @return cnArray<T>
            cnArray<T> toArray() const;

            // Use this function to free pointers stored in the list.
            // It will call the function argument for each object in it.
            // @param void (*freeFunc)(T): The function that frees the pointers.
            void free(void (*freeFunc)(T&));

        private:
            // keeps track of the lists length
            uint length;
            // reference to the first node in the list
            cnListNode<T>* firstNode;
    };

    #include "cnList.tpp"

#endif // _CNORMAL_STORAGE_LIST_H
