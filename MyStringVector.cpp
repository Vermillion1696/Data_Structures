#include <iostream>
#include <string>
#include <cstdlib>
#include "MyStringVector.h"
using namespace std;

/*
// ** Functions Related with Constructor and Destructor **
MyStringVector::MyStringVector() {
	str_data = new string[0];
	str_size = 0;
	str_capacity = 0;
	return;
}
MyStringVector::MyStringVector(const MyStringVector& v) {
	str_data = v.str_data;
}
MyStringVector::~MyStringVector() {
	delete[] str_data;
	return;
}

// ** Getter and Setter **
size_t MyStringVector::getCapacity() const {
	return str_capacity;
}
size_t MyStringVector::getSize() const {
	return str_size;
}
string* MyStringVector::getData() const {
	return str_data;
}
void MyStringVector::setCapacity(size_t n) {
	str_capacity = n;
	return;
}
void MyStringVector::setSize(size_t n) {
	str_size = n;
	return;
}
void MyStringVector::setData(string* data) {
	str_data = data;
	return;
}

// ** Functions Related with Capacity and Size **
void MyStringVector::shrink_to_fit() {
	str_capacity = str_size;
	return;
}
void MyStringVector::reserve(size_t n) {
	if (n <= MAX_SIZE) str_capacity = n;
	else str_capacity = MAX_SIZE;
	return;
}

// ** Functions Related with Adding and Removing **
void MyStringVector::push_back(string s) {
	
	// if MyStringVector is full
	if (str_size == str_capacity) {
		
		// make a string* with a bigger capacity
		// if str_capacity is 0 -> next capacity is 1
		// else (str_capacity is > 0) -> next capacity is (str_capacity * 2)
		size_t new_capacity = ((str_capacity == 0) ? 1 : (str_capacity << 1));
		string* new_data = new string[new_capacity];

		// move all previous datas
		for (size_t dir = 0; dir < str_size; ++dir) {
			new_data[dir] = str_data[dir];
		}

		// delete old data and save new one
		delete[] str_data;
		str_data = new_data;
		str_capacity = new_capacity;
	}
	
	// save the string "s" at str_data[str_size], and make the size + 1
	str_data[str_size++] = s;
	return;
}
void MyStringVector::pop_back() {

	// if str_size is not bigger than (str_capacity / 2)
	if (str_size <= (str_capacity >> 1)) {

		// make a string* with a smaller capacity
		// next capacity is (str_capacity / 2)
		size_t new_capacity = str_capacity >> 1;
		string* new_data = new string[new_capacity];

		// move all previous datas
		if (new_capacity != 0) {
			for (size_t dir = 0; dir < str_size; ++dir) {
				new_data[dir] = str_data[dir];
			}
		}

		// delete old data and save new one
		delete[] str_data;
		str_data = new_data;
		str_capacity = new_capacity;
	}
	
	// str_size - 1;
	// frequent memory reallocation can make the program very slow
	// when doing push_back() the string data will be overwritten so it does not matter to leave it
	str_size--;
	return;
}
void MyStringVector::clear() {
	delete[] str_data;
	str_data = new string[0];
	str_size = 0;
	str_capacity = 0;
}
bool MyStringVector::is_empty() const {
	return (str_size == 0);
}

// ** Operators Overloading **
MyStringVector& MyStringVector::operator=(const MyStringVector& other) {
	
	// make this capable for copying the other MyStringVector
	setCapacity(other.getCapacity());
	setSize(other.getSize());

	// move all previous datas
	for (size_t dir = 0; dir < getSize(); ++dir) {
		str_data[dir] = other.str_data[dir];
	}

	return;
}
MyStringVector& MyStringVector::operator+=(const MyStringVector& other) {

	// make this capable for adding the other MyStringVector
	setCapacity(getCapacity() + other.getCapacity());

	// precomputation for good readability
	size_t other_size = other.getSize();
	size_t this_size = getSize();

	// add other's datas
	for (size_t dir = this_size; dir < this_size + other_size; ++dir) {
		str_data[dir] = other.str_data[dir - other_size];
	}

	return;
}
string MyStringVector::operator[](const size_t index) {
	return str_data[index];
}
*/

int main() {
	cout << "Hello, World!" << endl;
	system("pause");
}