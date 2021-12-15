#include <iostream>
using namespace std;

class Time // #10
{
public:
	//this ����ϱ�
	void changeHour(int h) {
		this->h = h; //lvalue�� num�� Ŭ���� ���� ����  rvalue�� num�� �Լ��ι��� ����
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
		cout << this->h << "��";
		return *this;
	}

	Time& showMinute() {
		cout << this->m << "��";
		return *this;
	}

	Time& showSecond() {
		cout << this->s << "��" << '\n';
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