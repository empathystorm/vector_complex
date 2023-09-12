#include "vector.h"
#include <iostream>

using namespace std;

void input_vector(Vector& v) {
    for (int i = 0; i < v.get_size(); i++) {
        cin >> v[i];
    }
}

void output_vector(Vector& v) {
    for (int i = 0; i < v.get_size(); i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cout << "тестим векторы:\n";
    Vector v1 = {1, 2, 3}, v2(3);
    input_vector(v2);

    v1 = v1 + v2;
    output_vector(v1);
    v2 -= v1;
    output_vector(v2);
    cout << v1 * v2 << '\n';
    cout << v1.lenght() << '\n';

    cout << "тестим комплексные числа:\n";
}