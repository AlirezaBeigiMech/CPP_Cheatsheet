#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class A {
public:
    int val;
    A(int v = 0) : val(v) {}
};

class B {
public:
    int val;
    explicit B(const A& a) : val(a.val) { cout << "B constructed from A\n"; }

    B& operator=(const A& a) {
        cout << "B assigned from A\n";
        val = a.val;
        return *this;
    }

    operator A() const {
        cout << "B converted to A\n";
        return A(val);
    }
};

class Base {
public:
    virtual void dummy() {}
    virtual ~Base() {} 
};

class Derived : public Base {
public:
    void derivedFunc() { cout << "Derived function called\n"; }
};

void print(char* str) {
    cout << str << '\n';
}

int main() {

    cout << "---- Implicit Conversion ----\n";
    short s = 2000;
    int i = s;  // implicit promotion
    cout << "int i: " << i << "\n";

    cout << "\n---- Class Conversion (explicit) ----\n";
    A a1(42);
    B b1(a1);  // ok, explicit call
    b1 = a1;   // assignment

    cout << "\n---- Typecast Operator ----\n";
    A a2 = b1;  // uses operator A()

    cout << "\n---- static_cast ----\n";
    Base* basePtr = new Derived;
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->derivedFunc();

    cout << "\n---- dynamic_cast ----\n";
    Base* baseReal = new Derived;
    Base* baseWrong = new Base;
    if (Derived* dynPtr = dynamic_cast<Derived*>(baseReal)) {
        dynPtr->derivedFunc();
    }
    if (dynamic_cast<Derived*>(baseWrong) == nullptr) {
        cout << "dynamic_cast failed safely\n";
    }

    cout << "\n---- const_cast ----\n";
    const char* cstr = "Hello, const_cast!";
    print(const_cast<char*>(cstr));

    cout << "\n---- reinterpret_cast ----\n";
    int x = 12345;
    char* p = reinterpret_cast<char*>(&x);
    cout << "First byte of x: " << static_cast<int>(*p) << "\n";

    cout << "\n---- typeid & RTTI ----\n";
    cout << "Type of basePtr: " << typeid(basePtr).name() << "\n";
    cout << "Type of *basePtr: " << typeid(*basePtr).name() << "\n";

    delete basePtr;
    delete baseReal;
    delete baseWrong;

    return 0;
}
