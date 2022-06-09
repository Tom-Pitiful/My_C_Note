#include <iostream>
#include <string>
using namespace std;
//C++中常引用的好处：
//对于读取的函数，使用常引用可以节省开销，同时避免原有值的修改
class Stu
{
public:
    Stu(int n, string na);
    friend void display(const Stu& tem);
private:
    int num;
    string name;
};
Stu::Stu(int n,string na) :num(n), name(na) {}

void display(const Stu& tem)
{
    cout << "学号：" << tem.num << endl;
    cout << "姓名：" << tem.name << endl;
}

int main()
{
    Stu s1 = { 1000,"Tom" };
    display(s1);
    return 0;
}
