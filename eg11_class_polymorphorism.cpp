#include <iostream>
#include <string>
using namespace std;

// Abstract base class (Polymorphic)
class Shape {
protected:
    int width, height;

    // Private helper (accessible only in Shape)
    void debugPrint(const string& tag) const {
        cout << "[DEBUG] " << tag << ": width=" << width << ", height=" << height << '\n';
    }

public:
    Shape(int w = 0, int h = 0) : width(w), height(h) {}
    virtual ~Shape() {} 

    void setValues(int w, int h) {
        width = w;
        height = h;
    }

    virtual int area() = 0; // pure virtual

    void printArea()  {
        debugPrint("Before area calculation");
        cout << "Area: " << this->area() << '\n';
    }

    // Friend function accessing protected members
    friend void scaleShape(Shape& s, int factor);
};

// Friend function
void scaleShape(Shape& s, int factor) {
    s.width *= factor;
    s.height *= factor;
    cout << "[Friend] Shape scaled by factor " << factor << '\n';
}

class Rectangle : public Shape {
public:
    Rectangle(int w, int h) : Shape(w, h) {}

    int area()  {
        return width * height;
    }
};

class Triangle : public Shape {
public:
    Triangle(int w, int h) : Shape(w, h) {}

    int area()  {
        return (width * height) / 2;
    }
};

// Class using Shape's protected print indirectly (composition+inheritance)
class Printer {
protected:
    void printMsg(const string& msg) const {
        cout << "[Printer] " << msg << '\n';
    }
};

class TrianglePrinter : public Triangle, public Printer {
public:
    TrianglePrinter(int w, int h) : Triangle(w, h) {}

    void show() {
        printMsg("Printing triangle info");
        printArea();
    }
};

int main() {
    Shape* s1 = new Rectangle(4, 5);
    Shape* s2 = new Triangle(4, 5);
    TrianglePrinter tp(3, 6);

    s1->printArea();  // Polymorphic call
    s2->printArea();  // Polymorphic call

    scaleShape(*s1, 2);  // Friend function access
    s1->printArea();

    tp.show();  // Multiple inheritance with protected print function reuse

    delete s1;
    delete s2;

    return 0;
}
