#pragma once
#include"Banana.h"


#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
private:
    Banana<T> list;
    size_t size;
   

public:
    Array();
    Array(size_t n, bool random);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    ~Array();

   

    size_t getSize() const;
    size_t getUpperBound() const;
    bool isEmpty() const;
    bool freeExtra();
    bool removeAll();
    T getAt(size_t index) const;
    void setAt(size_t index, T value);
    T& operator[](size_t index);
    void add(T value);
    void append(const Array& other);
    void insertAt(size_t index, T value);
    void removeAt(size_t index);

};