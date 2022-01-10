#include <iostream>

/* EXAMPLE 1: this pointer
Every object in C++ has access to its own address through an important pointer called this pointer.
The this pointer is an implicit parameter to all member functions. Therefore, inside a member function,
this may be used to refer to the invoking object.

Friend functions do not have a this pointer, because friends are not members of a class. Only member functions have a this pointer.
*/

class Plane{
private:
    double length;
    double breadth;
public:
    static int numOfPlanes;

public:
    Plane(double l = 0.0, double b = 0.0){
        std::cout << "Constructor called!" << std::endl;
        length = l;
        breadth = b;

        numOfPlanes++;
    }

    double Area(){
        return length * breadth;
    }

    // return 1 if true, return 0 if false
    int comparePlanes(Plane plane){
        return this->Area() > plane.Area();
    }

    static int getNumOfPlanes(){
        return numOfPlanes;
    }

};

/* EXAMPLE 2: */
class Animal{
private:
    int age;
    char sex;
public:
    void setValues(int mAge, char mSex){
        age = mAge;
        sex = mSex;
    }

    //using this pointer
    void setValues2(int age, char sex){
        this->age = age; // age = age; //without this pointer, data members will contain garbage or nothing
        this->sex = sex; // sex = sex; //because the complier won’t know that you are referring to object’s data members unless you use this pointer.
    }

    void getValues(){
        std::cout << "age: " << age <<", sex: " << sex << std::endl;
    }

    Animal &setAge(int mAge){
        this->age = mAge;
        return *this;
    }
    Animal &setSex(int mSex){
        this->age++; //this line doesn't make sense here, just for exemplification purposes
        this->sex = mSex;
        return *this;
    }
};

/* EXAMPLE 4: Static Members */
int Plane::numOfPlanes = 0; // initialize static member

int main()
{
    /* EXAMPLE 1: */
    Plane p1(10.1, 2.0);
    Plane p2(10.0, 10.0);
    std::cout << p1.comparePlanes(p2) << std::endl;
    if(p1.comparePlanes(p2)){
        std::cout << "Plane 1 is bigger!" << std::endl;
    } else{
        std::cout << "Plane 2 is bigger or equal to plane 1 !" << std::endl;
    }

    /* EXAMPLE 2: */
    Animal cat;
    //cat.setValues(10, 'm');
    //cat.getValues();

    cat.setValues2(4, 'f');
    cat.getValues();

    Animal dog;
    dog.setAge(11).setSex('m');
    dog.getValues();

    /* EXAMPLE 3: Pointer to C++ Classes */
    Plane *pPlane; // Declare pointer to a class.
    pPlane = &p1; // save address of p1 into pPlane.

    // Now try to access a member using member access operator
    std::cout << "Area of p1: " << pPlane->Area() << std::endl;

    pPlane = &p2; // save address of p2 into pPlane.

    // Now try to access a member using member access operator
    std::cout << "Area of p2: " << pPlane->Area() << std::endl;

    /* EXAMPLE 4: Static Members */
    std::cout<< "Total number of planes: " << Plane::numOfPlanes << std::endl;
    std::cout<< "Total number of planes: " << Plane::getNumOfPlanes() << std::endl;

    return 0;
}
