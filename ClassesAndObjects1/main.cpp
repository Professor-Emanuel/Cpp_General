#include <iostream>
#include <cstring>

/*
The main purpose of C++ programming is to add object orientation to the C programming language and classes are the central feature
of C++ that supports object-oriented programming and are often called user-defined types.

A class is used to specify the form of an object and it combines data representation and methods for manipulating that data into
one neat package. The data and functions within a class are called members of the class.

When you define a class, you define a blueprint for a data type. This doesn't actually define any data, but it does define what
the class name means, that is, what an object of the class will consist of and what operations can be performed on such an object.

*/

/* EXAMPLE 1*/
class Animal{
public:
    char name[15];
    int age;
    char race[15];
    char sex[2]; // one character + the null terminating character \0
};

int main()
{
    //declare a cat & a dog of type Animal
    Animal cat;
    Animal dog;

    //cat specifications
    strcpy(cat.name, "Kitty");
    strcpy(cat.race, "Norvigian cat");
    strcpy(cat.sex, "F");
    cat.age = 3;

    //dog specifications
    strcpy(dog.name, "Thor");
    strcpy(dog.race, "Norvigian dog");
    strcpy(dog.sex, "M");
    dog.age = 2;

    //print specifications
    std::cout << "Cat: " << cat.name <<", "<< cat.race <<", "<< cat.sex<< ", " << cat.age <<std::endl;
    std::cout << "Dog: " << dog.name <<", "<< dog.race <<", "<< dog.sex<< ", " << dog.age <<std::endl;

    return 0;
}
