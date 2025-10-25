#include <iostream>

int main() {
    //nullptr = keyword represents a null pointer literal
    //when using pointers, be careful the code is not
    // dereferencing null or pointing to free memory
    //as this will cause undefined behavior
    int *pointer = nullptr;
    int x = 123;

    pointer = &x;
    //if the pointer is not assigned to an address, it will be assigned to nullptr

    if(pointer == nullptr){
        std::cout << "address was not assigned\n";
    }
    else {
        std::cout << "address was assigned\n";
        std::cout << *pointer;
    }
    return 0;
}