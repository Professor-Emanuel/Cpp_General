#include <iostream>
/*
Friendships are never corresponded unless specified: In our example, Rectangle is considered a friend class by
Square, but Square is not considered a friend by Rectangle. Therefore, the member functions of Rectangle can
access the protected and private members of Square but not the other way around. Of course, Square could
also be declared friend of Rectangle, if needed, granting such an access.

Another property of friendships is that they are not transitive: The friend of a friend is not considered a
friend unless explicitly specified.
*/

/* EXAMPLE 2: Friend Classes */
class Square; //this is an empty declaration of class Square.
              //This is necessary because class Rectangle uses Square
              //(as a parameter in member convert), and Square uses Rectangle (declaring it a friend).

/* EXAMPLE 1: Friend Functions
Typical use cases of friend functions are operations that are conducted between
two different classes accessing private or protected members of both.
*/
class Rectangle{
private:
    int width, height;

public:
    Rectangle(){}
    Rectangle(int x, int y): width(x), height(y){}

    int area(){
        return width*height;
    }
    friend Rectangle duplicate(const Rectangle&);

    void convert(Square s); // EXAMPLE 2
};

Rectangle duplicate(const Rectangle& p){
    Rectangle res;
    res.width = p.width * 2;
    res.height = p.height * 2;
    return res;
}

/* EXAMPLE 2: Friend Classes
Similar to friend functions, a friend class is a class whose members have access to the private or protected members of another class
*/
class Square{
    friend class Rectangle;
private:
    int side;
public:
    Square(int s):side(s){}
};

void Rectangle::convert(Square s){
    width = s.side;
    height = s.side;
}

int main()
{
    /* EXAMPLE 1: Friend Functions */
    Rectangle rect;
    Rectangle bar(2, 3);
    rect = duplicate(bar);
    std::cout << rect.area() << std::endl;

    /* EXAMPLE 2: Friend Classes */
    Rectangle rect2;
    Square sqr(4);
    rect2.convert(sqr);
    std::cout<< rect2.area() << std::endl;

    return 0;
}
