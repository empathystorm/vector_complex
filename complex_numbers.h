#ifndef LAB1_COMPLEX_NUMBERS_H
#define LAB1_COMPLEX_NUMBERS_H
#include <iostream>

class Complex {
public:
    Complex();
    explicit Complex(double x, double y);
    Complex(const Complex&);
    Complex& operator=(const Complex&);
    //сложение
    Complex& operator+=(const Complex&);
    Complex operator+(const Complex&) const;
    //вычитание
    Complex& operator-=(const Complex&);
    Complex operator-(const Complex&) const;
    //умножение
    Complex operator*(const Complex&) const;
    Complex& operator*=(const Complex&);
    //деление
    Complex operator/(const Complex&) const;
    Complex& operator/=(const Complex&);
    //ввод с клавиатуры
    friend std::istream& operator>>(std::istream&, Complex&);
    //вывод на экран
    friend std::ostream& operator<<(std::ostream&, const Complex&);
private:
    double re, im;
    [[nodiscard]] static double count_pow(const Complex&);
};

#endif //LAB1_COMPLEX_NUMBERS_H
