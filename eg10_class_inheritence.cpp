#include <iostream>
#include <string>
using namespace std;

// Base Class
class Polygon {
  protected:
    int width, height;
  public:
    Polygon(int w = 0, int h = 0) : width(w), height(h) {}
    void setValues(int w, int h) { width = w; height = h; }
};

// Friend Function Example
class Rectangle;

void doubleSize(Rectangle& r);  // Forward declaration

// Derived Class with Friend Function
class Rectangle : public Polygon {
  public:
    Rectangle(int w = 0, int h = 0) : Polygon(w, h) {}
    int area() const { return width * height; }
    friend void doubleSize(Rectangle& r);  // Friend function declaration
};

// Friend function definition
void doubleSize(Rectangle& r) {
    r.width *= 2;
    r.height *= 2;
}

// Friend Class Example
class Square;

class RectangleHelper {
  public:
    void convertFromSquare(Rectangle& r, const Square& s);
};

// Class granting friendship to another Class
class Square {
    friend class RectangleHelper;  // Friend class
  private:
    int side;
  public:
    Square(int s) : side(s) {}
};

// Friend Class Method accessing private member of Square
void RectangleHelper::convertFromSquare(Rectangle& r, const Square& s) {
    r.setValues(s.side, s.side);
}

// Multiple Inheritance Example
class Printable {
  public:
    void print(const string& msg) const {
        cout << msg << endl;
    }
};

void printfriend(Rectangle& r) ;

class Triangle : public Polygon, public Printable {
  public:
    Triangle(int w = 0, int h = 0) : Polygon(w, h) {}
    int area() const { return (width * height) / 2; }
    friend void printfriend(Triangle& r);
};

void printfriend(Triangle& r)  {
    cout << r.area() << endl;
}

int main() {
    // Basic Inheritance & Friend Function
    Rectangle rect(4, 5);
    cout << "Rectangle area: " << rect.area() << endl;
    doubleSize(rect);  // Friend function doubles private members
    cout << "Rectangle area after doubleSize: " << rect.area() << endl;

    // Friend Class Example
    Square sq(3);
    RectangleHelper helper;
    helper.convertFromSquare(rect, sq);  // Access private side of Square
    cout << "Rectangle area after converting from Square(3): " << rect.area() << endl;

    // Multiple Inheritance with Printable
    Triangle tr(4, 5);
    tr.print("Triangle area: " + to_string(tr.area()));
    printfriend(tr);

    return 0;
}
