#include <iostream>
/*
Inheritance allows us to define a class in terms of another class, which makes it easier to create and maintain an application.
This also provides an opportunity to reuse the code functionality and fast implementation time.
*/

/*
A derived class inherits all base class methods with the following exceptions −

Constructors, destructors and copy constructors of the base class.
Overloaded operators of the base class.
The friend functions of the base class.
*/


/* EXAMPLE 1: Inheritance */
//base class
class Plane{
private:
    double width;
    double height;

public:
    void setWidth(double mWidth){
        this->width = mWidth;
    }
    void setHeight(double mHeight){
        this->height = mHeight;
    }

    double getWidth(){
        return width;
    }
    double getHeight(){
        return height;
    }

};

//derived class
class Square: public Plane{
public:
    double getPerimeter(){
        return ( 2 * getWidth() + 2 * getHeight() );
    }
};


/* EXAMPLE 2: Multiple Inheritance */
//base class
class Box{
protected:
    int l, w, h;

public:
    Box(int ml = 0,int  mw = 0,int  mh = 0):l(ml), w(mw), h(mh) {}

    void printValues(){
        std::cout<< "Box: " << l << ", " << w << ", " << h;
        std::cout<<std::endl;
    }

    void setValues(int a, int b, int c){
        l = a;
        h = b;
        w = c;
    }
};

//base class
class PaintCost{
public:
    int getCost(int area){
        return area * 10;
    }
};

//derived class
class Cube: public Box, public PaintCost{
public:
    int getArea(){
        return ( 2 * (l*h + l*w + h*w) );
    }
};
int main()
{
    /* EXAMPLE 1: */
    Square s1;
    s1.setHeight(3.0);
    s1.setWidth(3.0);

    std::cout << "Square perimiter: " << s1.getPerimeter() << std::endl;

    /* EXAMPLE 2: */
    Box box1(10, 12, 20);
    box1.printValues();

    Cube cube1;
    cube1.setValues(10, 10, 10);
    std::cout<< cube1.getCost(cube1.getArea()) << std::endl;

    return 0;
}
