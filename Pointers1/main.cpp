#include <iostream>

int main()
{
    /* EXAMPLE 1:
    C++ pointers are easy and fun to learn. Some C++ tasks are performed more easily with pointers, and other
    C++ tasks, such as dynamic memory allocation, cannot be performed without them.

    As you know every variable is a memory location and every memory location has its address defined which
    can be accessed using ampersand (&) operator which denotes an address in memory. Consider the following
    which will print the address of the variables defined.
    */

    int var1;
    char var2[10];

    std::cout<<"Address of var1: " << &var1 << std::endl;
    std::cout<<"Address of var2: " << &var2 << std::endl;


    /* EXAMPLE 2:
    What are Pointers?
    A pointer is a variable whose value is the address of another variable. Like any variable
    or constant, you must declare a pointer before you can work with it. The general form of a pointer variable declaration is −

    type *var-name;
    Here, type is the pointer's base type; it must be a valid C++ type and var-name is the name
    of the pointer variable. The asterisk you used to declare a pointer is the same asterisk that
    you use for multiplication. However, in this statement the asterisk is being used to designate
    a variable as a pointer. Following are the valid pointer declaration −

    int    *ip;    // pointer to an integer
    double *dp;    // pointer to a double
    float  *fp;    // pointer to a float
    char   *ch     // pointer to character

    The actual data type of the value of all pointers, whether integer, float, character, or otherwise,
    is the same, a long hexadecimal number that represents a memory address. The only difference between
    pointers of different data types is the data type of the variable or constant that the pointer points to.

    Using Pointers in C++
    There are few important operations, which we will do with the pointers very frequently. (a) We define
    a pointer variable. (b) Assign the address of a variable to a pointer. (c) Finally access the value
    at the address available in the pointer variable. This is done by using unary operator * that returns
    the value of the variable located at the address specified by its operand. Following example makes use
    of these operations.
    */

    int var3 = 20;
    int *ip1 = &var3;
    std::cout<<"Value of var3: " << var3 << std::endl;
    std::cout<<"Address of var3: " << &var3 << std::endl;
    std::cout<<"Address of ip1: " << &ip1 << std::endl;
    std::cout<<"Address stored in ip1: " << ip1 << std::endl;
    std::cout<<"Value stored in ip1: " << *ip1 << std::endl;

    /*  EXAMPLE 3: NULL pointers
    It is always a good practice to assign the pointer NULL to a pointer variable in case you do not have
    exact address to be assigned. This is done at the time of variable declaration. A pointer that is
    assigned NULL is called a null pointer.

    The NULL pointer is a constant with a value of zero defined in several standard libraries, including iostream.
    Consider the following program

    NULL = is the value zero as an int
    nullptr = is a keyword that represents zero as an address
    */

    int *ip2 = NULL;
    //char *cp1 = nullptr;
    float *fp1 = nullptr;
    std::cout<<"Address stored in ip2: " << ip2 << std::endl;
    //std::cout<<"Value stored in ip2: " << *ip2 << std::endl; //ERROR - unpredictable behavior at compile time
    std::cout<<"Address stored in fp1: " << fp1 << std::endl;
    //std::cout<<"Address stored in cp1: " << cp1 << std::endl;
    //std::cout<<"Value stored in cp1: " << *cp1 << std::endl; //ERROR - unpredictable behavior at compile time

    /*
    On most of the operating systems, programs are not permitted to access memory at address 0 because that
    memory is reserved by the operating system. However, the memory address 0 has special significance; it
    signals that the pointer is not intended to point to an accessible memory location. But by convention,
    if a pointer contains the null (zero) value, it is assumed to point to nothing.
    */

    /* EXAMPLE 4: Pointer Arithmetic
    As you understood pointer is an address which is a numeric value; therefore, you can perform arithmetic
    operations on a pointer just as you can a numeric value. There are four arithmetic operators that can be
    used on pointers: ++, --, +, and -

    To understand pointer arithmetic, let us consider that ptr is an integer pointer which points to the address 1000.
    Assuming 32-bit integers, let us perform the following arithmetic operation on the pointer.

    ptr++
    the ptr will point to the location 1004 because each time ptr is incremented, it will point to the next integer.
    This operation will move the pointer to next memory location without impacting actual value at the memory location.
    If ptr points to a character whose address is 1000, then above operation will point to the location 1001 because
    next character will be available at 1001.

    Incrementing a Pointer
    We prefer using a pointer in our program instead of an array because the variable pointer can be incremented,
    unlike the array name which cannot be incremented because it is a constant pointer. The following program increments
    the variable pointer to access each succeeding element of the array.
    */

    const int MAX = 3;
    int var4[MAX] = {10, 100, 1000};
    int *ip3;

    ip3 = var4; // point to the address of the 1st element in var4, here &var4[0] is equivalent to var4
    for(int i = 0; i < MAX; i++){
        std::cout<< "Address of var4[" << i << "] = ";
        std::cout<< ip3 << std::endl;

        std::cout<< "Value of var4[" << i << "] = ";
        std::cout<< *ip3 << std::endl;

        ip3++;// point to the next location
    }

    int *ip4;
    ip4 = &var4[MAX-1];// point to the address of the last element in var4
    for(int i = MAX; i > 0; i--){
        std::cout<< "Address of var4[" << i << "] = ";
        std::cout<< ip4 << std::endl;

        std::cout<< "Value of var4[" << i << "] = ";
        std::cout<< *ip4 << std::endl;

        ip4--;// point to the previous location
    }

    /* EXAMPLE 5: Pointer Comparisons
    Pointers may be compared by using relational operators, such as ==, <, and >. If p1 and p2 point to variables
    that are related to each other, such as elements of the same array, then p1 and p2 can be meaningfully compared.

    The following program modifies the previous example one by incrementing the variable pointer so long as the
    address to which it points is either less than or equal to the address of the last element of the array, which is &var[MAX - 1].
    */
    int *ip5;
    ip5 = var4;
    int i = 0;

    while(ip5 <= &var4[MAX-1]){
        std::cout<< "Address of var4[" << i << "] = ";
        std::cout<< ip5 << std::endl;

        std::cout<< "Value of var4[" << i << "] = ";
        std::cout<< *ip5 << std::endl;

        ip5++;// point to the next location
        i++;
    }

    /* EXAMPLE 6: Pointers VS Arrays
    Pointers and arrays are strongly related. In fact, pointers and arrays are interchangeable in many cases.
    For example, a pointer that points to the beginning of an array can access that array by using either pointer
    arithmetic or array-style indexing. Consider the following program (see example 4/5)
    */

    /* EXAMPLE 7:
    However, pointers and arrays are not completely interchangeable. For example, consider the following program
    */

    int var5[MAX] = {10, 100, 1000};
    for(int i=0; i<MAX; i++){
        *var5 = i; //correct syntax
        //var5++; // incorrect: lvalue required as increment operand
    } //this for will make var5[0] = 0 then 1 and then 2, so var5[0] = 2 when the loop ends
    /*
    It is perfectly acceptable to apply the pointer operator * to var but it is illegal to modify var value.
    The reason for this is that var is a constant that points to the beginning of an array and can not be used as l-value.

    Because an array name generates a pointer constant, it can still be used in pointer-style expressions,
    as long as it is not modified. For example, the following is a valid statement that assigns var[2] the value 500 −

    *(var + 2) = 500;
    Above statement is valid and will compile successfully because var is not changed.
    */

    for(int i = 0; i < MAX; i++){
        std::cout<< "Address of var5[" << i << "] = ";
        std::cout<< (var5 + i) << std::endl;

        std::cout<< "Value of var5[" << i << "] = ";
        std::cout<< *(var5 + i) << std::endl;

        ip3++;// point to the next location
    }

    return 0;
}
