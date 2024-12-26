#include"Turn-FILO.h"
#include<stdexcept>


template <typename T>
void Turn<T>::push(const T& value) {
	list.AddToHead(value);
}


template <typename T>
void Turn<T>::pop() {
	if (list.Search(T()) == -1) {
		throw std::out_of_range("Queue is empty. Cannot  pop.");
	}
	list.DeleteFromTail();
}

template <typename T>
T Turn<T>::top() const {
	if (list.Search(T()) == -1) {
		throw std::out_of_range("Queue is empty. Cannot access top.");
	}
    return	list.Search(T());
}

template <typename T>
void Turn<T>::clear() {
	list.DeleteAll();
}

template <typename T>
size_t Turn<T>::size() const {
	int count = 0;
	for (int i = 0; list.Search(T()) != -1; i++){
		count++;
	}
	return count;
}

