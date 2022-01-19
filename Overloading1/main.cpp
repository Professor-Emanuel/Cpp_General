#include <iostream>
#include <string>

/* EXAMPLE 1: Function Overloading */
/*
You can have multiple definitions for the same function name in the same scope. The definition of the function
must differ from each other by the types and/or the number of arguments in the argument list. You cannot
overload function declarations that differ only by return type.
*/
class printData{
public:
    void print(int i){
        std::cout << "Printing int: " << i << std::endl;
    }
    void print(double f){
        std::cout << "Printing double: " << f << std::endl;
    }
    /*void print(char* c){
        std::cout << "Printing char: " << c << std::endl;
    }*/
    void print(std::string c){
        std::cout << "Printing string: " << c << std::endl;
    }
};

/* EXAMPLE 2: Operators Overloading */
/*
Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for the operator being defined.
Like any other function, an overloaded operator has a return type and a parameter list.
*/
class House{
public:
    double getVolume(void) {
         return length * breadth * height;
      }
    void setLength( double len ) {
         length = len;
    }
    void setBreadth( double bre ) {
         breadth = bre;
    }
    void setHeight( double hei ) {
         height = hei;
    }

    double getL(){
        return length;
    }
    double getH(){
        return height;
    }
    double getB(){
        return breadth;
    }

    // Overload + (binary) operator to add two House objects.
    House operator+(const House& H){
        House house;
        house.length = this->length + H.length;
        house.breadth = this->breadth + H.breadth;
        house.height = this->height + H.height;
        return house;
    }

    // Overload - (unary) operator to add two House objects.
    House operator-(){
        length = -length;
        height = -height;
        breadth = -breadth;
        return House(length, breadth, height);
    }

    // Overload < relational operator to compare two House objects.
    bool operator<(House& H){
        if(this->getVolume() < H.getVolume()){
            return true;
        }
        else
            return false;
    }

    // Overloading input/output operators
    // it is important to make the operator overloading function a friend of the class because it would be called without creating an object.
    friend std::ostream &operator<<(std::ostream &output, const House &h){
        output << "L: " << h.length << " H: " << h.height << " B: " << h.breadth << std::endl;
        return output;
    }

    friend std::istream &operator>>(std::istream &input, House &h){
        input >> h.length >> h.height >> h.breadth;
        return input;
    }

    // overloaded prefix ++ operator
    House operator++(){
        length++;
        breadth++;
        height++;
        return House(length, breadth, height);
    }

    // overloaded postfix -- operator
    House operator--(int ){
        //save original value
        House H(length, breadth, height);
        length--;
        breadth--;
        height--;
        return H;
    }

    // Assignment Operator Overloading
    void operator=(const House &h){
        length = h.length;
        breadth = h.breadth;
        height = h.height;
    }

    //The function call operator () can be overloaded for objects of class type. When you overload ( ), you are not
    //creating a new way to call a function. Rather, you are creating an operator function that can be passed an arbitrary number of parameters.
    House operator()(int q, int r, int p){
        House h;
        h.length = q + 2;
        h.breadth = r + p + 10;
        h.height = p + 3;
        return h;
    }

private:
    double length;      // Length of a house
    double breadth;     // Breadth of a house
    double height;      // Height of a house

public:
    House(double l = 0.0, double b = 0.0, double h = 0.0):length(l), breadth(b), height(h){}
};

// Overload - (binary) operator to substract two House objects.
House operator-(House &p, House &r){
    House house;
    house.setLength(p.getL() - r.getL());
    house.setBreadth(p.getB() - r.getB());
    house.setHeight(p.getH() - r.getH());
    return house;
}

int main()
{
    /* EXAMPLE 1: Function Overloading */
    printData pd;
    pd.print(5);
    pd.print(5.5);
    pd.print('A'); // this will use the "Printing int" definition
    pd.print("A"); //this will use the "Printing char" def, but with the warning: c++ forbids converting a string constant to 'char*' or comment that definition and declare one that takes string as argument
    pd.print("Abc"); //this will use the "Printing char" def, but with the warning: c++ forbids converting a string constant to 'char*' or comment that definition and declare one that takes string as argument

    /* EXAMPLE 2: Operators Overloading */
    House h1, h2, h3, h4;
    double volume = 0.0;

    h1.setBreadth(10.0);
    h1.setHeight(3.0);
    h1.setLength(5.0);

    h2.setBreadth(20.0);
    h2.setHeight(5.0);
    h2.setLength(10.0);

    volume = h1.getVolume();
    std::cout <<"Volume of house 1: "<< volume << std::endl;

    volume = h2.getVolume();
    std::cout <<"Volume of house 2: "<< volume << std::endl;

    h3 = h1 + h2;
    volume = h3.getVolume();
    std::cout <<"Volume of house 3: "<< volume << std::endl;

    h4 = h2 - h1;
    volume = h4.getVolume();
    std::cout <<"Volume of house 4: "<< volume << std::endl;

    h4 = -h4;
    volume = h4.getVolume();
    std::cout <<"Volume of house 4: "<< volume << std::endl;

    if(h1 < h2){
        std::cout << "h1 is smaller than h2" << std::endl;
    }
    else{
        std::cout << "h2 is smaller than h1" << std::endl;
    }

    if(h3 < h2){
        std::cout << "h3 is smaller than h2" << std::endl;
    }
    else{
        std::cout << "h2 is smaller than h3" << std::endl;
    }

    House h5;
    std::cout<< "Enter 3 values separated by space: " << std::endl;
    std::cin>>h5;
    //std::cout<< "l = " << h5.getL() << " h = " << h5.getH() << " b = " << h5.getB() << std::endl;
    std::cout<<h5;
    ++h5;
    std::cout<<h5;
    std::cout<<h3;
    // calls h3.operator--(0)
    // default argument of zero is supplied by compiler
    h3--;
    // explicit call to member postfix x--
    // x.operator--(0);
    std::cout<<h3;

    h5 = h3; // this works without overloading the assignment operator " = "
    std::cout<<h5;

    House h6 = h5(1, 2, 1); // h5's values don't matter at all - uses the function call operator () overloading
    std::cout<<h6;

    House h7(10.0, 10.10, 10.20); // uses the custom constructor
    std::cout<<h7;
    return 0;
}
