#include <iostream>
#include <ctime>

void getSeconds(unsigned long *par); /* EXAMPLE 2*/
double getAverage(int *arr, int size); /* EXAMPLE 3*/
int *getRandom(); /* EXAMPLE 4*/

int main()
{
    /* EXAMPLE 1: Pointer to pointer
    A pointer to a pointer is a form of multiple indirection or a chain of pointers. Normally, a pointer
    contains the address of a variable. When we define a pointer to a pointer, the first pointer contains
    the address of the second pointer, which points to the location that contains the actual value as shown below.

    A variable that is a pointer to a pointer must be declared as such. This is done by placing an additional
    asterisk in front of its name. For example, following is the declaration to declare a pointer to a pointer of type int.

    int **var;
    When a target value is indirectly pointed to by a pointer to a pointer, accessing that value requires that
    the asterisk operator be applied twice, as is shown below in the example.
    */

    int var1;
    int *ptr1;
    int **ptr2;

    var1 = 10;
    ptr1 = &var1;
    ptr2 = &ptr1;

    std::cout << "Value of var1 :" << var1 << std::endl;
    std::cout << "Address of var1 :" << &var1 << std::endl;
    std::cout << "Value available at *ptr1 :" << *ptr1 << std::endl;
    std::cout << "Address stored in ptr1 :" << ptr1 << std::endl;
    std::cout << "Value available at **ptr2 :" << **ptr2 << std::endl;
    std::cout << "Address stored in ptr2 :" << ptr2 << std::endl;

    /* EXAMPLE 2: Passing Pointers to Functions
    C++ allows you to pass a pointer to a function. To do so, simply declare the function parameter as a pointer type.

    Following a simple example where we pass an unsigned long pointer to a function and change the value inside the function
    which reflects back in the calling function.
    */

    unsigned long sec;
    getSeconds( &sec );

    std::cout<< "Number of seconds: " << sec << std::endl;

    /* EXAMPLE 3:
    The function which can accept a pointer, can also accept an array as shown in the following example.
    */

    int balance[5] = {10, 19, 1, 90, 21};
    double avg;

    avg = getAverage(balance, 5);
    std::cout << "Average value is: " << avg << std::endl;

    /* EXAMPLE 4: Return Pointer from Functions
    As we have seen in last chapter how C++ allows to return an array from a function, similar way C++ allows you to return
    a pointer from a function. To do so, you would have to declare a function returning a pointer as in the following example.

    int * myFunction() {
       .
       .
       .
    }
    Second point to remember is that, it is not good idea to return the address of a local variable to outside of the function,
    so you would have to define the local variable as static variable.

    Now, consider the following function, which will generate 10 random numbers and return them using an array name which represents
    a pointer i.e., address of first array element.
    */

    int *p;

    p = getRandom();
    for(int i=0; i<10; i++){
        std::cout<< "*(p + "<<i<< ") : ";
        std::cout<< *(p + i)<< std::endl;
    }

    return 0;
}

/* EXAMPLE 2 */
void getSeconds(unsigned long *par){
    *par = time(NULL);
    return;
}

/* EXAMPLE 3 */
double getAverage(int *arr, int size){
    int i, sum = 0;
    double avg;
    for(i=0; i<size; i++){
        sum +=arr[i];
    }
    avg = double(sum)/ size; //(double)sum

    return avg;
}

/* EXAMPLE 4 */
int *getRandom(){
    static int r[10];

    //set the seed
    srand((unsigned)time(NULL));

    for(int i=0; i<10; i++){
        r[i] = rand();
        std::cout<< r[i] << std::endl;
    }

    return r;
}
