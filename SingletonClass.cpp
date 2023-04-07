#include <iostream>
#include <fstream>

using namespace std;

class SingletonClass
{
    private:
        static SingletonClass *instance;
        SingletonClass()
        {
            cout<<"DC"; 
        }
    public:
        static SingletonClass* getInstance()
        {
            if(instance == NULL)
            {
                instance = new SingletonClass();
            }
            return instance;
        }      
};
SingletonClass*  SingletonClass::instance = NULL;
int main()
{
    SingletonClass* s = SingletonClass::getInstance();
    return 0;
}