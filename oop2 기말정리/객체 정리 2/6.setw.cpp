#include <iostream>
#include <iomanip> //setw, setfill
using namespace std;

int main() {
	int a = 12345;
	int b = 1;

	cout << a << '\n';
	cout << setw(10) << b << '\n';
	cout << setw(10) << setfill('*') << b << '\n';
	cout << setw(10) << setfill('*') << left << b << '\n';

	cout << setw(10) << b <<'\n';

	//�и� left�� ������ ä�� �۵����� �˾Ҵµ� ���⼭ �۵��� �ȵ� ������ �𸣰���
	cout << internal << setw(10) << -123;
	//internal�� ��ȣ�� �������� �������� ������ ����
}