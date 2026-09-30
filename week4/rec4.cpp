#include <iostream>
#include <memory>

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

template <typename T>
T max_val(T a, T b) {
    if (a > b) {
       return a;
    }
    else {
        return b;
    }
}

class Rect {
    public:
        int base;
        int height;
        int x; // bottom left
        int y; // bottom right
        ~Rect();
        Rect(int b, int h);
};
Rect::Rect(int b, int h) {
    base = b;
    height = h;
    std::cout << "ya radilsya!\n" << "my base and height are " << base << " and " << height << '\n';
}

Rect::~Rect() {
    std::cout << "destroyed\n";
}

std::unique_ptr<int[]> an_int() {
    std::unique_ptr<int[]> to_return = std::make_unique<int[]>(10);
    return std::move(to_return);
}


int main() {

    int a = 2;
    int b = 1;

    std::cout << computeFinal(a, b) << '\n';

    // Adding to the heap
    int* p_0 = new int[5];
    int* p_1 = new int[3]{1, 2, 3};

    leaker();
    // rather than previous guys which are c-style pointers, smart
    // pointers are wrappers around a pointer to make syure the object is delted
    // if it is no longer used

    // unique ptr -> manages another obj until the object goes out of scope
    // shared ptr


    std::unique_ptr<int[]> p_u = std::make_unique<int[]>(10);

    Rect* lame_pointer = new Rect(5,6);
    std::unique_ptr<Rect> p_s = std::make_unique<Rect>(3,4);
    (*p_s).height = 69;
    std::cout << "Height of unique pointer is now " << (*p_s).height << '\n';

    // shared_ptr
    // a group of pointers who r collectively responsible for resource
    // last to get destroyed calls destroyer

    // cpp 20 version ---> std::shared_ptr<int[]> p_share_1 = std::make_shared<int[]>(10);
    std::shared_ptr<Rect> p_share_1 = std::make_shared<Rect>(1, 2);
    std::shared_ptr<Rect> p_share_2 = p_share_1;

    // to move in funciton so no dangling pointer converts pointer to r value
    std::unique_ptr<int[]> a_guy = an_int();

    return 0;

}
