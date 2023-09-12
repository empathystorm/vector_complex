#include "vector.h"
#include <cmath>

//public:
Vector::Vector() : data(nullptr), size(0) {}

Vector::Vector(unsigned x) : Vector() {
    try {
        data = new int[x];
    } catch (const std::bad_alloc& err) {
        delete[] data;
        throw;
    }
    size = x;
}

Vector::Vector(std::initializer_list<int> list) : Vector(list.size()) {
    int* ptr = data;
    for (const int& val : list) {
        *ptr = val;
        ++ptr;
    }
}

Vector::Vector(const Vector& other) : Vector() {
    Vector temp(other.size);
    temp.copy(other);
    std::swap(data, temp.data);
    std::swap(size, temp.size);
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        Vector temp(other);
        std::swap(data, temp.data);
        std::swap(size, temp.size);
    }
    return *this;
}

int& Vector::operator[](unsigned index) {
    if (index < size) return data[index];
    throw std::out_of_range("Index out of range");
}

Vector& Vector::operator+=(const Vector& other) {
    if (size == other.size) {
        for (unsigned i = 0; i < size; i++) {
            data[i] += other.data[i];
        }
    }
    return *this;
}

Vector Vector::operator+(const Vector& other) const {
    Vector temp(*this);
    temp += other;
    return temp;
}

Vector& Vector::operator-=(const Vector& other) {
    *this += other * -1;
    return *this;
}

Vector Vector::operator-(const Vector& other) const {
    Vector temp(*this);
    temp -= other;
    return temp;
}

Vector& Vector::operator*=(int num) {
    for (unsigned i = 0; i < size; i++) {
        data[i] *= num;
    }
    return *this;
}

Vector Vector::operator*(int num) const {
    Vector temp(*this);
    temp *= num;
    return temp;
}

unsigned Vector::get_size() const {
    return size;
}

int Vector::operator*(const Vector& other) const {
    if (size == other.size) {
        int scalar = 0;
        for (unsigned i = 0; i < size; i++) {
            scalar += data[i] * other.data[i];
        }
        return scalar;
    }
    throw std::invalid_argument("The sizes of the vectors do not match");
}

double Vector::lenght() const {
    return sqrt(*this * *this);
}

Vector::~Vector() {
    delete[] data;
}

//private:
void Vector::copy(const Vector& other) {
    for (unsigned i = 0; i < std::min(size, other.size); i++) {
        data[i] = other.data[i];
    }
}
