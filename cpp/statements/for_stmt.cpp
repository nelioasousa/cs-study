#include <iostream>
#include <vector>

/* From https://en.cppreference.com/w/cpp/language/for
 * 
 * for statament syntax:
 * 
 * for ( init-statement (opt) condition (opt) ; iteration-expression (opt) )
 *     statement
 * 
 * Executes init-statement once, then executes statement and
 * iteration-expression repeatedly, until the value of condition becomes false.
 * The test takes place before each iteration.
 * 
 * init-statement must end with with a semicolon:
 * 
 * for ( declaration-or-expression (opt) ; condition (opt) ; expression (opt) )
 *     statement
 * 
 * 1. condition can be either an expression or a declaration of a single
 *    variable. Value of condition is implicitly converted to bool.
 * 
 * 2. init-statement can declare any number of variables using
 *    decl-specifier-seq grammar. It can also be a type alias declaration or a
 *    structured biding.
 * 
 * 3. init-statement and condition are within the same scope.
 * 
 * 4. iteration-expression and statement have disjoint scopes nested within the
 *    scope of the for statement (scope of condition and init-statement)
 * 
 * 5. iteration-expression is evaluated at the end of statement and before the
 *    evaluation of the condition test.
 * 
 * 6. When continue statement is encountered inside statement, jumps straigth to
 *    iteration-expression.
 * 
 * 7. When break statement is encountered inside statement, for loop is exited.
 * 
 * 8. In C++, names declared in init-statement and condition can't be shadowed
 *    (redeclared) in the scope of statement. C code allows this shadowing.
 * 
 * cppreference examples are pretty good, see below. */


int main()  // 1-7 are from cppreference
{
    std::cout << "1) typical loop with a single statement as the body:\n";
    for (int i = 0; i < 10; ++i)
        std::cout << i << ' ';


    std::cout << "\n\n" "2) init-statement can declare multiple names, as\n"
                 "long as they can use the same decl-specifier-seq:\n";
    for (int i = 0, *p = &i; i < 9; i += 2)
        std::cout << i << ':' << *p << ' ';


    std::cout << "\n\n" "3) condition may be a declaration:\n";
    char cstr[] = "Hello";
    for (int n = 0; char c = cstr[n]; ++n)
        std::cout << c;


    std::cout << "\n\n" "4) init-statement can use the auto type specifier:\n";
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    for (auto iter = v.begin(); iter != v.end(); ++iter)
        std::cout << *iter << ' ';


    std::cout << "\n\n" "5) init-statement can be an expression:\n";
    int n = 0;
    for (std::cout << "Loop start\n";
         std::cout << "Loop test\n";
         std::cout << "Iteration " << ++n << '\n')
    {
        if (n > 1)
            break;
    }


    std::cout << "\n" "6) constructors and destructors of objects created\n"
                 "in the loop's body are called per each iteration:\n";
    struct S
    {
        S(int x, int y) { std::cout << "S::S(" << x << ", " << y << "); "; }
        ~S() { std::cout << "S::~S()\n"; }
    };
    for (int i{0}, j{5}; i < j; ++i, --j)
        S s{i, j};


    std::cout << "\n" "7) init-statement can use structured bindings:\n";
    long arr[]{1, 3, 7};
    for (auto [i, j, k] = arr; i + j < k; ++i)
        std::cout << i + j << ' ';


    std::cout << "\n\n" "8) printable char:\n";
    for (char c {33}, terminator {}; c < 127; ++c)  // printable ASCII: 33-126
    {
        terminator = (c - 32) % 15 && c != 126 ? ' ' : '\n';
        std::cout << c << terminator;
    }
}
