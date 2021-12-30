#include <iostream>

int main()
{
    /* EXAMPLE 1:
    Before we understand the concept of array of pointers, let us consider the following example, which makes use of an array of 3 integers.
    */

    const int MAX = 3;
    int var1[MAX] = {2, 5, 8};

    for(int i=0; i<MAX; i++){
        std::cout<< "Value of var1[" << i << "] = ";
        std::cout<< var1[i] << std::endl;
    }

    /* EXAMPLE 2: Array of Pointers
    There may be a situation, when we want to maintain an array, which can store pointers to an int or char or any other data type available.

    int *ptr[MAX];

    This declares ptr as an array of MAX integer pointers. Thus, each element in ptr, now holds a pointer to an int value.
    */

    int var2[MAX] = { 1, 9, 17};
    int *ptr1[MAX];

    for(int i=0; i<MAX; i++){
        ptr1[i] = &var2[i]; // assign the address of integer.
    }

    for(int i=0; i<MAX; i++){
        std::cout<< "Value of var2[" <<i<< "]= ";
        std::cout<< *ptr1[i] << std::endl;

        std::cout<< "Address of var2[" <<i<< "]= ";
        std::cout<< ptr1[i] << std::endl;
    }

    /* EXAMPLE 3:
    You can also use an array of pointers to character to store a list of strings
    For chars/strings is tricky, look at the cout sintax
    */
    const char *ptr2[MAX] = {"Max Megan", "Naruto Shaly", "Sara McKid"};
    for(int i=0 ;i<MAX; i++){
        std::cout<< "Value of ptr2[" <<i<< "]= ";
        std::cout<< ptr2[i] << std::endl;

        std::cout<< "Address of ptr2[" <<i<< "]= ";
        std::cout<< &ptr2[i] << std::endl;
    }

    /*below code aso works, but is it standard? */
    char var3[MAX][20] = {"Max Megan", "Naruto Shaly", "Sara McKid"};
    const char *ptr3[MAX];

    for(int i=0; i<MAX; i++){
        ptr3[i] = &var3[i][0]; // assign the address of integer.
    }

    for(int i=0 ;i<MAX; i++){
        std::cout<< "Value of ptr3[" <<i<< "]= ";
        std::cout<< ptr3[i] << std::endl;

        std::cout<< "Address of ptr3[" <<i<< "]= ";
        std::cout<< ptr3+i << std::endl;
    }

    return 0;
}
