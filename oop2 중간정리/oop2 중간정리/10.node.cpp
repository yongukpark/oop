#include <iostream>
using namespace std;

class ���� {
private:
public:
	virtual void �����Ҹ�() = 0;
	virtual void �ٸ�����() = 0;
	virtual void ����() = 0;

	virtual ~����() {
		cout << "��������" << '\n';
	}
};

class �� : public ���� {
public:
	virtual void �����Ҹ�() {
		cout << "�п�" << '\n';
	}
	virtual void �ٸ�����() {
		cout << "4��" << '\n';
	}
	virtual void ����() {
		cout << "������" << '\n';
	}

	virtual ~��() {
		cout << "������" << '\n';
	}
};

class �䳢 : public ���� {
public:
	virtual void �����Ҹ�() {
		cout << "����" << '\n';
	}
	virtual void �ٸ�����() {
		cout << "4��" << '\n';
	}
	virtual void ����() {
		cout << "��ġ��" << '\n';
	}

	virtual ~�䳢() {
		cout << "�䳢����" << '\n';
	}
};

int main() {
	�� ��1;
	��1.�����Ҹ�();
	��1.�ٸ�����();
	��1.����();

	�䳢 �䳢1;
	�䳢1.�����Ҹ�();
	�䳢1.�ٸ�����();
	�䳢1.����();
}