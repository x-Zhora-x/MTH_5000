#include <iostream>

class Horse {
    std::string name;
    int speed;
    int age;
    bool original;
    Horse(const Horse& other);
    Horse(Horse && other);
    Horse() =  delete; // NOOOO default constructor BOOOOOm
};

// Copy constructor
Horse::Horse(const Horse& other) {
    name = other.name;
    speed = other.speed;
    age = other.age;
    original = false;
}
// Move constructor
Horse::Horse(Horse && other) {
    name = other.name;
    speed = other.speed;
    age = other.age;
}



int main() {



    return 0;
}
