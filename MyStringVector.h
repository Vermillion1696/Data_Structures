#pragma once

class MyStringVector {
public:
	// These are requested members to be implemented.
	MyStringVector();
	MyStringVector(const MyStringVector& v);
	~MyStringVector();

	MyStringVector& operator=(const MyStringVector& other);
	MyStringVector& operator+=(const MyStringVector& add);
	string operator[](const size_t index);

	void pop_back();
	void push_back(string s);
	void shrink_to_fit();
	void reserve(size_t n);
	void clear();
	bool is_empty() const;

	// These functions' original name were capacity() and size().
	// For an additional constraints, I decided to protect the principles of OOP.
	// Private variables are only accessed by these functions.
	size_t getCapacity() const;
	size_t getSize() const;
	string* getData() const;

	// These are not requested members to be implemented.
	// They are just needed for convenience.
	void setSize(size_t n);
	void setCapacity(size_t n);
	void setData(string* data);

private:
	string* str_data;
	size_t str_size;
	size_t str_capacity;

	// Using bit-shift operations make the program much faster.
	// As an example of bit-shift operation result, (1 << 20) means 2^19 (pow(2,19)).
	size_t MAX_SIZE = (1 << 21);
};