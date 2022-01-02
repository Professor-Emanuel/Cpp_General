#include <iostream>

/* EXAMPLE 2 */
void swap(int &x, int &y);

/* EXAMPLE 3 */
double vals[] = {1.1, 10.3, 30.2, 2.21, -5.71};
double &setValues(int i);

/* EXAMPLE 4 */
int &someFunc();

int main()
{
    /*Example 1: References
    A reference variable is an alias, that is, another name for an already existing variable. Once a reference
    is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.

    References vs Pointers
    References are often confused with pointers but three major differences between references and pointers are −

    You cannot have NULL references. You must always be able to assume that a reference is connected to a legitimate piece of storage.

    Once a reference is initialized to an object, it cannot be changed to refer to another object. Pointers can be pointed to another object at any time.

    A reference must be initialized when it is created. Pointers can be initialized at any time.

    Creating References in C++
    Think of a variable name as a label attached to the variable's location in memory. You can then think of a reference as a second label attached
    to that memory location. Therefore, you can access the contents of the variable through either the original variable name or the reference.
    For example, suppose we have the following example

    int i = 17;

    We can declare reference variables for i as follows.

    int& r = i;

    Read the & in these declarations as reference. Thus, read the first declaration as "r is an integer reference initialized to i".
    */

    //declare simple variables
    int i;
    double d;

    //declare reference variables
    int &r = i;
    double &s = d;

    i = 5;
    d = 11.5;

    std::cout<<"Value of i using simple variable: " << i << " and using reference variable: " << r << std::endl;
    std::cout<<"Value of d using simple variable: " << d << " and using reference variable: " << s << std::endl;

    /*
    References are usually used for function argument lists and function return values. So following are two important
    subjects related to C++ references which should be clear to a C++ programmer: References as Parameters & Reference as Return Value.
    */

    /* EXAMPLE 2: call by reference using C++ references
    */
    int a = 10;
    int b = 20;
    std::cout<<"Original a: " << a << std::endl;
    std::cout<<"Original b: " << b << std::endl;

    swap(a, b);
    std::cout<<"Swapped a: " << a << std::endl;
    std::cout<<"Swapped b: " << b << std::endl;

    /* EXAMPLE 3: Reference as Return Value
    A C++ program can be made easier to read and maintain by using references rather than pointers.
    A C++ function can return a reference in a similar way as it returns a pointer.

    When a function returns a reference, it returns an implicit pointer to its return value. This way,
    a function can be used on the left side of an assignment statement. For example, consider this simple program.
    */
    std::cout<<"Original values: "<< std::endl;
    for(int i=0; i<5; i++){
        std::cout << "vals[" << i << "] = ";
        std::cout << vals[i] << std::endl;
    }

    setValues(1) = - 6.77;
    setValues(4) = 11.91;

    std::cout<<"Altered values: "<< std::endl;
    for(int i=0; i<5; i++){
        std::cout << "vals[" << i << "] = ";
        std::cout << vals[i] << std::endl;
    }

    /* EXAMPLE 4 */
    int m = someFunc();
    std::cout<<"m: " << m << std::endl;

    return 0;
}

/* EXAMPLE 2 */
void swap(int &x, int &y){
    x = x + y;
    y = x - y;
    x = x - y;
}

/* EXAMPLE 3 */
double &setValues(int i){
    return vals[i]; // return a reference to the i-th element
}

/* EXAMPLE 4
When returning a reference, be careful that the object being referred to does not go out of scope. So it is not legal to return a
reference to local var. But you can always return a reference on a static variable.
*/
int &someFunc(){
    //int q = 5;
    //return q; // Compile time error
    static int g = 7;
    return g; // Safe, g lives outside this scope
}

