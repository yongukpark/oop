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
	//다중 상속을 받을 경우 이름이 같은 함수가 있을 경우 
	//어떤 클래스의 함수인지 명시
	void temp() {
		BBB::show();
		AAA::show();
	}
};

int main() {
	CCC* c = new CCC();
	c->temp();
	//다중 상속을 받을 경우 이름이 같은 함수가 있을 경우 
	//어떤 클래스의 함수인지 명시
	c->AAA::show();
	c->BBB::show();


}