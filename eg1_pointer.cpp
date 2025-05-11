#include <iostream>
using namespace std;

// Function for function pointer demo
int add(int a, int b) { return a + b; }

void pointer_summary_demo() {
    // Basic pointer declaration and dereference
    int a = 10, b = 20;
    int *p = &a;
    cout << "*p = " << *p << " (value at a)\n";

    *p = 15;  // modify a through pointer
    cout << "a = " << a << " (after *p = 15)\n";

    // Pointer to pointer
    int **pp = &p;
    **pp = 30;
    cout << "a = " << a << " (after **pp = 30)\n";

    // Pointers and arrays
    int arr[3] = {1, 2, 3};
    int *arrPtr = arr;  // same as &arr[0]
    *(arrPtr + 1) = 5;  // modify second element
    cout << "arr[1] = " << arr[1] << '\n';

    // Const pointer usage
    const int ci = 100;
    const int *cp = &ci;
    cout << "*cp (const int*) = " << *cp << '\n';

    // Pointer arithmetic
    char cArr[] = {'a', 'b', 'c'};
    char *cPtr = cArr;
    cout << "*++cPtr = " << *++cPtr << " (moves to 'b')\n";

    // Void pointer usage
    void *vp = &a;
    cout << "*vp (cast to int*) = " << *(int*)vp << '\n';

    // Null pointer
    int *nullPtr = nullptr;
    if (!nullPtr)
        cout << "nullPtr is nullptr\n";

    // Function pointer
    int (*funcPtr)(int, int) = add;
    cout << "add(3, 4) via function pointer = " << funcPtr(3, 4) << '\n';
}

int main() {
    pointer_summary_demo();
    return 0;
}
