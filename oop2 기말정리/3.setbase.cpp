#include <iostream>
#include <iomanip> //setbase
using namespace std;

int main() {

	int num;
	cin >> num;
	cout << "oct : " << oct << num << '\n';
	cout << num << '\n'; //oct가 초기화 안됨
	cout << "dec : " << dec << num << '\n';
	cout << num << '\n'; //dex가 초기화 안됨
	cout << "hex : " << hex << num << '\n';
	cout << num << '\n'; //hex가 초기화 안됨

	for (int i = 8; i <= 20; i+=2) {
		cout << dec << i << "진수 : " << setbase(i) << num << '\n';
		//setbase 8, 10, 16진수 이외의 값은 모두 10진수로 취급
	}
}