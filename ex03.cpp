#include <iostream>

using namespace std;

//문제 6번 Weapon 부모 클래스와 Bomb, Gun 자식 클래스 작성하기
class Weapon
{
public:
	virtual void load() = 0;
};

class Bomb : public Weapon
{
public:
	void load() override
	{
		cout << "폭탄을 적재합니다." << endl;
	}
};

class Gun : public Weapon
{
public:
	void load() override
	{
		cout << "총을 적재합니다." << endl;
	}
};

//문제 8번 getSmallest() 함수를 제네릭을 사용하여 작성하기
template <class T>
T getSmallest(T arr[], int n)
{
	for (int i = n - 1; i > 0; i--) {
		// 0 ~ (i-1)까지 반복
		for (int j = 0; j < i; j++) {
			// j번째와 j+1번째의 요소가 크기 순이 아니면 교환
			if (arr[j] < arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr[n-1];
}

//문제 9번 Circle 클래스에서 원의 중심을 나타내는 변수 x와 y의 자료형을 
//타입 매개 변수로 작성하기
template <typename G> 
class Circle
{
	//원의 중심 좌표
	G x;
	G y;
	//원의 반지름
	G r; 
public:
	Circle(G x, G y, G r) : x{ x }, y{ y }, r{r} {}
	double area()
	{
		return r * r * 3.14;
	}
};

int main()
{
	Gun g;
	Bomb b1;
	Bomb b2;

	Weapon* weapon[3] = { &g,&b1,&b2 };

	for (int i = 0; i < 3; i++)
	{
		weapon[i]->load();
	}

	cout << "---------------------------------------------" << endl;

	double list[] = { 1.2, 3.3, 9.0, 1.5, 8.7 };
	cout << "최솟값 : " << getSmallest(list, 5) << endl;

	cout << "---------------------------------------------" << endl;

	Circle<double> circleA(0.0, 0.0, 10.0);
	cout << "면적 : " << circleA.area() << endl;

	return 0;

}