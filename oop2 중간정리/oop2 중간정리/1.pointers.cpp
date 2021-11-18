#include <iostream>
using namespace std;


void func_normal(int);
void func_reference(int&);
void func_pointer(int*);
int sumElements1(const int[], const size_t);
int sumElements2(const int*, const size_t);

int main() {

	//포인터란 무엇일까요
	int a = 4;
	int save_value;
	int* save_address;
	save_value = a;
	save_address = &a;
	cout << save_address << "의 값은 " << save_value << "입니다.\n";

	//포인터를 이용한 배열 활용 방법
	int arr[5] = { 1,2,3,4,5 };
	int* ptr1, * ptr2;
	ptr1 = arr; //배열이름 = (배열 첫번째의) 주소?
	ptr2 = &arr[0]; //배열의 0번째 값의 주소
	cout << "주소 " << ptr1 << "의 값은 : " << *ptr1 << '\n';
	cout << "주소 " << ptr2 << "의 값은 : " << *ptr2 << '\n';

	cout << ptr1[1] << ' ' << *(ptr1 + 2) << '\n'; //첫번째 주소 + 2의 값 = arr[2]의 값
	cout << ptr2[3] << ' ' << *(ptr2 + 4) << '\n'; //

	//함수에 변수주는법
	int a1 = 0, b1 = 0, c1 = 0;
	func_normal(a1); //리턴 후 값은 안바뀜
	cout << a1 << '\n';
	func_reference(b1); //리턴 후 참조한 값이 바뀜
	cout << b1 << '\n';
	func_pointer(&c1); //리턴 후 참조한 주소의 값이 바뀜
	cout << c1 << '\n';

	//함수로 배열 넘기는법
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
