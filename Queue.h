#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* front; // Points to the front of the queue
    Node* rear;  // Points to the rear of the queue
    size_t queueSize; // Tracks the number of elements in the queue

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

// Destructor
template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Enqueue function
template <typename T>
void Queue<T>::enqueue(T value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    queueSize++;
}

// Dequeue function
template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue underflow: Cannot dequeue from an empty queue.");
    }
    Node* temp = front;
    T dequeuedValue = front->data;
    front = front->next;
    delete temp;
    if (!front) {
        rear = nullptr;
    }
    queueSize--;
    return dequeuedValue;
}

template <typename T>
T Queue<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty: Cannot peek.");
    }
    return front->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
size_t Queue<T>::size() const {
    return queueSize;
}

template <typename T>
void Queue<T>::display() const {
    Node* current = front;
    std::cout << "Queue contents (front to rear): ";
    while (current) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

#endif
