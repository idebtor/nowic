// 
// Topic: Using a reference varaible
// 
// The C/C++ language do offer a function, `toupper()` to convert a character
// to an uppercase, but not for a word or a string. Write a function called 
// `touppers()` that converts a string to all uppercases in place where it 
// does not require extra memory. 
//  - Use a skeleton file, `touppers.cpp`, provided. 
//  - Use a reference variable and `toupper()`, but not functions in <algorithm>.
// 
// author: idebtor@gmail.com
// 
// Sample Run:
//  > g++ touppers.cpp -o touppers
//  > ./touppers
//  > Enter words: Hello Mr. Kim
//  > HELLO MR. KIM
//
#include <iostream>

//////////////////////////////////////////////////////////////////////////////
// Define void touppers() that converts an input arguments into all uppercases
// Use C++ reference and a for loop.



///////////////////// your code above ////////////////////////////////////////
int main() {
    std::string str;
    std::cout << "Enter words: ";
    std::getline(std::cin, str);

    std::cout << "uncomment the following line and implement touppers() \n";
    // touppers(str);

    std::cout << str << std::endl;
    return 0;
}

