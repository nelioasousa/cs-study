#include <iostream>
#include <string>

constexpr int get_int_back(int a) { return a; }

int main()
{
    // nested if-else
    int vl = 11;
    if (vl > 5)
    {
        std::cout << "5 < vl";
        if (vl < 10)
            std::cout << " < 10\n";
        else
            std::cout << " >= 10\n";
    } else {
        std::cout << "vl <= 5";
    }


    // cppreference:
    //   in nested if-statements, the else is associated with the closest if that doesn't have an else
    //
    // bellow snippet was adapted from cppreference
    // when uncommented it throw a warning: -Wdangling-else
    //
    // int i = 2;
    // int j = 1;
    // if (i > 1)
    //     if (j > 2)  // nested if
    //         std::cout << i << " > 1 and " << j << " > 2\n";
    // else  // this else is part of if (j > 2), not of if (i > 1)
    //     std::cout << i << " > 1 and " << j << " <= 2\n";


    // if-statements can have a initializer
    // declarations in the initializer can be accessed from both if and else
    unsigned char score = 8;
    if (std::string result; score > 7)
    {
        result = "approved";
        std::cout << "Student " << result << std::endl;
    } else {
        result = "failed";
        std::cout << "Student " << result << std::endl;
    }


    // `constexpr` and `consteval` can be used with if-statements to allow
    // compilation-time evaluation of conditionals for code optimization
    // `consteval` is only available in C++23 forward
    if constexpr (get_int_back(5))
        std::cout << "If condition is true, the code in the else block is discarded" << std::endl;
    else
        std::cout << "If condition is false, the code in the if block is discarded" << std::endl;


    return 0;
}
