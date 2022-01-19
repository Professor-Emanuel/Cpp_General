#include <iostream>

/* EXAMPLE 1: */
/*
The word polymorphism means having many forms. Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

C++ polymorphism means that a call to a member function will cause a different function to be executed depending on the type of object that invokes
the function.
*/

class Plane{
protected:
    int w, h;

public:
    Plane(int w=0, int h=0):w(w), h(h){}

    virtual int area(){
        std::cout <<"Parent class area: " << std::endl;
        return 0;
    }

    // pure virtual function
    // virtual int area() = 0; // use this type, when no meaningful definition can be given to a virtual function
};

class Rectangle: public Plane {
public:
    Rectangle( int a = 0, int b = 0):Plane(a, b) { }

    int area () {
        std::cout << "Rectangle class area :" <<std::endl;
        return (w * h);
    }
};

class Triangle: public Plane {
public:
    Triangle( int a = 0, int b = 0):Plane(a, b) { }

    int area () {
        std::cout << "Triangle class area :" <<std::endl;
        return (w * h / 2);
    }
};

int main()
{
    /* EXAMPLE 1: */
    Plane *plane;
    Rectangle rect(10, 11);
    Triangle trgl(10, 12);

    // store the address of Rectangle
    plane = &rect;

    // call rectangle area.
    plane->area();

    // store the address of Triangle
    plane = &trgl;

    // call triangle area.
    plane->area();
    /* EXAMPLE 1: not what one expects!!!
    OUTPUT:
    Parent class area :
    Parent class area :
    */
    /*
    The reason for the incorrect output is that the call of the function area() is being set once by the compiler as
    the version defined in the base class. This is called static resolution of the function call, or static linkage -
    the function call is fixed before the program is executed. This is also sometimes called early binding because the
    area() function is set during the compilation of the program.

    But now, let's make a slight modification in our program and precede the declaration of area() in the Plane class with the keyword virtual
    OUTPUT:
    Rectangle class area :
    Triangle class area :
    */

    return 0;
}
