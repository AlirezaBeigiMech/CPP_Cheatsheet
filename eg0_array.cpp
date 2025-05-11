#include <iostream>
#include <array>
using namespace std;

#define HEIGHT 3
#define WIDTH 5

// 1. Function to print a 1D array
void print1D(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// 2. Function to print a 2D array passed as parameter
void print2D(int arr[][WIDTH], int height) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < WIDTH; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {
    // --- 1. Multidimensional array ---
    int jimmy[HEIGHT][WIDTH];

    // Fill with multiplication pattern
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            jimmy[i][j] = (i + 1) * (j + 1);

    cout << "Multidimensional array:\n";
    print2D(jimmy, HEIGHT);

    // --- 2. Flat array simulating 2D ---
    int flat[HEIGHT * WIDTH];
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            flat[i * WIDTH + j] = (i + 1) * (j + 1);

    cout << "\nSimulated 2D with flat array:\n";
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
            cout << flat[i * WIDTH + j] << " ";
        cout << endl;
    }

    // --- 3. Pass 1D arrays as function arguments ---
    int first[] = {5, 10, 15};
    int second[] = {2, 4, 6, 8, 10};
    cout << "\nPrinting 1D arrays passed to function:\n";
    print1D(first, 3);
    print1D(second, 5);

    // --- 4. std::array usage ---
    array<int, 3> myarray = {10, 20, 30};
    for (size_t i = 0; i < myarray.size(); ++i)
        ++myarray[i];

    cout << "\nstd::array contents:\n";
    for (int value : myarray)
        cout << value << endl;

    return 0;
}


