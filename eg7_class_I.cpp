#include <iostream>
using namespace std;

// -------------------- Rectangle Class --------------------
class Rectangle {
    int width, height;  // private by default
public:
    // Default constructor
    Rectangle() : width(1), height(1) {}

    // Overloaded constructor
    Rectangle(int w, int h) : width(w), height(h) {}

    // Area method
    int area() const { return width * height; }

    // Setters (for illustration)
    void set_values(int w, int h) {
        width = w;
        height = h;
    }
};

// -------------------- Cylinder Class with Composition --------------------
class Cylinder {
    Rectangle base;
    double height;
public:
    Cylinder(int r_width, int r_height, double h) : base(r_width, r_height), height(h) {}

    double volume() const {
        return base.area() * height;
    }
};

// -------------------- Circle Class for Uniform Initialization --------------------
class Circle {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double circumference() const { return 2 * 3.14159265 * radius; }
};

// -------------------- Main --------------------
int main() {
    // Constructor overloads
    Rectangle rectA;             // Default constructor
    Rectangle rectB(3, 4);       // Functional
    Rectangle rectC{5, 6};       // Uniform
    Rectangle rectD = {7, 8};    // POD-style

    cout << "[Rectangle areas]\n";
    cout << "A: " << rectA.area() << "\n";
    cout << "B: " << rectB.area() << "\n";
    cout << "C: " << rectC.area() << "\n";
    cout << "D: " << rectD.area() << "\n\n";

    // Composition and member initializer list
    Cylinder tube(2, 5, 10.0);
    cout << "[Cylinder volume]\n";
    cout << "Volume: " << tube.volume() << "\n\n";

    // Circle with multiple init forms
    Circle foo(10.0);     // functional
    Circle bar = 20.0;    // assignment init
    Circle baz{30.0};     // uniform
    Circle qux = {40.0};  // POD-like

    cout << "[Circle circumference]\n";
    cout << "Foo: " << foo.circumference() << "\n";
    cout << "Bar: " << bar.circumference() << "\n";
    cout << "Qux: " << qux.circumference() << "\n\n";

    // Pointers to class objects
    Rectangle* pRect = new Rectangle(9, 9);
    Rectangle stackRect(4, 5);
    Rectangle* arr = new Rectangle[2] { {1,2}, {3,4} };

    cout << "[Pointer usage]\n";
    cout << "Heap pointer area: " << pRect->area() << "\n";
    cout << "Stack pointer area: " << (&stackRect)->area() << "\n";
    cout << "Array[0] area: " << arr[0].area() << "\n";
    cout << "Array[1] area: " << arr[1].area() << "\n";

    delete pRect;
    delete[] arr;

    return 0;
}
