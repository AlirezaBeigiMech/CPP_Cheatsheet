#include <iostream>
#include <exception>
using namespace std;

// 1. Basic try-catch with throw
void basicThrowCatch() {
    cout << "\n--- Basic throw/catch Example ---\n";
    try {
        throw 20;
    } catch (int e) {
        cout << "Caught exception: " << e << endl;
    }
}

// 2. Multiple catch handlers
void multipleCatch() {
    cout << "\n--- Multiple catch Example ---\n";
    try {
        throw 'A';
    } catch (int) {
        cout << "Caught int exception\n";
    } catch (char) {
        cout << "Caught char exception\n";
    } catch (...) {
        cout << "Caught unknown exception\n";
    }
}

// 3. Re-throw to outer try block
void rethrowExample() {
    cout << "\n--- Rethrow Example ---\n";
    try {
        try {
            throw 404;
        } catch (int n) {
            cout << "Inner catch: caught " << n << ", rethrowing...\n";
            throw; // rethrow
        }
    } catch (...) {
        cout << "Outer catch: handled rethrown exception\n";
    }
}

// 4. Custom exception class derived from std::exception
class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "Custom MyException occurred!";
    }
};

// 5. Using std::exception and derived class
void standardExceptionExample() {
    cout << "\n--- Standard Exception Example ---\n";
    MyException myex;
    try {
        throw myex;
    } catch (const exception& e) {
        cout << "Caught: " << e.what() << endl;
    }
}

// 6. Standard bad_alloc example
void badAllocExample() {
    cout << "\n--- bad_alloc Example ---\n";
    try {
        int* arr = new int[1000000000]; // likely to fail
    } catch (const bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    }
}

int main(){
    basicThrowCatch();
    multipleCatch();
    rethrowExample();
    standardExceptionExample();
    badAllocExample();

    cout << "\n=== End of Exception Tutorial ===\n";
    return 0;
}
