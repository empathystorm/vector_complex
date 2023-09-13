#include "complex_numbers.h"

//public:
Complex::Complex() : re(0), im(0) {}

Complex::Complex(double x, double y) : Complex() {
    re = x;
    im = y;
}

Complex::Complex(const Complex& other) = default;

Complex& Complex::operator=(const Complex& other) = default;

Complex& Complex::operator+=(const Complex& other) {
    re += other.re;
    im += other.im;
    return *this;
}

Complex Complex::operator+(const Complex& other) const {
    Complex temp(*this);
    temp += other;
    return temp;
}

Complex& Complex::operator-=(const Complex& other) {
    *this += other * Complex(-1, 0);
    return *this;
}

Complex Complex::operator-(const Complex& other) const {
    Complex temp(*this);
    temp -= other;
    return temp;
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im,
                   re * other.im + im * other.re);
}

Complex& Complex::operator*=(const Complex& other) {
    *this = *this * other;
    return *this;
}

Complex Complex::operator/(const Complex& other) const {
    if (count_pow(other) != 0) {
        return Complex((re * other.re + im * other.im) / count_pow(other),
                       (im * other.re - re * other.im) / count_pow(other));
    }
    throw std::invalid_argument("Division by zero");
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

std::istream& operator>>(std::istream& in, Complex& other) {
    return in >> other.re >> other.im;
}

std::ostream& operator<<(std::ostream& out, const Complex& other) {
    return out << "(" << other.re << (other.im >= 0 ? "+" : "") << other.im << "i)";
}

//private:
double Complex::count_pow(const Complex& n) {
    return n.re * n.re + n.im * n.im;
}
