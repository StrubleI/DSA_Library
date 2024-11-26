#pragma once
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {

private:

	struct Node {
		T data;
		Node* next;
		Node(T value) : data(value), next(nullptr);
	};

	Node* top;
	size_t stackSize;


public:

	~Stack();
	Stack() : top(nullptr), stackSize(0);

	void push(T value); // Add an element to the top
	T pop();            // Remove and return the top element
	T peek() const;     // View the top element without removing it
	bool isEmpty() const; // Check if the stack is empty
	size_t size() const;  // Get the size of the stack
	void display() const; // Display the stack contents

};

template <typename T>
void Stack<T>::push(T value) {
	Node* newNode = new Node(value);
	newNode->next = top;
	top = newNode;
	stacksize++;
}

template <typename T>
Stack<T>::~Stack() {
	while (!isEmpty){
		pop();
	}
}

template <typename T>
T Stack<T>::pop() {
	if (isEmpty()) {
		throw std::underflow_error("Stack underflow: Cannot pop from an empty stack.");
	}
	
	Node* temp = top;
	T poppedValue = top->data;
	top = top->next;
	delete temp;
	stacksize--;
	return poppedValue;

}

template <typename T>
T Stack<T>::peek() const{
	if (isEmpty()) {
		throw std::underflow_error("Stack is empty: can't peek.")
	}
	else return top->data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return top == nullptr;
}

template <typename T>
size_t Stack<T>::size() const {
	return stackSize;
}

template <typename T>
void Stack<T>::display() const {
	Node* current = top;
	std::cout << "Stack contents: ";
	while (current) {
		std::cout << current->data << " -> ";
		current->next;
	}
}

#endif