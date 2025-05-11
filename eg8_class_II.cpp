// classes (II) summary with examples
#include <iostream>
#include <string>
using namespace std;

// Operator overloading class
class CVector {
public:
    int x, y;
    CVector(int a = 0, int b = 0) : x(a), y(b) {}
    CVector operator+(const CVector& rhs) {
        return CVector(x + rhs.x, y + rhs.y);
    }
};

// Class with static member
class Dummy {
public:
    static int count;
    Dummy() { ++count; }
};
int Dummy::count = 0;

// Class with const member function
class ConstDemo {
    int x;
public:
    ConstDemo(int val) : x(val) {}
    int get() const { return x; } // can be called on const objects
    void set(int val) { x = val; } // cannot be called on const objects
};

// Overloading based on const
class OverloadConst {
    int x;
public:
    OverloadConst(int val) : x(val) {}
    int& get() { return x; }
    const int& get() const { return x; }
};

// Demonstrating const object and member access
void demonstrateConstAccess() {
    const ConstDemo cd(42);
    cout << "ConstDemo.get(): " << cd.get() << "\n";
    // cd.set(12); // Error: cannot assign to const reference

    OverloadConst oc1(100);
    const OverloadConst oc2(200);
    cout << "Non-const get: " << oc1.get() << "\n";
    cout << "Const get: " << oc2.get() << "\n";

    // oc2.get() = 300; // Error: cannot assign to const reference
}

// Class template
template <class T>
class MyPair {
    T a, b;
public:
    MyPair(T first, T second) : a(first), b(second) {}
    T getMax() const { return (a > b) ? a : b; }
};

// Template specialization
template <>
class MyPair<char> {
    char a, b;
public:
    MyPair(char first, char second) : a(first), b(second) {}
    char getUppercase() const {
        return (a >= 'a' && a <= 'z') ? (a + 'A' - 'a') : a;
    }
};

int main() {
    // Operator overloading example
    CVector v1(1, 2), v2(3, 4);
    CVector v3 = v1 + v2;
    cout << "v3: (" << v3.x << ", " << v3.y << ")\n";

    // Static member example
    Dummy d1, d2;
    cout << "Dummy count: " << Dummy::count << "\n";

    // Const member function usage
    ConstDemo cd(42);
    cout << "ConstDemo (non-const): " << cd.get() << "\n";

    // Demonstrating const overloads
    demonstrateConstAccess();

    // Class template example
    MyPair<int> intPair(5, 8);
    cout << "Max int: " << intPair.getMax() << "\n";

    // Template specialization example
    MyPair<char> charPair('j', 'x');
    cout << "Uppercase char: " << charPair.getUppercase() << "\n";

    return 0;
}
