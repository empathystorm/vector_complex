#ifndef LAB1_VECTOR_H
#define LAB1_VECTOR_H
#include <iostream>

class Vector {
public:
    Vector();
    //конструктор с размером
    explicit Vector(unsigned x);
    //конструктор со списком { .. , .. , .. }
    Vector(std::initializer_list<int>);
    //конструкторы копирования
    Vector(const Vector&);
    Vector& operator=(const Vector&);
    //оператор обращения к элементу
    int& operator[](unsigned);
    //сложение векторов
    Vector& operator+=(const Vector&);
    Vector operator+(const Vector&) const;
    //вычитание векторов
    Vector& operator-=(const Vector&);
    Vector operator-(const Vector&) const;
    //умножение вектора на число
    Vector& operator*=(int);
    Vector operator*(int) const;
    //получение размера вектора
    [[nodiscard]] unsigned get_size() const;
    //вычисление скалярного произведения векторов
    int operator*(const Vector&) const;
    //вычисление длины вектора
    [[nodiscard]] double lenght() const;
    ~Vector();
private:
    int* data;
    unsigned size;
    void copy(const Vector&);
};

#endif //LAB1_VECTOR_H
