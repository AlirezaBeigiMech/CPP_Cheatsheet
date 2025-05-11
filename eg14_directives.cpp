#include <iostream>
using namespace std;

// -------------------- Macro Definitions --------------------
#define TABLE_SIZE 100  // Simple macro

#define getmax(a,b) ((a)>(b)?(a):(b))  // Function-like macro

// Stringizing (# operator)
#define str(x) #x

// Token pasting (## operator)
#define glue(a,b) a##b

int main(){
    // --- Simple macro usage ---
    int table1[TABLE_SIZE];
    cout << "TABLE_SIZE macro expands to: " << TABLE_SIZE << endl;

    // --- Function macro usage ---
    int x = 5;
    cout << "getmax(x, 2): " << getmax(x, 2) << endl;
    cout << "getmax(7, x): " << getmax(7, x) << endl;

    // --- Stringizing example ---
    cout << str(This is a macro turned into string) << endl;

    // --- Token pasting example ---
    glue(c, out) << " <- this is cout using token pasting" << endl;

    // --- Undefining and redefining macros ---
    #undef TABLE_SIZE
    #define TABLE_SIZE 200
    int table2[TABLE_SIZE];
    cout << "TABLE_SIZE redefined to: " << TABLE_SIZE << endl;

    // --- Conditional Inclusion Example ---
    #ifdef TABLE_SIZE
    cout << "TABLE_SIZE is defined!" << endl;
    #endif

    #ifndef ARRAY_SIZE
    #define ARRAY_SIZE 50
    #endif
    cout << "ARRAY_SIZE defined as: " << ARRAY_SIZE << endl;

    // --- #if, #elif, #else Example ---
    #if TABLE_SIZE > 200
        #undef TABLE_SIZE
        #define TABLE_SIZE 200
    #elif TABLE_SIZE < 100
        #undef TABLE_SIZE
        #define TABLE_SIZE 100
    #else
        #undef TABLE_SIZE
        #define TABLE_SIZE 150
    #endif
    cout << "TABLE_SIZE after conditional directives: " << TABLE_SIZE << endl;

    // --- #line directive Example ---
    #line 999 "FakeFile.cpp"
    // Uncommenting below will give compiler error at FakeFile.cpp:999
    // int a?;

    // --- #error directive Example ---
    #ifndef __cplusplus
    #error A C++ compiler is required!
    #endif

    return 0;
}
