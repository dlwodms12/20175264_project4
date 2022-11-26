#include <iostream>

using namespace std;

//���� 6�� Weapon �θ� Ŭ������ Bomb, Gun �ڽ� Ŭ���� �ۼ��ϱ�
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
		cout << "��ź�� �����մϴ�." << endl;
	}
};

class Gun : public Weapon
{
public:
	void load() override
	{
		cout << "���� �����մϴ�." << endl;
	}
};

//���� 8�� getSmallest() �Լ��� ���׸��� ����Ͽ� �ۼ��ϱ�
template <class T>
T getSmallest(T arr[], int n)
{
	for (int i = n - 1; i > 0; i--) {
		// 0 ~ (i-1)���� �ݺ�
		for (int j = 0; j < i; j++) {
			// j��°�� j+1��°�� ��Ұ� ũ�� ���� �ƴϸ� ��ȯ
			if (arr[j] < arr[j + 1]) {
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr[n-1];
}

//���� 9�� Circle Ŭ�������� ���� �߽��� ��Ÿ���� ���� x�� y�� �ڷ����� 
//Ÿ�� �Ű� ������ �ۼ��ϱ�
template <typename G> 
class Circle
{
	//���� �߽� ��ǥ
	G x;
	G y;
	//���� ������
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
	cout << "�ּڰ� : " << getSmallest(list, 5) << endl;

	cout << "---------------------------------------------" << endl;

	Circle<double> circleA(0.0, 0.0, 10.0);
	cout << "���� : " << circleA.area() << endl;

	return 0;

}