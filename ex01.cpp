//����4

#include <iostream>
#include <string>
using namespace std;

//Box Ŭ����
class Box
{
private:
	double length;
	double width;
	double height;
public:
	Box(int l = 0, int w=0 , int h = 0) : length(l), width(w), height(h){}
	double getVolume(void) 
	{
		return length * width * height;
	}

	//1�� - '<' ������ �������ϴ� ������ �ߺ� �Լ��� �ۼ��ϱ�
	bool operator<(const Box& a)const
	{
		return length * width * height < a.length* a.width* a.height;
	}
};

//Time Ŭ����
//2�� - '++' �����ڸ� �ߺ������ϰ�, �ʿ��� ����Լ��� ������, �Ҹ��ڸ� �����ϱ�
class Time
{
private: 
	int hours;
	int minutes;

public:
	Time() :hours(0), minutes(0) {}
	Time(int h, int m) : hours{ h }, minutes{ m } 
	{
		displayTime();
	}

	void displayTime()
	{
		if (minutes == 60)
		{
			++hours;
			minutes = 0;
		}
		cout << hours << ": " << minutes << endl;
	}
	//����
	Time& operator++()
	{
		++minutes;
		return *this;
	}
	//����
	Time& operator++(int)
	{
		Time temp = *this;
		++(*this);
		return temp;
	}
};

//3�� - student Ŭ���� �ۼ�
//Person Ŭ����
class Person
{
	string name;
	int birthYear;
public:
	Person(string name, int year)
	{
		this->name = name;
		this->birthYear = year;
	}
	void print()
	{
		cout << "���� : " << name << endl;
		cout << "������� : " << birthYear << endl;
	}
};
//student Ŭ����
class Student : public Person
{
	string university;
public:
	Student(string name, int year, string university) :Person(name, year)
	{
		this->university = university;
	}
	void print()
	{
		Person::print();
		cout << "���б� : " << university << endl;
	}
};

//4-1�� Employee Ŭ������ �����϶�
//Employee Ŭ����
class Employee
{
private:
	//�̸�
	string name;
	//����
	int salary;

public:
	//������
	Employee(string name, int salary)
	{
		this->name = name;
		this->salary = salary;
	}
	//������
	string getEmployee_name()
	{
		return name;
	}
	int getEmployee_salary()
	{
		return salary;
	}
	//������
	Employee setEmployee(string name, int salary)
	{
		this->name = name;
		this->salary = salary;
	}
	//������ ����ϴ� �Լ�
	int computeSalary(int salary)
	{
		return salary;
	}
};

//4-2�� �� Ŭ������ ��ӹ޴� Manager Ŭ���� �ۼ�
class Manager : public Employee
{
	int bonus;
public:
	//������
	Manager(string name, int salary, int bonus) : Employee(name, salary)
	{
		this->bonus = bonus;
	}
	//������
	string getManager_name()
	{
		return getEmployee_name();
	}
	int getManager_salary()
	{
		return getEmployee_salary();
	}

	//������
	Manager setEmployee(string n, int s, int b)
	{
		Employee::setEmployee(n, s);
		this->bonus = b;
	}
	//������ ����ϴ� �Լ�
	int computeSalary(int salary, int bonus)
	{
		return salary + bonus;
	}
	//���
	void print()
	{
		cout << "�̸� : " << getManager_name() << endl;
		cout << "���� : " << getManager_salary() << endl;
		cout << "���ʽ� : " << bonus << endl;
		cout << "��ü �޿� : " << computeSalary(getManager_salary(), bonus) << endl;
	}
};

int main()
{
	Box a(10, 10, 10);
	Box b(20, 20, 20);
	cout << (a < b) << endl;;

	cout << "--------------------------------------" << endl;

	Time t(10, 59);
	t++;
	t.displayTime();
	t++;
	t.displayTime();

	cout << "--------------------------------------" << endl;

	Student s("ȫ�浿", 1997, "�ѱ����б�");
	s.print();

	cout << "--------------------------------------" << endl;

	Manager m("��ö��", 200, 100);
	m.print();


	return 0;
}