#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int len = 10; // length of arrays a and b

    // prints arrays a and b
    cout << "Array a: ";
    for (int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Array b: ";
    for (int i = 0; i < len; i++)
        cout << b[i] << " ";
    cout << endl;

    // swaps values of arrays a and b
    cout << "Swapping" << endl;
    for (int i = 0; i < len; i++)
        swap(&a[i], &b[i]);

    // prints arrays a and b
    cout << "Array a: ";
    for (int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Array b: ";
    for (int i = 0; i < len; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}
