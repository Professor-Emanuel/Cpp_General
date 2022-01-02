#include <iostream>
/*
A class constructor is a special member function of a class that is executed whenever we create new objects of that class.

A constructor will have exact same name as the class and it does not have any return type at all, not even void.
Constructors can be very useful for setting initial values for certain member variables.

A destructor is a special member function of a class that is executed whenever an object of it's class goes out
of scope or whenever the delete expression is applied to a pointer to the object of that class.

A destructor will have exact same name as the class prefixed with a tilde (~) and it can neither return a value
nor can it take any parameters. Destructor can be very useful for releasing resources before coming out of the
program like closing files, releasing memories etc.
*/

class Segment{
public:
    void setL(double myL);
    double getL();
    Segment();
    ~Segment();
    Segment(double myL);
    Segment(const Segment &obj);

private:
    double l;
};

// basic constructor
Segment::Segment(){
    std::cout<< "Segment created!" << std::endl;
}

// custom constructor using Initialization Lists
Segment::Segment(double myL): l(myL) {
    std::cout<< "Segment created by custom constructor!" << std::endl;
};

/* equivalent result without Initialization Lists
Segment::Segment(double myL){
    std::cout<< "Segment created by custom constructor!" << std::endl;
    l = myL;
};
*/

// copy constructor
Segment::Segment(const Segment &obj){
    std::cout << "Segment created by Copy constructor!" << std::endl;
    l = obj.l;
}

// basic deconstructor
Segment::~Segment(){
    std::cout<< "Segment destroyed!" << std::endl;
}

// copy constructor
/*
The copy constructor is a constructor which creates an object by initializing it with an object of the same class,
which has been created previously. The copy constructor is used to.

Initialize one object from another of the same type.
Copy an object to pass it as an argument to a function.
Copy an object to return it from a function.
If a copy constructor is not defined in a class, the compiler itself defines one.If the class has pointer variables
and has some dynamic memory allocations, then it is a must to have a copy constructor.
*/

void Segment::setL(double myL){
    l = myL;
}

double Segment::getL(){
    return l;
}

int main()
{
    Segment line;
    Segment line2(22.5);
    Segment line3 = line2;

    line.setL(20.5);
    std::cout << "Length of line: " << line.getL() << std::endl;
    std::cout << "Length of line2: " << line2.getL() << std::endl;
    std::cout << "Length of line3: " << line3.getL() << std::endl;
    return 0;
}
