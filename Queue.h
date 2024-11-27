#pragma once
#ifndef QUEUE
#define QUEUE

#include <iostream>
#include <stdexcept>

template <typename T>

class Queue {
private:

	struct Node {
		T data;
		Node* next;
		Node(T value) : data(value), next(nullptr);
	};

	Node* front;
	Node* rear;
	size_t queueSize;

public:

	Queue() : front(nullptr), rear(nullptr), queueSize(0) {}
	~Queue();

	void enqueue(T value); // Add an element to the rear
	T dequeue();           // Remove and return the front element
	T peek() const;        // View the front element without removing it
	bool isEmpty() const;  // Check if the queue is empty
	size_t size() const;   // Get the size of the queue
	void display() const;  // Display the queue contents

};


template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(T value) {
    
}

template <typename T>
T Queue<T>::dequeue() {
    
}

template <typename T>
T Queue<T>::peek() const {
    
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
size_t Queue<T>::size() const {
    
}

template <typename T>
void Queue<T>::display() const {
    
}

#endif 