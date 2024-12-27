#include"Array(1).h"
#include<iostream>
#include<cstring>


template <typename T>
Array<T>::Array() : size(0){}

template <typename T>
Array<T>::Array(size_t n, bool random) : size(n) {
    for (size_t i = 0; i < n; ++i){
        add(random ? rand() % 100 : T())
    }
}


template <typename T>
Array<T>::Array(const Array& other) : size(other.size) {
    for (size_t i = 0; i < other.size; ++i) {
        list.AddToTail(other.list.getHead()->data);
    }
}

template <typename T>
Array<T>::Array(Array&& other) noexcept : list(std::move(other.list)), size(other.size) {
    other.size = 0;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        removeAll();
        size = other.size;
        for (size_t i = 0; i < other.size; ++i) {
            list.AddToTail(other.list.getHead()->data);
        }
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        removeAll();
        list = std::move(other.list);
        size = other.size;
        other.size = 0
    }
    return *this;
}


template <typename T>
Array<T>::~Array() {
    removeAll();
}
template <typename T>
size_t Array<T>::getSize() const {
    return size;
}

template <typename T>
size_t Array<T>::getUpperBound() const {
    return size == 0 & -1 : size - 1;
}

template <typename T>
bool Array<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
bool Array<T>::freeExtra() {}

template <typename T>
bool Array<T>::removeAll() {
    list.DeleteAll();
    size = 0;
}

template <typename T>
T Array<T>::getAt(size_t index) const {
    if (index >=size) throw std::out_of_range("Index goes beyond the limits: ");
    Node* current = list.getHead();
    for (size_t i = 0; i < index; ++i){
        current = current->next;
    }
    return current->data;
}

template <typename T>
void Array<T>::setAt(size_t index, T value)  {
    if (index >= size) throw std::out_of_range("Index goes beyond the limits: ");
    Node* current = list.getHead();
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
     current->data = value;
}
template <typename T>
T& Array<T>::operator[](size_t index) {
    return const_cast<T&>(getAt(index));
}

template <typename T>
void Array<T>::add(T value) {
    list.AddToTail(value);
    size++;
}

template <typename T>
void Array<T>::append(const Array& other) {
    for (size_t i = 0; i < other.size; ++i){
        add(other.getAt(i));
    }
}
template <typename T>
void Array<T>::insertAt(size_t index, T value) {
    if (index > size) throw std::out_of_range("Index goes beyond the limits: ");
    if (index == size){
        add(value);
    }
    else {
        Node* current = list.getHead();
        for (size_t i = 0; i < index; ++i){
            current = current->next;
        }
        list.InsertAtPosition(value, index);
        size++;
    }
}

template <typename T>
void Array<T>::removeAt(size_t index) {
    if (index >= size) throw std::out_of_range("Index goes beyond the limits: ");
    list.DeleteAtPosition(index);
    size--;
}



#include"Array(1).h"