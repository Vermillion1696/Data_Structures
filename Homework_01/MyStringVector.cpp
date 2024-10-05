#include <iostream>
#include <stdexcept>
#include <string>
#include "MyStringVector.h"
using namespace std;

// These functions are related to constructors and destructors.
MyStringVector::MyStringVector() : data(nullptr), capacity(0), size(0) {}
MyStringVector::MyStringVector(const MyStringVector& other) : data(new std::string[other.capacity]), capacity(other.capacity), size(other.size) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}
MyStringVector::~MyStringVector() {
    delete[] data;
}

/*
    1. MyStringVector::MyStringVector() : data(nullptr), capacity(0), size(0) {}
    -> 기본 constructor, 어떠한 info도 없으므로, data는 nullptr, capacity와 size는 0으로 초기화한다.



*/


// These functions are related to memory management.
void MyStringVector::reserve(size_t new_capacity) {
    string* new_data = new string[new_capacity];
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}
void MyStringVector::shrink_to_fit() {
    if (size == 0) {
        delete[] data;
        data = nullptr;
        capacity = 0;
    } else {
        reserve(size);
    }
}

// These functions are related to data management.
void MyStringVector::push_back(const std::string& value) {
    
    
    
    if (size == capacity) {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}
void MyStringVector::pop_back() {
    if (size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    --size;
}

// These operators are related to data access.
std::string& MyStringVector::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}
const std::string& MyStringVector::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// These are getter and setter functions.
size_t MyStringVector::get_size() const {
    return size;
}
size_t MyStringVector::get_capacity() const {
    return capacity;
}
void MyStringVector::set_size(size_t new_size) {
    size = new_size;
}
void MyStringVector::set_capacity(size_t new_capacity) {
    capacity = new_capacity;
}

// These functions are related to data status.
bool MyStringVector::empty() const {
    return size == 0;
}
void MyStringVector::clear() {
    size = 0;
}

int main() {
    MyStringVector vec;
    vec.push_back("Hello");
    vec.push_back("World");

    for (size_t i = 0; i < vec.get_size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.pop_back();
    std::cout << "After pop_back: " << vec[0] << std::endl;
    system("pause");
    
    return 0;
}