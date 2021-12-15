#include <iostream>
using namespace std;

class AAA {
public:
	void show() {
		cout << "AAA" << '\n';
	}
};

class BBB {
public:
	void show() {
		cout << "BBB" << '\n';
	}
};

class CCC : public BBB, public AAA {
public:
	//���� ����� ���� ��� �̸��� ���� �Լ��� ���� ��� 
	//� Ŭ������ �Լ����� ���
	void temp() {
		BBB::show();
		AAA::show();
	}
};

int main() {
	CCC* c = new CCC();
	c->temp();
	//���� ����� ���� ��� �̸��� ���� �Լ��� ���� ��� 
	//� Ŭ������ �Լ����� ���
	c->AAA::show();
	c->BBB::show();


}