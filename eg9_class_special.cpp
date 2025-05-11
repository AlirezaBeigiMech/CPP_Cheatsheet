#include <iostream>
#include <string>

class Demo {
    std::string name;
public:
    Demo() : name("Default") { std::cout << "Default Constructor\n"; }
    Demo(const std::string& n) : name(n) { std::cout << "Parameterized Constructor\n"; }
    ~Demo() { std::cout << "Destructor for " << name << '\n'; }

    // Copy Constructor
    Demo(const Demo& other) : name(other.name) {
        std::cout << "Copy Constructor\n";
    }

    // Copy Assignment
    Demo& operator=(const Demo& other) {
        std::cout << "Copy Assignment\n";
        if (this != &other) name = other.name;
        return *this;
    }

    // Move Constructor
    Demo(Demo&& other) noexcept : name(std::move(other.name)) {
        std::cout << "Move Constructor\n";
    }

    // Move Assignment
    Demo& operator=(Demo&& other) noexcept {
        std::cout << "Move Assignment\n";
        if (this != &other) name = std::move(other.name);
        return *this;
    }
};
int main() {
    Demo a("A");
    Demo b = a;          // Copy Constructor
    Demo c("C");
    c = a;               // Copy Assignment

    Demo d = Demo("D");  // Move Constructor
    c = Demo("E");       // Move Assignment
}
