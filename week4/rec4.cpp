#include <iostream>

// Heap use of NEW
// Stack else


// Stack allocation
int computeA(int a) {
    return a * a;
}

int computeFinal(int a, int b) {
    int c = computeA(a) + b;
    return c;
}

void leaker() {
    int* a = new int[99];
    std::cout << "mem leaked valgrind me \n";
}


int main() {

    int a = 2;
    int b = 1;

    std::cout << computeFinal(a, b) << '\n';

    // Adding to the heap
    int* p_0 = new int[5];
    int* p_1 = new int[3]{1, 2, 3};

    leaker();

    return 0;
}
