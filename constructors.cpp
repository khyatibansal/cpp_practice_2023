#include <iostream>
#include <fstream>

using namespace std;

// Virtual concept
class String
{
    private:
        char *st;
        int len;
    public:
        // Default constructor
        String():st((char*)"hello"), len(5){
            cout << "Default constructor";
        }
        // Paramterised constructor
        String(char *st, int len): st(st), len(len){
            cout << "Paramterised constructor";
        }    
        // Copy constructor
        String(String &s2)
        {
            st = s2.st;
            len = s2.len;
            cout << "Copy constructor";
        }
        // Assignment constructor

        String operator=(String &s2) {
            cout << "Assignment constructor";
            return s2;
        }

        virtual char* getString()
        {
            return st;
        }
        // Move constructor
};
class SubString: public String
{
    public:
        char* getString() override
        {
            cout << "subclass";
            return String().getString();
        }
};

template<typename T>
T add(T a, T b)
{
    return a+b;
}
template<typename T>
T subtract(T a, T b)
{
    return abs(a-b);
}
template<typename T>
T operation(T a, T b, T (*myfuncp)(T,T))
{
    T result = (*myfuncp)(a,b);
    return result;
}
int main()
{
    String s1;
    //String s2;
    //String s3;
    char *s = "Hello";
    // Paramterised constructor
    String s4(s, 5);

    // Copy constructor(Different address will return)
    // Copy constructor  = the copy constructor is used to create a new object from an existing object
    String s2(s4);
    // Assignment constructor (Same address will return)
    // Assignement operator = to assign the value of one object to another
    
    //cout << &s1 << &s2 << &s3 << &s4;
    String* s3 = new SubString();
    cout << s3->getString();
    //int (*myfunp)(int,int) = add;
    int a=2;
    int b=2;
    add(a,b);
    int result = operation(a,b,add);
    cout << result;
    return 0;
}

