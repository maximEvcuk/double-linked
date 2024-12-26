#pragma once

#ifndef BANANA_H
#define BANANA_H

template <typename T>

class Banana {
private:
	struct Node {
		T data;
		Node* prev;
		Node* next;

		Node(T val) : data(val), prev(nullptr), next(nullptr) {}
	};

	Node* head;
	Node* tail;

public:
	Banana();
	~Banana();
	void AddToHead(T value);
	void AddToTail(T value);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteAll();
	void Show() const;


	void InsertAtPosition(T value, int position);
	void DeleteAtPosition(int position);
	int Search(T value) const;
	int Replace(T oldValue, T newValue);
	void Reverse();

	Node* getHead() const {
		return head;
	}

};
#include "Banana.cpp"
#endif // BANANA_H