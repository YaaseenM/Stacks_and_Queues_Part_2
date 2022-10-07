#ifndef STACKS_AND_QUEUES_PART_2_ABQ_H
#define STACKS_AND_QUEUES_PART_2_ABQ_H

#include <iostream>

using namespace std;

template<typename T>
struct ABQ {
    ABQ();

    ABQ(int capacity);

    ABQ(const ABQ &d);

    ABQ &operator=(const ABQ &d);

    ~ABQ();

    void enqueue(T data);

    T dequeue();

    T peek();

    unsigned int getSize();

    unsigned int getMaxCapacity();

    T *getData();

    float *theArray;
    int _size = 0;
    int _capacity = 1;
    float value = 0.0f;
};

// Default Constructor
// Maximum capacity is set to 1, and current size set to 0.
template<typename T>
ABQ<T>::ABQ() {
    theArray = new float[_capacity];
    _size = 0;
}

// Constructor for an ABQ with the specified starting maximum capacity.
template<typename T>
ABQ<T>::ABQ(int capacity) {
    _capacity = capacity;
    theArray = new float[_capacity];
    _size = 0;
}

// Copy Constructor
template<typename T>
ABQ<T>::ABQ(const ABQ &d) {
    this->_capacity = d._capcity;
    this->_size = d._size;

    theArray = new float[_capacity];
    for (int i = 0; i < _size; i++) {
        theArray[i] = d.theArray[i];
    }

}

// Assignment operator
template<typename T>
ABQ<T> &ABQ<T>::operator=(const ABQ &d) {
    delete[] theArray;
    this->_capacity = d._capcity;
    this->_size = d._size;
    theArray = new float[_capacity];
    for (int i = 0; i < _size; i++) {
        theArray[i] = d.theArray[i];
    }
    return *this;
}


// Destructor
template<typename T>
ABQ<T>::~ABQ() {
    delete[] theArray;
}

// Add a new item to the end of the queue and resize necessary
template<typename T>
void ABQ<T>::enqueue(T data) {
    if (_size == _capacity) {
        _capacity = _capacity * 2;
        float *newArray = new float[_capacity];
        for (int i = 0; i < _size; i++) {
            newArray[i] = theArray[i];
        }
        delete[] theArray;
        theArray = new float[_capacity];
        for(int i = 0; i < _size; i++) {
            theArray[i] = newArray[i];
        }
        delete[] newArray;
    }
    theArray[_size] = data;
    _size++;
}

// Return the item at the end of the queue, resizes if necessary, and return the value removed.
// Throws a runtime_error if the stack is empty.
template<typename T>
T ABQ<T>::dequeue() {
    if (_size == 0) {
        throw runtime_error("An error has occurred.");
    }
    value = theArray[0];
    _size--;
    for(int i = 0; i < _size ; i++) {
        theArray[i] = theArray[i + 1];
    }
    if (((float)_size / (float)_capacity) < (1/2.0f)) {
        _capacity = _capacity / 2;
        float *newArray = new float[_capacity];
        for (int i = 0; i < _size; i++) {
            newArray[i] = theArray[i];
        }
        delete[] theArray;
        theArray = new float[_capacity];
        for(int i = 0; i < _size; i++) {
            theArray[i] = newArray[i];
        }
        delete[] newArray;
    }


    return value;

}

// Return the value of the item at the front of the queue, without removing it.
// Throws a runtime_error if the queue is empty.
template<typename T>
T ABQ<T>::peek() {
    if (_size == 0) {
        throw runtime_error("An error has occurred.");
    }
    return theArray[0];
}

// Returns the current number of items in the ABQ.
template<typename T>
unsigned int ABQ<T>::getSize() {
    return _size;
}

// Returns the current max capacity of the ABQ.
template<typename T>
unsigned int ABQ<T>::getMaxCapacity() {
    return _capacity;
}

// Returns the array representing the queue.
template<typename T>
T *ABQ<T>::getData() {
    return theArray;
}
#endif //STACKS_AND_QUEUES_PART_2_ABQ_H