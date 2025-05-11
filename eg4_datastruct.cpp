#include <iostream>
#include <string>
using namespace std;

// 1. Struct with inline object declarations
struct Product {
    int weight;
    double price;
} apple, banana;

// 2. Nested struct definition
struct Movie {
    string title;
    int year;
};

struct Friend {
    string name;
    Movie favorite_movie;
};

// 3. Function that accepts struct by value
void printProduct(Product p) {
    cout << "- Weight: " << p.weight << "g, Price: $" << p.price << endl;
}

// 4. Function that accepts nested struct by pointer
void printFriendFavorite(Friend* f) {
    cout << f->name << "'s favorite movie: " 
         << f->favorite_movie.title << " (" << f->favorite_movie.year << ")\n";
}

int main() {
    // Direct struct access
    apple.weight = 150;
    apple.price = 0.99;
    banana = {120, 0.79};

    cout << "Product Info:\n";
    printProduct(apple);
    printProduct(banana);

    // Struct array
    Product catalog[2] = {{200, 1.50}, {80, 0.49}};
    cout << "\nCatalog:\n";
    for (int i = 0; i < 2; ++i)
        printProduct(catalog[i]);

    // Pointer to struct
    Product* pBanana = &banana;
    pBanana->price = 0.69; // modifying via pointer
    cout << "\nUpdated banana price via pointer:\n";
    printProduct(banana);

    // Nested struct usage
    Friend charlie = {"Charlie", {"The Matrix", 1999}};
    Friend maria = {"Maria", {"Amélie", 2001}};
    Friend* pf = &charlie;

    cout << "\nFavorite Movies:\n";
    printFriendFavorite(&maria);
    printFriendFavorite(pf);  // points to charlie

    return 0;
}
