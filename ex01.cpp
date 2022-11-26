//과제4

#include <iostream>
#include <string>
using namespace std;

//Box 클래스
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

	//1번 - '<' 연산을 재정의하는 연산자 중복 함수를 작성하기
	bool operator<(const Box& a)const
	{
		return length * width * height < a.length* a.width* a.height;
	}
};

//Time 클래스
//2번 - '++' 연산자를 중복정의하고, 필요한 멤버함수나 생성자, 소멸자를 정의하기
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
	//전위
	Time& operator++()
	{
		++minutes;
		return *this;
	}
	//후위
	Time& operator++(int)
	{
		Time temp = *this;
		++(*this);
		return temp;
	}
};

//3번 - student 클래스 작성
//Person 클래스
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
		cout << "성명 : " << name << endl;
		cout << "출생연도 : " << birthYear << endl;
	}
};
//student 클래스
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
		cout << "대학교 : " << university << endl;
	}
};

//4-1번 Employee 클래스를 설계하라
//Employee 클래스
class Employee
{
private:
	//이름
	string name;
	//월급
	int salary;

public:
	//생성자
	Employee(string name, int salary)
	{
		this->name = name;
		this->salary = salary;
	}
	//접근자
	string getEmployee_name()
	{
		return name;
	}
	int getEmployee_salary()
	{
		return salary;
	}
	//설정자
	Employee setEmployee(string name, int salary)
	{
		this->name = name;
		this->salary = salary;
	}
	//월급을 계산하는 함수
	int computeSalary(int salary)
	{
		return salary;
	}
};

//4-2번 위 클래스를 상속받는 Manager 클래스 작성
class Manager : public Employee
{
	int bonus;
public:
	//생성자
	Manager(string name, int salary, int bonus) : Employee(name, salary)
	{
		this->bonus = bonus;
	}
	//접근자
	string getManager_name()
	{
		return getEmployee_name();
	}
	int getManager_salary()
	{
		return getEmployee_salary();
	}

	//설정자
	Manager setEmployee(string n, int s, int b)
	{
		Employee::setEmployee(n, s);
		this->bonus = b;
	}
	//월급을 계산하는 함수
	int computeSalary(int salary, int bonus)
	{
		return salary + bonus;
	}
	//출력
	void print()
	{
		cout << "이름 : " << getManager_name() << endl;
		cout << "월급 : " << getManager_salary() << endl;
		cout << "보너스 : " << bonus << endl;
		cout << "전체 급여 : " << computeSalary(getManager_salary(), bonus) << endl;
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

	Student s("홍길동", 1997, "한국대학교");
	s.print();

	cout << "--------------------------------------" << endl;

	Manager m("김철수", 200, 100);
	m.print();


	return 0;
}