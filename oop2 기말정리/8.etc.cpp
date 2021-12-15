#include <iostream>
using namespace std;

int main() {

	int n = 12;
	cout << showbase; //몇진법인지 명시해줌
	cout << n << '\n';
	cout << hex << n << '\n';
	cout << uppercase << n << "\n\n"; //대문자로 출력해줌

	cout << dec;

	bool b = true;

	cout << b << '\n'; //true = 1, false = 0 으로 출력됨
	cout << boolalpha << b << "\n\n"; //true,false 그대로 출력됨


}