#include <iostream>
using namespace std;

class A
{
public:
    void f1()
    {
        cout << "A" << endl;
    }
};

class B1 : virtual public A
{
public:
    void f2()
    {
        cout << "B1" << endl;
    }
};

class B2 : virtual public A
{
public:
    void f3()
    {
        cout << "b3" << endl;
    }
};

class C : public B1, public B2
{
public:
    void f4()
    {
        cout << "C" << endl;
    }
};

int main()
{
    C obj;
    obj.f4();
    obj.f2();
    obj.f3();

    obj.f1();


    return 0;
}