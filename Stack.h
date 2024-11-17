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

	Stack() : top(nullptr), stackSize(0);

	void push(T value); // Add an element to the top
	T pop();            // Remove and return the top element
	T peek() const;     // View the top element without removing it
	bool isEmpty() const; // Check if the stack is empty
	size_t size() const;  // Get the size of the stack
	void display() const; // Display the stack contents

};

#endif