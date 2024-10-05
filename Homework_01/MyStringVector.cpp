#include <iostream>
#include <stdexcept>
#include <string>
#include "MyStringVector.h"
using namespace std;

// These functions are related to constructors and destructors.
MyStringVector::MyStringVector() : data(nullptr), capacity(0), size(0) {}
MyStringVector::MyStringVector(const size_t capacity) : data(new string[capacity]), capacity(capacity), size(0) {}
MyStringVector::MyStringVector(const MyStringVector& other) : data(new string[other.capacity]), capacity(other.capacity), size(other.size) {
	// Precondition: other.capacity >= 0, other.size <= other.capacity
	// Postcondition: this->data is a deep copy of other's data
	for (size_t i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
}
MyStringVector::~MyStringVector() {
	// Precondition: none
	// Postcondition: memory allocated for data is released
	delete[] data;
	return;
}

// These functions are related to memory management.
void MyStringVector::reserve(size_t new_capacity) {
	// Precondition: new_capacity >= size
	// Postcondition: capacity is increased to new_capacity, data is moved to a larger block of memory
	string* new_data = new string[new_capacity];
	for (size_t i = 0; i < size; ++i) {
		new_data[i] = move(data[i]);
	}
	delete[] data;
	data = new_data;
	capacity = new_capacity;
	return;
}

void MyStringVector::shrink_to_fit() {
	// Precondition: none
	// Postcondition: capacity is reduced to the current size, or deallocated if size is 0
	if (size == 0) {
		delete[] data;
		data = nullptr;
		capacity = 0;
	} else {
		reserve(size);
	}
	return;
}

// These functions are related to data management.
void MyStringVector::push_back(const string& value) {
	// Precondition: none
	// Postcondition: value is added to the vector, size is incremented
	if (!(size < capacity)) {
		reserve(capacity == 0 ? 1 : capacity * 2);
	}
	data[size++] = value;
	return;
}

void MyStringVector::pop_back() {
	// Precondition: size > 0
	// Postcondition: the last element is removed, size is decremented
	if (size == 0) {
		throw out_of_range("Vector is empty");
	}
	--size;
	return;
}

// These are getter and setter functions.
size_t MyStringVector::get_size() const {
	// Precondition: none
	// Postcondition: returns the number of elements in the vector
	return size;
}

size_t MyStringVector::get_capacity() const {
	// Precondition: none
	// Postcondition: returns the capacity of the vector
	return capacity;
}

void MyStringVector::set_size(size_t new_size) {
	// Precondition: new_size <= capacity
	// Postcondition: size is updated to new_size
	size = new_size;
	return;
}

void MyStringVector::set_capacity(size_t new_capacity) {
	// Precondition: new_capacity >= size
	// Postcondition: capacity is updated to new_capacity
	capacity = new_capacity;
	return;
}

// These functions are related to data status.
bool MyStringVector::is_empty() const {
	// Precondition: none
	// Postcondition: returns true if size is 0, otherwise false
	return get_size() == 0;
}

void MyStringVector::clear() {
	// Precondition: none
	// Postcondition: all elements are removed, size and capacity are set to 0
	delete[] data;
	set_capacity(0);
	set_size(0);
	return;
}

// These are operators.
string& MyStringVector::operator[](size_t index) {
	// Precondition: index < size
	// Postcondition: returns reference to the element at position index
	if (index >= size) {
		throw out_of_range("Index out of range");
	}
	return data[index];
}

const string& MyStringVector::operator[](size_t index) const {
	// Precondition: index < size
	// Postcondition: returns const reference to the element at position index
	if (index >= size) {
		throw out_of_range("Index out of range");
	}
	return data[index];
}

MyStringVector& MyStringVector::operator=(const MyStringVector& other) {
	// Precondition: none
	// Postcondition: this vector is a deep copy of other
	if (this != &other) {
		delete[] data;
		data = new string[other.capacity];
		capacity = other.capacity;
		size = other.size;
		for (size_t i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

MyStringVector& MyStringVector::operator+=(const MyStringVector& other) {
	// Precondition: none
	// Postcondition: elements of other are appended to this vector, size is increased
	for (size_t i = 0; i < other.size; ++i) {
		push_back(other[i]);
	}

	this->set_size(this->get_size() + other.get_size());

	return *this;
}
