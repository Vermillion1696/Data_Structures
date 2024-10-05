#include <iostream>
#include <stdexcept>
#include <string>
#include "MyStringVector.h"
using namespace std;

MyStringVector::MyStringVector() : data(nullptr), capacity(0), size(0) {}
MyStringVector::~MyStringVector() {
    delete[] data;
}

void MyStringVector::resize(size_t new_capacity) {
    std::string* new_data = new std::string[new_capacity];
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

void MyStringVector::push_back(const std::string& value) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

void MyStringVector::pop_back() {
    if (size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    --size;
}

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

size_t MyStringVector::get_size() const {
    return size;
}

size_t MyStringVector::get_capacity() const {
    return capacity;
}

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

    return 0;
}