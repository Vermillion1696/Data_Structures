#ifndef MYSTRINGVECTOR_H
#include <string>

class MyStringVector {
private:
    std::string* data;
    size_t capacity;
    size_t size;
public:
    // These functions are related to constructors and destructors.
    MyStringVector();
    MyStringVector(const size_t capacity);
    MyStringVector(const MyStringVector& other);
    ~MyStringVector();

    // These functions are related to memory management.
    void shrink_to_fit();
    void reserve(size_t new_capacity);

    // These functions are related to data management.
    void push_back(const std::string& value);
    void pop_back();

    // These are getter and setter functions.
    size_t get_size() const;
    size_t get_capacity() const;
    void set_size(size_t new_size);
    void set_capacity(size_t new_capacity);

    // These functions are related to data status.
    bool is_empty() const;
    void clear();

    // These are operators.
    std::string& operator[](size_t index);
    const std::string& operator[](size_t index) const;
    MyStringVector& operator=(const MyStringVector& other);
    MyStringVector& operator+=(const MyStringVector& other);
};
#endif