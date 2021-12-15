#include <iostream>
using namespace std;

class Time // #10
{
public:
	//this 사용하기
	void changeHour(int h) {
		this->h = h; //lvalue의 num은 클래스 안의 변수  rvalue의 num은 함수로받은 변수
	}

	Time& setHour(int a) {
		h = a;
		return *this;
	}
	Time& setMinute(int a) {
		m = a;
		return *this;
	}
	Time& setSecond(int a) {
		s = a;
		return *this;
	}

	Time& showHour() {
		cout << this->h << "시";
		return *this;
	}

	Time& showMinute() {
		cout << this->m << "분";
		return *this;
	}

	Time& showSecond() {
		cout << this->s << "초" << '\n';
		return *this;
	}

private:
	int h = 0;
	int m = 0;
	int s = 0;
};

int main() {
	Time t;
	t.showHour().showMinute().showSecond();
	t.changeHour(3);
	t.showHour().showMinute().showSecond();
	t.setHour(12).setMinute(20).setSecond(30);
	t.showHour().showMinute().showSecond();


}