# Summary
([cppreference](https://en.cppreference.com/w/cpp/language/statements)) Statements are fragments of the C++ program that are executed in sequence.

([Learn C++](https://www.learncpp.com/cpp-tutorial/statements-and-the-structure-of-a-program/)) They are the smallest independent unit of computation in the C++ language.

C++ statements are grouped in the following types:
1. labeled statements;
2. expression statements;
3. compound statements;
4. selection statements;
5. iteration statements;
6. jump statements;
7. declaration statements;
8. try blocks;
9. atomic and synchronized blocks.

## Labeled statements
Labeled statements are just statements that receive a label for identification purposes. They are used by `goto` and `switch` statements for flow control.

## Expression statements
Statements that end in an [expression](https://en.cppreference.com/w/cpp/language/expressions). In other words, expression followed by a semicolon.

## Compound statements
([cppreference](https://en.cppreference.com/w/cpp/language/statements)) A compound statement or block groups a sequence of statements into a single statement.

`if` statements and functions body are examples of compound statements. Blocks are delimited by open and close curly brackets delimiting a sequence of code lines (statements).

([cppreference](https://en.cppreference.com/w/cpp/language/statements#Compound_statements)) Each compound statement introduces its own block scope; variables declared inside a block are destroyed at the closing brace in reverse order:
```
int main()
{ // start of outer block
    {                                // start of inner block
        std::ofstream f("test.txt"); // declaration statement
        f << "abc\n";                // expression statement
    }                                // end of inner block, f is flushed and closed
    std::ifstream f("test.txt"); // declaration statement
    std::string str;             // declaration statement
    f >> str;                    // expression statement
} // end of outer block, str is destroyed, f is closed
```

## Selection statements
([cppreference](https://en.cppreference.com/w/cpp/language/statements#Selection_statements)) A selection statement chooses between one of several control flows.

`if`, `if/else`, and `switch` statements are selection statements.

## Iteration statements
Looping statements. `while`, `do-while`, `for`, and `range for` statements.

## Jump statements
([cppreference](https://en.cppreference.com/w/cpp/language/statements#Jump_statements)) A jump statement unconditionally transfers control flow.

`break`, `continue`, `return`, and `goto` statements.

## Declaration statements
([cppreference](https://en.cppreference.com/w/cpp/language/statements#Declaration_statements)) A declaration statement introduces one or more identifiers into a block.

## Try blocks
([cppreference](https://en.cppreference.com/w/cpp/language/statements#Try_blocks)) A try block catches exceptions thrown when executing other statements.

## Atomic and synchronized blocks
Quite complex for now. cppreference link to [transactional memory](https://en.cppreference.com/w/cpp/language/transactional_memory).
