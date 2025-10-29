#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;

    // std::cout << "Enter your name: ";
    // std::cin >> name;

    //if the entered response includes a space, ie first and last name,
    // the code will skip the following cin prompts

    //getline() function needed for strings that have spaces
    std::cout << "What's your full name?: ";
    std::getline(std::cin, name);

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout << "Hello, " << name << '\n';
    std::cout << "You are " << age << " years old";

    return 0;

}