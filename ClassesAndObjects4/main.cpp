#include <iostream>

/*
    A private member variable or function cannot be accessed, or even viewed from outside the class. Only the class and friend
    functions can access private members.

    By default all the members of a class are private, unless specified otherwise.

    A protected member variable or function is very similar to a private member but it provided one additional benefit that
    they can be accessed in child classes which are called derived classes.

*/

class Furniture{
public:
    double height;

protected:
    double width;
    int price;

public:
    void setLength(double mLength);
    double getLength(void);

    void setWidth(double mWidth){
        width = mWidth;
    }
    double getWidth(void){
        return width;
    }

private:
    double length;
};

void Furniture::setLength(double mLength){
    length = mLength;
}

double Furniture::getLength(void){
    return length;
}

// derived/child class
class Table:public Furniture{
    public:
        void setTablePrice(int mPrice){
            price = mPrice; //public inheritance not required to be able to access price
        }

        int getTablePrice(){
            return price; //public inheritance not required to be able to access price
        }
};

int main()
{
    Furniture closet;
    closet.height = 1.5;
    closet.setWidth(2.2);
    closet.setLength(1.25);

    std::cout<<"Closet dimensions: " << closet.height << ", "
    << closet.getWidth() <<", " << closet.getLength() <<std::endl;

    Table table;
    table.height = 2.25; //public inheritance required to be able to access height
    table.setWidth(3.15); //public inheritance required to be able to access setWidth
    table.setLength(4.25); //public inheritance required to be able to access setLength
    table.setTablePrice(2000);
    std::cout<<"Table dimensions: " << table.height << ", "
    << table.getWidth() <<", " << table.getLength() <<std::endl; //public inheritance required to be able to access these members
    std::cout<<"Table price: " << table.getTablePrice() <<std::endl;

    return 0;
}
