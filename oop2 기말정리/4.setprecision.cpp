#include <iostream>
#include <iomanip> //setprecision
using namespace std;

int main() {
	
	double n = 1.234567;

	cout << "fixed �����\n";
	for (int i = 0; i < 10; i++) {
		cout << setprecision(i) << n << '\n';
		//setprecision(n) �Ҽ��� n�ڸ����� �ݿø�
	}

	cout << fixed << "\nfixed �����\n";
	for (int i = 0; i < 10; i++) {
		cout << setprecision(i) << n << '\n';
		//fixed�� ����ϸ� ���� �ڸ� 0���� ä��
	}
}