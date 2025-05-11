#include <iostream>
#include <new>
using namespace std;

int main() {
    int i = 5;  
    //size_t i = static_cast<size_t>(-1) / sizeof(int); // max size_t for int
    int simulated_input[] = {75, 436, 1067, 8, 32};  
    int* p = new (nothrow) int[i];

    if (p == nullptr) {
        cout << "Error: memory could not be allocated"; // put i = 100000000000, it triggers this
    } else {
        // Simulate entering numbers
        for (int n = 0; n < i; ++n) {
            p[n] = simulated_input[n];
        }

        // Output the entered numbers
        cout << "You have entered: ";
        for (int n = 0; n < i; ++n) {
            cout << p[n];
            if (n < i - 1) cout << ", ";
        }
        cout << endl;

        delete[] p;
    }

    return 0;
}
