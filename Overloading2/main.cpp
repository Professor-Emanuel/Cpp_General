#include <iostream>
#include <vector>

/* EXAMPLE 1: Overloading [] */
/*
The subscript operator [] is normally used to access array elements. This operator can be overloaded to enhance the existing functionality of C++ arrays.
*/

const int SIZE = 10;

class safeArray{
private:
    int arr[SIZE];

public:
    safeArray(){
        register int i;
        for(i=0; i < SIZE; i++){
            arr[i] = i;
        }
    }

    int &operator[](int i){
        if(i > SIZE){
            std::cout<< "\nIndex out of bounds!" << std::endl;
            //return first element;
            return arr[0];
        }
        return arr[i];
    }
};

/* EXAMPLE 2: Class Member Access Operator (->) Overloading */
/*
It is defined to give a class type a "pointer-like" behavior. The operator -> must be a member function.
If used, its return type must be a pointer or an object of a class to which you can apply.

The operator-> is used often in conjunction with the pointer-dereference operator * to implement "smart pointers."
These pointers are objects that behave like normal pointers except they perform other tasks when you access an
object through them, such as automatic object deletion either when the pointer is destroyed, or the pointer is
used to point to another object.

The dereferencing operator-> can be defined as a unary postfix operator.
class Ptr {
   //...
   X * operator->();
};
Objects of class Ptr can be used to access members of class X in a very similar manner to the way pointers are used. For example −

void f(Ptr p ) {
   p->m = 10 ; // (p.operator->())->m = 10
}
The statement p->m is interpreted as (p.operator->())->m.
*/

class Object{
    static int i, j;

public:
    void f() const{
        std::cout<< i++ << std::endl;
    }
    void g() const{
        std::cout<< j++ << std::endl;
    }
};

// Static member definitions:
int Object::i = 10;
int Object::j = 5;

// Implement a container for the above class
class ObjectContainer{
    std::vector<Object*> a;
public:
    void add(Object *object){
        a.push_back(object);
    }
    friend class SmartPointer;
};

// implement smart pointer to access member of Obj class.
class SmartPointer{
    ObjectContainer oc;
    int index;

public:
    SmartPointer(ObjectContainer& objc){
        oc = objc;
        index = 0;
    }

    // Return value indicates end of list:
    bool operator++(){// Prefix version
        if(index >= oc.a.size())
            return false;

        if(oc.a[++index] == 0)
            return false;

        return true;
    }

    bool operator++(int){// Postfix version
        return operator++();
    }

    // overload operator->
    Object* operator->() const{
        if(!oc.a[index]){
            std::cout<< "Zero value";
            return (Object*)0;
        }
        return oc.a[index];
    }

};

int main()
{
    /* EXAMPLE 1: Overloading [] */
    safeArray A;
    std::cout <<"Value of A[2]: " << A[2] << std::endl;
    std::cout <<"Value of A[12]: " << A[12] << std::endl;
    std::cout <<"Value of A[9]: " << A[9] << std::endl;
    std::cout <<"Value of A[22]: " << A[22] << std::endl;

    /* EXAMPLE 2: Class Member Access Operator (->) Overloading */
    const int sz = 10;
    Object o[sz];
    ObjectContainer oc;

    for(int i=0; i< sz; i++){
        oc.add(&o[i]);
    }

    SmartPointer sp(oc); // Create an iterator
    do{
        sp->f();// smart pointer call
        sp->g();// smart pointer call
    }while(sp++);

    return 0;
}
