#include <iostream>
#include <cstring>

/* EXAMPLE 1: DATA STRUCTURES
C/C++ arrays allow you to define variables that combine several data items of the same kind, but structure is another
user defined data type which allows you to combine data items of different kinds.
*/

struct Books{
    char author[30];
    char title[50];
    int id;
}book1;

/* EXAMPLE 2: Structures as Function Arguments
You can pass a structure as a function argument in very similar way as you pass any other variable or pointer.
*/
void printStructure(struct Books book);

/* EXAMPLE 3 : Pointers to Structures
    You can define pointers to structures in very similar way as you define pointer to any other variable as follows

    struct Books *struct_pointer;

    Now, you can store the address of a structure variable in the above defined pointer variable. To find the address of
    a structure variable, place the & operator before the structure's name as follows

    struct_pointer = &Book1;

    To access the members of a structure using a pointer to that structure, you must use the -> operator as follows −

    struct_pointer->title;
*/
void printStructure(struct Books *book);

int main()
{
    /* EXAMPLE 1 */
    struct Books book2, book3, book4;

    // book1 specifications
    strcpy(book1.author, "Kate Walch");
    strcpy(book1.title, "C Programming");
    book1.id = 901190;

    // book2 specifications
    strcpy(book2.author, "Andy McKid");
    strcpy(book2.title, "C Programming for dummies");
    book2.id = 901197;

    //print book1 informations
    std::cout<< "book1 author: " << book1.author << std::endl;
    std::cout<< "book1 title: " << book1.title << std::endl;
    std::cout<< "book1 id: " << book1.id << std::endl;

    //print book2 informations
    std::cout<< "book2 author: " << book2.author << std::endl;
    std::cout<< "book2 title: " << book2.title << std::endl;
    std::cout<< "book2 id: " << book2.id << std::endl;

    /* EXAMPLE 2 */
    // book3 specifications
    strcpy(book3.author, "Candy McLan");
    strcpy(book3.title, "Biology for dummies");
    book3.id = 901220;

    //print book3 informations
    printStructure(book3);

    // book4 specifications
    strcpy(book4.author, "Alan Gefrey");
    strcpy(book4.title, "Biology of neurons");
    book4.id = 901225;

    //print book3 informations
    printStructure(&book4);

    return 0;
}

/* EXAMPLE 2 */
void printStructure(struct Books book){
    std::cout<< "book author: " << book.author << std::endl;
    std::cout<< "book title: " << book.title << std::endl;
    std::cout<< "book id: " << book.id << std::endl;
}

/* EXAMPLE 3 */
void printStructure(struct Books *book){
    std::cout<< "book author: " << book->author << std::endl;
    std::cout<< "book title: " << book->title << std::endl;
    std::cout<< "book id: " << book->id << std::endl;
}

/* In example 2 and 3 we can use the same function name with the same number of arguments, because the argument type is different, and C++ is a polymorphic
programming language*/
