#include <iostream>

/* EXAMPLE 1: */
class Polygon{
protected:
    int width, height;

public:
    void setW(int width){
        this->width = width;
    }
    void setH(int height){
        this->height = height;
    }
    int getW(){
        return width;
    }
    int getH(){
        return height;
    }

};

class Rectangle:public Polygon{
public:
    int area(){
        return width*height; //width & height are protected inherited members so we can access them directly
        //if they would have been private, we needed to use get functions().
    }
};

class Triangle:public Polygon{
public:
    int area(){
        return (width*height) / 2;
    }
};

/* EXAMPLE 2: */
/*
Even though access to the constructors and destructor of the base class is not inherited as such, they are automatically
called by the constructors and destructor of the derived class.

Unless otherwise specified, the constructors of a derived class calls the default constructor of its base classes
(i.e., the constructor taking no arguments). Calling a different constructor of a base class is possible, using the
same syntax used to initialize member variables in the initialization list:

derived_constructor_name (parameters) : base_constructor_name (parameters) {...}
*/
class Mother {
  public:
    Mother ()
      { std::cout << "Mother: no parameters\n"; }
    Mother (int a)
      { std::cout << "Mother: int parameter\n"; }
};

class Daughter : public Mother {
  public:
    // nothing specified: call default constructor
    Daughter (int a)
      { std::cout << "Daughter: int parameter\n\n"; }
};

class Son : public Mother {
  public:
    // constructor specified: call this specific constructor
    Son (int a) : Mother (a)
      { std::cout << "Son: int parameter\n\n"; }
};

/* EXAMPLE 3: Multiple inheritance */
class Output{
public:
    static void print(int i){
        std::cout << i << std::endl;
    }
};
class Rectangle2: public Polygon, public Output{
    public:
    int area(){
        return width*height; //width & height are protected inherited members so we can access them directly
        //if they would have been private, we needed to use get functions().
    }
};
class Triangle2:public Polygon, public Output{
public:
    int area(){
        return (width*height) / 2;
    }
};

int main()
{
    /* EXAMPLE 1: */
    Rectangle rect;
    Triangle trgl;

    //base class member functions
    rect.setH(4);
    rect.setW(3);
    trgl.setH(10);
    trgl.setW(5);

    //derived class member functions
    std::cout << rect.area() << std::endl;
    std::cout << trgl.area() << std::endl;

    /* EXAMPLE 2: */
    Daughter kelly(0); //this calls Mother constructor with no parameters
    Son bud(0);//this calls Mother constructor with parameters

    /* EXAMPLE 3: Multiple inheritance */
    Rectangle2 rect2;
    Triangle2 trgl2;
    rect2.setH(10);
    rect2.setW(11);
    trgl2.setH(10);
    trgl2.setW(9);
    rect2.print(rect2.area());
    trgl2.print(trgl2.area());

    return 0;
}
