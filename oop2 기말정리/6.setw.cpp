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

	//분명 left가 고정된 채로 작동될줄 알았는데 여기서 작동이 안됨 이유는 모르겠음
	cout << internal << setw(10) << -123;
	//internal은 부호는 왼쪽정렬 나머지는 오른쪽 정렬
}