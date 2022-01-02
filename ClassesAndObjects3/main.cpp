#include <iostream>
#include <string>

/* EXAMPLE 1: Class Member Functions
    A member function of a class is a function that has its definition or its prototype within the class
    definition like any other variable. It operates on any object of the class of which it is a member,
    and has access to all the members of a class for that object.


*/

/* EXAMPLE 1*/
class Animal{
public:
    std::string name;
    std::string race;
    int age;

    //methods to set the informations
    void setAge(int mAge);
    void setName(std::string mName);
    void setRace(std::string mRace);

    // methods to get the informations
    std::string GetName(){
        return name;
    }
    std::string GetRace(){
        return race;
    }
    int GetAge(){
        return age;
    }
};

void Animal::setAge(int mAge){
    age = mAge;
}
void Animal::setName(std::string mName){
    name = mName; //C++ style allows using = sign instead of strcpy()
}
void Animal::setRace(std::string mRace){
    race = mRace; //C++ style allows using = sign instead of strcpy()
}

// non-member function
void printDetails(Animal &animal){
    std::cout << animal.GetName() <<", "<< animal.GetRace() << ", " << animal.GetAge() <<std::endl;
}

int main()
{
    Animal cat, dog;

    cat.setAge(2);
    cat.setName("Kat");
    cat.setRace("Birnap");

    dog.setAge(5);
    dog.setName("Pups");
    dog.setRace("Shepard");

    printDetails(cat);
    printDetails(dog);

    return 0;
}
