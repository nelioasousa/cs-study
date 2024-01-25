#include <iostream>

int main()
{
    /* From cppreference:
    ~ `switch` grammar:
    attr(optional) switch ( init-statement(optional) condition ) statement

    ~ `case :` label grammar
    attr(optional) case constant-expression : statement

    ~ `default :` label grammar
    attr(optional) default : statement
    
    `switch` condition must be of integral or enumeration type
    `case :` constant-expression must have the same type of condition */


    // switch with init-statement
    // switch with a declaration as condition
    switch (std::cout << "Initializing...\n"; unsigned char charValue{69})
    {
        case 0:  // constant-expression converted to condition type
            std::cout << "Its 0!\n";
            break;
        case 1:
            std::cout << "Its 1!\n";
            break;
        case 2:
            std::cout << "Its 2!\n";
            break;
        // // Uncommenting this block:
        // // - Throw out of range warning
        // // - Throw implicit fallthrough warning
        // case 256:
        //     std::cout << "Out of range...\n";
        //     // [[fallthrough]];
        default:
            std::cout << "Its " << (int)charValue << "!\n";
    }


    // The following code compiles, but it has a lot of problems...
    // See https://stackoverflow.com/q/56267791
    switch (char character{69})
    {
        case 'a':
            /* cppreference:
            Because transfer of control is not permitted to enter the scope of
            a variable, if a declaration statement is encountered inside the
            statement, it has to be scoped in its own compound statement: */
            {
                int a = (int)character;  // only allowed since statement is scoped as a compound statement
                std::cout << "char 'a' = " << a << '\n';
                break;
            }
        case 'b':
            int b;               // this is allowed, but:
            b = (int)character;  // b is visible anywhere in the switch scope regardless of whether the case block ran
            std::cout << "char 'b' = " << b << '\n';
            break;
        case 'c':
            ++b;  // undefined behavior if it's run: `b` isn't initialized
            // int c = (int)character;  // not allowed
            std::cout << "char 'c' = " << (int)character << '\n';
            break;
        default:
            int char_value = (int)character;  // allowed inside default, but why?
            std::cout << "char '" << character << "' = " << char_value << '\n';
            break;
    }


    return 0;
}
