#include <iostream>

int main() {
    std::cout << "oi buddy\n";

    bool a = true;
    char b = 'b';
    int c = 3;
    double d = 3.0;
    unsigned e = 5;

    std::cout << sizeof(a) << std::endl;
    std::cout << sizeof(b) << std::endl;
    std::cout << sizeof(c) << std::endl;
    std::cout << sizeof(d) << std::endl;
    std::cout << sizeof(a) << std::endl;

    std::cout << "address of d in hex:" << &d << std::endl;
    // Going to point to this guy and store this address!

    double* float_pointer;
    float_pointer = &d; // Now ive stored the adress


    return 0;
}
