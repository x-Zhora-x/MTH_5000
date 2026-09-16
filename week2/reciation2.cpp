#include <iostream>

int main() {
    int32_t x = 0;
    int32_t* px;
    px = & x;

    int32_t& ref_x = x; // Same obkect as x just an alias for it nwo
    // Needs to be asigned a variable or error!
    *px = 3;

    std::cout << *px << std::endl;

    int arr[5]; // The array size never changes during the array lifetime.
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    std::cout << sizeof(arr) << '\n';
    // 20 since int is 4 bytes (32 bits)

    int arr2[5] = {1,2,3,4,5}; //assign size 5;
    //int arr2[] = {1,2,3,4,5}; Could also do this and cmpiler knows its size 5

    int* ptr = arr2; // points at first guy
    std::cout << *ptr << '\n';

    for (int i=0; i < 5; i++){
        std::cout << *ptr << ",";
        ptr++; // You can itterate pointers
    }
    std::cout << std::endl;

    int* ptr2 = arr2;

    std::cout << *(ptr2 + 2) << std::endl;
    // This is the third thing in the array and the ptr 2 still points ot the firrst one
    std::cout << *ptr2 << std::endl;

    return 0;
}
