#include"Array.h"
#include<iostream>
#include<cstring>


template <typename T>
Array<T>::Array(size_t initialCapacity) : size(0), capacity(initialCapacity) {
    arr = new T[capacity]();
}

template <typename T>
Array<T>::Array(size_t n, bool random) : size(n), capacity(n) {
    arr = new T[capacity];
    if (random)
    {
        fillWithRandomValues();
    }
}

template <typename T>
Array<T>::Array(size_t n, T min, T max) : size(n), capacity(n) {
    arr = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = min + static_cast<T>(rand() % (max - min + 1));
    }
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size), capacity(other.capacity) {
    arr = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
Array<T>::Array(Array&& other) noexcept : arr(other.arr), size(other.size), capacity(other.capacity) {
    other.arr = nullptr;
    other.size = 0;
    other.getCapacity = 0;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] arr;
        size = other.size;
        capacity = other.capacity;
        arr = other.arr;
        other.size = 0;
        other.capacity = 0;;
    }
    return *this;
}


template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
void Array<T>::display() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Array<T>::fillWithRandomValues() {
    for (size_t i = 0; i < size; ++i) {
        arr[i] = static_cast<T>(rand() % 100);
    }
}


template <typename T>
void Array<T>::resize(size_t newSize) {
    if (newSize > capacity)
    {
        reserve(newSize);
    }
    size = newSize;
}

template <typename T>
void Array<T>::sort() {
    std::sort(arr, arr + size);
}

template <typename T>
T Array<T>::min() const {
    if (size == 0) {
        std::cout << "Array is empty" << std::endl;
        return T();
    }

    T minValue = arr[0];
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

template <typename T>
T Array<T>::max() const {
    if (size == 0) {
        std::cout << "Array is empty" << std::endl;
        return T();
    }


    T maxValue = arr[0];
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

template <typename T>
size_t Array<T>::getSize() const {
    return size;
}

template <typename T>
size_t Array<T>::getCapacity() const {
    return capacity;
}

template <typename T>
void Array<T>::append(T value) {
    if (size >= capacity)
    {
        reserve(capacity * 2);
    }arr[size++] = value;
}

template <typename T>
void Array<T>::erase(size_t index) {
    if (size > index)
    {
        for (size_t i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

template <typename T>
void Array<T>::clear() {
    size = 0;
}

template <typename T>
void Array<T>::reserve(size_t newCapacity) {
    if (newCapacity > capacity) {
        T* newArr = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        size = newCapacity;
    }
}

template <typename T>
void Array<T>::shrink() {
    if (size < capacity)
    {
        T* newArr = new T[size];
        for (size_t i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = size;
    }
}


#include"Array.h"