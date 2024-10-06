#include <iostream>
#include <stdexcept>
#include <string>
#include "MyStringVector.h"
using namespace std;

// These functions are related to constructors and destructors.
MyStringVector::MyStringVector() {
	// Precondition: sufficient memory is available
	// Postcondition: capacity is set to 0, size is set to 0, data is set to nullptr
	data = nullptr;
	capacity = 0;
	size = 0;
}

MyStringVector::MyStringVector(const size_t capacity) {
	// Precondition: sufficient memory is available, capacity >= 0
	// Postcondition: capacity is set to the given value, size is set to 0, data is allocated
	data = new string[capacity];
	this->capacity = capacity;
	size = 0;
}

MyStringVector::MyStringVector(const MyStringVector& other) : data(new string[other.capacity]), capacity(other.capacity), size(other.size) {
	// Precondition: sufficient memory is available, other.capacity >= 0, other.size <= other.capacity
	// Postcondition: this->data is a deep copy of other's data
	for (size_t i = 0; i < other.size; ++i) {
		data[i] = other.data[i];
	}
}

MyStringVector::~MyStringVector() {
	// Precondition: constructor has been called
	// Postcondition: memory allocated for data is released
	delete[] data;
}

// These functions are related to memory management.
void MyStringVector::reserve(size_t new_capacity) {
	// Precondition: new_capacity >= size, vector is valid, if data is nullptr capacity is 0
	// Postcondition: capacity is increased to new_capacity, data is moved to a larger block of memory, size is unchanged
	if (new_capacity > capacity) {
		string* new_data = new string[new_capacity];
		for (size_t i = 0; i < size; ++i) {
			new_data[i] = move(data[i]);
		}
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}
}

void MyStringVector::shrink_to_fit() {
	// Precondition: vector is valid if size > 0
	// Postcondition: capacity is reduced to the current size, or deallocated if size is 0, size is unchanged
	if (size == 0) {
		delete[] data;
		data = nullptr;
		capacity = 0;
	}
	else {
		reserve(size);
	}
}

// These functions are related to data management.
void MyStringVector::push_back(const string& value) {
	// Precondition: vector is valid, sufficient memory is available
	// Postcondition: value is added to the vector, size is incremented, reserve is called if necessary
	if (size >= capacity) {
		reserve(capacity == 0 ? 1 : capacity * 2);
	}
	data[size++] = value;
}

void MyStringVector::pop_back() {
	// Precondition: size > 0
	// Postcondition: the last element is removed, size is decremented
	if (size == 0) {
		throw out_of_range("Vector is empty");
	}
	--size;
}

// These are getter and setter functions.
size_t MyStringVector::get_size() const {
	// Precondition: vector is valid
	// Postcondition: returns the number of elements in the vector, vector is unchanged
	return size;
}

size_t MyStringVector::get_capacity() const {
	// Precondition: vector is valid
	// Postcondition: returns the capacity of the vector, vector is unchanged
	return capacity;
}

void MyStringVector::set_size(size_t new_size) {
	// Precondition: new_size <= capacity
	// Postcondition: size is updated to new_size
	if (new_size > capacity) {
		throw out_of_range("New size exceeds capacity");
	}
	size = new_size;
}

void MyStringVector::set_capacity(size_t new_capacity) {
	// Precondition: new_capacity >= size
	// Postcondition: capacity is updated to new_capacity
	if (new_capacity < size) {
		throw out_of_range("New capacity is less than the current size");
	}
	capacity = new_capacity;
}

// These functions are related to data status.
bool MyStringVector::is_empty() const {
	// Precondition: vector is valid
	// Postcondition: returns true if size is 0, otherwise false, vector is unchanged
	return size == 0;
}

void MyStringVector::clear() {
	// Precondition: vector is valid
	// Postcondition: all elements are removed, size and capacity are set to 0
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

// These are operators.
string& MyStringVector::operator[](size_t index) {
	// Precondition: index < size
	// Postcondition: returns reference to the element at position index
	if (index >= size) {
		cerr << "Error: Index " << index << " out of range. Terminating program." << endl;
		std::terminate(); // Terminates the program
	}
	return data[index];
}

const string& MyStringVector::operator[](size_t index) const {
	// Precondition: index < size
	// Postcondition: returns const reference to the element at position index
	if (index >= size) {
		cerr << "Error: Index " << index << " out of range. Terminating program." << endl;
		std::terminate(); // Terminates the program
	}
	return data[index];
}

MyStringVector& MyStringVector::operator=(const MyStringVector& other) {
	// Precondition: other is a valid MyStringVector object, does not point to this, sufficient memory is available 
	// Postcondition: this vector is a deep copy of other, freeing any memory previously allocated, if this == &other, no change
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
	// Precondition: other is a valid MyStringVector object, sufficient memory is available, capacity can be increased, if other.get_size() > 0 watch out for memory allocation
	// Postcondition: elements of other are appended to this vector, size is increased, if necessary capacity is increased, other is unchanged, memory is allocated if necessary
	for (size_t i = 0; i < other.size; ++i) {
		push_back(other[i]);
	}
	return *this;
}
