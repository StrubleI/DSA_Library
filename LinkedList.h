#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>

class LinkedList {

private:

	struct Node {
		T data;
		Node* next;

		Node(T value) : data(value), next(nullptr) {}
	};
	Node* head;

public:

	LinkedList() : head(nullptr){}
	~LinkedList();

	void insert(T value);
	bool remove(T value);
	bool find(T value);
	void display() const;

};

template <typename T>
LinkedList<T>::~LinkedList() {

	Node* current = head;

	while (current) {
		Node* temp = current;
		current = current->next;
		delete temp;
	}

}

template <typename T>
void LinkedList<T>::insert(T value) {
	Node* newNode = new Node(value)
	newNode->next = head;
	head = newNode
}

template <typename T>
bool LinkedList<T>::find(T value) {
	Node* current = head;
	while (current) {
		if (current->data == value) return true;
		current = current->next;
	}
	return false;
}

template <typename T>
void LinkedList<T>::display() const{
	Node* current = head;

	while (current) {
		std::cout << (*current).data << " -> ";
		current = current->next;
	}
}

template <typename T>
bool LinkedList<T>::remove(T value) {
	Node *current = head, *prev = nullptr;
	while (current && (*current).data != value) {
		prev = current;
		current = current->next;
	}

	if (!current) return false;

	if (prev) prev->next = current->next;
	else head = current->next;

	delete current;
	return true;
}

#endif