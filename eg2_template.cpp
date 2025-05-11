#include <iostream>
using namespace std;

// 1. Function overloading
int operate(int a, int b) {
    return a * b;
}

double operate(double a, double b) {
    return a / b;
}

// 2. Function overloading with same logic
int sum(int a, int b) {
    return a + b;
}

double sum(double a, double b) {
    return a + b;
}

// 3. Function template (single type)
template <class T>
T generic_sum(T a, T b) {
    T result = a + b;
    return result;
}

// 4. Function template (two different types)
template <class T, class U>
bool are_equal(T a, U b) {
    return (a == b);
}

// 5. Function template with non-type template parameter
template <class T, int N>
T fixed_multiply(T val) {
    return val * N;
}


int main() {
    int x = 5, y = 2;
    double m = 5.0, n = 2.0;

    // --- Function Overloading ---
    cout << "operate(int, int): " << operate(x, y) << endl;        // 10
    cout << "operate(double, double): " << operate(m, n) << endl;  // 2.5

    // --- Overloaded sum ---
    cout << "sum(int): " << sum(10, 20) << endl;                   // 30
    cout << "sum(double): " << sum(1.0, 1.5) << endl;              // 2.5

    // --- Function Templates (Explicit instantiation) ---
    int k = generic_sum<int>(x, y);             // compiler sees: int generic_sum(int, int)
    double h = generic_sum<double>(m, n);       // compiler sees: double generic_sum(double, double)
    cout << "explicit generic_sum<int>: " << k << endl;            // 7
    cout << "explicit generic_sum<double>: " << h << endl;         // 7.5

    // --- Function Templates (Type deduction) ---
    auto k2 = generic_sum(x, y);                // deduced as int
    auto h2 = generic_sum(m, n);                // deduced as double
    cout << "deduced generic_sum: " << k2 << " and " << h2 << endl;

    // --- Template with different types ---
    cout << "are_equal(10, 10.0): ";
    if (are_equal(10, 10.0)) cout << "Equal\n"; else cout << "Not equal\n";

    // --- Non-type Template Parameters ---
    cout << "fixed_multiply<int, 2>(10): " << fixed_multiply<int, 2>(10) << endl; // 20
    cout << "fixed_multiply<int, 3>(10): " << fixed_multiply<int, 3>(10) << endl; // 30

    return 0;
}
