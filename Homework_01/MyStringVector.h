#pragma once
#include <string>

class MyStringVector {
private:
    std::string* data;
    size_t capacity;
    size_t size;

    void resize(size_t new_capacity);

public:
    MyStringVector();
    ~MyStringVector();

    void push_back(const std::string& value);
    void pop_back();
    std::string& operator[](size_t index);
    const std::string& operator[](size_t index) const;
    size_t get_size() const;
    size_t get_capacity() const;
    bool empty() const;
    void clear();
};