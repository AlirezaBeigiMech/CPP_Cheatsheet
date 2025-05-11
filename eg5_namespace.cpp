#include <iostream>

// Global scope variable
int global_x = 42;

namespace alpha {
    int x = 100;
    int y = 200;
}

namespace beta {
    double x = 3.14;
    double y = 2.718;
}

// Namespace alias
namespace A = alpha;

void demonstrate_local_scope() {
    int global_x = 7;  // local variable shadows global_x
    std::cout << "[Local Scope] global_x (shadowed): " << global_x << '\n';
}

void demonstrate_inner_block_shadowing() {
    int x = 10;
    int y = 20;

    {
        int x = 50; // shadows outer x
        y = 60;     // modifies outer y
        std::cout << "[Inner block] x: " << x << ", y: " << y << '\n';
    }

    std::cout << "[Outer block] x: " << x << ", y: " << y << '\n';
}

void demonstrate_namespaces() {
    std::cout << "[alpha::x]: " << alpha::x << '\n';
    std::cout << "[beta::x]: " << beta::x << '\n';

    // Using specific names from namespaces
    using alpha::x;
    using beta::y;

    std::cout << "[using alpha::x]: " << x << '\n'; // alpha::x
    std::cout << "[using beta::y]: " << y << '\n';  // beta::y
}

void demonstrate_using_namespace() {
    {
        using namespace alpha;
        std::cout << "[alpha] x: " << x << ", y: " << y << '\n';
    }
    {
        using namespace beta;
        std::cout << "[beta] x: " << x << ", y: " << y << '\n';
    }
}

void demonstrate_namespace_aliasing() {
    std::cout << "[Namespace alias A::y]: " << A::y << '\n';
}

// Static vs automatic storage demo
void demonstrate_storage_classes() {
    static int static_var; // automatically initialized to 0
    int auto_var;          // uninitialized, garbage value

    std::cout << "[Static variable]: " << static_var << '\n';
    std::cout << "[Automatic variable]: " << auto_var << " (undefined value)\n";
}

int main() {
    std::cout << "Global variable: " << global_x << '\n';
    demonstrate_local_scope();
    std::cout << '\n';

    demonstrate_inner_block_shadowing();
    std::cout << '\n';

    demonstrate_namespaces();
    std::cout << '\n';

    demonstrate_using_namespace();
    std::cout << '\n';

    demonstrate_namespace_aliasing();
    std::cout << '\n';

    demonstrate_storage_classes();
    std::cout << '\n';

    return 0;
}
