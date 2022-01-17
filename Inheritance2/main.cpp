#include <iostream>
#include <string>

/* EXAMPLE 1: */

//base class
class Animal{
public:

    void eat(){
        std::cout<< "Eat!" << std::endl;
    }
    void sleep(){
        std::cout<< "Sleep!" << std::endl;
    }
    void setColor(std::string color){
        this->color = color;
    }
    std::string getColor(){
        return color;
    }


protected:
    std::string type;

private:
    std::string color;

};

//derived class
class Cat:public Animal{
public:
    void miau(){
        std::cout <<"Miau!" << std::endl;
    }

    void setType(std::string type){
        this->type = type;
    }

    std::string getType(){
        return type;
    }

    void displayInfo(std::string mColor){
        std::cout << "I am a " << getType() << " and my color is " << mColor << std:: endl;
    }
};

int main()
{
    /* EXAMPLE 1: */
    Cat cat;

    //call members of the base call
    cat.eat();
    cat.sleep();
    cat.setColor("gray");

    //call members of the derived call
    cat.miau();
    cat.setType("mammal");

    cat.displayInfo(cat.getColor());


    return 0;
}
