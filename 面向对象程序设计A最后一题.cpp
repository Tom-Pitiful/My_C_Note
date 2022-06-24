/*
2022/6/24
面向对象编程C++期考最后一题：
创建Person类和Student类和Teacher类
Person类中含有num和name两个数据成员以及成员函数input()和display()
Student类是由Person继承而来，新增数据成员classid和score和getClassid(),getScore()
Teacher类是Person类的派生类，其成员函数avgScore()计算学生的平均分，增加职称poft,住址depart两个数据成员
在主函数中定义10个学生Student[10]，调用无参的默认构造函数，
定义一个老师Teacher t1，利用input()函数进行输入10个学生的数据，同时用avgScore()计算班级平均分，用display()函数进行输出相同班级的平均分
*/

#include <iostream>
#include <string>
using namespace std;
#define N 10
class Person
{
public:
    void input();
    void display();

protected:
    int num;
    string name;
};

void Person::input()
{
    cin >> num >> name;
}
void Person::display()
{
    cout << "num: " << num << " name: " << name << endl;
}

class Student : public Person
{
public:
    int getClassid();
    float getScore();
    void input();

private:
    int classid;
    float score;
};
int Student::getClassid()
{
    return classid;
}
float Student::getScore()
{
    return score;
}
void Student::input()
{
    Person::input();
    cin >> classid >> score;
}

class Teacher : public Person
{
public:
    void avgScore(Student s1[]);
    void display();

private:
    string poft, depart;
    int un_same_classid[N];
    float avg[N];
    int class_num;
};

//先将Student类中的classid和score都复制出来一份，方便后续操作
//将相同的班级的学生组合到一起，采用冒泡排序将班级编号classid进行排序，排序的同时将分数也进行调换
//通过前一个班级id和后一个班级id的比较得出班级的个数，为后面储存班级id和平均分做准备
//比较前一个学生和后一个学生的班级编号，若班级编号相同则将该班所有学生分数累加到该班最后一个学生的分数里，同时做一个计数器记录学生的个数
//若相邻学生的班级编号不同，将前一个学生的班级编号和分数进行平均分的计算以及班级编号的储存，继续比较下一对学生的班级编号，并计算该班平均分并储存
void Teacher::avgScore(Student s1[])
{
    const int n = N;
    int classid[n];
    float score[n], temp1;
    int i, j, k, count, temp;

    for (i = 0; i < n; i++) //将学生类中的班级编号与分数复制一份出来
    {
        classid[i] = s1[i].getClassid();
        score[i] = s1[i].getScore();
    }

    for (i = 0; i < n - 1; i++) //对班级编号排序
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (classid[j + 1] < classid[j])
            {
                temp = classid[j + 1];
                classid[j + 1] = classid[j];
                classid[j] = temp;

                temp1 = score[j + 1];
                score[j + 1] = score[j];
                score[j] = temp1;
            }
        }
    }
    class_num = 1;
    for (i = 0; i < n - 1; i++) //计算不同班级的个数
    {
        if (classid[i] != classid[i + 1])
            class_num++;
    }

    for (j = 0, i = 0; j < class_num; j++) //计算每个班级的平均分并记录到avg数组中，同时记录不同班级的班级编号到un_same_classid数组中
    {
        count = 1;
        while (i < n)
        {
            if (classid[i] == classid[i + 1])
            {
                score[i + 1] += score[i];
                count++;
                i++;
            }
            else
            {
                un_same_classid[j] = classid[i];
                avg[j] = score[i] / count;
                i++;
                break;
            }
        }
    }
}

void Teacher::display()
{
    for (int i = 0; i < class_num; i++)
    {
        cout << "classid: " << un_same_classid[i] << endl;
        cout << "the average score: " << avg[i] << endl;
    }
}

int main()
{
    Student s1[N];
    Teacher t1;
    for (int i = 0; i < N; i++)
        s1[i].input();
    t1.avgScore(s1);
    t1.display();
    return 0;
}

/*测试样例
100101 a 1001 88
100203 b 1002 57
100103 c 1001 66
100321 d 1003 84
100109 e 1001 69
100155 f 1001 70
100213 g 1002 71
100323 H 1003 77
100225 I 1002 41
100813 J 1008 68
*/
