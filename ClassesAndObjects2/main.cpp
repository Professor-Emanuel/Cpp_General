#include <iostream>
#include <string> // C++
#include <cstring> // C

// C++ style
class Test{
public:
    Test(const std::string &type): _type(type){}

private:
    std::string _type;
};

// C style
class Test2{
public:
    Test2(const char *type){
        // Assign memory and *copy* the string
        _type = new char[ std::strlen(type) + 1 ];
        std::strcpy(_type, type);
    }

    ~Test2(){
        // Remember to *release* the memory when you are done
        delete [] _type;
    }

private:
    char *_type;
};

int main()
{
    Test test1("test1");

    Test2 test2("test2");
    return 0;
}
