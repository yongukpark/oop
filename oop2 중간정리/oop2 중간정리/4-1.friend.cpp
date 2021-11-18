#include <iostream>
using namespace std;

class year
{
public:
	year(int a) {
		y = a;
	}
	void showYear() {
		cout << y << "�� ";
	}

	//friend ����
	friend void setYear(year&, int);
private:
	int y = 0;
};

class month
{
public:
	month(int a, const year& b) {
		m = a;
		y = b;
	}

	void showMonth() {
		y.showYear(); //class year�� �Լ��� ��밡��
		cout << m << "��" << '\n';
	}

	//friend ����
	friend void setMonth(month&, int);

private:
	int m = 0;
	year y = 0; //class year���� ������ ��ü�� ����
};

void setYear(year& y, int a) {
	y.y = a;
}

void setMonth(month& m, int a) { // friend�� ���ǵ� �Լ������� ������� ������ ����
	m.m = a;
}


int main() {
	year y(2021); //y ����
	month m(9, y); //year Ŭ�������� y ������ �������
	y.showYear();
	cout << '\n';
	setMonth(m, 12); //class�Լ��� �ƴ� �Ϲ��Լ��� ��������� ������
	m.showMonth();
}