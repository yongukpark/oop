#include <iostream>
#include <iomanip> //setbase
using namespace std;

int main() {

	int num;
	cin >> num;
	cout << "oct : " << oct << num << '\n';
	cout << num << '\n'; //oct�� �ʱ�ȭ �ȵ�
	cout << "dec : " << dec << num << '\n';
	cout << num << '\n'; //dex�� �ʱ�ȭ �ȵ�
	cout << "hex : " << hex << num << '\n';
	cout << num << '\n'; //hex�� �ʱ�ȭ �ȵ�

	for (int i = 8; i <= 20; i+=2) {
		cout << dec << i << "���� : " << setbase(i) << num << '\n';
		//setbase 8, 10, 16���� �̿��� ���� ��� 10������ ���
	}
}