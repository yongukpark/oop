#include <iostream>
using namespace std;


void func_normal(int);
void func_reference(int&);
void func_pointer(int*);
int sumElements1(const int[], const size_t);
int sumElements2(const int*, const size_t);

int main() {

	//�����Ͷ� �����ϱ��
	int a = 4;
	int save_value;
	int* save_address;
	save_value = a;
	save_address = &a;
	cout << save_address << "�� ���� " << save_value << "�Դϴ�.\n";

	//�����͸� �̿��� �迭 Ȱ�� ���
	int arr[5] = { 1,2,3,4,5 };
	int* ptr1, * ptr2;
	ptr1 = arr; //�迭�̸� = (�迭 ù��°��) �ּ�?
	ptr2 = &arr[0]; //�迭�� 0��° ���� �ּ�
	cout << "�ּ� " << ptr1 << "�� ���� : " << *ptr1 << '\n';
	cout << "�ּ� " << ptr2 << "�� ���� : " << *ptr2 << '\n';

	cout << ptr1[1] << ' ' << *(ptr1 + 2) << '\n'; //ù��° �ּ� + 2�� �� = arr[2]�� ��
	cout << ptr2[3] << ' ' << *(ptr2 + 4) << '\n'; //

	//�Լ��� �����ִ¹�
	int a1 = 0, b1 = 0, c1 = 0;
	func_normal(a1); //���� �� ���� �ȹٲ�
	cout << a1 << '\n';
	func_reference(b1); //���� �� ������ ���� �ٲ�
	cout << b1 << '\n';
	func_pointer(&c1); //���� �� ������ �ּ��� ���� �ٲ�
	cout << c1 << '\n';

	//�Լ��� �迭 �ѱ�¹�
	const int sumArr[5] = { 10,20,30,40,50 };
	cout << sumElements1(sumArr, 5) << '\n';
	cout << sumElements2(sumArr, 5) << '\n';

}

void func_normal(int k) {
	k = 10;
	cout << k << ' ';
}

void func_reference(int& k) {
	k = 10;
	cout << k << ' ';
}

void func_pointer(int* k) {
	*k = 10;
	cout << *k << ' ';
}

int sumElements1(const int values[], const size_t size) { // #2
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += values[i];
	}
	return sum;
}

int sumElements2(const int* values, const size_t size) { // #2
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(values + i);
	}
	return sum;
}
