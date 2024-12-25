#pragma once


#include"Array.h"

template <typename T>
class Turn {
private:
	Array<T> array;

public:
	Turn(size_t capacity = 10);
	void push(const T& value);
	void pop();
	T top() const;
	void clear();
	size_t size() const;
};