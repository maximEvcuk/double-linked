#include "Banana.h"
#include <iostream>

template <typename T>
Banana<T>::Banana() : head(nullptr), tail(nullptr) {}

template <typename T>
Banana<T>::~Banana() {
	DeleteAll();
}

// + Голова  
template <typename T>
void Banana<T>::AddToHead(T value) {
	Node* newNode = new Node(value);
	if (!head) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

// + Хвіст 
template <typename T>
void Banana<T>::AddToTail(T value) {
	Node* newNode = new Node(value);
	if (!tail) {
		head = tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

// - Голова
template <typename T>
void Banana<T>::DeleteFromHead() {
	if (!head) return;
	Node* temp = head;
	head = head->next;
	if (head) head->prev = nullptr;
	else tail = nullptr;
	delete temp;
}

// - Хвіст
template <typename T>
void Banana<T>::DeleteFromTail() {
	if (!tail) return;
	Node* temp = tail;
	tail = tail->prev;
	if (tail) tail->next = nullptr;
	else head = nullptr;
	delete temp;
}

// - Всі елементи 

template <typename T>
void Banana<T>::DeleteAll() {
	while (head) {
		DeleteFromHead();
	}
}

//- Всі елементи списку 
template <typename T>
void Banana<T>::Show() const {
	Node* current = head;
	while (current) {
		std::cout << current->data << " ";
		current = current->next;
	}
	sstd::cout << std::endl;
}

template <typename T>
void Banana<T>::InsertAtPosition(T value, int position) {
	if (position < 0) return;
	if (position == 0) {
		AddToHead(value);
		return;
	}

	Node* newNode = new Node(value);
	Node* current = head;
	for (int i = 0;current != nullptr && i < position; ++i) {
		current = current->next;
	}

	if (current == nullptr) {
		AddToHead(value);
	}

	else {
		newNode->prev = current->prev;
		newNode->next = current;
		if (current->prev) current->prev->next = newNode;
		current->prev = newNode;
		if (newNode->prev == nullptr) head = newNode;
	}
}

template <typename T>
void Banana<T>::DeleteAtPosition(int position) {
	if (position < 0) return;
	Node* current = head;

	for (int i = 0; current != nullptr && i < position;; ++i) {
		current = current->next;
	}

	if (current == nullptr) return;

	if (current == prev) current->prev->next = current->next;
	if (current == next) current->next->prev = current->prev;
	if (current == head)  head = current->next;
	if (current == tail) tail = current->prev;

	delete current;
}

template <typename T>
int Banana<T>::Search(T value) const {
	Node* current = head;
	int position = 0;

	while (current) {
		if (current->data == value) {
			return position;
		}
		current = current->next;
		position++;
	}
	return -1;
}

template <typename T>
int Banana<T>::Replace(T oldValue, T newValue) {
	Node* current = head;
	int count = 0;

	while (current) {
		if (current->data == oldValue) {
			current->data = newValue;
			count++;
		}
		current = current->next;
	}
	return (count > 0) ? count : -1;
}

template <typename T>
void Banana<T>::Reverse() {
	Node* current = head;
	Node* temp = nullptr;

	while (current) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	if (temp) head = temp->prev;
}
