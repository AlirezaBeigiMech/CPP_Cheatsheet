#include <iostream>
#include <cstring>
using namespace std;

// 1. Type Aliases
typedef unsigned int WORD;
typedef char* pChar;
typedef char field[50];

using C = char;
using Field = char[50];  // modern alias
using Price = float;

// 2. Union Example
union MyTypes {
    char c;
    int i;
    float f;
};

// 3. Union for shared access
union Mixed {
    int l;
    struct {
        short hi;
        short lo;
    } s;
    char bytes[4];
};

// 4. Anonymous union inside struct
struct Book {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    }; // anonymous union
};

// 5. Regular enum
enum Colors { black, blue, green, cyan, red, purple, yellow, white };
enum Months { January = 1, February, March, April };

// 6. Scoped enum class
enum class EyeColor : char { blue, green, brown };

int main() {
    // Type alias usage
    WORD score = 3000;
    pChar greeting = (char*)"Hello";
    field name = "OpenAI";
    Field aliasName = "Alias";

    cout << "Score: " << score << ", Greeting: " << greeting << ", Name: " << name << ", AliasName: " << aliasName << '\n';

    // Union: shared memory
    MyTypes u;
    u.i = 65;
    cout << "Union access - int: " << u.i << ", char: " << u.c << '\n'; // Same memory!

    // Union: mixed access
    Mixed mix;
    mix.l = 0x12345678;
    cout << "Mixed.l: " << hex << mix.l << dec << '\n';
    cout << "High short: " << mix.s.hi << ", Low short: " << mix.s.lo << '\n';
    cout << "Bytes: ";
    for (int i = 0; i < 4; ++i)
        cout << (int)(unsigned char)mix.bytes[i] << " ";
    cout << '\n';

    // Anonymous union in struct
    Book b1;
    strcpy(b1.title, "C++ Primer");
    strcpy(b1.author, "Lippman");
    b1.dollars = 39.99f;
    cout << "Book: " << b1.title << " by " << b1.author << ", Price: $" << b1.dollars << '\n';

    // Regular enum usage
    Colors myColor = green;
    if (myColor == green) myColor = red;
    cout << "My color enum value: " << myColor << '\n';  // Implicitly converted to int

    // Enum with values
    Months m = March;
    cout << "Month value: " << m << '\n';

    // Enum class usage
    EyeColor eye = EyeColor::green;
    if (eye == EyeColor::green) eye = EyeColor::blue;
    cout << "EyeColor enum class (still needs scoping): EyeColor::blue\n";

    return 0;
}
