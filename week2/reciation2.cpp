#include <iostream>

/*
Function Parameter
  Pass by value : passing the copy of the value
  Pass by pointer : passing the copy of the value’s pointer
  Pass by reference : passing a reference
*/


void increment1(int value) {
    value ++;
}
// Pass by value -> copy constructor

/*
 * Semantics: providing the function with the address of the variable rather than its value.
 • Function can modify the original value through dereferencing
 • Direct access to original variable
 • Memory efficiency
 */
void increment2(int* a) {
 (*a)++;
}
// passing by pointer



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

    // x is 3
    const int* ptr3 = &x;
    // #ptr = 3 error!!
    ptr3 = &arr2[0];
    // Not error becasue u can repoint it!

    int y = 4;
    int* ptr4 = &y;
    increment1(*ptr4);
    std::cout << *ptr4 << std::endl;
    increment2(ptr4);

    std::cout << *ptr4 << std::endl;

    /*
     * correct ways of returning a pointer
     • Returning a pointer to a global or static variable
     • Returning a pointer to a non-local array element
     • Returning a pointer from a class member function
     • Returning a pointer to memory on heap
     DO NOOTTTTTT return a pointer to a local vairable
     */

    return 0;
}
