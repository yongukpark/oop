#include <iostream>
using namespace std;

class play {
public:

	play(int x) { //const_num�� const�̹Ƿ� �� ���� �ȵ�
		const_num = x;
	}

	play(int x) : const_num(x) {}//�̷��� �� �����(�׳� �ȴ�) 


	//Ŭ���� �ȿ����� const
	int dice = 1;
	int rolldice(void) {
		dice = rand() % 6 + 1;
		int localdice = 1;
		localdice = rand() % 6 + 1;
	}

	int const_rolldice(void) const {
		dice = rand() % 6 + 1; // �Լ� ���� ������ ���� �ٲ� �� ����
		int localdice = 1; //���� ������ ���� �ٲ� �� ����
		localdice = rand() % 6 + 1;
	}




private:
	int num = 0;
	const int const_num = 0;
};

int main() {
	// const��
	int num = 1;
	const int pi = 3.14; //���ٲٴ� ����� �������

	//������ +const 
	int x = 0;
	const int* const_ptr1 = &x; //���� �ٲ� �� ����
	int* const const_ptr2 = &x; //�ּҸ� �ٲ� �� ����
	const int* const const_ptr3 = &x; //��, �ּ� �ٲ� �� ����

	const_ptr1 = &x;  //����(�ּҹٲٱ�)
	*const_ptr2 = x;  //����(���ٲٱ�)
	*const_ptr1 = x;  //�Ұ���(���ٲٱ�)
	const_ptr2 = &x;  //�Ұ���(�ּҹٲٱ�)


}