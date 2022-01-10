#include <iostream>
/* EXAMPLE 1: FRIEND function
A friend function of a class is defined outside that class' scope but it has the right to access all private and
protected members of the class. Even though the prototypes for friend functions appear in the class definition,
friends are not member functions.

A friend can be a function, function template, or member function, or a class or class template, in which case
the entire class and all of its members are friends.

*/

/* EXAMPLE 2: INLINE function
C++ inline function is powerful concept that is commonly used with classes. If a function is inline, the compiler
places a copy of the code of that function at each point where the function is called at compile time.

Any change to an inline function could require all clients of the function to be recompiled because compiler would
need to replace all the code once again otherwise it will continue with old functionality.

To inline a function, place the keyword inline before the function name and define the function before any calls are
made to the function. The compiler can ignore the inline qualifier in case defined function is more than a line.

!!!A function definition in a class definition is an inline function definition, even without the use of the inline specifier.
*/

class Plane{
private:
    double l;

public:
    double h;
    friend void printL(Plane plane);
    friend int addTen(Plane&);

    friend void printTheL(Plane &plane);
    void setL(double myL);
};

//member function
void Plane::setL(double myL){
    l = myL;
}

/* EXAMPLE 1a: */
//non-member function, but a friend function
void printL(Plane plane){
    /* Because printL() is a friend of Plane, it can
   directly access any member of this class */
   std::cout<< "L = " << plane.l << std::endl;
}

/* EXAMPLE 1b: */
//non-member function, but a friend function
int addTen(Plane &plane){
    //accessing private members from the friend function
    plane.l += 10;
    return plane.l;
}

/* EXAMPLE 1c: */
void printTheL(Plane &plane){
    std::cout<< "L = " << plane.l << std::endl;
}

/* EXAMPLE 1d: */
//A more meaningful use of friend functions would be operating on objects of two different classes. That's when the friend function can be very helpful.
// Add members of two different classes using friend functions
class classB; // forward declaration is needed because an object of type classB is a parameter in the add function
class classA{
private:
    int nA;
    friend int add(classA, classB); // friend function declaration

public:
    classA(): nA(12){} // constructor to initialize nA to 12
};

class classB{
private:
    int nB;
    friend int add(classA, classB); // friend function declaration

public:
    classB(): nB(1){}
};

// access members of both classes
int add(classA objA, classB objB){
    return (objA.nA + objB.nB);
}

/* EXAMPLE 1e: friend class */
class ClassC;
class ClassD{
private:
    int nD;
    friend class ClassC;

public:
    ClassD(): nD(10){}
};
class ClassC{
private:
    int nC;
public:
    ClassC(): nC(11){}

    // member function to add nD
    // from ClassD and nC from ClassC
    int add(){
        ClassD objD;
        return objD.nD + nC;
    }
};


/* EXAMPLE 2a: */
inline double Minimum(double a, double b){
    return ( (a) < (b) ? (a) : (b) );
}

/* EXAMPLE 2b: */
inline void printNum(int n){
    std::cout << n << std::endl;
}

int main()
{
    /* EXAMPLE 1a: */
    Plane plane;
    plane.setL(10.25);
    printL(plane);

    /* EXAMPLE 1b: */
    Plane planeTen;
    planeTen.setL(0);
    printL(planeTen);
    addTen(planeTen);
    printL(planeTen);
    printTheL(planeTen);

    /* EXAMPLE 1d: */
    classA objA;
    classB objB;
    std::cout << "SUM = " << add(objA, objB) << std::endl;

    /* EXAMPLE 1e: */
    ClassC objC;
    std::cout << "SUM = " << objC.add() << std::endl;

    /* EXAMPLE 2a: */
    std::cout << "Minimum (20, 10) = " << Minimum(20, 10) << std::endl;
    std::cout << "Minimum (20.12, 20.15) = " << Minimum(20.12, 20.15) << std::endl;
    std::cout << "Minimum (-20.12, -20.15) = " << Minimum(-20.12, -20.15) << std::endl;

    /* EXAMPLE 2b: */
    printNum(10);
    printNum(100);
    printNum(1000);

    return 0;
}
