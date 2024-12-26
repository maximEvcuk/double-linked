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
    return	list.getHead() ->data;
}

template <typename T>
void Turn<T>::clear() {
	list.DeleteAll();
}

template <typename T>
size_t Turn<T>::size() const {
	int count = 0;
	typename Banana<T>::Node* current = list.getHead();
	while(current){
		count++;
		current = current->next;

	}
	return count;
}
template <typename T>
Banana<T> Turn<T>::clone() const {
		Banana<T> clonedList;
		typename Banana<T>::Node* current = list.getHead();
		while (current){
			clonedList.AddToTail(current->data);
			current = current->next;
		}
		return clonedList();
}
template <typename T>
Turn<T>  Turn<T>::operator+(const Turn<T>& other) const {
	Turn<T> newTurn;
	typename Banana<T>::Node* current = list.getHead();
	while (current){
		newTurn.push(current->data);
		current = current = current->next;
	}
	current = other.list.getHead();
	while (current){
		newTurn.push(current->data);
		current = current->next
	}
	return newTurn;
}

template <typename T>
Turn<T>  Turn<T>::operator*(const Turn<T>& other) const {
	Turn<T> commonTurn;
	typename Banana<T>::Node* current = list.getHead();
	while (current) {
		if (other.list.Search(current->data) != -1){
			commonTurn.push(current->data);
		}
		current = current->next;
	}
	return commonTurn;
}
		
