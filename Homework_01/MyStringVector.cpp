// 2023203093 김수오
// MyStringVector.cpp

#include <iostream>
#include <stdexcept>
#include <string>
#include "MyStringVector.h"
using namespace std;

// These functions are related to constructors and destructors.
MyStringVector::MyStringVector() {
	// Precondition: sufficient memory is available
	// Postcondition: str_capacity is set to 0, str_size is set to 0, str_data is set to nullptr
	str_data = nullptr;
	str_capacity = 0;
	str_size = 0;
}

MyStringVector::MyStringVector(const size_t capacity) {
	// Precondition: sufficient memory is available, str_capacity >= 0
	// Postcondition: str_capacity is set to the given value, str_size is set to 0, str_data is allocated
	str_data = new string[capacity];
	str_capacity = capacity;
	str_size = 0;
}

MyStringVector::MyStringVector(const MyStringVector& other) : str_data(new string[other.get_capacity()]), str_capacity(other.get_capacity()), str_size(other.get_size()) {
	// Precondition: sufficient memory is available, other.str_capacity >= 0, other.str_size <= other.str_capacity
	// Postcondition: this->str_data is a deep copy of other's data
	for (size_t i = 0; i < other.str_size; ++i) {
		str_data[i] = other.str_data[i];
	}
}

MyStringVector::~MyStringVector() {
	// Precondition: constructor has been called
	// Postcondition: memory allocated for str_data is released
	delete[] str_data;
}

// These functions are related to memory management.
void MyStringVector::reserve(size_t new_capacity) {
	// Precondition: new_capacity >= str_size, vector is valid, if str_data is nullptr str_capacity is 0
	// Postcondition: str_capacity is increased to new_capacity, str_data is moved to a larger block of memory, str_size is unchanged
	if (new_capacity > str_capacity) {
		string* new_data = new string[new_capacity];
		for (size_t i = 0; i < str_size; ++i) {
			new_data[i] = str_data[i];
		}
		delete[] str_data;
		str_data = new_data;
		str_capacity = new_capacity;
	}
}

void MyStringVector::shrink_to_fit() {
	// Precondition: vector is valid if str_size > 0
	// Postcondition: str_capacity is reduced to the current str_size, or deallocated if str_size is 0, str_size is unchanged
	if (str_size < str_capacity) {
		if (str_size == 0) {
			// If str_size == 0, deallocate memory
			delete[] str_data;
			str_data = nullptr;
			str_capacity = 0;
		}
		else {
			// Reallocate memory to fit exactly the str_size.
			string* new_data = new string[str_size];
			for (size_t i = 0; i < str_size; ++i) {
				new_data[i] = str_data[i];
			}
			delete[] str_data;
			str_data = new_data;
			str_capacity = str_size;
		}
	}
}

// These functions are related to data management.
void MyStringVector::push_back(const string& value) {
	// Precondition: vector is valid, sufficient memory is available
	// Postcondition: value is added to the vector, str_size is incremented, reserve is called if necessary
	if (str_size >= str_capacity) {
		reserve(str_capacity == 0 ? 1 : str_capacity * 2);
	}
	str_data[str_size++] = value;
}

void MyStringVector::pop_back() {
	// Precondition: str_size > 0
	// Postcondition: the last element is removed, str_size is decremented
	if (str_size == 0) {
		throw out_of_range("Vector is empty");
	}
	--str_size;
}

// These are getter and setter functions.
size_t MyStringVector::get_size() const {
	// Precondition: vector is valid
	// Postcondition: returns the number of elements in the vector, vector is unchanged
	return str_size;
}

size_t MyStringVector::get_capacity() const {
	// Precondition: vector is valid
	// Postcondition: returns the str_capacity of the vector, vector is unchanged
	return str_capacity;
}

void MyStringVector::set_size(size_t new_size) {
	// Precondition: new_size <= str_capacity
	// Postcondition: str_size is updated to new_size
	if (new_size > str_capacity) {
		throw out_of_range("New size exceeds capacity");
	}
	str_size = new_size;
}

void MyStringVector::set_capacity(size_t new_capacity) {
	// Precondition: new_capacity >= str_size
	// Postcondition: str_capacity is updated to new_capacity
	if (new_capacity < str_size) {
		throw out_of_range("New capacity is less than the current str_size");
	}
	str_capacity = new_capacity;
}

// These functions are related to data status.
bool MyStringVector::is_empty() const {
	// Precondition: vector is valid
	// Postcondition: returns true if str_size is 0, otherwise false, vector is unchanged
	return str_size == 0;
}

void MyStringVector::clear() {
	// Precondition: vector is valid
	// Postcondition: all elements are removed, str_size and str_capacity are set to 0
	delete[] str_data;
	str_data = nullptr;
	str_size = 0;
	str_capacity = 0;
}

// These are operators.
string& MyStringVector::operator[](size_t index) {
	// Precondition: index < str_size
	// Postcondition: returns reference to the element at position index
	if (index >= str_size) {
		throw std::out_of_range("Index out of range");
	}
	return str_data[index];
}

const string& MyStringVector::operator[](size_t index) const {
	// Precondition: index < str_size
	// Postcondition: returns const reference to the element at position index
	if (index >= str_size) {
		throw std::out_of_range("Index out of range");
	}
	return str_data[index];
}

MyStringVector& MyStringVector::operator=(const MyStringVector& other) {
	// Precondition: other is a valid MyStringVector object, does not point to this, sufficient memory is available 
	// Postcondition: this vector is a deep copy of other, freeing any memory previously allocated, if this == &other, no change
	if (this != &other) {
		delete[] str_data;
		str_data = new string[other.str_capacity];
		str_capacity = other.str_capacity;
		str_size = other.str_size;
		for (size_t i = 0; i < str_size; ++i) {
			str_data[i] = other.str_data[i];
		}
	}
	return *this;
}

MyStringVector& MyStringVector::operator+=(const MyStringVector& other) {
	// Precondition: other is a valid MyStringVector object, sufficient memory is available, str_capacity can be increased, if other.get_size() > 0 watch out for memory allocation
	// Postcondition: elements of other are appended to this vector, str_size is increased, if necessary str_capacity is increased, other is unchanged, memory is allocated if necessary

	// 먼저 필요한 공간을 계산하여 충분한 str_capacity를 미리 확보
	size_t new_size = this->get_size() + other.get_size();
	if (new_size > this->get_capacity()) {
		// 새로운 str_capacity를 충분히 크게 설정 (예: 두 배 증가)
		size_t new_capacity = std::max(new_size, this->get_capacity() * 2);
		this->reserve(new_capacity);  // str_capacity를 증가시키기 위해 reserve 함수 호출
	}

	// other의 요소를 this에 추가
	for (size_t i = 0; i < other.get_size(); ++i) {
		this->push_back(other[i]);
	}

	// str_size를 업데이트
	this->set_size(new_size);

	return *this;
}