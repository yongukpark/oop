#include <iostream>
using namespace std;

//�����Ҵ��� ���ÿ� ���� / �����Ҵ��� ���� ����
//�����Ҵ��� �ӵ��� �� �� ����
//�����Ҵ��� �Լ��� ������ ����� / �����Ҵ��� delete ������� �����

class point {

public:
	point(int a, int b) {
		x = a;
		y = b;
	}
private:
	int x;
	int y;
};

int main() {
	//���� ����, ����
	int num = 3; //���� : ���� ����
	int* pnum = new int(3); //���� : ���� ����
	cout << num;
	cout << "\n" << pnum;
	cout << "\n" << *pnum;
	delete pnum;

	//�迭 ����, ����
	int* panum = new int[5]{ 1,2,3,4,5 };
	cout << "\n" << panum;
	cout << "\n" << *panum << '\n';
	delete[] panum;

	//������ �迭 ����, ����
	int** paanum = new int* [5];
	for (int i = 0; i < 5; i++) {
		paanum[i] = new int[5];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			paanum[i][j] = i * j;
			cout << paanum[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < 5; i++) {
		delete[] paanum[i];
	}


	delete[] paanum;

	//������ ����, ����

	point* p = new point(1, 3);

	delete p;
}