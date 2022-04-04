#ifndef PRACTICE_TEMPLATE_CLASS_H
#define PRACTICE_TEMPLATE_CLASS_H

template<typename T>
class vector {
private:
    T *buf;
    int len;

public:
    vector() : buf{nullptr}, len{0} {}
    explicit vector(int size) : buf{new T[size]}, len{size} {};
    vector(vector &v) : buf{nullptr}, len{v.len} {}
    vector(vector &&v) noexcept : buf{v.buf}, len{v.len} {}
    ~vector();
};


#endif//PRACTICE_TEMPLATE_CLASS_H
