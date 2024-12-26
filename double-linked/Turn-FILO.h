#pragma once
#include "Banana.h"

template <typename T>
class Turn {
private:
	Banana<T> list;

public:
	Turn() = default;
	void push(const T& value);
	void pop();
	T top() const;
	void clear();
	size_t size() const;
};