#include"Turn-FILO.h"
#include<stdexcept>


template <typename T>
Turn<T>::Turn(size_t capacity) : array(capacity) {}

template <typename T>
void Turn<T>::push(const T& value) {
	array.append(value);
}

template <typename T>
void Turn<T>::pop() {
	if (array.getSize() == 0) {
		throw std::out_of_range("Stack is empty. Cannot  pop.");
	}
	array.erase(0);
}

template <typename T>
T Turn<T>::top() const {
	if (array.getSize() == 0) {
		throw std::out_of_range("Stack is empty. Cannot access top.");
	}
	return array[0];
}

template <typename T>
void Turn<T>::clear() {
	array.clear();
}

template <typename T>
size_t Turn<T>::size() const {
	return array.getSize();
}

